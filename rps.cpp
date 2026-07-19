#include <iostream>
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

int main() 
{
    return 0;
}