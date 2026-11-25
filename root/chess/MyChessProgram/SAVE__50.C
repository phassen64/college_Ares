/* Chess-Analyser */

/* CHESS RULES for the USER and the Computer */
/* Part A */

/* ROOK - Fields */	/* Example : E4 */

PROC BOOL n_field (from_field, to_field)
	Field_nr_type	*from_field ;	/* IN */
	Field_nr_type	*to_field ;     /* OUT */
BEGIN
    /* E5 */
    to_field->column = from_field->column  ;
    to_field->row = from_field->row + 1 ;
    IF NOT test_field_range (to_field)
    THEN
       RETURN (FALSE) ;
    FI
    RETURN (TRUE) ;
END


PROC BOOL e_field (from_field, to_field)
	Field_nr_type	*from_field ;	/* IN */
	Field_nr_type	*to_field ;     /* OUT */
BEGIN
    /* F4 */
    to_field->column = from_field->column + 1 ;
    to_field->row = from_field->row ;
    IF NOT test_field_range (to_field)
    THEN
       RETURN (FALSE) ;
    FI
    RETURN (TRUE) ;
END


PROC BOOL s_field (from_field, to_field)
	Field_nr_type	*from_field ;	/* IN */
	Field_nr_type	*to_field ;     /* OUT */
BEGIN
    /* E3 */
    to_field->column = from_field->column ;
    to_field->row = from_field->row - 1 ;
    IF NOT test_field_range (to_field)
    THEN
       RETURN (FALSE) ;
    FI
    RETURN (TRUE) ;
END


PROC BOOL w_field (from_field, to_field)
	Field_nr_type	*from_field ;	/* IN */
	Field_nr_type	*to_field ;     /* OUT */
BEGIN
    /* D4 */
    to_field->column = from_field->column - 1 ;
    to_field->row = from_field->row ;
    IF NOT test_field_range (to_field)
    THEN
       RETURN (FALSE) ;
    FI
    RETURN (TRUE) ;
END

/* Bishop Fields */	/* Example Field : E4 */


PROC BOOL nw_field (from_field, to_field)
	Field_nr_type	*from_field ;	/* IN */
	Field_nr_type	*to_field ;     /* OUT */
BEGIN
    /* D5 */
    to_field->column = from_field->column - 1 ;
    to_field->row = from_field->row + 1 ;
    IF NOT test_field_range (to_field)
    THEN
       RETURN (FALSE) ;
    FI
    RETURN (TRUE) ;
END


PROC BOOL ne_field (from_field, to_field)
	Field_nr_type	*from_field ;	/* IN */
	Field_nr_type	*to_field ;     /* OUT */
BEGIN
    /* F5 */
    to_field->column = from_field->column + 1 ;
    to_field->row = from_field->row + 1 ;
    IF NOT test_field_range (to_field)
    THEN
       RETURN (FALSE) ;
    FI
    RETURN (TRUE) ;
END


PROC BOOL se_field (from_field, to_field)
	Field_nr_type	*from_field ;	/* IN */
	Field_nr_type	*to_field ;     /* OUT */
BEGIN
    /* F3 */
    to_field->column = from_field->column + 1 ;
    to_field->row = from_field->row - 1 ;
    IF NOT test_field_range (to_field)
    THEN
       RETURN (FALSE) ;
    FI
    RETURN (TRUE) ;
END


PROC BOOL sw_field (from_field, to_field)
	Field_nr_type	*from_field ;	/* IN */
	Field_nr_type	*to_field ;     /* OUT */
BEGIN
    /* D3 */
    to_field->column = from_field->column - 1 ;
    to_field->row = from_field->row - 1 ;
    IF NOT test_field_range (to_field)
    THEN
       RETURN (FALSE) ;
    FI
    RETURN (TRUE) ;
END

/* Knigth Moves */	/* AS EXAMPLE : E4 */

PROC BOOL k0_field (from_field, to_field)
	Field_nr_type	*from_field ;	/* IN */
	Field_nr_type	*to_field ;     /* OUT */
BEGIN
    /* C5 */
    to_field->column = from_field->column - 2 ;
    to_field->row = from_field->row + 1 ;
    IF NOT test_field_range (to_field)
    THEN
       RETURN (FALSE) ;
    FI
    RETURN (TRUE) ;
END


PROC BOOL k1_field (from_field, to_field)
	Field_nr_type	*from_field ;	/* IN */
	Field_nr_type	*to_field ;     /* OUT */
BEGIN
    /* D6 */
    to_field->column = from_field->column - 1 ;
    to_field->row = from_field->row + 2 ;
    IF NOT test_field_range (to_field)
    THEN
       RETURN (FALSE) ;
    FI
    RETURN (TRUE) ;
END


PROC BOOL k2_field (from_field, to_field)
	Field_nr_type	*from_field ;	/* IN */
	Field_nr_type	*to_field ;     /* OUT */
BEGIN
    /* F6 */
    to_field->column = from_field->column + 1 ;
    to_field->row = from_field->row + 2 ;
    IF NOT test_field_range (to_field)
    THEN
       RETURN (FALSE) ;
    FI
    RETURN (TRUE) ;
END


PROC BOOL k3_field (from_field, to_field)
	Field_nr_type	*from_field ;	/* IN */
	Field_nr_type	*to_field ;     /* OUT */
BEGIN
    /* G5 */
    to_field->column = from_field->column + 2 ;
    to_field->row = from_field->row + 1 ;
    IF NOT test_field_range (to_field)
    THEN
       RETURN (FALSE) ;
    FI
    RETURN (TRUE) ;
END


PROC BOOL k4_field (from_field, to_field)
	Field_nr_type	*from_field ;	/* IN */
	Field_nr_type	*to_field ;     /* OUT */
BEGIN
    /* G3 */
    to_field->column = from_field->column + 2 ;
    to_field->row = from_field->row - 1 ;
    IF NOT test_field_range (to_field)
    THEN
       RETURN (FALSE) ;
    FI
    RETURN (TRUE) ;
END


PROC BOOL k5_field (from_field, to_field)
	Field_nr_type	*from_field ;	/* IN */
	Field_nr_type	*to_field ;     /* OUT */
BEGIN
    /* F2 */
    to_field->column = from_field->column + 1 ;
    to_field->row = from_field->row - 2 ;
    IF NOT test_field_range (to_field)
    THEN
       RETURN (FALSE) ;
    FI
    RETURN (TRUE) ;
END


PROC BOOL k6_field (from_field, to_field)
	Field_nr_type	*from_field ;	/* IN */
	Field_nr_type	*to_field ;     /* OUT */
BEGIN
    /* D2 */
    to_field->column = from_field->column - 1 ;
    to_field->row = from_field->row - 2 ;
    IF NOT test_field_range (to_field)
    THEN
       RETURN (FALSE) ;
    FI
    RETURN (TRUE) ;
END


PROC BOOL k7_field (from_field, to_field)
	Field_nr_type	*from_field ;	/* IN */
	Field_nr_type	*to_field ;     /* OUT */
BEGIN
    /* C3 */
    to_field->column = from_field->column - 2 ;
    to_field->row = from_field->row - 1 ;
    IF NOT test_field_range (to_field)
    THEN
       RETURN (FALSE) ;
    FI
    RETURN (TRUE) ;
END
