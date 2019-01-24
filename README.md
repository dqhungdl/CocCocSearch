# CoccocSearch Tool
  * CoccocSearch tool is a software package which used to find all files in specific directory that contain all input key words.

## Requirements
  * This package requires [MinGW](https://sourceforge.net/projects/mingw-w64/) to compile C++ code and `.exe` extension.
  * This package only works on Windows OS.

## Installing
  * Edit your system PATH, add this folder's path to your system PATH for easy command-line access `coccoc.exe`.
  * If `coccoc.exe` is not exist in this folder, click `install.bat` or using `cmd`, changing directory to this folder and using command `install` for successful installing.

## Using
  * This program works on command-line with this interface:
    ```
    coccoc "many words" [path to dictionary]
    ```
    
    #### Example:
    ```
    coccoc "coccoc web brower" C:\Users
    ```
  * If `[path to dictionary]` is omitted, the program works on current directory.
    #### Example: 
    ```
    coccoc "coccoc web brower"
    ```
  * Note that if the directory has subdirectories, this program will find all files in the directory and its subdirectories.
  * Be careful with lowercase or uppercase key words, is it different.

## Author
  * Quoc Hung Duong (dqhungdl@gmail.com).

## License
  * **This package is free!**
