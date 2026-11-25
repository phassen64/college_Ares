/* Chess-Analyser  */
/* Main Service Procs */


PROC Color_type other_color (color)
	Color_type color ;
BEGIN
   IF (color EQ white)
   THEN
      RETURN (black) ;
   ELSIF (color EQ black)
   THEN
      RETURN (white) ;
   ELSE
      RETURN (no_color) ;
   FI
END /* other_color */

PROC Position_value_type position_value (test_color)
Color_type test_color ;
BEGIN
   Position_value_type    stone_value ;
   Position_value_type    result_value ;

     stone_value = compute_stone_values (test_color) ;

     result_value = stone_value ; /* in the first version only stone value */

     RETURN (result_value) ;

END /* position_value */



PROC Position_value_type compute_stone_values (test_color)
Color_type test_color ;

BEGIN
   Stone_type   	found_stone ;
   INT			i ;
   INT			min_id, max_id ;
   Position_value_type	counter = 0 ;

   min_id = (INT)Stone_color_id[test_color].min_id ;
   max_id = (INT)Stone_color_id[test_color].max_id ;

   FOR (i=min_id; i LE max_id; i++)
   DO
         found_stone = Chess_stones [i].stone ;
         counter = counter + Chess_stone_values[found_stone] ;
   OD

   RETURN (counter) ;

END /* compute_stone_values */


PROC BOOL test_field_range (field_nr)
Field_nr_type	*field_nr ;

BEGIN
   IF (field_nr->column GE 0) AND (field_nr->column LE 7) AND
      (field_nr->row GE 0) AND (field_nr->row LE 7)
   THEN
      RETURN (TRUE) ;
   ELSE
      RETURN (FALSE) ;
   FI
END


PROC BOOL test_stone_id_range (test_stone_id, test_color)
	Stone_id_type	test_stone_id ; /* IN : 0.. max */
       	Color_type	test_color ;    /* IN : white, black, no_color */

BEGIN

   IF ((test_stone_id GE Stone_color_id[test_color].min_id) AND
      (test_stone_id LE Stone_color_id[test_color].max_id) )
   THEN
      RETURN (TRUE) ;
   ELSE
      RETURN (FALSE) ;
   FI

END /* test_stone_id_range */


PROC BOOL test_empty_stone_id (test_stone_id)
	Stone_id_type	test_stone_id ; /* IN : 0.. max - must be valid ! */
BEGIN

   IF Chess_stones[test_stone_id].stone EQ Empty
   THEN
      RETURN (TRUE) ;
   ELSE
      RETURN (FALSE) ;
   FI
END /* test_empty_stone_id */



PROC BOOL convert_str_to_field_nr (string, field_nr)
CHAR 		*string ;
Field_nr_type 	*field_nr ;

BEGIN

   IF (string[0] GE 'A' AND string[0] LE 'H') AND
      (string[1] GE '1' AND string[1] LE '8')
   THEN
      field_nr->column = string[0] - 'A' ;
      field_nr->row = string[1] - '0' - 1;
      RETURN (TRUE) ;
   ELSE
      printf ("\nError : convert-str-to-field-nr");
      RETURN (FALSE);
   FI

END /* convert_str_to_field_nr */


PROC BOOL convert_field_nr_to_str (field_nr, string )
Field_nr_type 	*field_nr ;
CHAR 		*string ;

BEGIN

   IF (field_nr->column GE 0) AND (field_nr->column LE 7) AND
      (field_nr->row GE 0) AND (field_nr->row LE 7)
   THEN
      string[0] = ('A' + (field_nr->column - 0)) ;
      string[1] = ('1' + (field_nr->row - 0)) ;
      string[2] = '\0' ;
      RETURN (TRUE) ;
   ELSE
      printf ("\nError : convert-field-nr-to-str");
      RETURN (FALSE);
   FI

END /* convert_field_nr_to_str */


PROC BOOL convert_char_to_stone (stone_char, stone_ptr)
	CHAR 		stone_char ;
	Stone_id_type	*stone_ptr ;
BEGIN
   CASE (stone_char)
   OF 'Q' : *stone_ptr = Queen ;
   OF 'R' : *stone_ptr = Rook ;
   OF 'B' : *stone_ptr = Bishop ;
   OF 'N' : *stone_ptr = Knigth ;
   OTHERWISE
      *stone_ptr = Empty ;
      printf ("\nError : convert-char-to-stone");
      RETURN (FALSE) ;
   ESAC ;

   RETURN (TRUE) ;

END /* convert_char_to_stone */


PROC BOOL convert_stone_to_char (stone , stone_char)
	Stone_id_type	stone ;         /* IN */
	CHAR 		*stone_char ;   /* OUT */
BEGIN
   CASE (stone)
   OF Queen :  *stone_char  = 'Q' ;
   OF Rook   : *stone_char  = 'R' ;
   OF Bishop : *stone_char  = 'B' ;
   OF Knigth : *stone_char  = 'N' ;
   OTHERWISE
      *stone_char = ' ' ;
      printf ("\nError : convert-stone-to-char");
      RETURN (FALSE) ;
   ESAC ;

   RETURN (TRUE) ;

END /* convert_stone_to_char */


PROC BOOL convert_short_to_long_move (move_ptr)
	Move_type	*move_ptr ;	/* IN/OUT */

BEGIN
	Stone_id_type   f_stone_id ;
	Stone_id_type   t_stone_id ;

   f_stone_id = Chess_field
                [move_ptr->from_field.column][move_ptr->from_field.row] ;
   t_stone_id = Chess_field
                [move_ptr->to_field.column] [move_ptr->to_field.row] ;

   IF (test_empty_stone_id (f_stone_id))
   THEN
      printf ("\nError : convert-short-to-long-move : undefined f-stone-id ") ;
      RETURN (FALSE) ;
   FI

   IF (test_stone_id_range (t_stone_id, Moving_color))
   THEN
      printf ("\nError : convert-short-to-long-move : t-stone-id color check ");
      RETURN (FALSE) ;
   FI

   /* move is theoretically valid */
   /* test the rules at this point in the next step ! */

   move_ptr->from_stone = Chess_stones [f_stone_id].stone ;
   move_ptr->to_stone = Chess_stones [t_stone_id].stone ;

   move_ptr->from_stone_id = f_stone_id ;
   move_ptr->to_stone_id = t_stone_id ;

   RETURN (TRUE) ;

END /* convert_short_to_long_move */


PROC BOOL convert_str_to_move (string, move_ptr)
	CHAR		*string ;	/* IN 	*/
	Move_type	*move_ptr ;	/* OUT 	*/

BEGIN
   IF NOT (convert_str_to_field_nr (&(string[0]), &(move_ptr->from_field)) )
   THEN
      printf ("\nError : convert-str-to-move : from-field not defined") ;
      RETURN (FALSE) ;
   FI

   IF NOT (convert_str_to_field_nr (&(string[3]), &(move_ptr->to_field)) )
   THEN
      printf ("\nError : convert-str-to-move : to-field not defined") ;
      RETURN (FALSE) ;
   FI

   IF (string[5] EQ '-')
   THEN
      IF (NOT (convert_char_to_stone (string[6], &(move_ptr->new_stone)) ))
      THEN
         printf ("\nError : convert-str-to-move : wrong new stone input!");
         RETURN (FALSE);
      ELSE
         move_ptr->move_kind = conversion ;
      FI
   ELSE
      move_ptr->move_kind = simple ;
   FI
   /* default conversion is 'Queen' ! */

   IF NOT ( convert_short_to_long_move (move_ptr) ) /* from/to field -> move */
   THEN
      printf ("\nError : convert-str-to_move : short to long not possible");
      RETURN (FALSE) ;
   FI

   RETURN (TRUE) ;

END /* convert_str_to_move */


PROC BOOL test_check (test_color)
   Color_type  		test_color ;		/* IN */

BEGIN
   DCL Stone_id_type	from_stone_id=empty_id, king_id ;
   DCL Field_nr_type	king_field ;

   king_id = Castle_data [test_color].king_id ;
   king_field = Chess_stones [king_id].field ;

   IF (test_check_field (king_field, test_color, &from_stone_id))
   THEN
      RETURN (TRUE) ;
   ELSE
      RETURN (FALSE) ;
   FI

END /* test_check */

PROC BOOL test_remis (test_color)
   Color_type  		test_color ;		/* IN */

BEGIN
   DCL Color_type	next_color ;

   next_color = other_color (test_color) ;

   IF (compute_stone_values (test_color)) LE
      (compute_stone_values (next_color))
   THEN
      RETURN (TRUE) ;
   ELSE
      RETURN (FALSE) ;
   FI

END /* test_remis */

PROC Game_end_type test_game_end ()
BEGIN
   INT			min_id , max_id ;
   INT			i ;
   INT			nr_of_moves=0 ;

   Mate_flag = FALSE ;
   Patt_flag = FALSE ;

   min_id = (INT)Stone_color_id[Moving_color].min_id ;
   max_id = (INT)Stone_color_id[Moving_color].max_id ;

   Move_mind_ptr = &(Move_mind[0][0]) ;

   FOR (i=min_id; i LE max_id; i++)
   DO
      IF (NOT (test_empty_stone_id((Stone_id_type)i)) )
      THEN
         search_moves ((Stone_id_type)i, Moving_color, TRUE, &nr_of_moves) ;
         IF (nr_of_moves GT 0)
         THEN
            RETURN (play) ;
         FI
      FI
   OD

   IF (Check_flag)
   THEN
      Mate_flag = TRUE ;
      IF (Moving_color EQ User_color)
      THEN
         RETURN (mate) ;
      ELSE
         RETURN (loose) ;
      FI
   ELSE
      Patt_flag = TRUE ;
      IF (Moving_color EQ User_color)
      THEN
         RETURN (patt) ;
      ELSE
         RETURN (patt) ;
      FI

   FI

END /* test_game_end */

PROC BOOL test_check_field (test_field, test_color, check_stone_id)
   Field_nr_type	test_field ;		/* IN */
   Color_type  		test_color ;		/* IN */
   Stone_id_type	*check_stone_id ;	/* OUT */

BEGIN
   DCL Field_nr_type	from_field ;
   DCL Field_nr_type	to_field ;
   DCL BOOL		same_direction ;
   DCL Stone_id_type	from_stone_id ;
   DCL INT		i ;

   /* Knigth Check ? */

   to_field = test_field ;
   FOR (i=0; i LT max_knigth_field; i++)
   DO
      IF (*Knigth_field_proc[i])(&to_field, &from_field)
      THEN
         from_stone_id = Chess_field [from_field.column][from_field.row] ;
         IF Chess_stones[from_stone_id].stone EQ Knigth
            AND NOT (test_stone_id_range (from_stone_id, test_color))
         THEN
            *check_stone_id = from_stone_id ;
            RETURN (TRUE) ;
         FI
      FI
   OD


   /* Rook or Queen Check ? */

   FOR (i=0; i LT max_rook_field; i++)
   DO
      to_field = test_field ;
      same_direction = TRUE ;
      WHILE (same_direction)
      DO
         IF ( (*Rook_field_proc[i])(&to_field, &from_field) )
         THEN
            from_stone_id = Chess_field [from_field.column][from_field.row] ;
            IF (test_empty_stone_id (from_stone_id))
            THEN
               to_field = from_field ;  /* same direction */
            ELSE
               same_direction = FALSE ;  /* to stone <> no color ! */
               IF   ((Chess_stones[from_stone_id].stone EQ Rook) OR
		     (Chess_stones[from_stone_id].stone EQ Queen))
                  AND
		    (NOT (test_stone_id_range (from_stone_id, test_color)))
               THEN
                  *check_stone_id = from_stone_id ;
                  RETURN (TRUE) ;
               FI
            FI
         ELSE
            same_direction = FALSE ;
         FI
      OD
   OD


   /* Bishop or Queen Check ? */

   FOR (i=0; i LT max_bishop_field; i++)
   DO
      to_field = test_field ;
      same_direction = TRUE ;
      WHILE (same_direction)
      DO
         IF ( (*Bishop_field_proc[i])(&to_field, &from_field) )
         THEN
            from_stone_id = Chess_field [from_field.column][from_field.row] ;
            IF (test_empty_stone_id (from_stone_id))
            THEN
               to_field = from_field ;
            ELSE
               same_direction = FALSE ;  /* to stone <> no color ! */
               IF  ((Chess_stones[from_stone_id].stone EQ Bishop) OR
		    (Chess_stones[from_stone_id].stone EQ Queen))
                  AND
                    (NOT (test_stone_id_range (from_stone_id, test_color)))
               THEN
                  *check_stone_id = from_stone_id ;
                  RETURN (TRUE) ;
               FI
            FI
         ELSE
            same_direction = FALSE ;
         FI
      OD
   OD


   /* King Check ? */

   to_field = test_field ;
   FOR (i=0; i LT max_king_field; i++)
   DO
      IF (*King_field_proc[i])(&to_field, &from_field)
      THEN
         from_stone_id = Chess_field [from_field.column][from_field.row] ;
         IF Chess_stones[from_stone_id].stone EQ King
            AND NOT (test_stone_id_range (from_stone_id, test_color))
         THEN
            *check_stone_id = from_stone_id ;
            RETURN (TRUE) ;
         FI
      FI
   OD


   /* Pawn Check ? */

   FOR (i=0; i LT max_pawn_strikes; i++)
   DO
      to_field = test_field ;
      IF (*Pawn_strike_field_proc[test_color][i]) (&test_field, &from_field)
      THEN
         from_stone_id = Chess_field[from_field.column][from_field.row] ;
         IF Chess_stones[from_stone_id].stone EQ Pawn
            AND NOT (test_stone_id_range (from_stone_id, test_color))
         THEN
            *check_stone_id = from_stone_id ;
            RETURN (TRUE) ;
         FI
      FI
   OD

   RETURN (FALSE) ;

END /* test_check_field */


