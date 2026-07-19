#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enChoice {Rock = 1, Paper = 2, Scissors = 3};
enum enWinner {Player1 = 1, Computer = 2, Draw = 3};

struct stRound
{
    short roundNumber = 0;
    enChoice playerChoice;
    enChoice computerChoice;
    enWinner roundWinner;
};

struct stGameResult
{
    short totalRounds = 0;
    int playerWins = 0;
    int computerWins = 0;
    int draws = 0;
    enWinner finalWinner;
};

int readNumber(string message)
{
    int num;
    cout<<message;
    cin>>num;
    return num;
}

int randomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

enChoice getPlayerChoice()
{
    int choice;
    do
    {
        choice = readNumber("Your Choice: [1] Rock, [2] Paper, [3] Scissors? ");
    } while (choice < 1 || choice > 3);
    return (enChoice)choice;
}
enChoice getComputerChoice()
{
    return (enChoice)randomNumber(1, 3);
}

int main() 
{
    return 0;
}