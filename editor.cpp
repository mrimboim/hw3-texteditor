#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;

#define MAX_WIDTH 20 // Maximum size of a line
#define MAX_LINES 30 // Maximum number of lines

int main(int argc, char *argv[])
{
    //intial command line validation 
    if (argc < 2)
    {
        cout << "Too few command-line arguments." << '\n';
        
    }else if(argc > 2){
        cout << "Too many command-line arguments." << '\n';
    }

    // save filename to a string var, run it through the file function
    string fileName(argv[1]);
    //some kind of data structre to be used for the main buffer varaible
    //int openFileStatus = openFile(fileName, &data structre) <- might need to use pass by refrence





}