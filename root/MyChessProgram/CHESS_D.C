/* Chess-Analyser - DYNAMIC DATA File */

/* This Data may be only changed by the MOVE MAKER Procedures : 	*/
/*  	make-move , unmake-move, test-check-move			*/


/***************** DATA STRUCTURES ****************************************/

/* Chess-Field */
Field_type			Chess_field ;	/* IN : field ; OUT : id */
Field_type			*field = &Chess_field ;

/* chess stones */
Stone_position_type 		Chess_stones ;  /* IN : id ; OUT :field,stype */

/* save the moves */
Move_history_type 		Move_history ;
Move_type 			*Move_history_ptr = &(Move_history[0]) ;
Move_type			*move = &(Move_history[0]) ;

/* account moves */
Move_mind_type 			Move_mind ; /* for saving moves */
Move_type			*Move_mind_ptr = &(Move_mind[0][0]) ;


/******************** DATA **********************************************/

INT				Max_move_nr = 0 ; /* default */
INT				Move_nr = 0 ;

/* Color */

Color_type			Moving_color = white ;
Color_type			User_color  ;
Color_type			Computer_color ;

/* game level */

INT				Level 		   = 1 ;
INT				Depth 		   = 1 ;
INT				Nr_of_random_moves = 3 ; /* random moves */
INT				Random_init_nr	   = 0 ; /* init of rnd gen */

/* castle */

BOOL				Castle_flag [max_color]= { TRUE, TRUE } ;
BOOL				Castle_type_flag [max_color][max_castle]
				= { {TRUE, TRUE}, {TRUE,TRUE} } ;

/* e.p */

BOOL				Ep_flag = FALSE ;
Stone_id_type			Ep_pawn_id ;
Field_nr_type			Ep_pawn_field ;


/* game end */

BOOL				Check_flag  = FALSE ;
BOOL				Mate_flag   = FALSE ;
BOOL				Patt_flag   = FALSE ;

