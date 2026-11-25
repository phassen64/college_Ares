
var m0 = new Array(1)

m0[1] = new Array(34,27,5,14,61,25,2,11,59,52,4,6,71,5,62,45);
m0[1].base = new Array(11,12,13,14,15,16,16,17,0);
m0[1].root =0;
m0[1].move =10;
m0[3] = new Array(11,17,34,26);
m0[3].base = new Array(22,23,0);
m0[3].root =2;
m0[3].move =2;
m0[2] = new Array(1,11,62,45,5,14,34,27,4,6,71,5);
m0[2].base = new Array(19,20,21,24,25,25,0);
m0[2].root =0;
m0[2].move =11;
m0[4] = new Array(21,4,62,45,4,19,58,37);
m0[4].base = new Array(30,31,32,33,0);
m0[4].root =0;
m0[4].move =16;
m0[5] = new Array(1,16,58,37,16,10,52,45);
m0[5].base = new Array(34,35,36,37,0);
m0[5].root =0;
m0[5].move =16;
m0[7] = new Array(0,2,27,19,12,19,45,9,11,9,60,62,127,61,17,25,40,41);
m0[7].base = new Array(49,50,51,52,53,54,54,55,56,0);
m0[7].root =6;
m0[7].move =10;
m0[6] = new Array(9,17,52,45,2,9,62,52,3,11,58,37,5,3,56,58,1,16,41,40,17,25,49,33,3,2,40,24);
m0[6].base = new Array(38,39,40,41,42,43,44,45,46,47,48,57,58,59,0);
m0[6].root =0;
m0[6].move =16;
m0[8] = new Array(8,24,62,45,24,32,42,32,3,27,52,34);
m0[8].base = new Array(60,61,62,63,64,65,0);
m0[8].root =0;
m0[8].move =16;
m0[0] = new Array(52,36,10,18,51,35,11,27,36,27,18,27,50,34,6,21,57,42,14,22,59,41,5,14,34,27,4,6,71,5,61,52,1,11,52,45,11,17,62,52,2,29,60,62,127,61,3,11,58,37);
m0[0].base = new Array(0,1,2,3,4,5,6,7,8,9,10,18,26,27,27,28,29,66,67,68,69,70,70,71,72,0);
m0[0].root =0;
m0[0].move =0;
var n0 = new Array();
var b0 = -1;
var pieces = "KDSLT ";
var pos_after = "Stellung nach ";
var start_pos = "  ";
function g0(a,b)
{	gm(m0,n0,0,b0,'b14_pg6g0.htm',a,b);}
function MB_50()
{b0=MB_5(m0,n0,0,b0,'b14_pg6g0.htm'); GMS(m0,n0,0,b0,'b14_pg6g0.htm');}
function MB0()
{b0=MB(m0,n0,0,b0,'b14_pg6g0.htm'); GMS(m0,n0,0,b0,'b14_pg6g0.htm');}
function MF_50()
{b0=MF_5(m0,n0,0,b0,'b14_pg6g0.htm'); GMS(m0,n0,0,b0,'b14_pg6g0.htm');}
function MF0()
{b0=MF(m0,n0,0,b0,'b14_pg6g0.htm',true); ib14_pg60.value=GMS(m0,n0,0,b0,'b14_pg6g0.htm');}
var nMoves = new Array(0,0);
var nLevels = new Array(0,0);
var nNameCount = new Array(0,0);
var nOld = new Array(-1,-1);
baseName = 'b14_pg6';
var EmptyWhitePath = "gif/w.gif";
var EmptyBlackPath = "gif/b.gif";
var BackColor = "#FFF8B3";
