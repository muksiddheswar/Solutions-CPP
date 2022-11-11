@ECHO OFF

ECHO Execting file cleanup...
ECHO Recursively deleting all *.exe file in the current directory.

@ECHO OFF
powershell -Command "& {ls *.exe -Recurse | foreach{echo $_}}"
powershell -Command "& {ls *.exe -Recurse | foreach{rm $_}}"


PAUSE

