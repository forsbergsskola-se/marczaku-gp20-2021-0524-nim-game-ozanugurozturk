using namespace std;

#include <iostream>
#include <cstdlib>
#include <ctime>

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };

char current_Marker;
int current_Player;

void DrawBoard()
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;   
}

bool PlaceMarker(int slot)
{
    int row = slot / 3;
    int col;
    if (slot % 3 == 0)
    {
        row = row - 1;
        col = 2;
    }
    else
    {
        col = (slot % 3) - 1;
    }
    
    if (board[row][col] != 'x' && board[row][col] != 'o')
    {
        board[row][col] = current_Marker;
        return true;
    }
    else return false;
    
}

int Winner() 
{
    //cross win check
    if (board[1][1] == board[0][0] && board[1][1] == board[2][2])
    {
        return current_Player;
    }
    if (board[1][1] == board[2][0] && board[1][1] == board[0][2])
    {
        return current_Player;
    }
    for (int i = 0; i < 3; i++)
    {
        //row check
        if (board[i][0] == board[i][1] && board [i][1] == board[i][2])
        {
            return current_Player;
        }
        //column check
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return current_Player;
        }     
    }

    return 0;
}

void SwapPlayer() 
{
    if (current_Marker =='x'){
        current_Marker = 'o';
    }
    else current_Marker = 'x';
    

    if (current_Player == 1){
        current_Player = 2;
    }
    else current_Player = 1;
}  //consequent swap player during game

void GameLogicWithFriend() 
{
    cout << " Player 1, choose your marker ( 'x' or 'o' )";
    char marker_pl;
    cin >> marker_pl;

    current_Player = 1;
    current_Marker = marker_pl;

    DrawBoard();

    int player_Won;

    for (int i = 0; i < 9; i++)
    {
        cout << "It's player" << current_Player << "'s turn. Please enter the slot number that you want to put your mark.\n";
        cout << "Myslot is : ";
        int slot;
        cin >> slot;
        if (slot < 1 || slot > 9) {
            cout << "You entered unavailable value! Try between 1-9 for choosing the slot to put your marker."; i--;
            continue;
        }
        if (!PlaceMarker(slot)) {
            cout << "That slot was occupied before! Try another one."; i--;
            continue;
        }
        DrawBoard();
        player_Won = Winner();

        if (player_Won == 1) { cout << "Player 1 won!. Congrats!"; break;}
        if (player_Won == 2) { cout << "Player 2 won!. Congrats!"; break;}

        SwapPlayer();  
    }
    if (player_Won == 0)
    {
        cout << "The game is tied... Play again to beat eachother!"; 
        
    }
}

void GameLogicAgainstAi()
{
    cout << " Please choose your marker ( 'x' or 'o' )";
    char marker_pl;
    cin >> marker_pl;

    current_Player = 1;
    current_Marker = marker_pl;

    DrawBoard();

    int player_Won;

    for (int i = 0; i < 4; i++)
    {
        cout << "It's your turn. Please enter the slot number that you want to put your mark.\n";
        cout << "Myslot is : ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9)
        {
            cout << "You entered unavailable value! Try between 1-9 for choosing the slot to put your marker.";
            i--;
            continue;
        }

        if (!PlaceMarker(slot)) {
            cout << "That slot was occupied before! Try another one.";
            i--;
            continue;

        }

        DrawBoard();

        player_Won = Winner();

        if (player_Won == 1) { cout << "Player 1 won!. Congrats!"; break; }
        if (player_Won == 2) { cout << "Player 2 won!. Congrats!"; break; }

        SwapPlayer();
        srand(time(NULL));
        while (!PlaceMarker((rand() % (10 - 1 + 1)) + 1)) //getting different numbers with random
        {
            continue;
        }
        cout << "\n";
        cout << "The AI made it's own decision.\n";
        DrawBoard();

        SwapPlayer();
    }
    if (player_Won == 0)
    {
        cout << "The game is tied... Play again to beat eachother!";

    }
}

int main()
{
    int gameMode;
    cout << "Hey, do you want to play with your friend or against computer!\n";
    cout << "Press ' 1 ' for playing with your friend, press ' 2 ' for playing against computer. \n";
    cin >> gameMode;
        if (gameMode !=1 && gameMode !=2)
        {
            cout << "Invalid Input for game mode selection!\n";
        }
        else if (gameMode == 1)
        {
            GameLogicWithFriend();
        }
        else
        {
            GameLogicAgainstAi();
        }       
}
