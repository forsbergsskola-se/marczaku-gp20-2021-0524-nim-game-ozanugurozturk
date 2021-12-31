using namespace std;

#include <iostream>
#include <string>
#include <cmath>

int MatchSelect(int Num, int Total, string PlayerName) // I always get the total matches left for other player from here.
{
    if (Num > 0 && Num < 4)
    {
        Total -= Num;
    }
    else
    {
        cout << "Invalid Number, you missed your chance to decide how many matches to remove from the table" << endl;
        Num = rand() % 3 + 1;
        Total -= Num;
        cout << "Computer automaticly removed " << Num << " matches from the table for your turn." << endl;
    }
    if (Total == 0)
    {
        cout << "You win " << PlayerName << "' you are the winner!" << endl;
    }
    return Total;
}

bool GameFinished(int Total)
{
    if (Total >= 0) return false;
    else return true;
}

void GameLogicVsAi()
{
    int Total = 24;
    int Num;
    string Player1;
    string Player2 = "AI";

    cout << "There are 24 matches on the table, you may draw 1, 2 or 3 matches (not more, not less) the player.\n";
    cout << "You are playing against AI.\n";
    cout << "Who has right to take last match from the table is going to be winner.\n";
    cout << "Please enter your name as player 1.\n";
    cin >> Player1;
    while (!GameFinished(Total))
    {
        cout << "There are " << Total << " matches left." << endl;
        cout << Player1 << ", please enter the amount of matches that you want to remove from the table: " << endl;
        cin >> Num;

        Total = MatchSelect(Num, Total, Player1);

        if (Total == 0) break;
        
        if (Total <=3) //with this if clause I wanted to make sure that computer decides to finish the game while it can.
        {
            Num = Total;
        }
        else Num = rand() % 3 + 1;

        cout << Player2 << ", removed "<< Num<< " matches from the table : " << endl;
  

        Total = MatchSelect(Num, Total, Player2);
    }
}

void GameLogicVsFriend() 
{
    int Total = 24;
    int Num;
    string Player1;
    string Player2;

    cout << "There are 24 matches on the table, you may draw 1, 2 or 3 matches (not more, not less) the player.\n";
    cout << "Who has right to take last match from the table is going to be winner.\n";
    cout << "\n";
    cout << "Please enter your name as player 1.\n";
    cin >> Player1;
    cout << "\n";
    cout << "Please enter your name as player 2.\n";
    cin >> Player2;

    while (!GameFinished(Total))
    {
            cout << "\n";
            cout << "There are " << Total << " matches left."<< endl;
            for (int i = 0; i < Total-1; i++)
            {
                cout << "|";
            }
            cout << "\n";
            cout << Player1 << ", please enter the amount of matches that you want to remove from the table: " << endl;
            cin >> Num;

            Total = MatchSelect(Num, Total, Player1);

            if (Total == 0) break;

            cout << "\n";
            cout << "There are " << Total << " matches left." << endl;
            for (int i = 0; i < Total - 1; i++)
            {
                cout << "|";
            }
            cout << "\n";
            cout << Player2 << ", please enter the amount of matches that you want to remove from the table: " << endl;
            cin >> Num;

            Total = MatchSelect(Num, Total, Player2);
    }
}

int main()
{
    int gameMode;
    cout << "Hey, do you want to play with your friend or against computer!\n";
    cout << "Press ' 1 ' for playing with your friend, press ' 2 ' for playing against computer. \n";
    cin >> gameMode;
    cout << "\n";
    if (gameMode != 1 && gameMode != 2)
    {
        cout << "Invalid Input for game mode selection!\n";
    }
    else if (gameMode == 1)
    {
        GameLogicVsFriend();
    }
    else
    {
        GameLogicVsAi();
    }
}
