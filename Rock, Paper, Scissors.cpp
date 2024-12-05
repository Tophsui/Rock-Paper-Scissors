#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream> // For file handling

using namespace std;

// Function prototypes
void displayIntro();
int getComputerChoice();
string getUserChoice();
void displayChoices(int, string);
bool determineWinner(int, string, string&, string&);
void saveSessionToFile(const string& userChoice, const string& computerChoice, const string& result);
void displayPreviousSessions();
void displayMenu();

int main() {
    // Display introduction to the game
    displayIntro();

    // Loop to allow multiple rounds
    bool gameContinues = true;
    while (gameContinues) {
        displayMenu();

        int choice;
        cin >> choice;

        if (choice == 1) { // Start a new session
            // Get the computer's choice (random)
            int computerChoice = getComputerChoice();

            // Get the user's choice
            string userChoice = getUserChoice();

            // Display both players' choices
            displayChoices(computerChoice, userChoice);

            // Determine and display the winner
            string result;
            gameContinues = determineWinner(computerChoice, userChoice, result, userChoice);

            // Save session result to file
            saveSessionToFile(userChoice, result, result);
        }
        else if (choice == 2) { // Display previous sessions
            displayPreviousSessions();
        }
        else if (choice == 3) { // Exit the game
            gameContinues = false;
            cout << "Thank you for playing!" << endl;
        }
        else {
            cout << "Invalid option. Please try again." << endl;
        }
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
bool determineWinner(int computerChoice, string userChoice, string& result, string& userChoice) {
    if ((computerChoice == 1 && userChoice == "scissors") ||
        (computerChoice == 2 && userChoice == "rock") ||
        (computerChoice == 3 && userChoice == "paper")) {
        // Computer wins
        cout << "Computer wins!\n";
        result = "Computer wins!";
    }
    else if ((computerChoice == 1 && userChoice == "rock") ||
        (computerChoice == 2 && userChoice == "paper") ||
        (computerChoice == 3 && userChoice == "scissors")) {
        // It's a draw
        cout << "It's a draw!\n";
        result = "Draw!";
    }
    else {
        // User wins
        cout << "You win!\n";
        result = "You win!";
    }

    return true; // session over, no need to continue the game
}

// Function to save the session results to the file
void saveSessionToFile(const string& userChoice, const string& result) {
    ofstream outFile("sessions.txt", ios::app); // Open file in append mode
    if (outFile.is_open()) {
        outFile << "User choice: " << userChoice << ", Result: " << result << endl;
        outFile.close();
    }
    else {
        cout << "Error opening file for saving session!" << endl;
    }
}

// Function to display previous sessions from the file
void displayPreviousSessions() {
    ifstream inFile("sessions.txt"); // Open file for reading
    string line;

    if (inFile.is_open()) {
        cout << "\nPrevious Sessions:\n";
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }
    else {
        cout << "No previous sessions found." << endl;
    }
}

// Function to display the menu
void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Start a new session\n";
    cout << "2. Display previous sessions\n";
    cout << "3. Exit\n";
    cout << "Please choose an option: ";
}
