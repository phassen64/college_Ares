
var m0 = new Array(1)

m0[1] = new Array(21,36,30,37,11,27,62,45,12,20,57,51,5,19,37,19,10,19,52,44,4,6,71,5,50,34,1,18);
m0[1].base = new Array(4,5,6,7,8,9,10,11,12,13,14,14,15,16,0);
m0[1].root =0;
m0[1].move =3;
m0[2] = new Array(50,34,21,36,59,58,1,18,62,45,13,21,30,51,12,28);
m0[2].base = new Array(18,19,20,21,22,23,24,25,0);
m0[2].root =0;
m0[2].move =4;
m0[4] = new Array(50,34,27,34);
m0[4].base = new Array(33,34,0);
m0[4].root =3;
m0[4].move =6;
m0[5] = new Array(57,51,21,29,62,52,2,20,50,34,1,11,59,41,0,1);
m0[5].base = new Array(35,36,37,38,39,40,41,42,0);
m0[5].root =3;
m0[5].move =6;
m0[3] = new Array(30,21,12,21,52,44,5,19,61,43,10,18,62,45,4,6,71,5,60,62,127,61,21,29,57,51,14,30,50,34,30,38);
m0[3].base = new Array(26,27,28,29,30,31,32,43,43,44,44,45,46,47,48,49,0);
m0[3].root =0;
m0[3].move =4;
m0[6] = new Array(57,42,2,29);
m0[6].base = new Array(50,51,0);
m0[6].root =0;
m0[6].move =4;
m0[7] = new Array(57,51,2,29);
m0[7].base = new Array(52,53,0);
m0[7].root =0;
m0[7].move =4;
m0[8] = new Array(52,44,21,36,30,37,2,29,57,51,12,20,61,43,1,11,43,36,27,36,62,52,5,19,37,19,10,19,52,46,11,21);
m0[8].base = new Array(54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,0);
m0[8].root =0;
m0[8].move =4;
m0[0] = new Array(51,35,6,21,58,30,11,27,62,45,21,36,30,37,2,29);
m0[0].base = new Array(0,1,2,3,17,70,71,72,0);
m0[0].root =0;
m0[0].move =0;
var n0 = new Array();
var b0 = -1;
var pieces = "KDSLT ";
var pos_after = "Stellung nach ";
var start_pos = "  ";
function g0(a,b)
{	gm(m0,n0,0,b0,'d00g0.htm',a,b);}
function MB_50()
{b0=MB_5(m0,n0,0,b0,'d00g0.htm'); GMS(m0,n0,0,b0,'d00g0.htm');}
function MB0()
{b0=MB(m0,n0,0,b0,'d00g0.htm'); GMS(m0,n0,0,b0,'d00g0.htm');}
function MF_50()
{b0=MF_5(m0,n0,0,b0,'d00g0.htm'); GMS(m0,n0,0,b0,'d00g0.htm');}
function MF0()
{b0=MF(m0,n0,0,b0,'d00g0.htm',true); id000.value=GMS(m0,n0,0,b0,'d00g0.htm');}
var nMoves = new Array(0,0);
var nLevels = new Array(0,0);
var nNameCount = new Array(0,0);
var nOld = new Array(-1,-1);
baseName = 'd00';
var EmptyWhitePath = "gif/w.gif";
var EmptyBlackPath = "gif/b.gif";
var BackColor = "#FFF8B3";
