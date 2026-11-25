/* Chess-Analyser - HARD DATA File  */
/* NEVER CHANGE THIS DATA DURING OPERATIONAL MODE */


float		Chess_stone_values [max_stone_types] =
			{ 	empty_value,
				king_value,
				queen_value,
				rook_value,
				bishop_value,
				knigth_value,
				pawn_value  } ;

CHAR		*Stone_str [max_stone_types]
			= {	"Empty",
				"King",
				"Queen",
				"Rook",
				"Bishop",
				"Knigth",
				"Pawn" 	} ;

CHAR		*Color_str [max_color+1]
			= {	"white",
				"black",
				"no_color"  } ;


Stone_id_range_type	Stone_color_id [max_color+1]
			= {     { min_white_stone_id, max_white_stone_id } ,
				{ min_black_stone_id, max_black_stone_id } ,
				{ 0, 0 } } ;


Line_type		Pawn_origin_row [max_color]
			= { (Line_type)  1, (Line_type)  6 } ;

Line_type		Pawn_ep_row [max_color] /* one step row of other color*/
			= { (Line_type)  5, (Line_type)  2 } ;

Line_type		Pawn_double_step_row [max_color]
			= { (Line_type)  3, (Line_type)  4 } ;

Line_type		Pawn_last_row [max_color]
			= { (Line_type)  7, (Line_type)  0 } ;

Stone_type		Conversion_stone [max_conversion]
			= { Queen, Rook, Bishop, Knigth } ;

Field_nr_type		King_origin_field [max_color]
			= { 	{ (Line_type) 4,(Line_type)  0  },
                                { (Line_type) 4,(Line_type)  7  } } ;

Field_nr_type		Rook_origin_field [max_color][max_castle]
			= {
  				{
					{ (Line_type) 0,(Line_type)  0  },
                                	{ (Line_type) 0,(Line_type)  7  }
				} ,
  				{
					{ (Line_type) 7,(Line_type)  0  },
                                	{ (Line_type) 7,(Line_type)  7  }
				}
			  } ;


Castle_data_type
	Castle_data [max_color] =
	{
		{ /* white */

			white_king_id ,
                	{ (Line_type) 4, (Line_type) 0 } ,
              		{ (Line_type) 6, (Line_type) 0 } ,
              		{ (Line_type) 2, (Line_type) 0 } ,

                	{ /* Castle Direction */

				{ /* short castle */

                      			{ (Line_type) 5, (Line_type) 0 } ,
                      			white_rook2_id ,
                      			{ (Line_type) 7, (Line_type) 0 } ,
                      			{ (Line_type) 5, (Line_type) 0 } ,
                      			{ (Line_type) -1, (Line_type) -1} ,
				} ,

                 		{ /* long castle */

                      			{ (Line_type) 3, (Line_type) 0 } ,
                      			white_rook1_id ,
                      			{ (Line_type) 0, (Line_type) 0 } ,
                      			{ (Line_type) 3, (Line_type) 0 } ,
                      			{ (Line_type) 1, (Line_type) 0 }
				}
			}
		} ,

	        { /* black */

			black_king_id ,
			{ (Line_type) 4, (Line_type) 7 } ,
			{ (Line_type) 6, (Line_type) 7 } ,
			{ (Line_type) 2, (Line_type) 7 } ,

			{ /* Castle Direction */

				{ /* short castle */

					{ (Line_type) 5, (Line_type) 7 } ,
					black_rook2_id ,
					{ (Line_type) 7, (Line_type) 7 } ,
					{ (Line_type) 5, (Line_type) 7 } ,
					{ (Line_type) -1, (Line_type) -1 }
				} ,

				{ /* long castle */

					{ (Line_type) 3, (Line_type) 7 } ,
					black_rook1_id ,
					{ (Line_type) 0, (Line_type) 7 } ,
					{ (Line_type) 3, (Line_type) 7 } ,
					{ (Line_type) 1, (Line_type) 7 }
				}
			}
                }
	} ;


Bool_proc_type		Pawn_forward_field_proc [max_color]
			= {	n_field, s_field } ;

Bool_proc_type		Pawn_strike_field_proc [max_color][max_pawn_strikes]
			= { {	ne_field, nw_field } ,
			    {	se_field, sw_field } } ;


Bool_proc_type		King_field_proc [max_king_moves]
				= { 	n_field,
					s_field,
					e_field,
					w_field,
					ne_field,
					se_field,
					sw_field,
					nw_field } ;

Bool_proc_type		Queen_field_proc [max_queen_field]
				= { 	n_field,	/* usg : max : 7 */
					s_field,
					e_field,	/* usg : max : 7 */
					w_field,
					ne_field,       /* usg : max : 7 */
					sw_field,
					se_field,       /* usg : max : 7 */
					nw_field } ;

Bool_proc_type		Rook_field_proc [max_rook_field]
				= { 	n_field,       /* usg : max : 7 */
					s_field,
					e_field,       /* usg : max : 7 */
					w_field } ;

Bool_proc_type		Bishop_field_proc [max_bishop_field]
				= { 	ne_field,       /* usg : max : 7 */
					sw_field,
					se_field,       /* usg : max : 7 */
					nw_field } ;

Bool_proc_type		Knigth_field_proc [max_knigth_moves]
				= { 	k0_field,
					k1_field,
					k2_field,
					k3_field,
					k4_field,
					k5_field,
					k6_field,
					k7_field   } ;


