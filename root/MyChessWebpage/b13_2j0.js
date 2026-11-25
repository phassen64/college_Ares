
var m0 = new Array(1)

m0[1] = new Array(14,22,59,41,5,14,34,27,4,6,71,5,61,52);
m0[1].base = new Array(10,11,12,13,14,14,15,0);
m0[1].root =0;
m0[1].move =9;
m0[2] = new Array(12,20,62,45);
m0[2].base = new Array(16,17,0);
m0[2].root =0;
m0[2].move =9;
m0[0] = new Array(52,36,10,18,51,35,11,27,36,27,18,27,50,34,6,21,57,42,1,18,58,30);
m0[0].base = new Array(0,1,2,3,4,5,6,7,8,9,18,0);
m0[0].root =0;
m0[0].move =0;
var n0 = new Array();
var b0 = -1;
var pieces = "KDSLT ";
var pos_after = "Stellung nach ";
var start_pos = "  ";
function g0(a,b)
{	gm(m0,n0,0,b0,'b13_2g0.htm',a,b);}
function MB_50()
{b0=MB_5(m0,n0,0,b0,'b13_2g0.htm'); GMS(m0,n0,0,b0,'b13_2g0.htm');}
function MB0()
{b0=MB(m0,n0,0,b0,'b13_2g0.htm'); GMS(m0,n0,0,b0,'b13_2g0.htm');}
function MF_50()
{b0=MF_5(m0,n0,0,b0,'b13_2g0.htm'); GMS(m0,n0,0,b0,'b13_2g0.htm');}
function MF0()
{b0=MF(m0,n0,0,b0,'b13_2g0.htm',true); ib13_20.value=GMS(m0,n0,0,b0,'b13_2g0.htm');}
var nMoves = new Array(0,0);
var nLevels = new Array(0,0);
var nNameCount = new Array(0,0);
var nOld = new Array(-1,-1);
baseName = 'b13_2';
var EmptyWhitePath = "gif/w.gif";
var EmptyBlackPath = "gif/b.gif";
var BackColor = "#FFF8B3";
