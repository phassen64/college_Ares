
var m0 = new Array(1)

m0[1] = new Array(11,19);
m0[1].base = new Array(8,0);
m0[1].root =0;
m0[1].move =7;
m0[3] = new Array(29,36,45,28,6,21,58,30);
m0[3].base = new Array(12,13,14,15,0);
m0[3].root =2;
m0[3].move =2;
m0[2] = new Array(13,29,51,35,28,35,36,28,5,26,60,62,127,61,6,12,32,41,11,27,28,19,75,75,3,19,61,60);
m0[2].base = new Array(9,10,11,16,17,18,18,19,20,21,22,22,23,24,0);
m0[2].root =0;
m0[2].move =7;
m0[4] = new Array(32,18,11,18);
m0[4].base = new Array(26,27,0);
m0[4].root =0;
m0[4].move =9;
m0[5] = new Array(51,43);
m0[5].base = new Array(28,0);
m0[5].root =0;
m0[5].move =9;
m0[6] = new Array(5,26,50,42,4,6,71,5,51,35,28,35,42,35,26,17,36,28);
m0[6].base = new Array(30,31,32,32,33,34,35,36,37,0);
m0[6].root =0;
m0[6].move =10;
m0[7] = new Array(21,36);
m0[7].base = new Array(38,0);
m0[7].root =0;
m0[7].move =10;
m0[9] = new Array(3,11,41,27);
m0[9].base = new Array(52,53,0);
m0[9].root =8;
m0[9].move =13;
m0[8] = new Array(9,25,32,41,2,9,61,60,5,26,50,42,11,19,51,35,26,17,58,30,15,23,30,39,4,6,71,5,48,32);
m0[8].base = new Array(39,40,41,42,43,44,45,46,47,48,49,50,51,51,54,0);
m0[8].root =0;
m0[8].move =10;
m0[0] = new Array(52,36,12,28,62,45,1,18,61,25,8,16,25,32,6,21,60,62,127,61,5,12);
m0[0].base = new Array(0,1,2,3,4,5,6,7,25,25,29,0);
m0[0].root =0;
m0[0].move =0;
var n0 = new Array();
var b0 = -1;
var pieces = "KDSLT ";
var pos_after = "Stellung nach ";
var start_pos = "  ";
function g0(a,b)
{	gm(m0,n0,0,b0,'c70_la4g0.htm',a,b);}
function MB_50()
{b0=MB_5(m0,n0,0,b0,'c70_la4g0.htm'); GMS(m0,n0,0,b0,'c70_la4g0.htm');}
function MB0()
{b0=MB(m0,n0,0,b0,'c70_la4g0.htm'); GMS(m0,n0,0,b0,'c70_la4g0.htm');}
function MF_50()
{b0=MF_5(m0,n0,0,b0,'c70_la4g0.htm'); GMS(m0,n0,0,b0,'c70_la4g0.htm');}
function MF0()
{b0=MF(m0,n0,0,b0,'c70_la4g0.htm',true); ic70_la40.value=GMS(m0,n0,0,b0,'c70_la4g0.htm');}
var nMoves = new Array(0,0);
var nLevels = new Array(0,0);
var nNameCount = new Array(0,0);
var nOld = new Array(-1,-1);
baseName = 'c70_la4';
var EmptyWhitePath = "gif/w.gif";
var EmptyBlackPath = "gif/b.gif";
var BackColor = "#FFF8B3";
