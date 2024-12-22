#include <iostream>
using namespace std;

// Structure to hold player score details
struct PlayerScore {
    string name;
    int score;
};


    // Display the game title
    void displayGameName() {
        cout << "=====================================\n";
        cout << "     Welcome to the Number Guessing Game\n";
        cout << "=====================================\n";
    }

int main() {
    NumberGuessingGame game;
    string playerName;

    game.displayGameName();

    cout << "Enter your name: ";
    cin >> playerName;

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
