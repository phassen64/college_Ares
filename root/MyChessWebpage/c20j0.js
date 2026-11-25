
var m0 = new Array(1)

m0[2] = new Array(36,28,3,12);
m0[2].base = new Array(10,11,0);
m0[2].root =1;
m0[2].move =5;
m0[3] = new Array(35,41,21,36,41,26,36,26,59,52,26,20,57,42,4,6,71,5);
m0[3].base = new Array(12,13,14,15,16,17,18,19,19,0);
m0[3].root =1;
m0[3].move =5;
m0[1] = new Array(5,26,51,35,28,35,52,35,6,21,57,42,4,6,71,5,58,44,5,4,61,34,26,33,60,62,127,61,33,42,49,42,4,36,44,30);
m0[1].base = new Array(4,5,6,7,8,9,20,20,21,22,23,24,25,25,26,27,28,29,0);
m0[1].root =0;
m0[1].move =3;
m0[5] = new Array(57,42,11,27,42,27,21,36);
m0[5].base = new Array(32,33,34,35,0);
m0[5].root =4;
m0[5].move =1;
m0[6] = new Array(37,28,11,19,51,43,36,30);
m0[6].base = new Array(38,39,40,41,0);
m0[6].root =4;
m0[6].move =3;
m0[4] = new Array(6,21,53,37,21,36,51,43,36,26,37,28,11,19,43,35,26,11);
m0[4].base = new Array(30,31,36,37,42,43,44,45,46,0);
m0[4].root =0;
m0[4].move =3;
m0[7] = new Array(51,35,27,36,57,42,1,18,35,27,18,12,52,46,6,21,61,34,10,18,46,36,21,27,60,62,127,61,2,20,59,31,12,22);
m0[7].base = new Array(48,49,50,51,52,53,54,55,56,57,58,59,60,60,61,62,63,0);
m0[7].root =0;
m0[7].move =4;
m0[9] = new Array(36,27,5,19);
m0[9].base = new Array(67,68,0);
m0[9].root =8;
m0[9].move =2;
m0[8] = new Array(53,37,28,37,52,37,27,36);
m0[8].base = new Array(64,65,66,69,0);
m0[8].root =0;
m0[8].move =4;
m0[10] = new Array(57,42,27,35);
m0[10].base = new Array(70,71,0);
m0[10].root =0;
m0[10].move =4;
m0[11] = new Array(52,46,27,36,46,36,6,21);
m0[11].base = new Array(72,73,74,75,0);
m0[11].root =0;
m0[11].move =4;
m0[0] = new Array(52,36,12,28,62,52,11,27,36,27,3,27,57,42,27,24,51,43,6,21);
m0[0].base = new Array(0,1,2,3,47,76,77,78,79,80,0);
m0[0].root =0;
m0[0].move =0;
var n0 = new Array();
var b0 = -1;
var pieces = "KDSLT ";
var pos_after = "Stellung nach ";
var start_pos = "  ";
function g0(a,b)
{	gm(m0,n0,0,b0,'c20g0.htm',a,b);}
function MB_50()
{b0=MB_5(m0,n0,0,b0,'c20g0.htm'); GMS(m0,n0,0,b0,'c20g0.htm');}
function MB0()
{b0=MB(m0,n0,0,b0,'c20g0.htm'); GMS(m0,n0,0,b0,'c20g0.htm');}
function MF_50()
{b0=MF_5(m0,n0,0,b0,'c20g0.htm'); GMS(m0,n0,0,b0,'c20g0.htm');}
function MF0()
{b0=MF(m0,n0,0,b0,'c20g0.htm',true); ic200.value=GMS(m0,n0,0,b0,'c20g0.htm');}
var nMoves = new Array(0,0);
var nLevels = new Array(0,0);
var nNameCount = new Array(0,0);
var nOld = new Array(-1,-1);
baseName = 'c20';
var EmptyWhitePath = "gif/w.gif";
var EmptyBlackPath = "gif/b.gif";
var BackColor = "#FFF8B3";
