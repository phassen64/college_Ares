/* Chess-Analyser */
/* Initial Procedures */

PROC void init_chess_game ()

BEGIN
        init_random () ;	 /* Random Generator Init */
	init_chess_field () ;	 /* Chess-Field Reconstruction */
	init_stone_position () ; /* Chess-Stones init */
	init_move_history () ;   /* default moves */
	init_mind_moves () ;
END

PROC void restart_chess_game ()
BEGIN
   printf ("\nWe restart the Chess Game !");

   init_dynamic_data () ;
   init_chess_field () ;
   init_stone_position () ;
   /* The moves are now usable */
   init_mind_moves () ;
END

#define first_stones 		9
#define second_stones 		5
#define max_diff_stones  	14

PROC void start_special_chess_game ()
BEGIN
   DCL INT  		i,j,color, stone, stone_nr, stone_id ;
   DCL INT		castle ;
   DCL CHAR  		*color_str [2] = {	"\nWhite Stones ::",
					"	\n\nBlack Stones ::" } ;
   DCL CHAR  		*castle_str [2] = {	"Short Castle ",
					        "Long Castle " } ;
   DCL CHAR  		field_str[20], input_str[20] ;
   DCL Field_nr_type 	field_nr ;
   DCL Stone_id_type	rook_id[2] ;
   DCL Stone_id_type	king_id ;
   DCL Stone_type	stone_arr1[first_stones]
			= { Empty, King, Queen, Rook, Rook, Bishop, Bishop,
				Knigth, Knigth } ; /* one time */
   DCL Stone_type	stone_arr2[second_stones] /* as much as can */
			= { Pawn, Queen, Rook, Bishop, Knigth } ;
   DCL BOOL		stop_flag ;

   /* We init all necessary data */

   init_move_history () ;
   init_dynamic_data () ;

   /* delete chess-field */
   FOR (i=0; i LT max_column; i++)
   DO
      FOR (j=0; j LT max_row; j++)
      DO
         Chess_field [i][j] = empty_id  ;
      OD
   OD

   /* delete chess-stones */

   FOR (i=0; i LE max_stone_id; i++)	/* empty id is a Chess stone ! */
   DO
      Chess_stones[i].stone = Empty ;
   OD

   printf ("\n\nSpecial Game");
   printf ("\nGive in your position ('!'=other color, '.'=other stone) ::\n");

   /******************* Chess-field and Chess-Stones Position ************/

   FOR (color=0; color LT 2 ; color++)
   DO
      printf ("%s",color_str[(Color_type)color]);
      stone_id = Stone_color_id [(Color_type)color].min_id ;
      stop_flag = FALSE ;
      stone_nr = 1 ; /* 0 is Empty */

      WHILE ((stone_id LT Stone_color_id[(Color_type)color].max_id)
            AND (stone_nr LT max_diff_stones) AND (NOT stop_flag))
      DO
         IF stone_nr LT first_stones
         THEN
            stone = stone_arr1 [stone_nr] ;
         ELSE
            stone = stone_arr2 [stone_nr-first_stones] ;
         FI

         printf ("\n%8s : ",Stone_str[(Stone_type)stone]);
         scanf ("%s",field_str) ;

         IF field_str[0] EQ '!'
         THEN
            stop_flag = TRUE ; /* change the color */

         ELSIF field_str[0] EQ '.'
         THEN
            Chess_stones[stone_id].stone               = Empty ;
            stone_nr += 1 ;
            stone_id += 1 ;

         ELSE
            IF (convert_str_to_field_nr (field_str,&field_nr))
            THEN
               IF (Chess_field[field_nr.column][field_nr.row] EQ empty_id)
               THEN
                  Chess_stones[stone_id].stone           = (Stone_type)stone ;
                  Chess_stones[stone_id].field               = field_nr ;
                  Chess_field[field_nr.column][field_nr.row] = stone_id;
                  stone_id += 1 ;
                  IF (stone_nr LT first_stones)
                  THEN
                     stone_nr += 1 ;
                  FI
               ELSE
                  printf ("\nAlready a Stone on this field !");
               FI
            FI

         FI /* field str */


      OD /* stone id */

   OD  /* color */

   /********************* Castle Flags *****************************/

   printf ("\n\nCastle Test :");
   FOR (color=0; color LT 2; color++)
   DO
      printf ("%s",color_str[(Color_type)color]);

      king_id  = Castle_data[color].king_id ;
      rook_id[0] = Castle_data[color].castle_direction[short_castle].rook_id ;
      rook_id[1] = Castle_data[color].castle_direction[long_castle].rook_id ;

      /* King OK ? */

      IF NOT ((Chess_stones[king_id].field.column EQ
		Castle_data[color].from_king_field.column)
      AND
         (Chess_stones[king_id].field.row EQ
		Castle_data[color].from_king_field.row))
      THEN
         printf ("\nKing is not in castle position => no castle");
         Castle_flag[color] = FALSE ;
      FI

      /* Rooks Ok ? */

      IF Castle_flag[color]
      THEN

         FOR (castle=short_castle ; castle LE long_castle; castle++)
         DO
            IF NOT
               ((Chess_stones[rook_id[castle]].field.column EQ
                   Castle_data[color].castle_direction[castle].
                           from_rook_field.column)
            AND
                (Chess_stones[rook_id[castle]].field.row EQ
                   Castle_data[color].castle_direction[castle].
                           from_rook_field.row) )
            THEN
               printf ("\n ** No %s Possible ** ",castle_str[castle]);
               Castle_type_flag[color][castle] = FALSE ;
            FI

         OD

      FI  /* main castle flag */

      IF (Castle_type_flag[color][short_castle] EQ FALSE)
            AND
            (Castle_type_flag[color][long_castle] EQ FALSE)
      THEN
         printf ("\nBoth Rooks on wrong position => not castling");
         Castle_flag [color] = FALSE ;
      FI

   OD /* castle flags */

   /********************** Moving Color *****************************/

   printf ("\nMoving Color = white (black='B') : ");
   scanf ("%s",input_str);
   IF input_str[0] NE 'B'
   THEN
      Moving_color = white ;
      User_color = white ;
      Computer_color = black ;
   ELSE
      Moving_color = black ;
      User_color = black ;
      Computer_color = white ;
   FI

   /******************* E.P. **********************************/

   printf ("\nLast Move a Double Step (for E.P) (J) : ");
   scanf ("%s",input_str);

   IF input_str[0] EQ 'J'
   THEN
      printf ("\nLast Move : ");
      scanf ("%s",field_str);

      IF (convert_str_to_field_nr (field_str,&field_nr))
      THEN
         stone_id = Chess_field[field_nr.column][field_nr.row] ;
         IF Chess_stones[stone_id].stone EQ Pawn
         THEN
            move->ep_flag 	= Ep_flag       = TRUE ;
            move->ep_pawn_id    = Ep_pawn_id    = stone_id ;
            move->ep_pawn_field  = Ep_pawn_field = field_nr ;
         FI
      FI
   FI

   RETURN ;

END /* start_special_game */


PROC void init_chess_field ()

BEGIN
   INT i,j ;

   /* White */

   Chess_field [0][0] = white_rook1_id  ;
   Chess_field [1][0] = white_knigth1_id ;
   Chess_field [2][0] = white_bishop1_id ;
   Chess_field [3][0] = white_queen_id ;
   Chess_field [4][0] = white_king_id ;
   Chess_field [5][0] = white_bishop2_id ;
   Chess_field [6][0] = white_knigth2_id ;
   Chess_field [7][0] = white_rook2_id ;

   Chess_field [0][1] = white_pawn1_id ;
   Chess_field [1][1] = white_pawn2_id ;
   Chess_field [2][1] = white_pawn3_id ;
   Chess_field [3][1] = white_pawn4_id ;
   Chess_field [4][1] = white_pawn5_id ;
   Chess_field [5][1] = white_pawn6_id ;
   Chess_field [6][1] = white_pawn7_id ;
   Chess_field [7][1] = white_pawn8_id ;

   /* Black */

   Chess_field [0][7] = black_rook1_id ;
   Chess_field [1][7] = black_knigth1_id ;
   Chess_field [2][7] = black_bishop1_id ;
   Chess_field [3][7] = black_queen_id ;
   Chess_field [4][7] = black_king_id ;
   Chess_field [5][7] = black_bishop2_id ;
   Chess_field [6][7] = black_knigth2_id ;
   Chess_field [7][7] = black_rook2_id ;

   Chess_field [0][6] = black_pawn1_id ;
   Chess_field [1][6] = black_pawn2_id ;
   Chess_field [2][6] = black_pawn3_id ;
   Chess_field [3][6] = black_pawn4_id ;
   Chess_field [4][6] = black_pawn5_id ;
   Chess_field [5][6] = black_pawn6_id ;
   Chess_field [6][6] = black_pawn7_id ;
   Chess_field [7][6] = black_pawn8_id ;

   FOR (i=0; i LT max_column; i++)
   DO
      FOR (j=2; j LT max_row-2; j++)
      DO
         Chess_field [i][j] = empty_id ;
      OD
   OD

END /* init_chess_field */

PROC void init_stone_position ()
BEGIN
    Stone_id_type 	save_id ;
    INT			i,j ;

   /* Empty id */
   Chess_stones [0].stone       = Empty ;

   /* White stones */
   Chess_stones [1].stone       = King ;
   Chess_stones [2].stone       = Queen ;
   Chess_stones [3].stone      	= Rook ;
   Chess_stones [4].stone       = Rook ;
   Chess_stones [5].stone       = Bishop ;
   Chess_stones [6].stone       = Bishop ;
   Chess_stones [7].stone       = Knigth ;
   Chess_stones [8].stone       = Knigth ;

   FOR (i=white_pawn1_id; i LE white_pawn8_id; i++)
   DO
      Chess_stones [i].stone 		= Pawn ;
   OD

   /* copy to Black Stones */
   FOR (i = min_white_stone_id; i LE max_white_stone_id; i++)
   DO
      Chess_stones [i+max_color_stones].stone 	= Chess_stones [i].stone;
   OD


   /* compute all fields */
   FOR (i=0; i LT max_column; i++)
   DO
      FOR (j=0; j LT max_row; j++)
      DO
         save_id = Chess_field [i][j] ;
         IF (save_id NE empty_id)
         THEN
            Chess_stones [save_id].field.column = i ;
            Chess_stones [save_id].field.row 	= j ;
	 FI
      OD
   OD

END    /* init_stone_position */


PROC void init_move_history ()
BEGIN
	INT	i ;

   FOR (i=0 ; i LT max_history_moves; i++)
   DO
       Move_history_ptr->check_flag 		= FALSE ;
       Move_history_ptr->ep_flag 		= FALSE ;
       Move_history_ptr->ep_pawn_id 		= -1 ;
       Move_history_ptr->new_stone 		= Empty ;
       Move_history_ptr->move_kind		= invalid ;
       Move_history_ptr->from_cflags_changes 	= no_changes ;
       Move_history_ptr->to_cflags_changes 	= no_changes ;
       Move_history_ptr ++ ;
   OD

   Move_history_ptr = &(Move_history[0]) ;
   move = Move_history_ptr ;

END /* init_move_history */


PROC void init_mind_moves ()
BEGIN
   DCL INT i,j ;

   Move_mind_ptr = &(Move_mind[0][0]) ;


   FOR (j=0; i LT max_depth; j++)
   DO
      FOR (i=0; i LT max_moves; i++)
      DO
         Move_mind_ptr->move_kind	= invalid ;
         Move_mind_ptr->to_field.column = -1 ;
         Move_mind_ptr->to_field.row = -1 ;
      OD
   OD

END /* init_mind_moves */

PROC void init_dynamic_data ()

BEGIN
   Move_nr 					= 0 ;
   Moving_color 				= white ;

   Move_history_ptr 				= &(Move_history[0]) ;
   move 					= &(Move_history[0]) ;
   Move_mind_ptr 				= &(Move_mind[0][0]) ;


   Castle_flag [white]				= TRUE ;
   Castle_type_flag [white][short_castle] 	= TRUE ;
   Castle_type_flag [white][long_castle] 	= TRUE ;

   Castle_flag [black]				= TRUE ;
   Castle_type_flag [black][short_castle] 	= TRUE ;
   Castle_type_flag [black][long_castle] 	= TRUE ;


   Ep_flag     = FALSE ;
   Check_flag  = FALSE ;
   Mate_flag   = FALSE ;
   Patt_flag   = FALSE ;

END /* init_dynamic_data */
