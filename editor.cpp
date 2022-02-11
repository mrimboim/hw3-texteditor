#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;

#define MAX_WIDTH 20         // Maximum size of a line
#define MAX_LINES 30         // Maximum number of lines
#define MAX_SCREEN_HEIGHT 5// number of lines displayed

int openFile(string fileName, vector<string> &buffer) // later add pass by ref for data struct
{
    string line;
    ifstream file(fileName);

    if (file.is_open()) // if statments to check size of each line and number of lines and close file at the end
    {
        while (getline(file, line))
        {
            // cout << line << "   size of line: " << line.size() << '\n';
            if (line.size() > MAX_WIDTH)
            {
                file.close();
                return 3;
            } // too many chars in line
            buffer.push_back(line);
        }

        // check if size of vector is greater then max num lines return 2
        // cout << "size of buffer: " << buffer.size() << '\n';
        if (buffer.size() > MAX_LINES)
        {
            file.close();
            return 2;
        }
        // if everything returned normally
        file.close();
        return 0;
    }
    else
    {
        return 1;
    }
}

void display(const int &row, const int &col, const int &topLine, const vector<string> &buffer)
{
    // print out cursor postion using col
    // print out numbers with set w
    string colCursor(MAX_WIDTH, ' ');
    colCursor.at(col) = '*';
    // 5 spaces between left side and start of numbers
    cout << right << setw(MAX_WIDTH + 5) << colCursor << '\n'; // CHARCTER CURSOR

    string windowBorder;
    int j;
    int numStringThing = 0;
    for (j = 0; j < MAX_WIDTH; j++)
    {
        numStringThing++;
        if (numStringThing >= 10)
        {
            numStringThing = 0;
        }
        windowBorder.append(to_string(numStringThing));
    }

    cout << right << setw(MAX_WIDTH + 5) << windowBorder << '\n'; // TOP WINDOW BORDER
    int i;
    for (i = 0; i < MAX_SCREEN_HEIGHT; i++)
    {
        string rowCursor;
        if (i == row) // make sure row never goes below last line as in i + topLine is not greater then buffer.size
        {
            rowCursor = "*";
        }
        else
        {
            rowCursor = " ";
        }

        if ((size_t)(topLine + i) > buffer.size())
        {
            cout << rowCursor << right << setw(3) << (topLine + i) << " " << '\n';
        }
        else
        {
            cout << rowCursor << right << setw(3) << (topLine + i) << "|" << buffer.at((topLine - 1) + i ) << '\n';
        }
    }

    cout << right << setw(MAX_WIDTH + 5) << windowBorder << '\n'; // BOTTOM WINDOW BORDER
}

void input(bool &exitStatus, string &prevCommand, int &row, int &col, int &topLine, stack<vector<string>> &undo, stack<vector<string>> &redo)
{   
    string currentCommand;
    //if statment if prev command is empty and current command is empty out that there is no prevoius command, otherwise
    // if prev is full and and current is empty do prev if current not empty do current(this being the firsst thing in the if cascade)
    cout << "Enter command: " << '\n';
    cin >> currentCommand; 

    if(!currentCommand.empty())
    {
        //possible input bvalidation 
        //splitting the string 
        prevCommand = current_exception;

    }else if(currentCommand.empty() && !prevCommand.empty())
    {

    }else
    {
        cout 
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

    /*                       OPEN FILE
    ----------------------------------------------------------------*/
    string fileName(argv[1]);                        // save filename to a string var, run it through the file function
    vector<string> buffer;                           // main buffer of program
    int openFileStatus = openFile(fileName, buffer); // returns 0 for good and 1, 2, 3 for each type of failure

    if (openFileStatus == 1) // gets file status from open file func if all good continues to the loop
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

    /*                   MAIN LOOP
    --------------------------------------------------------------*/
    bool exitStatus = false;
    int row = 0;     // what row postion is curoser on from 0-max_screen_height
    int col = 0;     // not sure if should start from oone or zero
    int topLine = 1; // what line is at top of screen
    string prevCommand;
    stack<vector<string>> undo;
    stack<vector<string>> redo;
    while (exitStatus == false)
    {
        display(row, col, topLine, buffer); // buffer -> void func
        // input(exitStatus, prevCommand, row, col, topLine, undo, redo)-> void func
        exitStatus = true; // erase after input is able to take in exits 
    }

    cout << "Goodbye!" << '\n';
    return 0;
}