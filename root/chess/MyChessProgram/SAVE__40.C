/* Chess-Analyser */
/* Include Move Makers */

PROC void make_move ()
/* automatically *move is used as pointer to the Move History */

BEGIN
   DCL
      Field_nr_type  	*from_field = &(move->from_field) ;
      Field_nr_type  	*to_field = &(move->to_field) ;
      Stone_id_type  	*from_stone_id = &(move->from_stone_id) ;
      Stone_id_type  	*to_stone_id = &(move->to_stone_id) ;
      Castle_direction_type
			*short_castle_ptr
			= & (Castle_data[Moving_color].
			              castle_direction[short_castle]) ;
      Castle_direction_type
			*long_castle_ptr
			= &(Castle_data[Moving_color].
			              castle_direction[long_castle]) ;
      Color_type	next_color ;

   /************************* DEFAULTS *************************************/

   Move_nr += 1 ;
   next_color = other_color (Moving_color) ;

   /******************* Chess Field adjust ******************************/

   CASE (move->move_kind)

   OF simple :    ;
      Ep_flag = FALSE ;

   OF short_castling :

      Ep_flag = FALSE ;
      Chess_field
	[short_castle_ptr->from_rook_field.column]
	[short_castle_ptr->from_rook_field.row] = empty_id ;
      Chess_field
	[short_castle_ptr->to_rook_field.column]
	[short_castle_ptr->to_rook_field.row]
			= short_castle_ptr->rook_id ;
      Chess_stones
   	[short_castle_ptr->rook_id].field
			= short_castle_ptr->to_rook_field ;

   OF long_castling :

      Ep_flag = FALSE ;
      Chess_field
	[long_castle_ptr->from_rook_field.column]
	[long_castle_ptr->from_rook_field.row] = empty_id ;
      Chess_field
	[long_castle_ptr->to_rook_field.column]
	[long_castle_ptr->to_rook_field.row]
			= long_castle_ptr->rook_id ;
      Chess_stones
   	[long_castle_ptr->rook_id].field
			= long_castle_ptr->to_rook_field ;

   OF double_step :  ;

      Ep_flag = TRUE ;
      Ep_pawn_id = *from_stone_id ;
      Ep_pawn_field.column = to_field->column ;
      Ep_pawn_field.row    = to_field->row ;

   OF ep :    ;

      Ep_flag = FALSE ;
      Chess_stones [move->ep_pawn_id].stone = Empty ;
      Chess_field  [move->ep_pawn_field.column]
				[move->ep_pawn_field.row] = empty_id ;

   OF conversion :  ;

      Ep_flag = FALSE ;
      Chess_stones [*from_stone_id].stone  = move->new_stone ;

   OTHERWISE  ;

   ESAC ;


   /******************* Field + Stone ADJUST ****************************/

   Chess_field[from_field->column][from_field->row] 	= empty_id ;
   Chess_field[to_field->column][to_field->row]     	= *from_stone_id ;

   Chess_stones[*from_stone_id].field       		= *to_field ;
   Chess_stones [*to_stone_id].stone 			= Empty ;

   /************ Castle Flags **** ************************************/

   IF Castle_flag [Moving_color]
   THEN
      move->from_cflags_changes = reset_castle_flags (*from_stone_id,
							Moving_color) ;
   ELSE
      move->from_cflags_changes = no_changes ;
   FI

   IF Castle_flag [next_color]
   THEN
      move->to_cflags_changes = reset_castle_flags (*to_stone_id, next_color) ;
   ELSE
      move->to_cflags_changes = no_changes ;
   FI

   /****************** Move ++  **************************************/

   Moving_color = next_color ;
   Move_history_ptr ++ ;		/* ptr to next entry in history */
   move = Move_history_ptr ;		/* init next move */

   /****************** new move Initialization ***************************/

   move->check_flag = test_check (next_color) ;  /* new check flag */
   Check_flag = move->check_flag ;               /* we give check  */

   move->ep_flag    = Ep_flag ;			 /* is next ep. possible ? */
   IF (Ep_flag)
   THEN
      move->ep_pawn_id = Ep_pawn_id ;
      move->ep_pawn_field = Ep_pawn_field ;
   FI

END /* make_move */

PROC void unmake_move ()
/* automatically *move is used as pointer to the Move History */

BEGIN
   DCL
      Castle_direction_type  *short_castle_ptr ;
      Castle_direction_type  *long_castle_ptr ;
      Color_type	     next_color = Moving_color ;


/********************** DEFAULTS **************************************/

   Move_nr -= 1 ;
   Moving_color = other_color (Moving_color) ;
   short_castle_ptr = & (Castle_data[Moving_color].
			              castle_direction[short_castle]) ;
   long_castle_ptr  = &(Castle_data[Moving_color].
 		   	              castle_direction[long_castle]) ;

/************************ MOVE -- **************************************/

   Move_history_ptr -- ;
   move = Move_history_ptr ;

/************************ Move Type ***************************************/

   CASE (move->move_kind)

   OF simple :    ;

   OF short_castling :

      Chess_field
	[short_castle_ptr->from_rook_field.column]
	[short_castle_ptr->from_rook_field.row]
			= short_castle_ptr->rook_id ;
      Chess_field
	[short_castle_ptr->to_rook_field.column]
	[short_castle_ptr->to_rook_field.row]
			= empty_id ;
      Chess_stones
   	[short_castle_ptr->rook_id].field
			= short_castle_ptr->from_rook_field ;

   OF long_castling :

      Chess_field
 	[long_castle_ptr->from_rook_field.column]
	[long_castle_ptr->from_rook_field.row]
			= long_castle_ptr->rook_id ;
      Chess_field
	[long_castle_ptr->to_rook_field.column]
	[long_castle_ptr->to_rook_field.row]
			= empty_id ;
      Chess_stones
   	[long_castle_ptr->rook_id].field
			= long_castle_ptr->from_rook_field ;

   OF double_step :  ;

   OF ep :

      Chess_field  [move->ep_pawn_field.column][move->ep_pawn_field.row]
			= move->ep_pawn_id ;
      Chess_stones [move->ep_pawn_id].stone = Pawn ;

   OF conversion :

      Chess_stones [move->from_stone_id].stone  = move->from_stone ;

   OTHERWISE  ;

   ESAC ;


   /******************* Field + Stone ADJUST ****************************/

   Chess_field[move->from_field.column][move->from_field.row]
						= move->from_stone_id ;
   Chess_field[move->to_field.column][move->to_field.row]
						= move->to_stone_id ;

   Chess_stones[move->from_stone_id].field      = move->from_field ;
   Chess_stones [move->to_stone_id].stone 	= move->to_stone ;

   IF (move->from_cflags_changes NE no_changes)
   THEN
      set_castle_flags (move->from_cflags_changes, Moving_color) ;
   FI

   IF (move->to_cflags_changes NE no_changes)
   THEN
      set_castle_flags (move->to_cflags_changes, next_color) ;
   FI

   Check_flag = move->check_flag ;	/* saved check flag */
   Ep_flag    = move->ep_flag ;         /* saved if a double step before */

   IF (Ep_flag)
   THEN
      Ep_pawn_id = move->ep_pawn_id ;
      Ep_pawn_field = move->ep_pawn_field ;
   FI

END /* unmake_move */

PROC BOOL test_check_move (move_ptr)
	Move_type	*move_ptr ;
BEGIN
   DCL BOOL check_ok ;

   /* 1. makes a provisional move     			*/
   /* 2. test check of the from color => illegal move 	*/
   /* 3. unmakes the provisional move			*/

   /******************* MAKE TEST MOVE ********************************/

   /* ENTER ID  */
   Chess_field[move_ptr->from_field.column][move_ptr->from_field.row]
				= empty_id ;
   Chess_field[move_ptr->to_field.column][move_ptr->to_field.row]
				= move_ptr->from_stone_id ;

   /* ENTER FIELD */
   Chess_stones[move_ptr->from_stone_id].field
	  			= move_ptr->to_field ;

   /* ENTER STONE TYP */
   IF move_ptr->move_kind EQ conversion
   THEN
      Chess_stones [move_ptr->from_stone_id].stone
				= move_ptr->new_stone ;
   FI
   Chess_stones [move_ptr->to_stone_id].stone 		= Empty ;

   /******************** CHECK TEST ************************************/

   IF test_check (Moving_color)
   THEN
      check_ok = TRUE ;
   ELSE
      check_ok = FALSE ;
   FI

   /****************** UNMAKE TEST MOVE *********************************/

   /* RE-ENTER STONE ID */
   Chess_field [move_ptr->from_field.column][move_ptr->from_field.row]
				= move_ptr->from_stone_id ;

   Chess_field [move_ptr->to_field.column][move_ptr->to_field.row]
				= move_ptr->to_stone_id ;

   /* RE-ENTER FIELD */
   Chess_stones [move_ptr->from_stone_id].field	 = move_ptr->from_field ;
   Chess_stones [move_ptr->to_stone_id].field 	 = move_ptr->to_field ;

   /* RE-ENTER STONE TYP */
   Chess_stones [move_ptr->from_stone_id].stone  = move_ptr->from_stone ;
   Chess_stones [move_ptr->to_stone_id].stone 	 = move_ptr->to_stone ;

   RETURN (check_ok) ;

END /* test_check_move */


PROC Castle_flags_change_type reset_castle_flags (moving_stone_id, test_color)
	Stone_id_type			moving_stone_id ;
       	Color_type			test_color ;
BEGIN
   IF ( Castle_flag [test_color] )
   THEN
      IF (moving_stone_id) EQ (Castle_data[test_color].king_id)
      THEN
	 Castle_flag [test_color] = FALSE ;
         RETURN (null_full) ;

      ELSIF (moving_stone_id) EQ
               (Castle_data[test_color].castle_direction[short_castle].rook_id)
      THEN
 	 IF (Castle_type_flag [test_color][long_castle])
         THEN
            Castle_type_flag [test_color][short_castle] = FALSE ;
            RETURN (null_short) ;
         ELSE
	    Castle_flag [test_color] = FALSE ;
            RETURN (null_full) ;
         FI

      ELSIF (moving_stone_id) EQ
                (Castle_data[test_color].castle_direction[long_castle].rook_id)
      THEN
 	 IF (Castle_type_flag [test_color][short_castle])
         THEN
            Castle_type_flag [test_color][long_castle] = FALSE ;
            RETURN (null_long) ;
         ELSE
	    Castle_flag [test_color] = FALSE ;
            RETURN (null_full) ;
         FI

      ELSE
         RETURN (no_changes) ;
      FI

   ELSE
      RETURN (no_changes) ;
   FI

END /* reset_castle_flags */

PROC void set_castle_flags (castle_flags_changes, test_color)
	Castle_flags_change_type	castle_flags_changes ;
	Color_type			test_color ;
BEGIN
	CASE (castle_flags_changes)
	OF null_short :
		Castle_type_flag [test_color][short_castle] = TRUE ;
	OF null_long :
		Castle_type_flag [test_color][long_castle] = TRUE ;
	OF null_full :
		Castle_flag [test_color] = TRUE ;
        OTHERWISE
		RETURN ;
	ESAC ;

        RETURN ;

END /* set_castle_flags */

