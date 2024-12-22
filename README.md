# Number Guessing Game

 Project Overview
The **Number Guessing Game** is a simple yet entertaining console-based game where players attempt to guess a randomly generated secret number within a specified range. The game offers multiple difficulty levels and maintains a high score leaderboard to track the best performances.

---

  Goals of the Project
The primary goals of this project are:
1. **Provide an engaging user experience**:
   - Include varying difficulty levels to cater to different skill levels.

2. **Practice fundamental programming concepts**:
   - Implement core concepts such as control structures, input/output, and random number generation.
   - Demonstrate the use of data structures (e.g., `vector`) and algorithms (e.g., sorting).

3. **File handling for persistence**:
   - Save and retrieve high scores to/from a text file, allowing for persistent data across game sessions.

4. **Enhance error handling and input validation**:
   - Provide feedback for invalid inputs to ensure a smooth gameplay experience.

5. **Foster code readability and maintainability**:
   - Write well-commented and clean code.

---

Features
- **Multiple Difficulty Levels**:
  - Easy: Guess numbers between 1-50 with 15 attempts.
  - Medium: Guess numbers between 1-100 with 10 attempts.
  - Hard: Guess numbers between 1-200 with 7 attempts.

- Dynamic Secret Number Generation**:
  - A new random number is generated for each game session.

- **Input Validation**:
  - Ensures that players enter valid guesses within the specified range.

- **High Score Leaderboard**:
  - Stores player scores in a text file (`scores.txt`) for future reference.
  - Displays the top 5 scores in ascending order of attempts.

- **Error Handling**:
  - Graceful handling of invalid inputs and file access errors.

---

## How to Run the Project
1. Clone or download this repository to your local machine.
2. Compile the code using a C++ compiler:
   ```bash
   g++ -o NumberGuessingGame NumberGuessingGame.cpp
