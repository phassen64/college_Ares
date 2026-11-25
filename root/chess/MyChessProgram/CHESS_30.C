/* CHESS-ANALYSER	*/
/* General IO Procedures */
/* Menue Procs */

PROC void print_menue ()
BEGIN

   printf ("\nInput possiblities :\n");

   printf ("Move := { <letter><digit>-<letter><digit>[-{'Q','R','B','K'}]") ;
   printf ("\n") ;

   printf ("Specials ::\n");

   printf ("?  := print this menue\n");

   /* look into the position */
   printf (">  := 1 Move Forward in Move History \n");
   printf ("<  := 1 Move Back in Move History \n");
   printf ("^  := Restart the Game\n");
   printf ("h  := Move History Listing\n") ;

   /* Change the Position */
   printf ("!  := Start a Special Game \n");

   /* Outputs */
   printf ("o  := output stone position\n");
   printf ("s  := Show Game Type\n");

   /* Position Value */
   printf ("v  := Position Value \n");

   /* Change the Game Type */
   printf ("l  := Level change\n") ;
   printf ("u  := User only\n");
   printf ("c  := Computer only \n") ;
   printf ("t  := Toggle the Color and Move \n");
   printf ("n  := Computer shall move now \n");

   /* Finnish the game */
   printf (".  := Stop the game\n");
   printf ("r  := You offer remis\n");

END /* print_menue */



PROC BOOL user_input (input_str)
	CHAR	*input_str ;	/* IN/OUT */

BEGIN
   Color_type		help_color ;

   WHILE (TRUE)
   DO
      printf ("\nInput   : ");
      scanf ("%s",input_str) ;

      CASE (*input_str)
         OF '?' : print_menue () ;

         OF '>' : make_history_move () ;
         OF '<' : unmake_history_move () ;
         OF '^' : restart_chess_game () ;
         OF 'h' : print_move_history () ;

         OF 's' : show_game () ;

         OF '!' : start_special_chess_game () ;
         OF 'o' : output_stone_position () ;

         /* Position Value provs */

         OF 'v' : output_position_value () ;

         OF 'l' : change_game () ;

         OF 't' :
		  IF Computer_color EQ no_color
                  THEN
                     Computer_color = Moving_color ;
                     User_color = other_color(Moving_color) ;
                  ELSE
                     help_color = Computer_color ;
                     Computer_color = other_color (help_color) ;
                     User_color = help_color ;
                  FI

                  printf ("\nNow you moves with : %s",Color_str[User_color]) ;
                  printf ("\nThe Computer moves : %s",
				Color_str[Computer_color]) ;
         OF 'u' :
         	  Computer_color = no_color ;
                  User_color = Moving_color ;
                  printf ("\nComputer is out ! ") ;
                  printf ("\nYou moves next with : %s",Color_str[User_color]) ;
         OF 'c' :
         	  User_color = no_color ;
                  Computer_color = Moving_color ;
                  printf ("\nUser is out ! ") ;
                  printf ("\nNext Computer move  : %s",
	    			Color_str[Computer_color]) ;


         /* Finish the Game */

         OF '.' : printf ("\nThe game is finnished - good bye !") ;
		  RETURN (FALSE) ;

         OF 'r' : IF (test_remis (Computer_color))
                  THEN
                     printf ("\nI take your offer - REMIS !");
		     RETURN (FALSE) ;
                  ELSE
                     printf ("\nSorry - I can't take your remis offer !");
                  FI

         OF 'n' : RETURN (TRUE) ;

         OTHERWISE
            /* User want to make a move */
            RETURN (TRUE) ;
      ESAC ;

   OD

END /* user_input */


PROC void print_move (int_move_nr)
INT  		int_move_nr ;

BEGIN
   INT  		ext_move_nr ;
   Field_nr_type	from_field, to_field ;
   CHAR   		from_str[20], to_str[20], new_stone_char=Empty ;
   Move_type		*history_move ;

   history_move = &(Move_history[int_move_nr]) ;
   ext_move_nr = (int_move_nr DIV 2) + 1;

   from_field = history_move->from_field ;
   to_field   = history_move->to_field ;

   convert_field_nr_to_str (&from_field, from_str) ;
   convert_field_nr_to_str (&to_field, to_str) ;

   IF (history_move->move_kind EQ conversion)
   THEN
      convert_stone_to_char (history_move->new_stone, &new_stone_char) ;
      printf ("%2.2s-%2.2s-%c",from_str,to_str,new_stone_char) ;
   ELSE
      printf ("%2.2s-%2.2s",from_str,to_str) ;
      printf ("  ");
   FI
   printf ("   "); /* three spaces */

END /* print_move */


PROC void print_move_history ()
BEGIN
   INT    ext_from_move_nr=0, ext_to_move_nr=0 ;
   INT    int_from_move_nr , int_to_move_nr ;

   printf ("\nfrom-move nr : ") ;
   scanf ("%hd",&ext_from_move_nr) ;

   IF ext_from_move_nr EQ 0
   THEN

      ext_from_move_nr = (Move_nr DIV 2) + (Move_nr MOD 2) ;
      int_from_move_nr = Move_nr - 1  ;
      int_from_move_nr -= int_from_move_nr MOD 2 ;
      int_to_move_nr   = Move_nr - 1  ;

   ELSE

      int_from_move_nr = (ext_from_move_nr - 1) * 2 ;
      int_from_move_nr -= int_from_move_nr MOD 2 ;

      printf ("\nto-move nr   : ") ;
      scanf ("%hd",&ext_to_move_nr) ;

      IF ext_to_move_nr EQ 0
      THEN
         int_to_move_nr   = Move_nr - 1  ;
      ELSE
         int_to_move_nr = (ext_to_move_nr - 1) * 2 ;
      FI
   FI

   WHILE (int_from_move_nr LE int_to_move_nr)
   DO
      printf ("\n") ;
      printf ("Move : %3d   ",ext_from_move_nr) ;

      print_move (int_from_move_nr) ;
      IF (int_from_move_nr NE int_to_move_nr)
      THEN
         print_move (int_from_move_nr+1) ;
      FI
      ext_from_move_nr += 1 ;
      int_from_move_nr += 2 ;
   OD

END /* print_move_history */

PROC void make_history_move ()
BEGIN
   DCL INT ext_move_nr ;

   IF (move->move_kind NE invalid)
   THEN
      ext_move_nr = ((Move_nr+1) DIV 2) + ((Move_nr+1) MOD 2) ;
      printf ("\nWe do Move nr %d : ", ext_move_nr);
      print_move (Move_nr);
      make_move () ;
   ELSE
      printf ("\nWe can't do a move !");
   FI
END



PROC void unmake_history_move ()
BEGIN
   DCL INT ext_move_nr ;

   IF (Move_nr GT 0)
   THEN
      unmake_move () ;
      ext_move_nr = ((Move_nr+1) DIV 2) + ((Move_nr+1) MOD 2) ;
      printf ("\nWe undo Move nr %d : ", ext_move_nr);
      print_move (Move_nr);
   ELSE
      printf ("\nWe can't undo a move !");
   FI
END


PROC void show_game ()
BEGIN
   output_stone_position () ;
   printf ("\nMove  : ");
   print_move (Move_nr-1) ; /* actual move */
   printf ("\nLevel : %d",Level) ;
   printf ("\nMoving Color now : %s",Color_str[Moving_color]) ;
END


PROC void change_game ()
BEGIN
   DCL  INT  save_int=0 ;

      printf ("\nOld Level            : %d",Level) ;
      printf ("\nOld Depth            : %d",Depth);
      printf ("\nFix Best Moves       : %d",nr_of_best_moves);
      printf ("\nOld Random Moves     : %d",Nr_of_random_moves);
      printf ("\nRandom init Nr       : %d",Random_init_nr);
      printf ("\n");
      printf ("\nNEW Level (spec = 0) : ") ;
      scanf ("%hd",&save_int) ;
      IF save_int LE 0
      THEN
         printf ("\nNEW Depth (0<x<max depth)       : ") ;
         scanf ("%hd",&Depth) ;
         Level = Depth ;
         printf ("\nNEW Nr of Random Moves  (>0)    : ") ;
         scanf ("%hd",&Nr_of_random_moves) ;
         printf ("\nNEW Random Init Nr     (>=0)    : ") ;
         scanf ("%hd",&Random_init_nr) ;
         init_random () ;
      ELSE
         Level = save_int ;
         Depth = Level ;
      FI

END /* change_game */


PROC void output_stone_position ()
BEGIN

   Stone_type	found_stone ;
   INT		i, j, k ;
   INT		min_id, max_id ;
   BOOL		convert_ok ;
   CHAR		*color_str [2] = {	"\nWhite Stones ::",
					"\n\nBlack Stones ::" } ;
   CHAR		field_str[20] ;


   FOR (k=0; k LT 2; k++)
   DO
      printf ("%s",color_str[k]);

      FOR (i=1 ; i LT max_stone_types ; i++) /* not the Empty */
      DO
         printf ("\n%8s : ",Stone_str[(Stone_type)i]);

         min_id = min_white_stone_id + k * max_color_stones ;
         max_id = min_id + max_color_stones - 1 ;

         FOR (j=min_id; j LE max_id; j++)
         DO
            found_stone = Chess_stones [j].stone ;

            IF found_stone EQ i
            THEN
               convert_ok = convert_field_nr_to_str (&(Chess_stones[j].field),
						field_str ) ;

	       printf ("%s  ",field_str) ;
            FI
         OD
      OD
   OD
END /* output_stone_position */


PROC void input_stone_position ()
BEGIN
BOOL position_ok = TRUE ;

   REPEAT

   UNTIL (position_ok) ;

END


PROC void output_position_value ()
BEGIN
   Position_value_type	white_val, black_val ;
   INT			white_moves=0, black_moves=0 ;
   INT			white_room_moves=0, black_room_moves=0 ;
   CHAR			*color_str [2] = {	"\nWhite : ",
						"\nBlack : " } ;

   white_val = compute_stone_values (white) ;
   black_val = compute_stone_values (black) ;

   printf ("\n\nStone Values ::");
   printf ("%s %f %s %f",color_str[0],white_val,color_str[1],black_val);

   search_all_moves (white,FALSE, &white_moves, &white_room_moves);
   search_all_moves (black,FALSE, &black_moves, &black_room_moves);

   printf ("\nMoves ::");
   printf ("%s %d:%d %s %d:%d",
			color_str[0],white_moves,white_room_moves,
			color_str[1],black_moves,black_room_moves );
   printf ("\n");


END /* output_position_values */


PROC Game_end_type game_end_info ()
BEGIN
   INT			min_id , max_id ;
   INT			nr_of_moves = 0;
   INT			nr_of_room_moves = 0;

   min_id = (INT)Stone_color_id[Moving_color].min_id ;
   max_id = (INT)Stone_color_id[Moving_color].max_id ;

   Move_mind_ptr = &(Move_mind[0][0]) ;
   search_all_moves (Moving_color, TRUE, &nr_of_moves, &nr_of_room_moves) ;

   IF (nr_of_moves GT 0)
   THEN
      IF (Check_flag)
      THEN
         printf ("\n\ngame-end-info : Check !!!") ;
      FI
      RETURN (play) ;
   ELSE
      IF (Check_flag)
      THEN
         Mate_flag = TRUE ;
         IF (Moving_color EQ User_color)
         THEN
            printf ("\n\ngame-end-info : Sorry you have loosed - CHECK mate !") ;
            RETURN (mate) ;
         ELSE
            printf ("\n\ngame-end-info : I have loosed - CHECK mate !") ;
            RETURN (loose) ;
         FI
      ELSE
         Patt_flag = TRUE ;
         IF (Moving_color EQ User_color)
         THEN
            printf ("\n\ngame-end-info : You are PATT !") ;
            RETURN (patt) ;
         ELSE
            printf ("\n\ngame-end-info : I am PATT !") ;
            RETURN (patt) ;
         FI
      FI
   FI

END /* game_end_info */
