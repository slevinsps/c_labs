chcp 1251
@echo off
fc expected_%1.txt actual_%1.txt
if "%1" == "4" pause
