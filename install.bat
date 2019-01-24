@echo off
echo Waiting for installing . . .
cd sources
g++ -std=c++11 -c coccoc.cpp searching.cpp directory.cpp trie.cpp
g++ -std=c++11 coccoc.o searching.o directory.o trie.o -o ../coccoc.exe
del coccoc.o searching.o directory.o trie.o
cd ..
echo Installing successful!
echo.
pause