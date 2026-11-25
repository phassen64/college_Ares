/* VALID USER MOVES */

PROC BOOL make_user_move (user_str, user_move)
	CHAR 		*user_str ;	/* IN 	  */
	Move_type	*user_move ;	/* IN/OUT */
BEGIN
   INT 				i , nr_of_moves ;

   IF (convert_str_to_move (user_str, user_move))
   THEN
      Move_mind_ptr = &(Move_mind[0][0]) ;
      nr_of_moves = 0 ;

      search_moves (user_move->from_stone_id, Moving_color, TRUE, &nr_of_moves);

      IF (nr_of_moves EQ 0)
      THEN
         printf ("\nError :: make-user-move : Stone has no move !") ;
         RETURN (FALSE) ;
      FI

      Move_mind_ptr = &(Move_mind[0][0]) ;

      FOR (i=0; i LT nr_of_moves; i++)
      DO
         IF (user_move->from_stone_id EQ Move_mind_ptr->from_stone_id)
	   AND (user_move->to_field.row EQ Move_mind_ptr->to_field.row)
           AND (user_move->to_field.column EQ Move_mind_ptr->to_field.column)
         THEN
            IF (user_move->move_kind EQ conversion)
            THEN
               IF (user_move->new_stone EQ Move_mind_ptr->new_stone)
               THEN
                  *move = *Move_mind_ptr ;
                  make_move () ;
                  RETURN (TRUE) ;
               FI
            ELSE
               *move = *Move_mind_ptr ;  /* other and default-conversion */
               make_move () ;
               RETURN (TRUE) ;
            FI
         FI
         Move_mind_ptr ++ ;    		/* we compare the next saved move */
      OD

      printf ("\nError :: make-user-move : Chess Rules not OK !");
      RETURN (FALSE) ;

   ELSE

      printf ("\nError :: make-user-move : Move Syntax not OK !");
      RETURN (FALSE) ;

   FI

END /* make_user_move */

