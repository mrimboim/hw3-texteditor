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

int openFile(string fileName, vector<string> &buffer) // later add pass by ref for data struct
{
    string line;
    ifstream file(fileName);

    if (file.is_open()) // if statments to check size of each line and number of lines and close file at the end
    {
        while (getline(file, line))
        {
            cout << line << "   size of line: " << line.size() << '\n';
            if(line.size() > MAX_WIDTH){file.close(); return 3;}//too many chars in line
            buffer.push_back(line);

        }

        //check if size of vector is greater then max num lines return 2
        cout << "size of buffer: " << buffer.size() << '\n';
        if(buffer.size() > MAX_LINES){file.close(); return 2;}
        //if everything returned normally
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

   
    string fileName(argv[1]); // save filename to a string var, run it through the file function
    vector<string> buffer; //main buffer of program 
    int openFileStatus = openFile(fileName, buffer);//returns 0 for good and 1, 2, 3 for each type of failure

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