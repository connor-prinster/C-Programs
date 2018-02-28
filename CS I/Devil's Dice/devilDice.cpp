/************************
* A#: A99999999
* Course: CS1400
* CS1400 Section: 1
* CS1405 Section: 1
* HW#: 7
***********************/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// Function prototypes
void playGame(void);
int roll(bool isPlayerTurn);
char getActionFromUser(void);
void printDisplay(int playerScore, int playerTurnPoints, int devilScore);
int devilTurn(int playerScore, int devilScore);
void updateWinHistory(bool playerWon);

/**
 * Main entry point for the Devil's Dice game
 * @return 0 on successful execution
 */
int main()
{
#ifdef JARVIS
  srand(0);
#else
  srand(time(NULL));
#endif

  playGame();

  return 0;
}

/**
 * Plays a game of Devil's Dice
 */
void playGame(void)
{
  int devilTotalScore = 0;
  int playerTotalScore = 0;
  int playerCurrentTurnPoints = 0;
  bool devilGetsATurn = false;
  bool didPlayerWin = false;
  bool isGameOver = false;

  cout << "---- Welcome to Devil's Dice! ----" << endl;

  while (!isGameOver)
  {
    char action = getActionFromUser();

    // TODO - Handle player actions here, updating provided variables when needed



    if (devilGetsATurn)
    {
      devilTotalScore += devilTurn(playerTotalScore, devilTotalScore);
      devilGetsATurn = false;
    }

    if (!isGameOver)
    {
      printDisplay(playerTotalScore, playerCurrentTurnPoints, devilTotalScore);
    }

    if (devilTotalScore >= 100)
    {
      cout << "Devil Wins!" << endl;
      isGameOver = true;
    }
  }

  updateWinHistory(didPlayerWin);
}

/**
 * Rolls a dice, returning a random value between 1 and 6
 * @param isPlayerTurn True if it is the player rolling, false otherwise
 * @return Random dice roll
 */
int roll(bool isPlayerTurn)
{
  int roll = 0;

  // TODO - Assign random dice roll and print out appropriate message

  return roll;
}

/**
 * Prompts for and gets an action from the user
 * @return The action selected by the user
 */
char getActionFromUser(void)
{
  char input;

  // TODO - Prompt for and get user input

  return input;
}

/**
 * Prints out the Devil's Dice display
 * @param playerScore Current total player score
 * @param playerTurnPoints Points player has accumulated so far this turn
 * @param devilScore Current total devil's score
 */
void printDisplay(int playerScore, int playerTurnPoints, int devilScore)
{
  // TODO - Print out the nicely formatted display
}

/**
 * Updates the win/loss history stored in a file
 * @param playerWon True if the player won the game, false otherwise
 */
void updateWinHistory(bool playerWon)
{
  // TODO - Read out win history from file (if exists), update values, and write back to file
}

/**
 * The devil take's his turn
 * @param playerScore Current total player score
 * @param devilScore Current total devil score
 * @return The devil's new total score after his turn has completed
 */
int devilTurn(int playerScore, int devilScore)
{
  int devilTurnScore = 0;
  bool devilTurnOver = false;
  int devilGoal = 21;

  if (playerScore > devilScore)
  {
    devilGoal = 30;
  }

  cout << endl;

  while (!devilTurnOver)
  {
    if ((devilTurnScore < devilGoal) && (devilScore + devilTurnScore < 100))
    {
      int devilRoll = roll(false);

      if (devilRoll == 1)
      {
        devilTurnScore = 0;
        devilTurnOver = true;
      }
      else
      {
        devilTurnScore += devilRoll;
      }
    }
    else
    {
      devilTurnOver = true;
    }
  }

  cout << "Devil got " << devilTurnScore << " points" << endl << endl;
  return devilTurnScore;
}