
var m0 = new Array(1)

m0[2] = new Array(11,27,36,27,12,27,61,60,2,20,25,18,9,18,58,30,3,1,59,58);
m0[2].base = new Array(15,16,17,18,19,20,21,22,23,24,0);
m0[2].root =1;
m0[2].move =9;
m0[1] = new Array(60,62,127,61,5,14,50,42,6,12,51,35,28,35,42,35,4,6,71,5,57,42,11,19,58,44,2,38,61,60,13,29,44,30);
m0[1].base = new Array(7,7,8,9,10,11,12,13,14,14,25,26,27,28,29,30,31,0);
m0[1].root =0;
m0[1].move =6;
m0[3] = new Array(5,33,50,42,35,42,57,42,33,12,30,51);
m0[3].base = new Array(35,36,37,38,39,40,0);
m0[3].root =0;
m0[3].move =9;
m0[0] = new Array(52,36,12,28,62,45,1,18,61,25,14,22,51,35,28,35,58,30,5,12,30,12,3,12,60,62,127,61,12,33,25,18);
m0[0].base = new Array(0,1,2,3,4,5,6,32,33,34,41,42,43,43,44,45,0);
m0[0].root =0;
m0[0].move =0;
var n0 = new Array();
var b0 = -1;
var pieces = "KDSLT ";
var pos_after = "Stellung nach ";
var start_pos = "  ";
function g0(a,b)
{	gm(m0,n0,0,b0,'c60_1g0.htm',a,b);}
function MB_50()
{b0=MB_5(m0,n0,0,b0,'c60_1g0.htm'); GMS(m0,n0,0,b0,'c60_1g0.htm');}
function MB0()
{b0=MB(m0,n0,0,b0,'c60_1g0.htm'); GMS(m0,n0,0,b0,'c60_1g0.htm');}
function MF_50()
{b0=MF_5(m0,n0,0,b0,'c60_1g0.htm'); GMS(m0,n0,0,b0,'c60_1g0.htm');}
function MF0()
{b0=MF(m0,n0,0,b0,'c60_1g0.htm',true); ic60_10.value=GMS(m0,n0,0,b0,'c60_1g0.htm');}
var nMoves = new Array(0,0);
var nLevels = new Array(0,0);
var nNameCount = new Array(0,0);
var nOld = new Array(-1,-1);
baseName = 'c60_1';
var EmptyWhitePath = "gif/w.gif";
var EmptyBlackPath = "gif/b.gif";
var BackColor = "#FFF8B3";
