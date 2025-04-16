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

int minimax(bool isMax) {
    char winner = checkWinner();
    if (winner == P2) return 1;
    if (winner == P1) return -1;
    if (!isMoveLeft()) return 0;

    int best;
    if (isMax) {
        best = numeric_limits<int>::min();
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == EMPTY) {
                    board[i][j] = P2;
                    best = max(best, minimax(false));
                    board[i][j] = EMPTY;
                }
    } else {
        best = numeric_limits<int>::max();
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == EMPTY) {
                    board[i][j] = P1;
                    best = min(best, minimax(true));
                    board[i][j] = EMPTY;
                }
    }
    return best;
}

pair<int, int> randomMove() {
    cout<<"AI is playing easy mode...\n";
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
        cout<<row<<col<<endl;
    } while (board[row][col] != EMPTY);
    return {row, col};
}

pair<int, int> bestMove() {
    int bestVal = numeric_limits<int>::min();
    pair<int, int> move = {-1, -1};

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == EMPTY) {
                board[i][j] = P2;
                int moveVal = minimax(false);
                board[i][j] = EMPTY;
                if (moveVal > bestVal) {
                    move = {i, j};
                    bestVal = moveVal;
                }
            }
    return move;
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


void menuAI(){
    char choice;
    do{
        cout << "1. For Easy Play\n2. For Hard Play\n3. For Exit\n";
        cout << "Select AI diffculty level: ";\
        choice=getche();
        cout << "\n\n";
        if(choice== '1'){
            cout << "Tic-Tac-Toe (You = O, AI = X)\n";
            cout << "AI is playing easy mode...\n";
            cout << "Press any key to start...\n";
            getch();
            system("cls");
            playGame('E');
        }
        else if(choice == '2'){
            cout << "Tic-Tac-Toe (You = O, AI = X)\n";
            cout << "AI is playing hard mode...\n";
            cout << "Press any key to start...\n";
            getch();
            system("cls");
            playGame('H');
        }else if(choice == '3'){
            cout << "Exiting the game...\n";
            cout << "Thank you for playing!\n";
            cout << "Press any key to exit...\n";
            getch();
            exit(0);
        }else{
            cout << "Invalid choice. Please try again.\n";
            cout<<"Press any key to continue...\n";
            getch();
            system("cls");
        }
    }while(true);
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