


/* forward */

/* IO */
void                    print_menue () ;        /* general menue */
void                    output_stone_position () ;
void                    input_stone_position () ;
void                    output_position_value () ;
BOOL                    convert_str_to_move () ;
BOOL                    convert_short_to_long_move () ;
BOOL                    convert_str_to_field_nr () ;
BOOL                    convert_field_nr_to_str () ;
BOOL                    test_stone_id_range () ;
BOOL                    test_empty_stone_id () ;

void                    make_history_move () ;
void                    unmake_history_move () ;

void                    show_game () ;
void                    change_game () ;
void                    print_move () ;         /* in : int move nr */
void                    print_move_history () ;

/* Movings */

void                    make_move () ;          /* actualize move history */
void                    unmake_move () ;

void                    fill_mind_move () ;

Castle_flags_change_type reset_castle_flags () ;
void                    set_castle_flags () ;

BOOL                    computer_move () ;      /* computer move */
BOOL                    find_moves () ;         /* find good moves */

void                    find_best_move () ;
void                    sort () ;
void                    insort () ;
void                    search_figure_moves () ;  /* rook .. knigth */
void                    search_best_moves () ;
BOOL                    find_best_moves () ;    /* find best  moves */
BOOL                    user_input () ;         /* user move/input */



BOOL                    make_user_move () ;

BOOL                    test_check () ;
BOOL                    test_check_field () ;
BOOL                    test_check_move () ;

BOOL                    test_mate () ;
BOOL                    test_remis () ;
Game_end_type           test_game_end () ;
Game_end_type           game_end_info () ;

void                    init_random () ;
INT                     random () ;

/* fields */
/* Ex : E4 */

BOOL                    n_field () ;    /* E5 */
BOOL                    e_field () ;    /* F4 */
BOOL                    s_field () ;    /* E3 */
BOOL                    w_field () ;    /* D4 */

BOOL                    nw_field () ;   /* D5 */
BOOL                    ne_field () ;   /* F5 */
BOOL                    se_field () ;   /* F3 */
BOOL                    sw_field () ;   /* D3 */

BOOL                    k0_field () ;   /* C5 */
BOOL                    k1_field () ;   /* D6 */
BOOL                    k2_field () ;   /* F6 */
BOOL                    k3_field () ;   /* G5 */
BOOL                    k4_field () ;   /* G3 */
BOOL                    k5_field () ;   /* F2 */
BOOL                    k6_field () ;   /* D2 */
BOOL                    k7_field () ;   /* C3 */

/* search for possible moves */
void                    test_move () ;          /* User input one move */
void                    search_moves () ;       /* all moves per stone id */
void                    search_all_moves () ;   /* all moves per one position */
void                    search_pawn_moves () ;
void                    search_knigth_moves () ;
void                    search_bishop_moves () ;
void                    search_rook_moves () ;
void                    search_queen_moves () ;
void                    search_king_moves () ;
void                    search_free_moves () ; /* only phase 3 */

/* other */

void                    chess_game () ;

void                    init_chess_game () ;
void                    restart_chess_game () ;
void                    init_dynamic_data () ;
void                    start_spec_chess_game () ;

void                    init_move_history () ;
void                    init_chess_field () ;
void                    init_stone_position () ;
void                    init_mind_moves () ;
void                    init_dynamic_data () ;

void                    see_move_history () ;
Color_type              other_color () ;

/* Position Value */
Position_value_type     position_value () ;
Position_value_type     local_position_value () ;  /* view of one color */
Position_value_type     global_position_value () ; /* view of all colors */
Position_value_type     compute_stone_values () ;

#include "chess_h.c"       /* hard data structures */
#include "chess_d.c"       /* dynamic data */

