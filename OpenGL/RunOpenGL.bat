REM
echo "Running"
gcc -c main.c -I\"D:\Programas\MinGW\x86_64-w64-mingw32\include/"
echo "Compiling graphics"
gcc -o main main.o -L\"D:\Programas\MinGW\x86_64-w64-mingw32\lib -lopengl32 -lglu32 -lfreeglut"
echo "Running app"
main.exe