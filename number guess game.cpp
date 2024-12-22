#include <iostream>
#include <fstream>  	 // For file handling
#include <vector>	// For using vectors
#include <algorithm>	// For sorting
#include <cstdlib>		// For random number generation
#include <ctime>		// For seeding random numbers with current time
using namespace std;

// Structure to hold player score details
struct PlayerScore {
    string name;
    int score;
};


// Comparator function to sort scores
bool compareScores(const PlayerScore &a, const PlayerScore &b) {
    return a.score < b.score; // Lower score (fewer attempts) is better
}

// NumberGuessingGame class
class NumberGuessingGame {
private:
    int secretNumber;
    int maxAttempts;
    int range;
    int attempts;

public:
    // Constructor initializes game settings
    NumberGuessingGame() : secretNumber(0), maxAttempts(10), range(100), attempts(0) {}


    // Display the game title
    void displayGameName() {
        cout << "=====================================\n";
        cout << "     Welcome to the Number Guessing Game\n";
        cout << "=====================================\n";
    }

// Set difficulty level
    void setDifficulty() {
        int choice;
        cout << "\nSelect Difficulty Level:\n";
        cout << "1. Easy   (1-50, 15 attempts)\n";
        cout << "2. Medium (1-100, 10 attempts)\n";
        cout << "3. Hard   (1-200, 7 attempts)\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1: range = 50; maxAttempts = 15; break; // Easy
            case 2: range = 100; maxAttempts = 10; break; // Medium
            case 3: range = 200; maxAttempts = 7; break; // Hard
            default: range = 100; maxAttempts = 10; break; // Default to Medium
        }
    }

    // Generate the secret number
    void generateNumber() {
        srand(time(0)); 
        secretNumber = rand() % range + 1; // Number between 1 and range
    }
    
     // Play the game
    int playGame() {
        int guess;
        attempts = 0;
        cout << "\nGuess the number between 1 and " << range << ".\n";

        while (attempts < maxAttempts) {
            cout << "Attempt " << attempts + 1 << "/" << maxAttempts << ": ";
            cin >> guess;

            // Input validation with exception handling
            if (cin.fail() || guess < 1 || guess > range) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! Please enter a number between 1 and " << range << ".\n";
                continue;
            }

            attempts++;

            if (guess == secretNumber) {
                cout << "Congratulations! You guessed the correct number in " << attempts << " attempts!\n";
                return attempts; // Return score
            } else if (guess < secretNumber) {
                cout << "Too low! Try again.\n";
            } else {
                cout << "Too high! Try again.\n";
            }
        }

        cout << "Sorry, you've used all attempts! The correct number was: " << secretNumber << ".\n";
        return maxAttempts; // Max score if failed
    }

    // Save score to file
    void saveScore(const string &playerName, int score) {
        ofstream file("scores.txt", ios::app); // Open file in append mode
        if (file.is_open()) {
            file << playerName << " " << score << "\n";
            file.close();
        } else {
            cerr << "Error: Unable to save score to file.\n";
        }
    }

    // Display high scores
    void displayHighScores() {
        ifstream file("scores.txt");
        vector<PlayerScore> scores;
        PlayerScore temp;

        if (file.is_open()) {
            while (file >> temp.name >> temp.score) {
                scores.push_back(temp);
            }
            file.close();

            // Sort scores
            sort(scores.begin(), scores.end(), compareScores);

            cout << "\n===== High Scores =====\n";
            for (size_t i = 0; i < scores.size() && i < 5; i++) {
                cout << i + 1 << ". " << scores[i].name << " - " << scores[i].score << " attempts\n";
            }
            cout << "========================\n";
        } else {
            cerr << "Error: Unable to read scores from file.\n";
        }
    }
};

int main() {
    NumberGuessingGame game;
    string playerName;

    game.displayGameName();

    cout << "Enter your name: ";
    cin >> playerName;  // Get the player's name

    // Set game difficulty
    game.setDifficulty(); 

    // Start the game
    game.generateNumber();
    int score = game.playGame();

    // Save the score
    game.saveScore(playerName, score);

    // Display high scores
    game.displayHighScores();

    return 0;
}
