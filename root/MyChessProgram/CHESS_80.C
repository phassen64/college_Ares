/* RANDOM GENERATOR FILE - only running on the VAX 	*/
/* VAX - VAX - VAX       				*/


PROC void init_random ()
	/* IN : Random_init_nr  - global */

/* Prozedur : init of the random generator */
/* only call this proc one time ! */
/* The global varibale 'Random init nr' is input */

BEGIN
  INT       i;

  FOR (i=0;i LE Random_init_nr;i++)
  DO
    rand()
  OD

END /* init_random */


PROC INT random (range)
	INT range;	/* IN : naturally number 1..n 			*/
			/* returns an int in the range of 0..range-1 	*/
			/* x = random (3) => x= {0,1,2} 		*/
BEGIN
  RETURN (rand()%range) ;
END /* random */

