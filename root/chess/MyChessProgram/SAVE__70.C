/* Make VALID COMPUTER Moves */

#define get_max(a,b)  (a GE b) ? a : b
#define get_min(a,b)  (a LE b) ? a : b

#define castle_value			(float)0.9
#define destroyed_castle_value		(float)2.0
#define check_value			(float)0.05
#define double_step_value		(float)0.15
#define matt_value			(float)100.0
#define patt_value			(float)0.0
#define move_fak			(float)0.1
#define bad_value			(float)-1000.0
#define opening_move_nr			(INT)30


PROC BOOL computer_move ()	/* nr of possible moves > 0  ! */
BEGIN
   DCL INT			i ;
   DCL INT			search_depth = Depth ;
   DCL float			position_value = 0;
   DCL INT			move_nr, rnd_move_nr ;
   DCL INT			nr_of_max_best_moves = nr_of_best_moves ;
   DCL INT			nr_of_moves=0 ;
   DCL Move_value_list_type 	value_list [max_moves+1] ;
   DCL Move_value_list_type 	*start_list_ptr = &(value_list[0]) ;
   DCL Move_value_list_type 	*list_ptr ;
   DCL Move_value_list_type 	save_value_list [nr_of_best_moves] ;
   DCL Move_value_list_type 	*array_ptr = &(save_value_list[0]) ;
   DCL Move_value_list_type 	*work_array_ptr = array_ptr ;


   save_value_list[0].next = (Move_value_list_type *) NULL  ;

   IF (find_best_moves (&start_list_ptr, &(value_list[0]),
			search_depth, &nr_of_max_best_moves, &position_value ))
   THEN
      nr_of_moves = get_min (Nr_of_random_moves, nr_of_max_best_moves) ;

      list_ptr = start_list_ptr ;	/* value list */
      work_array_ptr = array_ptr ;	/* save value list */
      FOR (i=0; i LT nr_of_max_best_moves; i++)
      DO
         *work_array_ptr = *list_ptr ;
         list_ptr = list_ptr->next ;
         work_array_ptr ++ ;
      OD

      sort (array_ptr, nr_of_max_best_moves) ;

      rnd_move_nr = random (nr_of_moves) ;
      move_nr = save_value_list[rnd_move_nr].move_nr ;
      *move = Move_mind[search_depth][move_nr] ;

      printf ("\nMy Move : ");
      print_move (Move_nr) ;
      make_move () ;
      RETURN (TRUE);
   ELSE
      /* no move found */
      printf ("\nSorry I have no move");
      RETURN (FALSE);
   FI

END /* computer_move */

BOOL PROC find_best_moves (start_list_ptr, array_ptr,
			   search_depth, nr_of_max_best_moves, position_value)

	Move_value_list_type 	**start_list_ptr ;	/* IN/OUT */
	Move_value_list_type 	*array_ptr ;		/* IN/OUT */
	INT			search_depth ;		/* IN */
	INT			*nr_of_max_best_moves ;	/* OUT */
	float			*position_value ;	/* OUT */
BEGIN
   DCL	Move_value_list_type	his_value_list[max_moves+1] ;
   DCL	Move_value_list_type	*his_list_ptr = &(his_value_list[0]) ;
   DCL	Move_value_list_type	*list_ptr = (Move_value_list_type *) NULL ;
   DCL	Color_type		next_color ;
   DCL  float			his_position_value = 0 ;
   DCL  INT			i ;
   DCL	INT			nr_of_moves=0, room_moves =0 ;
   DCL	INT			nr_of_his_moves=0 ;
   DCL  INT	       		move_nr ;

   IF search_depth EQ 0
   THEN
      next_color = other_color (Moving_color) ;
      *position_value = compute_stone_values (Moving_color)
			- compute_stone_values (next_color);
   ELSE

      Move_mind_ptr = &(Move_mind[search_depth][0]) ;
      search_all_moves (Moving_color, TRUE, &nr_of_moves, &room_moves);
      IF nr_of_moves EQ 0
      THEN
         IF (Check_flag)
         THEN
            *position_value = - matt_value ;
         ELSE
            *position_value = - patt_value ;
         FI
         RETURN (FALSE);
      FI

      *nr_of_max_best_moves = get_min (nr_of_moves, nr_of_best_moves) ;

      search_best_moves (start_list_ptr,array_ptr,search_depth, nr_of_moves);

      list_ptr = *start_list_ptr ;
      FOR (i=0; i LT *nr_of_max_best_moves; i++)
      DO
	 move_nr = list_ptr->move_nr ;
         *move   = Move_mind[search_depth][move_nr] ;
         make_move () ;
         find_best_moves (&his_list_ptr, &(his_value_list[0]),
			search_depth-1, &nr_of_his_moves, &his_position_value);
         list_ptr->value = - his_position_value ;

         unmake_move () ;
	 list_ptr = list_ptr->next ;
      OD

   FI

   RETURN (TRUE);

END /* find_best_moves */

PROC void search_best_moves (start_list_ptr, array_ptr, search_depth,
			     nr_of_moves)

	Move_value_list_type 	**start_list_ptr ;	/* IN/OUT */
	Move_value_list_type 	*array_ptr ;		/* IN */
	INT			search_depth ;		/* IN */
	INT			nr_of_moves ;		/* IN */

/* the Move Mind of 'search_depth' has to be filled by the caller 	*/
/* fills the Move Mind of search_depth-1 and forget them		*/
/* fills nr of moves best moves in the Move List starting by list ptr	*/
/* returns a list of best moves starting with list ptr			*/

BEGIN
   DCL 	float 			*value ;
   DCL  float	       		save_value ;
   DCL  float			max_strike_value ;
   DCL	float		 	moving_diff ;
   DCL 	INT			i, j ;
   DCL  INT		 	nr_of_my_moves, my_room_moves  ;
   DCL  INT		 	nr_of_his_moves, his_room_moves ;
   DCL  Stone_type		saved_from_stone ;
   DCL  Color_type		my_color = Moving_color ;
   DCL  Move_type		*saved_move_mind_ptr ;

   /* Initialize the List with the last one - BAD Element */

   array_ptr->value = bad_value ;
   array_ptr->next  = (Move_value_list_type *) NULL ;
   *start_list_ptr  = array_ptr ; /* the start points to [0] element */

   /* searching for best moves and concatenating in the list */

   FOR (i=0; i LT nr_of_moves; i++)
   DO
      array_ptr ++ ;
      array_ptr->move_nr = i ;
      value = &(array_ptr->value) ;
      *value = 0 ;

      *move = Move_mind[search_depth][i] ;

      saved_from_stone = move->from_stone ;

      IF (move->move_kind EQ short_castling) OR
		(move->move_kind EQ long_castling)
      THEN
         *value += castle_value ;
      ELSIF (move->move_kind EQ double_step)
      THEN
         IF Move_nr LE opening_move_nr
         THEN
            IF (move->from_field.column GE 2
               AND move->from_field.column LE 5)  /* not dange moves */
            THEN
               *value += double_step_value ;
            FI
         ELSE
            *value += double_step_value ;	/* end game */
         FI
      FI

      IF (move->from_stone EQ King) AND (Castle_flag[Moving_color])
      THEN
         *value -= destroyed_castle_value ;
      FI

      *value += Chess_stone_values [move->to_stone] ;

      make_move () ;

      nr_of_my_moves = 0 ;
      my_room_moves = 0 ;
      Move_mind_ptr = &(Move_mind [search_depth-1][0]) ;
      search_all_moves (my_color, FALSE, &nr_of_my_moves, &my_room_moves) ;

      /****** filling the next Move Mind  and forget	******************/
      /****** WE TEST MATE ***********************************************/

      nr_of_his_moves = 0 ;
      his_room_moves = 0 ;
      saved_move_mind_ptr = Move_mind_ptr = &(Move_mind [search_depth-1][0]) ;
      search_all_moves (Moving_color, TRUE, &nr_of_his_moves, &his_room_moves) ;

      IF (nr_of_his_moves EQ 0)
      THEN
         IF Check_flag
         THEN
            *value = matt_value ;
         ELSE
            *value = patt_value ;
         FI
      ELSE

         max_strike_value = empty_value ;
         FOR (j=0; j LT nr_of_his_moves; j++)
         DO
            save_value = Chess_stone_values[saved_move_mind_ptr->to_stone] ;

            IF save_value GT max_strike_value
            THEN
               max_strike_value = save_value ;
            FI

            saved_move_mind_ptr ++ ;

         OD

         *value -= max_strike_value ;
      FI

      IF Move_nr LE opening_move_nr
      THEN
         moving_diff = (my_room_moves - his_room_moves) * move_fak ;
      ELSE
         moving_diff = (nr_of_my_moves - nr_of_his_moves) * move_fak ;
      FI

      *value += moving_diff / Chess_stone_values[saved_from_stone] ;

      insort (   start_list_ptr, array_ptr ) ;

      unmake_move () ;

   OD

END /* search_best_moves */

PROC void insort (start_list_ptr, sort_elem_ptr )
	Move_value_list_type 	**start_list_ptr ;    /* IN: list start, OUT */
	Move_value_list_type 	*sort_elem_ptr ;      /* IN: initialized */

BEGIN
   DCL  Move_value_list_type 	*prev_elem_ptr ;
   DCL  Move_value_list_type 	*list_ptr = *start_list_ptr ;

   IF (sort_elem_ptr->value) GT (list_ptr->value)
   THEN
      /* new first element */
      sort_elem_ptr->prev 	= (Move_value_list_type *) NULL;
      sort_elem_ptr->next 	= *start_list_ptr ;
      list_ptr->prev		= sort_elem_ptr ;
      *start_list_ptr     	= sort_elem_ptr ;

   ELSE
      list_ptr = list_ptr->next ;
      WHILE (sort_elem_ptr->value LE list_ptr->value)
      DO
         list_ptr = list_ptr->next ;
      OD

      /* perform in every case the insort */
      prev_elem_ptr 	  = list_ptr->prev ;
      prev_elem_ptr->next = sort_elem_ptr ;
      sort_elem_ptr->prev = prev_elem_ptr ;
      sort_elem_ptr->next = list_ptr ;
      list_ptr->prev      = sort_elem_ptr ;
   FI

   RETURN ; /* for VAX Debugging */

END /*insort */

PROC void sort (array_ptr, number)
	Move_value_list_type 	*array_ptr ;	/* IN/OUT */
	INT			number ;	/* array [0..number-1 ] */

/* We use the algorithmn : Straigth-Insertion */

BEGIN
   DCL INT 			i, j, k ;
   DCL Move_value_list_type 	sort_elem ;
   DCL BOOL			searching ;

   FOR (i=1; i LT number; i++)
   DO
      sort_elem = *(array_ptr+i) ;
      searching = TRUE ;
      k = 0 ;
      FOR (j=i; (j GT 0) AND (searching) ; j--)
      DO
         IF ( sort_elem.value GT ((array_ptr + (j-1))->value) )
         THEN
            *(array_ptr+j) = *(array_ptr + (j-1)) ;
         ELSE
            k = j ;
            searching = FALSE ;
         FI
      OD
      *(array_ptr+k) = sort_elem ;
   OD

   RETURN ; /* for VAX debugging */

END /* sort */

