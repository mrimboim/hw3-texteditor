#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;

#define MAX_WIDTH 20 // Maximum size of a line
#define MAX_LINES 30 // Maximum number of lines

int openFile(string fileName) // later add pasby ref for data struct
{
    string line;
    ifstream file(fileName);

    if (file.is_open()) // if statments to check size of each line and number of lines and close file at the end
    {
        while (getline(file, line))
        {
            std::cout << line << "   size of line: " << line.size() << std::endl;
        }

        file.close();
        return 0;
    }
    else
    {
        return 1;
    }
}

int main(int argc, char *argv[])
{
    // intial command line validation
    if (argc < 2)
    {
        cout << "Too few command-line arguments." << '\n';
        return 1;
    }
    else if (argc > 2)
    {
        cout << "Too many command-line arguments." << '\n';
        return 1;
    }

    // save filename to a string var, run it through the file function
    string fileName(argv[1]);

    // some kind of data structre to be used for the main buffer varaible

    // int openFileStatus = openFile(fileName, &data structre) <- might need to use pass by refrence
    int openFileStatus = openFile(fileName);

    // gets file status from open file func if all good continues to the loop
    if (openFileStatus == 1)
    {
        cout << "Failed to open file: " << fileName << '\n';
        return 2;
    }
    else if (openFileStatus == 2)
    {
        cout << "File " << fileName << " has too many lines." << '\n';
        return 2;
    }
    else if (openFileStatus == 3)
    {
        cout << "File " << fileName << " has at least one too long line." << '\n';
        return 2;
    }
}