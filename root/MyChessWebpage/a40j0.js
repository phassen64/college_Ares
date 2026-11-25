
var m0 = new Array(1)

m0[3] = new Array(9,25,34,25,8,16,25,16,2,16,61,16,1,16,62,45,24,25,48,32,25,1,60,62,127,61,6,21,61,60,4,6,71,5,51,34);
m0[3].base = new Array(12,13,14,15,16,17,18,19,20,21,22,23,23,24,25,26,26,27,0);
m0[3].root =2;
m0[3].move =2;
m0[2] = new Array(3,24,57,51,11,19,61,43,1,16,62,45,16,33,43,57,6,21,60,62,127,61,4,6,71,5,61,60);
m0[2].base = new Array(9,10,11,28,29,30,31,32,33,34,34,35,35,36,0);
m0[2].root =1;
m0[2].move =2;
m0[6] = new Array(11,19,42,25);
m0[6].base = new Array(43,44,0);
m0[6].root =5;
m0[6].move =2;
m0[7] = new Array(14,42,49,42,3,10,58,30);
m0[7].base = new Array(45,46,47,48,0);
m0[7].root =5;
m0[7].move =2;
m0[5] = new Array(20,27,59,27,6,12,27,26);
m0[5].base = new Array(40,41,42,49,0);
m0[5].root =4;
m0[5].move =2;
m0[4] = new Array(12,20,57,42,3,24,58,51,24,17,59,32,1,16,42,25);
m0[4].base = new Array(37,38,39,50,51,52,53,54,0);
m0[4].root =1;
m0[4].move =2;
m0[8] = new Array(3,24,57,51,6,21,61,43,1,16,62,45);
m0[8].base = new Array(57,58,59,60,61,62,0);
m0[8].root =1;
m0[8].move =4;
m0[1] = new Array(10,26,35,27,11,19,53,37,6,21,57,42,4,6,71,5,62,45);
m0[1].base = new Array(6,7,8,55,56,63,64,64,65,0);
m0[1].root =0;
m0[1].move =5;
m0[9] = new Array(11,19,57,42,6,21,53,37,4,6,71,5,62,45);
m0[9].base = new Array(66,67,68,69,70,70,71,0);
m0[9].root =0;
m0[9].move =5;
m0[10] = new Array(10,18,57,42,11,27,34,27,18,27,42,27);
m0[10].base = new Array(72,73,74,75,76,77,0);
m0[10].root =0;
m0[10].move =5;
m0[11] = new Array(6,21,57,42,11,19,53,37);
m0[11].base = new Array(78,79,80,81,0);
m0[11].root =0;
m0[11].move =5;
m0[13] = new Array(15,23,49,41,10,18);
m0[13].base = new Array(99,100,101,0);
m0[13].root =12;
m0[13].move =3;
m0[12] = new Array(55,47,21,11,51,45,10,26);
m0[12].base = new Array(95,96,97,98,0);
m0[12].root =0;
m0[12].move =20;
m0[0] = new Array(52,36,14,22,51,35,5,14,50,34,1,18,62,45,12,28,35,27,18,35,45,35,28,35,61,43,11,19,60,62,127,61,6,21,57,51,4,6,71,5,51,45,21,11,58,30,3,4,59,51,10,26,27,18,90,90,9,18,30,23);
m0[0].base = new Array(0,1,2,3,4,5,82,83,84,85,86,87,88,89,90,90,91,92,93,93,94,102,103,104,105,106,107,107,108,109,0);
m0[0].root =0;
m0[0].move =0;
var n0 = new Array();
var b0 = -1;
var pieces = "KDSLT ";
var pos_after = "Stellung nach ";
var start_pos = "  ";
function g0(a,b)
{	gm(m0,n0,0,b0,'a40g0.htm',a,b);}
function MB_50()
{b0=MB_5(m0,n0,0,b0,'a40g0.htm'); GMS(m0,n0,0,b0,'a40g0.htm');}
function MB0()
{b0=MB(m0,n0,0,b0,'a40g0.htm'); GMS(m0,n0,0,b0,'a40g0.htm');}
function MF_50()
{b0=MF_5(m0,n0,0,b0,'a40g0.htm'); GMS(m0,n0,0,b0,'a40g0.htm');}
function MF0()
{b0=MF(m0,n0,0,b0,'a40g0.htm',true); ia400.value=GMS(m0,n0,0,b0,'a40g0.htm');}
var nMoves = new Array(0,0);
var nLevels = new Array(0,0);
var nNameCount = new Array(0,0);
var nOld = new Array(-1,-1);
baseName = 'a40';
var EmptyWhitePath = "gif/w.gif";
var EmptyBlackPath = "gif/b.gif";
var BackColor = "#FFF8B3";
