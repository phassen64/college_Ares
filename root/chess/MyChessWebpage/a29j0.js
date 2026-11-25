
var m0 = new Array(1)

m0[2] = new Array(54,27,3,21,39,54,28,18);
m0[2].base = new Array(24,25,26,27,0);
m0[2].root =1;
m0[2].move =13;
m0[1] = new Array(42,27,28,36,45,39,33,26,60,62,127,61,5,4,51,43,36,43,59,43,18,28,43,50,21,27,34,27,11,19,58,51);
m0[1].base = new Array(11,12,13,14,15,15,16,17,18,19,20,21,22,23,28,29,0);
m0[1].root =0;
m0[1].move =12;
m0[4] = new Array(28,36,45,35);
m0[4].base = new Array(34,35,0);
m0[4].root =3;
m0[4].move =2;
m0[3] = new Array(33,42,51,42,5,4,59,50,3,12,58,44);
m0[3].base = new Array(31,32,33,36,37,38,0);
m0[3].root =0;
m0[3].move =13;
m0[6] = new Array(48,40,33,42,51,42,11,19);
m0[6].base = new Array(41,42,43,44,0);
m0[6].root =5;
m0[6].move =1;
m0[7] = new Array(33,42,49,42,28,36,45,51,36,43,52,43,11,19,56,57);
m0[7].base = new Array(46,47,48,49,50,51,52,53,0);
m0[7].root =5;
m0[7].move =2;
m0[5] = new Array(5,4,51,43,11,19,58,30,33,42,49,42,15,23);
m0[5].base = new Array(39,40,45,54,55,56,57,0);
m0[5].root =0;
m0[5].move =13;
m0[9] = new Array(49,42,11,27,34,27,3,27);
m0[9].base = new Array(62,63,64,65,0);
m0[9].root =8;
m0[9].move =2;
m0[8] = new Array(45,60,33,42,51,42,5,4,60,50,11,19,58,30,15,23,30,21,3,21,50,44,4,28);
m0[8].base = new Array(59,60,61,66,67,68,69,70,71,72,73,74,0);
m0[8].root =0;
m0[8].move =14;
m0[10] = new Array(42,27,21,27,34,27,36,45,27,18,45,54);
m0[10].base = new Array(75,76,77,78,79,80,0);
m0[10].root =0;
m0[10].move =14;
m0[11] = new Array(51,42,5,4,49,33,15,23,30,47,11,27,34,27,3,27,47,37,27,28,56,57,14,30);
m0[11].base = new Array(83,84,85,86,87,88,89,90,91,92,93,94,0);
m0[11].root =0;
m0[11].move =16;
m0[0] = new Array(50,34,12,28,57,42,6,21,62,45,1,18,54,46,5,33,61,54,4,6,71,5,60,62,127,61,28,36,45,30,33,42,49,42,5,4,59,50,3,12,51,43,36,43,52,43,11,19);
m0[0].base = new Array(0,1,2,3,4,5,6,7,8,9,9,10,10,30,58,81,82,95,96,97,98,99,100,101,0);
m0[0].root =0;
m0[0].move =0;
var n0 = new Array();
var b0 = -1;
var pieces = "KDSLT ";
var pos_after = "Stellung nach ";
var start_pos = "  ";
function g0(a,b)
{	gm(m0,n0,0,b0,'a29g0.htm',a,b);}
function MB_50()
{b0=MB_5(m0,n0,0,b0,'a29g0.htm'); GMS(m0,n0,0,b0,'a29g0.htm');}
function MB0()
{b0=MB(m0,n0,0,b0,'a29g0.htm'); GMS(m0,n0,0,b0,'a29g0.htm');}
function MF_50()
{b0=MF_5(m0,n0,0,b0,'a29g0.htm'); GMS(m0,n0,0,b0,'a29g0.htm');}
function MF0()
{b0=MF(m0,n0,0,b0,'a29g0.htm',true); ia290.value=GMS(m0,n0,0,b0,'a29g0.htm');}
var nMoves = new Array(0,0);
var nLevels = new Array(0,0);
var nNameCount = new Array(0,0);
var nOld = new Array(-1,-1);
baseName = 'a29';
var EmptyWhitePath = "gif/w.gif";
var EmptyBlackPath = "gif/b.gif";
var BackColor = "#FFF8B3";
