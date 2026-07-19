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

enWinner roundWinner(stRound r)
{
    if (r.playerChoice == r.computerChoice)
        return enWinner::Draw;

    switch (r.playerChoice)
    {
    case enChoice::Rock:
        return (r.computerChoice == enChoice::Scissors)? enWinner::Player1 : enWinner::Computer;

    case enChoice::Paper:
        return (r.computerChoice == enChoice::Rock)? enWinner::Player1 : enWinner::Computer;

    case enChoice::Scissors:
        return (r.computerChoice == enChoice::Paper)? enWinner::Player1 : enWinner::Computer;
    
    default:
        return enWinner::Draw;
    }
    
}

string choiceName(enChoice choice)
{
    string choiceNames[3] = {"Rock", "Paper", "Scissors"};
    return choiceNames[choice - 1];
}
string winnerName(enWinner winner)
{
    string winnerNames[3] = { "Player1", "Computer", "No Winner (Draw)" };
    return winnerNames[winner - 1];
}

stRound playRound(int roundNumber)
{
    stRound round;
    round.roundNumber = roundNumber;
    round.playerChoice = getPlayerChoice();
    round.computerChoice = getComputerChoice();
    round.roundWinner = roundWinner(round);
    return round;
};

int readRound()
{
    int num;
    do
    {
        num = readNumber("How Many Rounds [1 - 10]? ");
    } while (num < 1 || num > 10);
    cout<<endl;

    return num; 
}

void printRound(stRound round)
{
    cout << "\n__________ Round [" << round.roundNumber << "] _________\n" << endl;
    
    cout << "Player1 Choice: " << choiceName(round.playerChoice) << endl;
    cout << "Computer Choice: " << choiceName(round.computerChoice) << endl;
    cout << "Round Winner: " << winnerName(round.roundWinner) << endl;

    cout << "______________________________\n" << endl;
}

int main() 
{
    return 0;
}