@echo ***************************************************************
@echo STRT:  runLOGON       [%date%;%time%]     
@echo ***************************************************************

::  -----------------------------------------------------------------
::  set ENV
::  -----------------------------------------------------------------

@echo *** setENV
@call d:\MY\cmd\_CFG\env\HST\setenv_HST.bat D:\MY HST

:set  MYCMD_DIR=%MY%\cmd
:set  MYENV_DIR=%MY%\cmd\_CFG\env\%MYENV%


set v_SRC=LOGON.txt
set v_OBJ=LOGON_%date%.txt

set v_MY_DIR=D:\MY
set v_MY_TOOL_DIR=%v_MY_DIR%\TOOLS
set v_TMP_DIR=%v_MY_DIR%\+\TS

:@set v_PERL_DIR=%v_MY_TOOL_DIR%\PERL\BIN
@set v_EXE=%v_MY_TOOL_DIR%\logParser\logParser.exe

@set v_CMD=logon
@set v_SRC_DIR=%v_TMP_DIR%
@set v_OBJ_DIR=%v_TMP_DIR%

set EV1=1
set EV2=2

::  -----------------------------------------------------------------
::  PROGRAM
::  -----------------------------------------------------------------

:: perl -v

@echo *** run batch CMD
@call :sub_getLOGON "%v_TMP_DIR%\%v_SRC%"
@echo *** EOF : subfct
@call pwd

@echo *** run PERL
:: ignore v_OBJ , weil DOS nur DD-MM-YYYY darstellt, wir brauchen aber: YYYY-MM-DD
:: call p.bat %v_CMD% -src="%v_TMP_DIR%\%v_SRC%" -obj="%v_TMP_DIR%\%v_OBJ%" -cmd=RUN -str="%EV1%;%EV2%"
call p.bat %v_CMD% -src="%v_TMP_DIR%\%v_SRC%" -cmd=RUN -str="%EV1%;%EV2%"

@echo *** PERL end
@call pwd


@goto :l_END


:: ==================================================================
:sub_getLOGON
:: ==================================================================
@set  _FILE=%1%
@echo PWD=
%v_EXE% -i:EVT  "SELECT EventId,TimeGenerated FROM Application WHERE (EventId=%EV1% OR EventId=%EV2%)" -o:CSV > %_FILE%
:: type  %_FILE%
dir   %_FILE%
@goto :EOF
:: ==================================================================


:l_END

popd
@echo ***************************************************************
@echo END!:  runLOGON       [%date%;%time%]    
@echo ***************************************************************

sleep 1
