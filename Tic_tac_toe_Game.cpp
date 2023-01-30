#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

const int gridSize = 3;
string Names[2];
char board[gridSize][gridSize] = 
{
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

bool isWinner(char symbol);
bool checkRows(char symbol);
bool checkColumns(char symbol);
bool checkDiagonals(char symbol);
void DisplayData();
void boardFrame();
void Header();
char gameMenu();

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

main()
{
    char option = ' ';
    while(true)
    {
        system("cls");
        Header();
        option = gameMenu();
        if(option == '1')
        {
            system("cls");
            DisplayData();
        }
        else if(option == '2')
        {
            system("cls");
            Header();
            cout <<endl;
            cout << "   It is the simple Tik Tak Toe game. First you should enter both the players names. It provide you a frame like," <<endl;
            boardFrame();
            cout << "   Here you can see numbers from 1 to 9. It is the block numbers. The game will ask you the block number where you" <<endl;
            cout << "   want to put your symbol. When the three same symbols arrange consecutively. One player must won the game. If it" <<endl;
            cout << "   is not happen then the game will draw." <<endl;
            
            cout << "   Press any key to continue..." <<endl;
            getch();
            system("cls");
        }
        else if(option == '3')
        {
            system("cls");
            break;
        }
        else
        {
            SetConsoleTextAttribute(h,4);
            cout << "   Invalid Input" <<endl;
            SetConsoleTextAttribute(h,15);
            cout << "   Press any key to continue...";
            getch();
        }
    }
}
bool isWinner(char symbol)
{
    if(checkRows(symbol) || checkColumns(symbol) || checkDiagonals(symbol))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool checkRows(char symbol)
{
    for(int i = 0; i < 3; i++)
    {
        int count = 0;   
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == symbol)
            {
            count++;
            }
            if(count == 3)
            {
                return 1;
            }
        }
    }
    return 0;
}
bool checkColumns(char symbol)
{
    for(int i = 0; i < 3; i++)
    {
        int count = 0;   
        for(int j = 0; j < 3; j++)
        {
            if(board[j][i] == symbol)
            {
            count++;
            }
            if(count == 3)
            {
                return 1;
            }
        }
    }
    return 0;
}
bool checkDiagonals(char symbol)
{
    int count = 0;
    for(int i = 0; i < 3; i++)
    {
        if(board[i][i] == symbol)
        {
            count++; 
        }
    }
    if(count == 3)
    {
        return 1;
    }
    count = 0;
    for(int i = 0,j = 2; i < 3; i++,j--)
    {
        if(board[i][j] == symbol)
        {
            count++; 
        }
    }
    if(count == 3)
    {
        return 1;
    }
    return 0;
}
void DisplayData()
{
    Header();
    cout << endl;
    cout << endl;
    cout << "   Let's Start Game..." <<endl;
    int count = 0;
    char choice = 'X';
    for(int i = 0; i < 2; i++)
    {
        cout << "   Enter Player " << i+1 << " Name..................";
        cin.ignore();
        getline(cin,Names[i]);
        cout << "   Your symbol to play is " << choice <<endl;
        choice = 'O';
    }
    cout <<endl;
    cout << "   Let's Start Game" <<endl;
    cout << "   Press any key to continue...";
    getch();
    int increment = 0;
    int noOfTurns = 0;
    system("cls");
    char turn;
    while(true)
    {
        Header();
        boardFrame();
        cout << endl;
        cout << "   "<< Names[0] << "'s turn..." <<endl;
        cout << "   Enter coordinates(e.g 1 or 2) ";
        cin >> turn;    
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(turn == board[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
        noOfTurns++;
        Header();
        boardFrame();
        system("cls");
        if(isWinner('X'))
        {
            Header();
            boardFrame();
            SetConsoleTextAttribute(h,2);
            cout << endl;
            cout << "   " << Names[0] << " is Winner   "<<endl;
            SetConsoleTextAttribute(h,15);
            cout << "   Press any key to continue...";
            getch();
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    board[i][j] = increment+'1';
                    increment++;
                }
            }
            break;
        }
        else if(isWinner('O'))
        {
            Header();
            boardFrame();
            SetConsoleTextAttribute(h,2);
            cout << endl;
            cout << "   " << Names[1] << " is Winner   " <<endl;
            SetConsoleTextAttribute(h,15);
            cout << "   Press any key to continue...";
            getch();
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    board[i][j] = increment+'1';
                    increment++;
                }
            }
            break;
        }
        if(noOfTurns == 9)
        {
            Header();
            boardFrame();
            SetConsoleTextAttribute(h,2);
            cout << "   **********************************"<<endl;
            cout << "   *            Draw Match          *" <<endl;
            cout << "   **********************************"<<endl;
            SetConsoleTextAttribute(h,15);
            cout << "   Press any key to continue...";
            getch();
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    board[i][j] = increment+'1';
                    increment++;
                }
            }
            break;
        }
        turn = '0';
        Header();
        boardFrame();
        cout << endl;
        cout << "   " << Names[1] << "'s turn..." <<endl;
        cout << "   Enter coordinates(e.g 1 or 2) ";
        cin >> turn;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[i][j] == turn)
                {
                    board[i][j] = 'O';
                }
            }
        }
        noOfTurns++;
        Header();
        boardFrame();
        system("cls");
        if(isWinner('X'))
        {
            Header();
            boardFrame();
            SetConsoleTextAttribute(h,2);
            cout << endl;
            cout << "   " << Names[0] << " is Winner   "<<endl;
            SetConsoleTextAttribute(h,15);
            cout << "   Press any key to continue...";
            getch();
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    board[i][j] = increment+'1';
                    increment++;
                }
            }
            break;
        }
        else if(isWinner('O'))
        {
            Header();
            boardFrame();
            SetConsoleTextAttribute(h,2);
            cout << endl;
            cout << "   " << Names[1] << " is Winner   " <<endl;
            SetConsoleTextAttribute(h,15);
            cout << "   Press any key to continue...";
            getch();
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    board[i][j] = increment+'1';
                    increment++;
                }
            }
            break;
        }
    }
}
void boardFrame()
{
    cout << endl;
    cout << "     _____" << " " << "_____" << " " << "_____" <<endl;
    cout << "    |     " << "|" << "     " << "|" << "     |" <<endl;
    cout << "    |  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  |" <<endl;
    cout << "    |_____" << "|" << "_____" << "|" << "_____|" <<endl;
    cout << "    |     " << "|" << "     " << "|" << "     |" <<endl;
    cout << "    |  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  |" <<endl;
    cout << "    |_____" << "|" << "_____" << "|" << "_____|" <<endl;
    cout << "    |     " << "|" << "     " << "|" << "     |" <<endl;
    cout << "    |  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  |" <<endl;
    cout << "    |_____" << "|" << "_____" << "|" << "_____|" <<endl;
}
void Header()
{
    cout << " ______________________________________________________________________________________________________________________"<<endl;
    cout << "|                                                                                                                      |"<<endl;
    cout << "|                *************** ***********   *********  ***************       *****         *********                |"<<endl;
    cout << "|                ******| |****** ***** *****  * *******   ******| |******      * * * *       * *******                 |"<<endl ;
    cout << "|                      | |           | |     | |                | |           * *   * *     | |                        |"<<endl;
    cout << "|                      | |           | |     | |                | |          * ******* *    | |                        |"<<endl;
    cout << "|                      | |           | |     | |                | |         * ********* *   | |                        |"<<endl;
    cout << "|                      | |       ***** *****  * ********        | |        * *         * *   * ******                  |"<<endl;
    cout << "|                      ***       ***********   **********       ***       ***           ***   *********                |"<<endl;
    cout << "|                                                                                                                      |"<<endl;
    cout << "|                                         ***************  *************   *******                                     |"<<endl;
    cout << "|                                         ******| |****** |  *********  | | *******                                    |"<<endl;
    cout << "|                                               | |       | |         | | | |                                          |"<<endl;
    cout << "|                                               | |       | |         | | | *****|                                     |"<<endl;
    cout << "|                                               | |       | |         | | | |                                          |"<<endl;
    cout << "|                                               | |       |  *********  | | *******                                    |"<<endl;
    cout << "|                                               ***        *************   *******                                     |"<<endl;
    cout << "|______________________________________________________________________________________________________________________|"<<endl;
}

char gameMenu()
{
    cout <<endl;
    cout << "   Main Menu" << endl;
    cout << "   ---------" << endl;
    cout << "   1. Play Game" << endl;
    cout << "   2. About Game" << endl;
    cout << "   3. Exit" <<endl;
    cout << "   Your Option...";
    char option;
    cin >> option;
    return option;
}