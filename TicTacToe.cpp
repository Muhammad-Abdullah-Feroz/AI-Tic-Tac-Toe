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

void playP2P(){
    initBoard();
    // drawBoard();

    while(true){
        int row, col , move;
        char winner = EMPTY;
        while(true){
            system("cls");
            cout<<"Player 1 : O , Player 2 : X"<<endl;
            cout<<"Player 1's turn (O)";
            drawBoard();
            cout <<endl<< "Enter your move (1-9): ";
            cin >> move;
            if (move < 1 || move > 9)
            {
                cout << "Invalid move. Try again." << endl;
                continue;
            }
            row = (move - 1) / 3;
            col = (move - 1) % 3;
            if (board[row][col] != EMPTY)
            {
                cout << "Invalid move. Try again." << endl;
                continue;
            }
            board[row][col] = P1;
            break;
        }
        winner = checkWinner();
        if (winner != EMPTY)
        {
            system("cls");
            cout <<endl<< "Player 1 wins!" << endl;
            drawBoard();
            break;
        }

        while(true){
            system("cls");
            cout<<"Player 1 : O , Player 2 : X"<<endl;
            cout<<"Player 2's turn (X)";
            drawBoard();
            cout<<endl<<"Enter your move : ";
            cin >> move;
            if (move < 1 || move > 9)
            {
                cout << "Invalid move. Try again." << endl;
                continue;
            }
            row = (move - 1) / 3;
            col = (move - 1) % 3;
            if (board[row][col] != EMPTY)
            {
                cout << "Invalid move. Try again." << endl;
                continue;
            }
            board[row][col] = P2;
            break;
        }
        winner = checkWinner();
        if (winner != EMPTY)
        {
            system("cls");
            cout <<endl<< "Player 2 wins!" << endl;
            drawBoard();
            break;
        }
        if (!isMoveLeft()){
            system("cls");
            drawBoard();
            cout <<endl<< "It's a draw!" << endl;
            break;
        }
    }
}


void menu(){
    char choice;
    do{
        cout<<"1. Player vs Player\n2. Player vs AI\n3. Exit\n";
        cout<<"Select your choice: ";
        choice=getche();
        cout<<"\n\n";
        if(choice == '1'){
            cout<<"Player vs Player\n";	
            cout<<"Tic-Tac-Toe (P1 = O, P2 = X)\n";
            cout<<"Press any key to start...\n";
            getch();
            system("cls");
            playP2P();
        }else if(choice == '2'){
            cout<<"Player vs AI\n";
            cout<<"Tic-Tac-Toe (You = O, AI = X)\n";
            cout<<"Press any key to start...\n";
            getch();
            system("cls");
            // call AI menu
            // menuAI();
        }else if (choice == '3'){
            cout<<"Exiting the game...\n";
            cout<<"Thank you for playing!\n";
            cout<<"Press any key to exit...\n";
            getch();
            exit(0);
        }else{
            cout<<"Invalid choice. Please try again.\n";
            cout<<"Press any key to continue...\n";
            getch();
            system("cls");
        }
    }while(true);
}


int main()
{
    playP2P();
    _getch();
    return 0;
}