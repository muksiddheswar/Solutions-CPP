@ECHO OFF

ECHO Executing file cleanup...
ECHO Recursively deleting all *.exe file in the current directory.

@ECHO OFF
powershell -Command "& {ls *.exe -Recurse | foreach{echo $_}}"
powershell -Command "& {ls *.exe -Recurse | foreach{rm $_}}"


ECHO Recursively deleting all *.stackdump file in the current directory.

@ECHO OFF
powershell -Command "& {ls *.stackdump -Recurse | foreach{echo $_}}"
powershell -Command "& {ls *.stackdump -Recurse | foreach{rm $_}}"


PAUSE

