#   *****************************************************************
#   FIND logon in csv-EVENT-files
#   *****************************************************************
#	FUNC:	The function handles csv-Event-Fiels
#	DATE:	11.12.2009
#	PARA:   -cmd:command
#			-str:'event1;event2' or 'event1,event2'
#			-src:in-CSV-Event-File
#           -obj:out-CSV-Event-LOGON-File
#   *****************************************************************
#   --- Include Modules
    use strict;
    use FCT;                        # GENERAL INCLUDE FILE
    use File::Copy;     # file copy
    use Cwd 'cwd','chdir';          # pwd


#   --- Function
    sub f_usage();
    sub f_version();
	sub f_testLogOn();      # nil
	sub f_runLogOn($$$$$);   # src,obj,csv,evLOGON,evLOGOFF

#   --- CONSTANTs
    my  $C_FILE_EXTENSION   	= "csv";

#   --- CMD and CMD function
    my  $C_CMD_TEST             =   "TEST";
    my  $C_CMD_RUN              =   "RUN";
    my  @C_CMD                  =   (
                                        $C_CMD_TEST,
                                        $C_CMD_RUN
                                     );

#	---	special constant
#   INPUT line: 1,2010-01-13 08:21:25
	my	$C_KEY_VALUE_SEPERATOR	            = ',';	# key,val
	my	$C_VALUE_SEPERATOR	                = ' ';	# val1 val2
	my	$C_EVENT_SEPERATOR	                = ';';	# key,val
	my  $C_NEWLINE                          = "\n";
    my  $C_MAX_LINE_NR                      = 10000;
	
#   --- global Vars
    my  %l_Opts=();
    my  ($file,$fileSRC,$fileOBJ,$fileCSV,$cmd)  =  (0,0,0,0,0);
    my  $fpSRC      =   gensym();
    my  $fpOBJ      =   gensym();
    my  $fpCSV      =   gensym();
    my  ($dir)          = (0);
    my  $homeDir          =   "";         # cmdDir    
    my  $fileTmp        =   __FILE__;
    my  $SCRIPT         =   __FILE__;
    my  $i              =   0;
    my  $iCMD           =   -1;
    my  $bOK            =   0;
    my  $n              =   0;
    my  $c              =   0;
    my  $rc             =   0;
    my  $sep            =   0;
    my  $tm             =   $C_TRACE_MASK_MAIN;
    my  $argList        =   "";
    my  @EventList  = ();
    my  @list       = ();
    my  $str = "";
    my  $ext;
    my  $date = 0;
    
    $SCRIPT         = F_modFileNamePath($SCRIPT);
    my $SCRIPT_NAME = F_getFileName($SCRIPT);

#   --- TEST
    #$n = F_modTimeStr2TimeInt("12:45:33");
    #printf("nVal=%d\n",$n);
    #$str = F_modTimeStr2TimeInt($n);
    #printf("sVal=%s\n",$str);
    #exit;

#   --- getOpts
    printf("SCRIPT::getOPTS\n");
    $rc = F_getOpts(%l_Opts,&f_usage);
    if (!defined $rc || $rc == 0) {
        warn "??? uedit->FGetOpts";
        exit;
    }        
    # F_printOpts($tm);  
    _T($tm,"UEDIT");

#   --- save this dir
    $homeDir = cwd();
    F_print("+++ $SCRIPT homeDir='$homeDir'\n",$tm);

    
#   --- check necessary args
	if ($l_Opts{VERSION} ne 0) {
		f_version();
		exit;
	}

    
#   --- check existing parameters    
    if ($l_Opts{cmd} eq 0)  { warn "??? -cmd='CMD'";  f_usage(); }
    if ($l_Opts{src} eq 0)  { warn "??? -src='not defined"; f_usage(); }
    if ($l_Opts{obj} eq 0)  { 
        warn "!!! -obj='DIR==DEFAULT'"; 
        $date           = F_getDate();
        $ext            = F_getFileExtension($l_Opts{src});
        $file           = F_subFileExtension($l_Opts{src});
        $l_Opts{obj}    =  $file .	'-' . $date . '.' . $ext;
    }
    if ($l_Opts{str} eq 0)  { warn "??? -str='0'"; f_usage(); }



#   --- uppercase cmd       
    $l_Opts{cmd} = uc($l_Opts{cmd});
    printf("parameter CMD == <$l_Opts{cmd}>\n");
    $cmd =  $l_Opts{cmd};

#   --- check CMD only
    $n      =   @C_CMD;  
    printf("CMD Alternatives:<$n>\n");
    $iCMD   =   -1;   
    for ($i=0; $i < $n; $i++) 
    {
        $cmd = $C_CMD[$i];
        printf("*** try CMD '$cmd'\n");
        if ($cmd eq $l_Opts{cmd}) {
            # printf("CMD '$cmd' is found'");
            $iCMD   = $i;
            $bOK    = 1;
            last;
        }
            
    }        
    if ($bOK == 0) {
        warn "??? cmd:'$l_Opts{cmd}' not found"; 
        f_usage();
        exit;
    }
    
#   --- check str and get Event1 and Event2  syntax: Ev1;Ev2
    printf("*** parameter STR == <$l_Opts{str}>\n");
    $str        = $l_Opts{str};
    @list       = split(//,$str);
    $n          = $#list + 1;
    $sep        = '';
    printf("check:{$str};list:{$list[0]}\n");
    for($i=0; $i <$n; $i++) {
        $c = $list[$i];   
        printf("CHECK sepC[%d]:'%s'\n",$i,$c);
        if (!isdigit($c)) {
            $sep = $c;
            printf("found SEP '$sep' at $i\n");
            last;
        }            
    }
    if ($sep eq '') {
        warn "??? str:'$l_Opts{str}' has no SEPERATOER"; 
        f_usage();
        exit;
    }        
    if (isalnum($sep)) {
        warn "??? str:'$l_Opts{str}' isalnum(SEPERATOER) not allowed"; 
        f_usage();
        exit;
    }        
    printf("*** SEP found == {$sep}\n");
  	@EventList  = ();
    $C_EVENT_SEPERATOR = $sep;
    @EventList  = split(/$C_EVENT_SEPERATOR/,$l_Opts{str},2);    
    $n          = $#EventList+1;               
	if ($n != 2)  
    {
        warn "??? str:'$l_Opts{str}' not 2 EVENTS"; 
        f_usage();
        exit;
    }	        
    
    
#   --- change dir to : srcDir
    $dir    	= F_getDirName($l_Opts{src});
    chdir($dir);                        

#   --- try to open SRC/OBJ/CSV file
    $fileSRC   	= F_getFileName($l_Opts{src});
    $fileOBJ   	= F_getFileName($l_Opts{obj});    
    $rc = open($fpSRC,"< $fileSRC");
    if ((!defined $rc) || ($fileSRC eq 0)) { 
        warn "??? I can't read '$fileSRC'";  
        exit; 
    }
    $rc = open($fpOBJ,"> $fileOBJ");
    if ((!defined $rc) || ($fileOBJ eq 0)) { 
        warn "??? I can't write file '$fileOBJ'";  
        exit; 
    }
    $file           =   F_subFileExtension($fileSRC);
#   $fileCSV        =   $file .	'.csv';
    $fileCSV        =   $file .	'.csv';
    $rc = open($fpCSV,"> $fileCSV");
    if ((!defined $rc) || ($fileCSV eq 0)) { 
        warn "??? I can't write file '$fileCSV'";  
        exit; 
    }

#   --- INFO
    F_print("+++ $SCRIPT opts={dir:'$dir';fileSRC:'$fileSRC';fileOBJ:'$fileOBJ';cmd='$cmd'}\n",
    $tm);

#   
#   --- start CMD   -------------------------------------------------
#
    #   --- get File Entries of Uedit File
    print   "+++ $SCRIPT:  I read Uedit Editor File '$l_Opts{src}'";    
    printf("::CMD:$iCMD\n");
    # $rc = $C_FCT[$iCMD]($fpSRC,$fpOBJ);
    
    $str = "... I created FILE:'$fileOBJ' and \n... '$fileCSV' at DIR:'$dir'";
    if ($cmd eq $C_CMD_TEST)  {
        $rc = f_testLogOn();
        $str = "... ready with CHECK!";

    } elsif ($cmd eq $C_CMD_RUN)  {
        $rc = f_runLogOn($fpSRC,$fpOBJ,$fpCSV,$EventList[0],$EventList[1]);
    }

    #   --- change dir to : objDir
    $dir    = F_getDirName($l_Opts{obj}) ;             
    chdir($dir);                        
    #   --- check cwd dir
    $dir = cwd();
    # print   "*01 I am at DIR=$dir\n";

    printf("%s\n",$str);
#   
#   --- -------------------------------------------------------------
#

#   --- close files
    close($fpCSV);
    close($fpOBJ);
    close($fpSRC);

L_END:
    #   --- after zip Script    
    print   "*** $SCRIPT:   I stop now\n";    
    chdir($homeDir);                # change ProcessDir
                
#   exit;



#   =================================================================
sub f_testLogOn() # nil
#   =================================================================
{
    F_HEADER('f_testLogOn',__FILE__,__LINE__);
    printf("=== This is fct TEST-LogOn-File\n");
    return(0);
}    

#   =================================================================
sub f_runLogOn($$$$$) # src,obj,ev_LOGIN,ev_LOGOFF
#   =================================================================
#   Parameters:
#       SRC:= csv-File
#       OBJ:= csv-File-TO
#       ev1:= from-Event
#       ev2:= to-Event
#   DES:    
#       + removes spaces 
#       + remove ending comments
#       + remove empty lines
#       + remove doubled lines
{
    my  $fpSRC      =   shift();
    my  $fpOBJ      =   shift();
    my  $fpCSV      =   shift();
    my  $ev_LOGIN   =   shift();
    my  $ev_LOGOFF  =   shift();
    my  $rc         =   0;
    my  ($cLine,$iLineNr)=(0,0);
    my  ($sReg,$t,$Mask)=(0,0,0);
  	my  @KeyValList = ();
  	my  @ValList = ();
  	my  ($i,$n,$iKeyValNr,$iValNr)=(0,0,0,0);
    my  ($Key,$Val)=(0,0);
    my  ($Date,$Time)=(0,0);
    my  ($t1,$t2,$t_INT,$t_STR)=(0,0,0,0);
    my  ($isLOGIN,$isLOGIN_OLD,$isLOGOFF,$isLOGOFF_OLD)=(0,0,0,0);
    my  ($dateLOGIN,$dateLOGOFF,$dateNOW,$timeLOGIN,$timeLOGOFF,$timeNOW)=(0,0,0,0,0,0);
    my  $dateFIRST  =   '';
    my  $cResult        =   '';
    my  $cResult_CSV    =   '';
    my  $cResult_LAST   =   '';
    my  %l_DateTimeHash =   ();

    printf("*** runLOGON:ev_LOGIN:{%s}\n",$ev_LOGIN);
    printf("*** runLOGON:ev_LOGOFF:{%s}\n",$ev_LOGOFF);

    # --- Header Lines for CSV
    $cResult_CSV = "DATE;LOGIN;LOGOFF;DIFF.HOUR;DIFF.DEZ";
    print ($fpCSV "$cResult_CSV\n");
        
    while (!eof($fpSRC))
    {
        # --- count lineNr
        $iLineNr ++;

        # --- readLine and remove last NL
        $cLine  = readline($fpSRC);    
        chomp($cLine);     # rmv NL           

        # --- spaces 
        $cLine =~ s/[[:space:]]+/ /;   #rmv multi spaces   

        # --- is Buffer empty ???
        if (length($cLine) == 0) { next ; }            
            
        # --- delete starting spaces
        $cLine =~ s/^[[:space:]]+//;       

        # --- delete ending spaces
        $cLine  =~ s/[[:space:]]+$//;


        # --- split into Key and Value(if exist)        *** Key=Value
      	@KeyValList = ();
        @KeyValList = split(/$C_KEY_VALUE_SEPERATOR/,$cLine,2);    
        $iKeyValNr  = $#KeyValList+1;               
	    if ($iKeyValNr != 2)  
	    {
	        goto l_next;
        }	        
        for($i=0; $i < 2; $i++) {
            if (defined $KeyValList[$i]) {  
			    #--- delete starting+ending spaces
				$KeyValList[$i]	    =~ s/^[[:space:]]+//;
            	$KeyValList[$i] 	=~ s/[[:space:]]+$//;
		    }
        }			        
        $Key = $KeyValList[0];
        $Val = $KeyValList[1];

        # --- TEST LINES
        if ($iLineNr > $C_MAX_LINE_NR) {goto l_next;
        }

        # --- check if KEY is DIGIT, if not go overlook this line
        $sReg  = $Key;
        $sReg =~ s/[[:^digit:]]//g;                 # alle Digits
        $n = length($sReg);
        # printf("*** LENGTH = [%d] \n",$n);
        if ((not defined $sReg) || ($n == 0)) {
            # printf("*** KEY[%s] not defined\n",$Key);
            goto l_next;
        }

        # --- check ev LOGON/LOGOFF
        $isLOGIN        = 0;
        $isLOGOFF_OLD   = $isLOGOFF;
        $isLOGOFF       = 0;
        if ($Key == $ev_LOGIN) {
            $isLOGIN    = 1;
        } elsif  ($Key  == $ev_LOGOFF) {           
            $isLOGOFF   = 1;
        } else {            
            warn "!!! not allowed event:$Key";
            goto l_next;
        }
        

        # --- split Value into DATE and TIME
      	@ValList = ();
        @ValList = split(/$C_VALUE_SEPERATOR/,$Val,2);    
        $iValNr  = $#ValList+1;               
	    if ($iValNr != 2)   
	    {
	        goto l_next;
        }	        
        $Date = $ValList[0];        # format: YYYY-MM-DD
        $Time = $ValList[1];

            
        # --- get oldest date
        $cResult_LAST = $cResult;
#!DBG   printf("%s\n",$cResult_LAST);
#!DBG   $cResult =  sprintf("[%4.4d]:KEY:'%s';DATE:'%s';TIME:'%s'",$iLineNr,$Key,$Date,$Time); 
#!DBG   $cResult =  sprintf("'DATE:'%s';TIME:'%s'",$Date,$Time); 

        if ($dateLOGIN ne $Date)
        {
            if ($dateFIRST ne '') {            
                if ($isLOGOFF_OLD == 1) {       
                    # printf("LOGIN:FIRST:LOGOFF\n");
                    $t1 = F_modTimeStr2TimeInt($timeLOGIN);
                    $t2 = F_modTimeStr2TimeInt($timeLOGOFF);
                    $n  = $t2-$t1;
                    $t_STR = F_modTimeInt2TimeStr($n);
                    $t_INT = $n / 3600;
                    $cResult = 
                    $cResult_LAST . 
                    ";LOGOFF:[" . $timeLOGIN . ";" . $timeLOGOFF . "]=(" 
#                    . $n . "=" . $rc . ")"; 
                    . $t_STR . ")={" . $t_INT ."}" ; 

                    $cResult = sprintf("*** DATE:[%s];STAMP:[%s--%s];DIFF[%s](%02.2f)",
                    $dateLOGOFF,$timeLOGIN,$timeLOGOFF,$t_STR,$t_INT);
#                   ---- print RESULTs into FILE and SCREEN        
                    printf("%s\n",$cResult);
                    print ($fpOBJ "$cResult\n");
#                   ---- print RESULTs into CSV-FILE     
                    # $cResult_CSV = sprintf("%s;%s;%s;%s;%02.2f",
                    $cResult_CSV = sprintf("'%s';'%s';'%s';'%s';'%02.2f'",
                    $dateLOGOFF,$timeLOGIN,$timeLOGOFF,$t_STR,$t_INT);
                    print ($fpCSV "$cResult_CSV\n");

                }
            }
            if ($isLOGIN == 1) {
                if ($dateFIRST eq '') {
                    $dateFIRST = $Date;
                }
                $dateLOGIN = $Date;
                $timeLOGIN = $Time;
#!DBG           $cResult = $cResult . "::*** LOGIN";
#!DBG           print ($fpOBJ "$cResult\n");
            }
        }
        else {
            if ($isLOGOFF == 1) {
                $dateLOGOFF = $Date;                
                $timeLOGOFF = $Time;
            }
        }
        
        # --- OUT

        # printf("LINE[%d]:VAL=<%s>\n",$iLineNr,$cLine);

l_next:
    }
    F_getDateTimeHash(%l_DateTimeHash);
    # F_HASH(%l_DateTimeHash,"DateHash_OUT");
    $dateNOW = sprintf("%4.4d-%2.2d-%2.2d",
        $l_DateTimeHash{Y},
        $l_DateTimeHash{M},
        $l_DateTimeHash{D}
    );
    $timeNOW = sprintf("%2.2d:%2.2d:%2.2d",
        $l_DateTimeHash{h},
        $l_DateTimeHash{m},
        $l_DateTimeHash{s}
    );
    if ($dateNOW ne $dateLOGIN) {
        warn "date <> dateLOGIN";
        return(__LINE__);
    }        
    $t1 = F_modTimeStr2TimeInt($timeLOGIN);
    $t2 = F_modTimeStr2TimeInt($timeNOW);
    $n  = $t2-$t1;
    $t_STR = F_modTimeInt2TimeStr($n);
    $t_INT = $n / 3600;
    $cResult = sprintf("*** DATE:[%s];STAMP:[%s--%s];DIFF[%s](%02.2f)",
    $dateLOGIN,$timeLOGIN,$timeNOW,$t_STR,$t_INT);
    printf("%s\n",$cResult);
    print ($fpOBJ "$cResult\n");
    $cResult_CSV = sprintf("'%s';'%s';'%s';'%s';'%02.2f'",
         $dateLOGOFF,$timeLOGIN,$timeNOW,$t_STR,$t_INT);
    print ($fpCSV "$cResult_CSV\n");

    return(0);
}



#   =================================================================
sub f_usage() 
#   =================================================================
{
    # my      $SCRIPT = __FILE__;
    # $SCRIPT         =   F_getFileName($SCRIPT);
    my $str;
    $str = ">>> perl $SCRIPT_NAME -cmd=<CMD> ";
    $str = $str ."-src=<from-csvFile> [-obj=<to-csvFile>] [-str=<2-event-List>\n";
    $str = $str . "\t<CMD>:={'RUN','TEST'}\n";
    $str = $str . "---  EXAMPLE\n";
    $str = $str . ">    perl $SCRIPT \n";
    $str = $str . "     -cmd=RUN\n";
    $str = $str . "     -src=D:\\tmp\\logOn.txt\n";
    $str = $str . "     -obj=D:\\tmp\\logOn_OUT.txt\n";
    $str = $str . "     -str='1;2'\n";
    print $str;

    exit;
}


#   =================================================================
sub f_version() 
#   =================================================================
{
    my $str;
   	$str = "VERSION: HST; Neumarkt; 10.12.2009\n";			   			
   	F_LINE('#',70);
    print $str;
   	F_LINE('#',70);
    exit;
}
