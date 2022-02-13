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
#define MAX_SCREEN_HEIGHT 10 // number of lines displayed

struct moveInstruction
{
    string direction;
    int numMovments;
};

void insert(int row, int col, int topLine, stack<vector<string>> &undo, stack<vector<string>> &redo, vector<string> &buffer, string toInsert)
{
    undo.push(buffer);
    cout << "WHAT IS out before: " << buffer[row + topLine - 1] << '\n';
    if (col > (int)buffer[row + topLine - 1].size() - 1)
    {
        string tempString = buffer[row + topLine - 1];
        int wheretoinsert = ((int)buffer[row + topLine - 1].size() - 1);
        cout << "where:" << wheretoinsert << '\n';
        int howmanytoinsert = (col - wheretoinsert);
        cout << "howmany:" << howmanytoinsert << '\n';

        buffer[row + topLine - 1].insert(wheretoinsert, howmanytoinsert, 'X');
    }
    cout << "AIZE OF INPUT TO INSERT:" << (int)toInsert.size() << '\n';
    int spaceLeft = (MAX_WIDTH - 1) - col;
    cout << "Spaceleft:" << spaceLeft << '\n';
    int postionInsertString;
    if (spaceLeft >= (int)toInsert.size())
    {
        postionInsertString = (int)toInsert.size();
    }
    else
    {
        postionInsertString = spaceLeft + 1;
    }
    buffer[row + topLine - 1].replace(col, (postionInsertString), toInsert.substr(0, postionInsertString));
    // int postionInsertString =
    cout << "size of substr" << toInsert.substr(0, postionInsertString) << "::" << '\n';
    cout << "WHAT IS out after: " << buffer[row + topLine - 1] << '\n';
    int startingPoint = postionInsertString;
    string nextSub = toInsert.substr(startingPoint);
    col = 0;
    cout << "next string next line:" << nextSub << '\n';
    while ((int)nextSub.size() > 0)
    {
        if ((row + topLine > (int)buffer.size() - 1) && (row + topLine < MAX_LINES )) // might be one off
        {
            spaceLeft = (MAX_WIDTH - 1) - col;

            if (spaceLeft >= (int)nextSub.size())
            {
                postionInsertString = (int)nextSub.size();
            }
            else
            {
                postionInsertString = spaceLeft + 1;
            }
            buffer.push_back(nextSub.substr(0, postionInsertString));
            nextSub = nextSub.substr((postionInsertString));
             cout << "next string next line:" << nextSub << '\n';
            topLine++;
        }
        else
        {
            nextSub = "";
            cout << "this one ran" << '\n';
        }
    }
}
void move(int &row, int &col, int &topLine, moveInstruction &mover, vector<string> &buffer)
{

    if (mover.direction == "w")
    {
        if (row == 0 && topLine == 1)
        {
            return;
        }
        else if ((topLine) == (int)buffer.size())
        {
            topLine--;
            return;
        }
        else if (row == 0)
        {
            topLine--;
            return;
        }
        else
        {
            row--;
            return;
        }
    }
    else if (mover.direction == "s")
    {

        if (row == 0 && topLine == (int)buffer.size())
        {
            return;
        }
        else if ((row + topLine) == (int)buffer.size())
        {
            row--;
            topLine++;
            return;
        }
        else if (row == 9)
        {
            topLine++;
            return;
        }
        else
        {
            row++;
            return;
        }
    }
    else if (mover.direction == "a")
    {
        if (col == 0)
        {
            return;
        }
        else
        {
            col--;
            return;
        }
    }
    else if (mover.direction == "d")
    {
        if (col == (MAX_WIDTH - 1))
        {
            return;
        }
        else
        {
            col++;
            return;
        }
    }
}

void savefile(const string &saveFilename, const vector<string> &buffer)
{
    fstream savingFile;
    savingFile.open(saveFilename, fstream::in | fstream::out | fstream::trunc);
    int i;
    for (i = 0; i < (int)buffer.size(); i++)
    {
        savingFile << buffer[i] << "\n";
    }
    savingFile.close();
}
void quit(bool &exitStatus) // put freaking stack thing
{
    exitStatus = true;
}
int openFile(string fileName, vector<string> &buffer) // later add pass by ref for data struct
{
    string line;
    ifstream file(fileName);

    if (file.is_open()) // if statments to check size of each line and number of lines and close file at the end
    {
        while (getline(file, line))
        {
            // cout << line << "   size of line: " << line.size() << '\n';
            if (line.size() > MAX_WIDTH + 1)
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
            cout << rowCursor << right << setw(3) << (topLine + i) << "|" << buffer.at((topLine - 1) + i) << '\n';
        }
    }

    cout << right << setw(MAX_WIDTH + 5) << windowBorder << '\n'; // BOTTOM WINDOW BORDER
}

void input(bool &exitStatus, string &prevCommand, int &row, int &col, int &topLine, stack<vector<string>> &undo, stack<vector<string>> &redo, vector<string> &buffer)
{
    string currentCommand;
    // if statment if prev command is empty and current command is empty out that there is no prevoius command, otherwise
    //  if prev is full and and current is empty do prev if current not empty do current(this being the firsst thing in the if cascade)
    cout << "Enter command: ";
    getline(cin, currentCommand);
    cout << '\n';
    if (!currentCommand.empty())
    {
        // possible input bvalidation
        // splitting the string

        prevCommand = currentCommand;
    }
    else if (currentCommand.empty() && !prevCommand.empty())
    {
        currentCommand = prevCommand;
    }
    else
    {
        cout << "No previous command." << '\n';
        return;
    }

    // breaking up the string
    char first = currentCommand.at(0);
    if (first == 'q' || first == 's' || first == 'w' || first == 'a' || first == 'd' || first == 'i' || first == 'r' || first == 'u')
    {
        if (currentCommand.size() == 1) // if it is an input that needs to extra params then pass otherwise error
        {
            if (first == 'i')
            {
                cout << "Insert needs something to insert" << '\n';
                return;
            }
            else
            {
                // pass all the move instructions with 0 as amount
                moveInstruction mover;
                switch (first)
                {
                case 'q':
                    quit(exitStatus);
                    return;
                    break;
                case 's':
                    mover.direction = "s";
                    mover.numMovments = 0;
                    move(row, col, topLine, mover, buffer);
                    return;
                    break;
                case 'w':
                    mover.direction = "w";
                    mover.numMovments = 0;
                    move(row, col, topLine, mover, buffer);
                    return;
                    break;
                case 'a':
                    mover.direction = "a";
                    mover.numMovments = 0;
                    move(row, col, topLine, mover, buffer);
                    return;
                    break;
                case 'd':
                    mover.direction = "d";
                    mover.numMovments = 0;
                    move(row, col, topLine, mover, buffer);
                    return;
                    break;
                case 'r':
                    // redo func
                    return;
                    break;
                case 'u':
                    // undo func
                    return;
                    break;
                }
            }
        }
        else if (currentCommand.size() == 4 && (currentCommand.find("save") != string::npos)) // if size for and not
        {
            cout << "Save command must have a path" << '\n';
            return;
        }
        else if ((currentCommand.find("save") != string::npos) && (currentCommand.at(4) == ' ') && currentCommand.size() > 5)
        {
            string saveFilename = currentCommand.substr(currentCommand.find(" ") + 1);
            savefile(saveFilename, buffer);
            return;
        }
        else if (first == 'i' && currentCommand.size() > 2 && currentCommand.at(1) == ' ')
        {
            string toInsert = currentCommand.substr(currentCommand.find(" ") + 1);
            insert(row, col, topLine, undo, redo, buffer, toInsert);
            return;
        }
        else if (first == 'w' && currentCommand.size() > 2)
        {
            string numMovments = currentCommand.substr(2);
            moveInstruction mover;
            mover.numMovments = stoi(numMovments);
            mover.direction = "w";
            int i;
            for (i = 0; i < mover.numMovments; i++)
            {
                move(row, col, topLine, mover, buffer);
            }
            return;
        }
        else if (first == 'a' && currentCommand.size() > 2)
        {
            string numMovments = currentCommand.substr(2);
            moveInstruction mover;
            mover.numMovments = stoi(numMovments);
            mover.direction = "a";
            int i;
            for (i = 0; i < mover.numMovments; i++)
            {
                move(row, col, topLine, mover, buffer);
            }
            return;
        }
        else if (first == 's' && currentCommand.size() > 2)
        {
            string numMovments = currentCommand.substr(2);
            moveInstruction mover;
            mover.numMovments = stoi(numMovments);
            mover.direction = "s";
            int i;
            for (i = 0; i < mover.numMovments; i++)
            {
                move(row, col, topLine, mover, buffer);
            }
            return;
        }
        else if (first == 'd' && currentCommand.size() > 2)
        {
            string numMovments = currentCommand.substr(2);
            moveInstruction mover;
            mover.numMovments = stoi(numMovments);
            mover.direction = "d";
            int i;
            for (i = 0; i < mover.numMovments; i++)
            {
                move(row, col, topLine, mover, buffer);
            }
            return;
        }
    }
    else
    {
        cout << "\"" << currentCommand << "\" "
             << "is not a recognized command" << '\n';
        return;
    }

    // if first part is q set thing to true, if first part is w a s d move w a s d, and if theres a number after
    //  if s then call save and move filename to func and save, if i then call insert and move string section. For undo redo pass a number after(for all of these you may need to pass more vars)
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
        try
        {
            input(exitStatus, prevCommand, row, col, topLine, undo, redo, buffer);
        }
        catch (const std::exception &ex)
        {
            cout << "SoMeThInG wEnT WoNg" << '\n';
        }
    }

    cout << "Goodbye!" << '\n';
    return 0;
}