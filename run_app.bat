@echo off
echo Dang bien dich he thong...
g++ -std=c++17 -Wall main.cpp benh_vien\*.cpp benh_nhan\*.cpp bac_si\*.cpp hoa_don\*.cpp co_so_vat_chat\*.cpp he_thong\*.cpp -o main.exe
if %ERRORLEVEL% EQU 0 (
    echo Bien dich thanh cong! Dang chay...
    main.exe
) else (
    echo Loi bien dich!
    pause
)
