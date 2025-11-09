#include <iostream>
#include <cstdlib>
#include <ctime>

enum Choice {
    ROCK = 1,
    PAPER = 2,
    SCISSORS = 3
};

std::string choiceToString(Choice choice) {
    switch (choice) {
        case ROCK: return "Rock";
        case PAPER: return "Paper";
        case SCISSORS: return "Scissors";
        default: return "Invalid Choice";
    }
}

void playRPS() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    std::cout << "--- Rock, Paper, Scissors Game ---" << std::endl;
    std::cout << "Enter your choice (1=Rock, 2=Paper, 3=Scissors): ";
    
    int playerInput;
    std::cin >> playerInput;

    if (playerInput < 1 || playerInput > 3) {
        std::cout << "Invalid input. Please enter 1, 2, or 3." << std::endl;
        return;
    }

    Choice playerChoice = static_cast<Choice>(playerInput);

    int computerChoiceInt = (std::rand() % 3) + 1;
    Choice computerChoice = static_cast<Choice>(computerChoiceInt);

    std::cout << "\nYou chose: " << choiceToString(playerChoice) << std::endl;
    std::cout << "Computer chose: " << choiceToString(computerChoice) << std::endl;
    std::cout << "--- Result ---" << std::endl;

    if (playerChoice == computerChoice) {
        std::cout << "**It's a Tie!**" << std::endl;
    } else if (
        (playerChoice == ROCK && computerChoice == SCISSORS) ||
        (playerChoice == PAPER && computerChoice == ROCK) ||
        (playerChoice == SCISSORS && computerChoice == PAPER)
    ) {
        std::cout << "**You Win!** " << choiceToString(playerChoice) << " beats " << choiceToString(computerChoice) << "." << std::endl;
    } else {
        std::cout << "**Computer Wins!** " << choiceToString(computerChoice) << " beats " << choiceToString(playerChoice) << "." << std::endl;
    }
}

int main() {
    playRPS();
    return 0;
}