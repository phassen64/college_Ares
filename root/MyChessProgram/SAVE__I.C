/* Chess-Analyser - Include-File */
/* Definitions and Modes */

/* my_chess_buffer.c */

/**** Global Synonyms *******/

#define max_row  		8
#define max_column 	       	8
#define max_lines	       	8
#define max_color_stones       	16
#define max_stone_id	       	32
#define max_fields	       	64
#define max_color	       	2
#define nr_of_best_moves	6	/* we search for n best moves  */
#define max_depth		6	/* we search depth times       */
#define max_moves	       	60
#define max_id_moves		28	/* queen moves */
#define max_possible_moves     	200
#define max_history_moves      	260
#define max_stone_types	       	7

/* max possible moves */
#define max_queen_moves		28
#define max_queen_field		8
#define max_rook_moves		14
#define max_rook_field		4
#define max_bishop_moves	14
#define max_bishop_field	4
#define max_knigth_field	8
#define max_knigth_moves	8

/* king */

#define max_king_moves		8
#define max_king_field		8
#define max_castle		2

/* pawns */

#define max_pawn_moves		4
#define max_pawn_field		4
#define max_pawn_strikes	2
#define max_conversion		4

/* default stone values */

#define king_value		(float) 100
#define queen_value		(float) 9
#define rook_value		(float) 4.5
#define bishop_value		(float) 3.5
#define knigth_value		(float) 3
#define pawn_value		(float) 1
#define empty_value		(float) 0

/* Stone identifications */

typedef INT			Stone_id_type ;

#define empty_id		(Stone_id_type) 0
#define white_king_id		(Stone_id_type) 1
#define white_queen_id		(Stone_id_type) 2
#define white_rook1_id		(Stone_id_type) 3
#define white_rook2_id		(Stone_id_type) 4
#define white_bishop1_id	(Stone_id_type) 5
#define white_bishop2_id	(Stone_id_type) 6
#define white_knigth1_id	(Stone_id_type) 7
#define white_knigth2_id	(Stone_id_type) 8
#define white_pawn1_id		(Stone_id_type) 9
#define white_pawn2_id		(Stone_id_type) 10
#define white_pawn3_id		(Stone_id_type) 11
#define white_pawn4_id		(Stone_id_type) 12
#define white_pawn5_id		(Stone_id_type) 13
#define white_pawn6_id		(Stone_id_type) 14
#define white_pawn7_id		(Stone_id_type) 15
#define white_pawn8_id		(Stone_id_type) 16
#define black_king_id		(Stone_id_type) 17
#define black_queen_id		(Stone_id_type) 18
#define black_rook1_id		(Stone_id_type) 19
#define black_rook2_id		(Stone_id_type) 20
#define black_bishop1_id	(Stone_id_type) 21
#define black_bishop2_id	(Stone_id_type) 22
#define black_knigth1_id	(Stone_id_type) 23
#define black_knigth2_id	(Stone_id_type) 24
#define black_pawn1_id		(Stone_id_type) 25
#define black_pawn2_id		(Stone_id_type) 26
#define black_pawn3_id		(Stone_id_type) 27
#define black_pawn4_id		(Stone_id_type) 28
#define black_pawn5_id		(Stone_id_type) 29
#define black_pawn6_id		(Stone_id_type) 30
#define black_pawn7_id		(Stone_id_type) 31
#define black_pawn8_id		(Stone_id_type) 32

#define min_white_stone_id	(Stone_id_type) 1
#define max_white_stone_id	(Stone_id_type) 16
#define min_black_stone_id	(Stone_id_type) 17
#define max_black_stone_id	(Stone_id_type) 32
#define color_stone_id		(Stone_id_type) 17


MODE	BOOL		(* Bool_proc_type) () ;
MODE	void		(* Void_proc_type) () ;

#define Null_bool_proc	((Bool_proc_type) -1) ;


/**** Modes ****/

typedef enum { play, mate, loose, patt, remis, stop }		Game_end_type ;
typedef enum { rigth_move, wrong_move, lost_move ,menue_move, break_move }
							User_input_move_type ;
typedef enum { simple, short_castling, long_castling, conversion,
	       double_step, ep, invalid } 	Move_kind_type ;
typedef enum { white, black, no_color } 		Color_type ;
typedef enum { Empty, King, Queen, Rook, Bishop, Knigth, Pawn }  Stone_type ;
typedef enum { short_castle, long_castle } 		Castle_type ;
typedef enum { no_changes, null_short, null_long, null_full }
						Castle_flags_change_type ;
typedef struct {  Stone_id_type	min_id ;
		  Stone_id_type	max_id ; } Stone_id_range_type ;

typedef INT	Stone_value_type ;
typedef	float	Position_value_type ;

/********************* Chess Field ****************************************/

MODE Stone_id_type	Field_type [max_column][max_row] ;

/********************* Chess Stones ****************************************/

typedef  INT	Line_type ;
typedef  struct {
		  	Line_type	column ;
		  	Line_type	row ;
	        } Field_nr_type ;

typedef struct {
			Field_nr_type		field ;
			Stone_type		stone ;
		} One_stone_position_type ;

MODE One_stone_position_type Stone_position_type [max_stone_id+1];

/********************* Move **********************************************/

MODE STRUCT
	{
	   /* from */   Field_nr_type           	from_field ;
                        Stone_type              	from_stone ;
                        Stone_id_type           	from_stone_id ;
		        Castle_flags_change_type	from_cflags_changes ;

            /* to */    Field_nr_type           	to_field ;
                        Stone_type              	to_stone ;
                        Stone_id_type           	to_stone_id ;
		        Castle_flags_change_type	to_cflags_changes ;

            /* kind */  Move_kind_type			move_kind ;

	    /* ep */	BOOL				ep_flag ;
			Field_nr_type			ep_pawn_field ;
			Stone_id_type			ep_pawn_id ;

	    /* cnv */	Stone_type			new_stone ;

            /* check */ BOOL                    	check_flag ;

	} Move_type ;


/**************    Move Mind   ********************************************/

MODE	Move_type 	Move_mind_type [max_depth][max_moves] ;

/*************    Move History   *******************************************/

MODE	Move_type 	Move_history_type [max_history_moves] ;

/**************   Castle Data    *******************************************/

MODE STRUCT	{
			Field_nr_type		medium_king_field ;
			Stone_id_type		rook_id ;
			Field_nr_type		from_rook_field ;
			Field_nr_type		to_rook_field ;
			Field_nr_type		medium_rook_field ;
	} Castle_direction_type ;

MODE STRUCT	{
			Stone_id_type		king_id ;
			Field_nr_type		from_king_field ;
			Field_nr_type		to_short_king_field ;
			Field_nr_type		to_long_king_field ;
			Castle_direction_type	castle_direction [max_castle] ;
	} Castle_data_type ;


/***************** Move Position Value List ***********************************/


MODE STRUCT Move_value_list_type
	{
		STRUCT	Move_value_list_type	*next ;
		STRUCT	Move_value_list_type	*prev ;
		INT				move_nr ;
		Position_value_type		value ;

	} Move_value_list_type ;

