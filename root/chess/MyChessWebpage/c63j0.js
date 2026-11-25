
var m0 = new Array(1)

m0[1] = new Array(57,42,29,36,42,36,6,21,59,52);
m0[1].base = new Array(7,8,9,10,11,0);
m0[1].root =0;
m0[1].move =6;
m0[3] = new Array(2,11,36,29,3,21,43,35);
m0[3].base = new Array(16,17,18,19,0);
m0[3].root =2;
m0[3].move =3;
m0[4] = new Array(29,36,43,36,6,21);
m0[4].base = new Array(20,21,22,0);
m0[4].root =2;
m0[4].move =3;
m0[5] = new Array(28,36,35,27,8,16,25,32,9,25,27,18,25,32,45,35,29,38,53,45,36,45,61,60);
m0[5].base = new Array(27,28,29,30,31,32,33,34,35,36,37,38,0);
m0[5].root =2;
m0[5].move =7;
m0[2] = new Array(11,19,60,62,127,61,6,21,36,29,2,29,43,35,8,16,25,18,9,18,35,28,19,28,45,28);
m0[2].base = new Array(13,14,14,15,23,24,25,26,39,40,41,42,43,0);
m0[2].root =0;
m0[2].move =7;
m0[7] = new Array(3,12,28,43);
m0[7].base = new Array(53,54,0);
m0[7].root =6;
m0[7].move =10;
m0[6] = new Array(29,36,43,36,6,21,60,62,127,61,5,26,25,18,9,18,45,28,4,6,71,5,57,42,3,12,28,43,26,35,36,28,35,28,61,60,11,19,43,28,19,28,59,43);
m0[6].base = new Array(44,45,46,47,47,48,49,50,51,52,52,55,56,57,58,59,60,61,62,63,64,65,0);
m0[6].root =0;
m0[6].move =7;
m0[8] = new Array(11,19,43,35,28,35,61,60,4,5,25,18,9,18,45,35);
m0[8].base = new Array(70,71,72,73,74,75,76,77,0);
m0[8].root =0;
m0[8].move =13;
m0[9] = new Array(45,28,18,28,43,35,26,35,59,35,11,19);
m0[9].base = new Array(79,80,81,82,83,84,0);
m0[9].root =0;
m0[9].move =14;
m0[10] = new Array(25,18,11,18,45,28,2,29,58,44,26,35);
m0[10].base = new Array(85,86,87,88,89,90,0);
m0[10].root =0;
m0[10].move =14;
m0[0] = new Array(52,36,12,28,62,45,1,18,61,25,13,29,51,43,6,21,36,29,5,26,60,62,127,61,4,6,71,5,58,44,26,17,25,18,11,18,45,28,2,29,57,51);
m0[0].base = new Array(0,1,2,3,4,5,6,12,66,67,68,68,69,69,78,91,92,93,94,95,96,0);
m0[0].root =0;
m0[0].move =0;
var n0 = new Array();
var b0 = -1;
var pieces = "KDSLT ";
var pos_after = "Stellung nach ";
var start_pos = "  ";
function g0(a,b)
{	gm(m0,n0,0,b0,'c63g0.htm',a,b);}
function MB_50()
{b0=MB_5(m0,n0,0,b0,'c63g0.htm'); GMS(m0,n0,0,b0,'c63g0.htm');}
function MB0()
{b0=MB(m0,n0,0,b0,'c63g0.htm'); GMS(m0,n0,0,b0,'c63g0.htm');}
function MF_50()
{b0=MF_5(m0,n0,0,b0,'c63g0.htm'); GMS(m0,n0,0,b0,'c63g0.htm');}
function MF0()
{b0=MF(m0,n0,0,b0,'c63g0.htm',true); ic630.value=GMS(m0,n0,0,b0,'c63g0.htm');}
var nMoves = new Array(0,0);
var nLevels = new Array(0,0);
var nNameCount = new Array(0,0);
var nOld = new Array(-1,-1);
baseName = 'c63';
var EmptyWhitePath = "gif/w.gif";
var EmptyBlackPath = "gif/b.gif";
var BackColor = "#FFF8B3";
