@echo off
for /f "tokens=2-4 delims=/ " %%A in ('date /t') do (
    set currentMonth=%%A
    set currentDate=%%B
    set currentYear=%%C
)
set Date = %date%
echo date is %Date%
echo Current Month is %currentMonth%
echo Current Date is %currentDate%
echo Current Year is %currentYear%
pause
