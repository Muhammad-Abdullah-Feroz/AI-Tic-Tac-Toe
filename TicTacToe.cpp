#include <iostream>
#include <conio.h>

using namespace std;

const char P1 = 'O';
const char P2 = 'X';
const char EMPTY = ' ';

char board[3][3];

void initBoard()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            board[i][j] = EMPTY;
        }
    }
}

void drawBoard()
{
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << " ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];
            if (j < 2)
                cout << " | ";
        }
        if (i < 2)
        {
            cout << endl
                 << "---+---+---" << endl;
        }
    }
    cout << endl;
}

bool isMoveLeft()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == EMPTY)
                return true;
        }
    }
    return false;
}

char checkWinner()
{
    // Check rows
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != EMPTY)
            return board[i][0];

    // Check columns
    for (int j = 0; j < 3; j++)
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != EMPTY)
            return board[0][j];

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != EMPTY)
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != EMPTY)
        return board[0][2];

    // No winner
    return EMPTY;
}



int main()
{

    _getch();
    return 0;
}