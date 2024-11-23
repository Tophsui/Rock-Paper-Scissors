#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Function prototypes
void displayIntro();
int getComputerChoice();
string getUserChoice();
void displayChoices(int, string);
void determineWinner(int, string);

int main() {
    // Display introduction to the game
    displayIntro();

    // Loop to allow multiple rounds until a winner is determined
    bool gameContinues = true;
    while (gameContinues) {
        // Get the computer's choice (random)
        int computerChoice = getComputerChoice();

        // Get the user's choice
        string userChoice = getUserChoice();

        // Display both players' choices
        displayChoices(computerChoice, userChoice);

        // Determine and display the winner
        gameContinues = determineWinner(computerChoice, userChoice);
    }

    return 0;
}

// Function to display the introductory message
void displayIntro() {
    cout << "Welcome to Rock, Paper, Scissors!\n";
    cout << "You will play against the computer.\n";
    cout << "Choose rock, paper, or scissors and try to beat the computer!\n";
}

// Function to get the computer's choice
int getComputerChoice() {
    // Randomly choose a number between 1 and 3 for the computer's choice
    srand(time(0));  // seed for random number generation
    return rand() % 3 + 1;
}

// Function to get the user's choice
string getUserChoice() {
    string choice;
    bool validChoice = false;

    // Loop until the user enters a valid choice
    while (!validChoice) {
        cout << "Enter your choice (rock, paper, or scissors): ";
        cin >> choice;

        if (choice == "rock" || choice == "paper" || choice == "scissors") {
            validChoice = true;
        }
        else {
            cout << "Invalid choice, please choose rock, paper, or scissors.\n";
        }
    }
    return choice;
}

// Function to display the choices of both the computer and the user
void displayChoices(int computerChoice, string userChoice) {
    // Map the computer's choice to rock, paper, or scissors
    string computerChoiceStr;
    if (computerChoice == 1) {
        computerChoiceStr = "rock";
    }
    else if (computerChoice == 2) {
        computerChoiceStr = "paper";
    }
    else {
        computerChoiceStr = "scissors";
    }

    // Display both choices
    cout << "Computer chose: " << computerChoiceStr << endl;
    cout << "You chose: " << userChoice << endl;
}

// Function to determine the winner and return true for a draw (to play again)
bool determineWinner(int computerChoice, string userChoice) {
    if ((computerChoice == 1 && userChoice == "scissors") ||
        (computerChoice == 2 && userChoice == "rock") ||
        (computerChoice == 3 && userChoice == "paper")) {
        // Computer wins
        cout << "Computer wins!\n";
        return false;
    }
    else if ((computerChoice == 1 && userChoice == "rock") ||
        (computerChoice == 2 && userChoice == "paper") ||
        (computerChoice == 3 && userChoice == "scissors")) {
        // It's a draw
        cout << "It's a draw! Let's play again.\n";
        return true;
    }
    else {
        // User wins
        cout << "You win!\n";
        return false;
    }
}