/* Chess-Analyser */

/* CHESS RULES for the USER and the Computer */
/* Part B */

PROC void search_all_moves (color, fill, nr_of_moves, nr_of_room_moves)
	Color_type	color ;			/* IN */
	BOOL		fill ;			/* IN */
	INT		*nr_of_moves ;		/* OUT */
	INT		*nr_of_room_moves ;	/* OUT */

        /* Move mind ptr is initialized by the caller */

BEGIN
   DCL INT  i ;
   DCL INT  min, max ;
   DCL INT  save_count = 0 ;

   *nr_of_moves = 0 ;
   *nr_of_room_moves = 0 ;

   min = (INT)Stone_color_id[color].min_id ;
   max = (INT)Stone_color_id[color].max_id ;

   FOR (i=min; i LE max ; i++)
   DO
      IF (NOT test_empty_stone_id (i))
      THEN
         search_moves (i, color, fill, nr_of_moves) ; /* -> Move Mind */

         IF (Chess_stones[i].stone NE King) AND
            (Chess_stones[i].stone NE Queen) AND
            (Chess_stones[i].stone NE Pawn)
         THEN
            *nr_of_room_moves += *nr_of_moves - save_count ;
         FI

         save_count = *nr_of_moves ;

      FI

   OD

END /* search_all_moves */

PROC void search_moves (from_stone_id, color, fill, nr_of_moves )

	Stone_id_type 	from_stone_id ;	/* IN: is in range - rigth color */
	Color_type	color ;		/* IN */
	BOOL		fill ;		/* IN */
	INT		*nr_of_moves ;  /* OUT: 0..max */

      	/* Move is already filled with : from_field, to_field */
BEGIN

   CASE (Chess_stones[from_stone_id].stone)
   OF King :
	search_king_moves (from_stone_id, color, fill, nr_of_moves) ;
   OF Queen :
	search_queen_moves (from_stone_id, color, fill, nr_of_moves) ;
   OF Rook :
	search_rook_moves (from_stone_id, color, fill, nr_of_moves) ;
   OF Bishop :
 	search_bishop_moves (from_stone_id, color, fill, nr_of_moves) ;
   OF Knigth :
	search_knigth_moves (from_stone_id, color, fill, nr_of_moves) ;
   OF Pawn :
	search_pawn_moves (from_stone_id, color, fill, nr_of_moves) ;
   OTHERWISE
	printf ("\n BAD ERROR IN search moves - not valid from stone id");
   ESAC ;
END /* search_moves */

PROC void search_king_moves (from_stone_id, color, fill, nr_of_moves)

	Stone_id_type 	from_stone_id ;	/* IN */
	Color_type	color ;		/* IN */
	BOOL		fill ;		/* IN */
	INT		*nr_of_moves ;  /* OUT: 0..max */

BEGIN
   DCL   Field_nr_type 	from_field, to_field ;
   DCL   INT            i ;
   DCL   Stone_id_type  to_stone_id , check_stone_id = empty_id ;

   from_field = Chess_stones[from_stone_id].field ;

   FOR (i=0; i LT max_king_field; i++)
   DO
      IF (*King_field_proc[i])(&from_field, &to_field)
      THEN
         to_stone_id = Chess_field [to_field.column][to_field.row] ;
         IF (NOT (test_stone_id_range (to_stone_id, color)))
         THEN
	    IF (fill)
            THEN
               Move_mind_ptr->move_kind  = simple ;
               Move_mind_ptr->from_stone = King ;
               fill_mind_move (from_stone_id, &from_field,
				                    &to_field,nr_of_moves) ;
            ELSE
               *nr_of_moves +=1 ;
            FI
	 FI
      FI
   OD

   /***** CASTLING ********/

   IF (NOT (Check_flag)) AND (Castle_flag[color])
   THEN
      /* short castle test */

      IF ( Castle_type_flag [color][short_castle] )
      THEN
         /* medium king field test */
         to_field = Castle_data [color]
				.castle_direction[short_castle]
				.medium_king_field ;
         to_stone_id = Chess_field [to_field.column][to_field.row] ;
         IF (NOT (test_check_field (to_field, color, &check_stone_id)))
            AND (test_empty_stone_id (to_stone_id))
         THEN
            /* to-field test */
            to_field = Castle_data [color].to_short_king_field ;
            to_stone_id = Chess_field [to_field.column][to_field.row] ;
            IF (NOT (test_check_field (to_field, color,&check_stone_id)))
               AND (test_empty_stone_id (to_stone_id))
            THEN
               IF (fill)
               THEN
                  Move_mind_ptr->move_kind   = short_castling ;
                  Move_mind_ptr->from_stone  = King ;
                  fill_mind_move (from_stone_id, &from_field,
                                                      &to_field,nr_of_moves) ;
               ELSE
                  *nr_of_moves +=1 ;
               FI
            FI
         FI

      FI /* short castle type flag */

      /* long castle test */
      IF ( Castle_type_flag [color][long_castle] )
      THEN
         /* medium king field test - not check ? empty ? */
         to_field = Castle_data [color]
				.castle_direction[long_castle]
				.medium_king_field ;
         to_stone_id = Chess_field [to_field.column][to_field.row] ;
         IF (NOT (test_check_field (to_field, color, &check_stone_id)))
            AND (test_empty_stone_id (to_stone_id))
         THEN
            /* to-field test - not check ?, empty ? */
            to_field = Castle_data [color].to_long_king_field ;
            to_stone_id = Chess_field [to_field.column][to_field.row] ;
            IF (NOT (test_check_field (to_field, color,&check_stone_id)))
               AND (test_empty_stone_id (to_stone_id))
            THEN
               /* medium rook field test - empty ? */
               to_field = Castle_data [color]
				.castle_direction[long_castle]
				.medium_rook_field ;

               to_stone_id = Chess_field [to_field.column][to_field.row] ;
               IF (test_empty_stone_id (to_stone_id))
               THEN
                  IF (fill)
                  THEN
                     to_field = Castle_data [color].to_long_king_field ;
                     Move_mind_ptr->move_kind   = long_castling ;
                     Move_mind_ptr->from_stone  = King ;
                     fill_mind_move (from_stone_id, &from_field, &to_field,
                                   nr_of_moves) ;
                  ELSE
                     *nr_of_moves +=1 ;
                  FI
               FI
            FI
         FI

      FI /* long castle type flag  */

   FI /* not check and castle flag ok */

END /* search_king_moves */

PROC void search_queen_moves (from_stone_id, color, fill, nr_of_moves)
	Stone_id_type 	from_stone_id ;
	Color_type	color ;		/* IN */
	BOOL		fill ;		/* IN */
	INT		*nr_of_moves ;    /* OUT: 0..max */
BEGIN
   DCL   Field_nr_type 	first_from_field, from_field, to_field ;
   DCL   INT            i ;
   DCL   BOOL		same_direction ;
   DCL   Stone_id_type  to_stone_id ;

   first_from_field = Chess_stones[from_stone_id].field ;

   FOR (i=0; i LT max_queen_field; i++)
   DO
      from_field = first_from_field ;
      same_direction = TRUE ;
      WHILE (same_direction)
      DO
         IF ( (*Queen_field_proc[i])(&from_field, &to_field) )
         THEN
            to_stone_id = Chess_field [to_field.column][to_field.row] ;
            IF (NOT (test_empty_stone_id (to_stone_id)) )
            THEN
               same_direction = FALSE ;  /* to stone <> no color ! */
            FI
            IF (NOT (test_stone_id_range (to_stone_id, color)))
            THEN
               /* to stone has other color or has no color = empty stone */
               IF (fill)
               THEN
                  Move_mind_ptr->move_kind = simple ;
                  Move_mind_ptr->from_stone = Queen ;
                  fill_mind_move (from_stone_id, &first_from_field, &to_field,
                                      nr_of_moves) ;
               ELSE
                  *nr_of_moves +=1 ;
               FI
               from_field = to_field ;
            FI
         ELSE
            same_direction = FALSE ;
         FI
      OD
   OD

END /* search_queen_moves */

PROC void search_rook_moves (from_stone_id, color, fill, nr_of_moves)
	Stone_id_type 	from_stone_id ;
	Color_type	color ;		/* IN */
	BOOL		fill ;		/* IN */
	INT		*nr_of_moves ;    /* OUT: 0..max */
BEGIN
   DCL   Field_nr_type 	first_from_field, from_field, to_field ;
   DCL   INT            i ;
   DCL   Stone_id_type  to_stone_id ;
   DCL   BOOL	      	same_direction ;

   first_from_field = Chess_stones[from_stone_id].field ;

   FOR (i=0; i LT max_rook_field; i++)
   DO
      from_field = first_from_field ;
      same_direction = TRUE ;
      WHILE (same_direction)
      DO
         IF ( (*Rook_field_proc[i])(&from_field, &to_field) )
         THEN
            to_stone_id = Chess_field [to_field.column][to_field.row] ;
            IF (NOT (test_empty_stone_id (to_stone_id)) )
            THEN
               same_direction = FALSE ;  /* to stone <> no color ! */
            FI
            IF (NOT (test_stone_id_range (to_stone_id, color)))
            THEN
               IF (fill)
               THEN
                  Move_mind_ptr->move_kind = simple ;
                  Move_mind_ptr->from_stone = Rook ;
                  fill_mind_move (from_stone_id, &first_from_field, &to_field,
                                       nr_of_moves) ;
               ELSE
                  *nr_of_moves +=1 ;
               FI
               from_field = to_field ;
            FI
         ELSE
            same_direction = FALSE ;
         FI
      OD
   OD
END /* search_rook_moves */

PROC void search_bishop_moves (from_stone_id, color, fill, nr_of_moves)
	Stone_id_type 	from_stone_id ;
	Color_type	color ;		/* IN */
	BOOL		fill ;		/* IN */
	INT		*nr_of_moves ;    /* OUT: 0..max */
BEGIN
   DCL   Field_nr_type 	first_from_field, from_field, to_field ;
   DCL   INT            i ;
   DCL   Stone_id_type  to_stone_id ;
   DCL   BOOL		same_direction ;

   first_from_field = Chess_stones[from_stone_id].field ;

   FOR (i=0; i LT max_bishop_field; i++)
   DO
      from_field = first_from_field ;
      same_direction = TRUE ;
      WHILE (same_direction)
      DO
         IF ( (*Bishop_field_proc[i])(&from_field, &to_field) )
         THEN
            to_stone_id = Chess_field [to_field.column][to_field.row] ;
            IF (NOT (test_empty_stone_id (to_stone_id)) )
            THEN
               same_direction = FALSE ;  /* to stone <> no color ! */
            FI
            IF (NOT (test_stone_id_range (to_stone_id, color)))
            THEN
               /* to stone has other color or has no color = empty stone */
               IF (fill)
               THEN
                  Move_mind_ptr->move_kind = simple ;
                  Move_mind_ptr->from_stone = Bishop ;
                  fill_mind_move (from_stone_id, &first_from_field,
                                           &to_field,nr_of_moves) ;
               ELSE
                  *nr_of_moves +=1 ;
               FI
               from_field = to_field ;
            FI
         ELSE
            same_direction = FALSE ;
         FI
      OD
   OD

END /* search_bishop_moves */


PROC void search_knigth_moves (from_stone_id, color, fill, nr_of_moves)
	Stone_id_type 	from_stone_id ;
	Color_type	color ;		/* IN */
	BOOL		fill ;		/* IN */
	INT		*nr_of_moves ;    /* OUT: 0..max */
BEGIN
   DCL   Field_nr_type 	from_field, to_field ;
   DCL   INT            i ;
   DCL   Stone_id_type  to_stone_id ;

   from_field = Chess_stones[from_stone_id].field ;


   FOR (i=0; i LT max_knigth_field; i++)
   DO
      IF (*Knigth_field_proc[i])(&from_field, &to_field)
      THEN
         to_stone_id = Chess_field [to_field.column][to_field.row] ;
         IF (NOT (test_stone_id_range (to_stone_id, color)))
         THEN
            IF (fill)
            THEN
               Move_mind_ptr->move_kind = simple ;
               Move_mind_ptr->from_stone = Knigth ;
               fill_mind_move (from_stone_id, &from_field,
					&to_field,nr_of_moves) ;
            ELSE
               *nr_of_moves +=1 ;
            FI
	 FI
      FI
   OD

END /* search_knigth_moves */

PROC void search_pawn_moves (from_stone_id, color, fill, nr_of_moves)
	Stone_id_type 	from_stone_id ;    /* IN */
 	Color_type	color  ;	   /* IN */
	BOOL		fill ;		   /* IN */
	INT		*nr_of_moves ;     /* OUT: 0..max */
BEGIN
   DCL   Field_nr_type 	from_field, first_from_field, to_field, ep_field ;
   DCL   Stone_id_type  to_stone_id ;
   DCL   INT            i , j ;
   DCL   BOOL		one_step, found_ep ;

   first_from_field = from_field = Chess_stones[from_stone_id].field ;

   /************************ one step **************************************/

   IF (*Pawn_forward_field_proc[color]) (&from_field, &to_field)
   THEN
      to_stone_id = Chess_field[to_field.column][to_field.row] ;
      IF test_empty_stone_id (to_stone_id)
      THEN
         /* We may not strike ! */
         IF to_field.row EQ Pawn_last_row [color]
         THEN
            IF (fill)
            THEN
               FOR (j=0; j LT max_conversion; j++)
               DO
                  Move_mind_ptr->new_stone = Conversion_stone [j] ;
                  Move_mind_ptr->from_stone = Pawn ;
                  Move_mind_ptr->move_kind = conversion ;
                  fill_mind_move (from_stone_id, &from_field, &to_field,
                                      nr_of_moves) ;
               OD
            ELSE
               *nr_of_moves += max_conversion ;
            FI
         ELSE
            IF (fill)
            THEN
               Move_mind_ptr->move_kind = simple ;
               Move_mind_ptr->from_stone = Pawn ;
               fill_mind_move (from_stone_id, &from_field,
						&to_field, nr_of_moves) ;
            ELSE
               *nr_of_moves += 1;
            FI
         FI
         one_step = TRUE ;
      FI
   FI

   /************************ strike **************************************/

   FOR (i=0; i LT max_pawn_strikes; i++)
   DO
      from_field = first_from_field ;
      IF (*Pawn_strike_field_proc[color][i]) (&from_field, &to_field)
      THEN
         to_stone_id = Chess_field [to_field.column][to_field.row] ;
         IF (test_stone_id_range (to_stone_id, other_color(color)) )
         THEN
            /* strike */
            IF to_field.row EQ Pawn_last_row [color]
            THEN
               IF (fill)
               THEN
                  FOR (j=0; j LT max_conversion; j++)
                  DO
                     Move_mind_ptr->new_stone  = Conversion_stone [j] ;
                     Move_mind_ptr->move_kind  = conversion ;
                     Move_mind_ptr->from_stone = Pawn ;
                     fill_mind_move (from_stone_id, &from_field, &to_field,
                                            nr_of_moves) ;
                  OD
               ELSE
                  *nr_of_moves += max_conversion ;
               FI
            ELSE
               IF (fill)
               THEN
                  Move_mind_ptr->move_kind = simple ;
                  Move_mind_ptr->from_stone = Pawn ;
                  fill_mind_move (from_stone_id, &from_field, &to_field,
                                   nr_of_moves) ;
               ELSE
                  *nr_of_moves +=1 ;
               FI
            FI
         FI
      FI
   OD

   /********************** double step ************************************/

   from_field = first_from_field ;

   IF (Pawn_origin_row [color] EQ from_field.row) AND (one_step)
   THEN
      to_field.column 	= from_field.column ;
      to_field.row 	= Pawn_double_step_row [color] ;
      to_stone_id 	= Chess_field[to_field.column][to_field.row] ;

      IF test_empty_stone_id (to_stone_id)
      THEN
         /* We may not strike ! */
	 IF (fill)
         THEN
            Move_mind_ptr->from_stone = Pawn ;
            Move_mind_ptr->move_kind  = double_step ;
            fill_mind_move (from_stone_id, &from_field, &to_field,nr_of_moves) ;
         ELSE
            *nr_of_moves += 1 ;
         FI
      FI
   FI

   /************************ e.p. ****************************************/

   IF (Ep_flag)
   THEN
      ep_field.column = Ep_pawn_field.column ;
      ep_field.row    = Pawn_ep_row [color] ;
      found_ep        = FALSE ;
      FOR (i=0; (i LT max_pawn_strikes) AND (NOT (found_ep)); i++)
      DO
         IF (*Pawn_strike_field_proc[color][i])
	 				(&from_field, &to_field)
         THEN
            IF (to_field.column EQ ep_field.column) AND
                  (to_field.row EQ ep_field.row)
            THEN
               found_ep = TRUE ;
	       IF (fill)
               THEN
                  Move_mind_ptr->from_stone    = Pawn ;
                  Move_mind_ptr->move_kind     = ep ;
                  fill_mind_move (from_stone_id, &first_from_field, &to_field,
				nr_of_moves) ;
               ELSE
                  *nr_of_moves += 1 ;
               FI
            FI
         FI
      OD
   FI

END /* search_pawn_moves */


PROC void fill_mind_move (from_stone_id, from_field, to_field, nr_of_moves)
	Stone_id_type	from_stone_id ;
	Field_nr_type	*from_field ;
	Field_nr_type	*to_field ;
        INT		*nr_of_moves ;

BEGIN
   Stone_id_type	to_stone_id ;
   Line_type		col, row ;

   to_stone_id = Chess_field [to_field->column][to_field->row] ;

   col = to_field->column ;
   row = to_field->row ;

   /* to-stone has not the same color -> move is valid */

   Move_mind_ptr->from_stone_id = from_stone_id ;
   Move_mind_ptr->from_field = *from_field ;

   /* Move_mind_ptr->from_stone = Chess_stones[from_stone_id].stone ; :user !*/

   Move_mind_ptr->to_stone_id = to_stone_id ;
   Move_mind_ptr->to_field   = *to_field ;
   Move_mind_ptr->to_stone   = Chess_stones[to_stone_id].stone ;

   Move_mind_ptr->ep_flag = Ep_flag ;
   IF (Ep_flag)
   THEN
      Move_mind_ptr->ep_pawn_id    = Ep_pawn_id ;
      Move_mind_ptr->ep_pawn_field = Ep_pawn_field ;
   FI

   Move_mind_ptr->check_flag = Check_flag ;

   /* We may not move into check - we make a provisional move */
   IF NOT (test_check_move (Move_mind_ptr))
   THEN
      Move_mind_ptr ++ ;
      *nr_of_moves += 1 ;
   FI

END /* fill_mind_move */
