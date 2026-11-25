
var m0 = new Array(1)

m0[1] = new Array(61,43,1,18,50,42,6,21,58,37,14,22,62,45,5,14,57,51,4,6,71,5,60,62,127,61,21,31,37,44,13,29,51,41);
m0[1].base = new Array(7,8,9,10,11,12,13,14,15,16,16,17,17,18,19,20,21,0);
m0[1].root =0;
m0[1].move =6;
m0[2] = new Array(1,18,58,30);
m0[2].base = new Array(25,26,0);
m0[2].root =0;
m0[2].move =9;
m0[3] = new Array(1,18,34,26);
m0[3].base = new Array(29,30,0);
m0[3].root =0;
m0[3].move =11;
m0[5] = new Array(33,24,61,43,27,34,43,34,4,6,71,5,60,62,127,61,1,18,59,43);
m0[5].base = new Array(34,35,36,37,38,38,39,39,40,41,0);
m0[5].root =4;
m0[5].move =2;
m0[4] = new Array(5,33,48,40,33,42,49,42,4,6,71,5,61,43);
m0[4].base = new Array(31,32,33,42,43,43,44,0);
m0[4].root =0;
m0[4].move =11;
m0[6] = new Array(21,27,61,43,4,6,71,5,60,62,127,61,1,18,61,60);
m0[6].base = new Array(47,48,49,49,50,50,51,52,0);
m0[6].root =0;
m0[6].move =13;
m0[0] = new Array(52,36,10,18,51,35,11,27,36,27,18,27,50,34,6,21,57,42,12,20,62,45,5,12,34,27,20,27,61,25,2,11,59,41);
m0[0].base = new Array(0,1,2,3,4,5,6,22,23,24,27,28,45,46,53,54,55,0);
m0[0].root =0;
m0[0].move =0;
var n0 = new Array();
var b0 = -1;
var pieces = "KDSLT ";
var pos_after = "Stellung nach ";
var start_pos = "  ";
function g0(a,b)
{	gm(m0,n0,0,b0,'b13g0.htm',a,b);}
function MB_50()
{b0=MB_5(m0,n0,0,b0,'b13g0.htm'); GMS(m0,n0,0,b0,'b13g0.htm');}
function MB0()
{b0=MB(m0,n0,0,b0,'b13g0.htm'); GMS(m0,n0,0,b0,'b13g0.htm');}
function MF_50()
{b0=MF_5(m0,n0,0,b0,'b13g0.htm'); GMS(m0,n0,0,b0,'b13g0.htm');}
function MF0()
{b0=MF(m0,n0,0,b0,'b13g0.htm',true); ib130.value=GMS(m0,n0,0,b0,'b13g0.htm');}
var nMoves = new Array(0,0);
var nLevels = new Array(0,0);
var nNameCount = new Array(0,0);
var nOld = new Array(-1,-1);
baseName = 'b13';
var EmptyWhitePath = "gif/w.gif";
var EmptyBlackPath = "gif/b.gif";
var BackColor = "#FFF8B3";
