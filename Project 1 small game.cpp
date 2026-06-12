// Project 1 small game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;

enum enChoiceType { stone = 1, paper = 2, scissor = 3 };

short ReadNumber(string message)
{
    int Number = 0;
    cout << message;
    cin >> Number;

    return Number;
}

int RandomChoice(int from, int to)
{
    int Random;
    Random = rand() % (to - from + 1) + from;
    return (Random);

}

string CheckChoices(int Num)
{
    enChoiceType ChoiceType;
    ChoiceType = (enChoiceType)Num;

    switch (ChoiceType)
    {
    case enChoiceType::paper:
        return "paper";
        break;
    case enChoiceType::stone:
        return "stone";
        break;
    default:
        return "scissor";

    }

}

void ShowWinner(int Player,int Computer,int &PlayerWon,int &ComputerWon,int &DrawTime)
{
    if (Player == Computer)
    {
        cout << "[No Winner].\n";
        system("color 6F");
        DrawTime++;
    }
    else
    {
        if ((Player == 1 && Computer == 3) ||
            (Player == 2 && Computer == 1) ||
            (Player == 3 && Computer == 2))
        {
            cout << "Player.\n";
            system("color 2F");
            PlayerWon++;

        }
        else
        {
            cout << "Computer.\n";
            system("color 4F ");
            cout << "\a";
            ComputerWon++;
        }
    };

}

void ShowMenu(int Num,int &PlayerWon,int &ComputerWon,int &DrawTime)
{
                   

    for (int i = 1; i <= Num; i++)
    {
        cout << "\nRound[" << i << "] begins:\n\n";
        cout << "Your choice: [1]:stone, [2]:Paper, [3]:Scissor ?  ";
       int Player= (ReadNumber(""));
       cout <<"Player Choice : "<< CheckChoices(Player) << endl;

       int Computer = RandomChoice(1, 3);
       cout <<"Computer Choice : "<< CheckChoices(Computer) << endl; 

       cout << "round winner : ";
        ShowWinner(Player,Computer,PlayerWon,ComputerWon,DrawTime);
        cout << endl;
    }

}

string CalculatFinalWinner(int PlayerWon, int ComputerWon)
{
    if (PlayerWon > ComputerWon)
    {
        system("Color 2F");
        return "Player.";

    }

    else if (PlayerWon < ComputerWon)
    {
        system("Color 4F");
        return "Computer.";

    }

    else
    {
        system("color 6F");
        return "[No winner].";

    }
}

void ShowFinalReslualt(int NumberOfRound,int PlayerWon, int ComputerWon,int DrawTime)
{
    
    cout << "\n\t\t\t------------------------------------------------------------\n";
    cout << "\t\t\t\t\t\t+++Game Over+++\t\t\t\t\n";
    cout << "\n\t\t\t------------------------------------------------------------\n";
    cout << "\t\t\t-----------------------[Game Results]------------------------\n\n";
    cout << "\t\t\tGame round            : " << NumberOfRound << endl;
    cout << "\t\t\tPlayer won times      : " << PlayerWon << endl;
    cout << "\t\t\tComputer won times    : " << ComputerWon << endl;
    cout << "\t\t\tDraw times            : " << DrawTime << endl;
    cout << "\t\t\tFinal winner          :" << CalculatFinalWinner(PlayerWon, ComputerWon) << endl;
    cout << "\n\t\t\t------------------------------------------------------------\n";

}

void StartPlaying()
{
    short NumOfRound = ReadNumber("Enter number of rounds.");
    int PlayerWon = 0, ComputerWon = 0, DrawTimes = 0;

    ShowMenu(NumOfRound, PlayerWon, ComputerWon, DrawTimes);

    ShowFinalReslualt(NumOfRound,PlayerWon, ComputerWon, DrawTimes);

   

}

bool PlayAgain()
{
    string Koko = "";
    cout << "Do you want to play again ?yes/no.\n";
    cin >> Koko;
    if (Koko == "yes")
        return true;
    else
    {
        system("color 0F");
        return  false;
    }

}

void ResetScreen()
{
    system("cls");
    system("color 0f");
}

void Starts()
{
    do {
        ResetScreen();
        StartPlaying();

    } while (PlayAgain());
}


int main()
{
    srand(time(0)); 
    
    Starts();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
