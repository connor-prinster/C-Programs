#include <iostream>
#include <iomanip>

#include "FilmStats.h"

using namespace std;

enum MenuOption
{
  SELECT_INPUT_FILE = 1,
  FILM_BY_RANK = 2,
  TOTAL_BY_RANGE = 3,
  AVERAGE_BY_RANGE = 4,
  QUIT = 5
};

void printMenu(void);
MenuOption getInput(void);

int main()
{
  FilmStats stats;
  MenuOption option;

  printMenu();

  do
  {
    option = getInput();

    switch (option)
    {
      case SELECT_INPUT_FILE:
      {
        string inputFile;
        cout << "Input file: ";
        cin >> inputFile;
        cout << endl;
        stats.processFile(inputFile) ? cout << "Successfully opened file: " : cout << "Failed to open file: ";
        cout << inputFile << endl;
      }
      break;

      case FILM_BY_RANK:
      {
        int rank;
        cout << "Rank: ";
        cin >> rank;
        cout << endl;

        Film rankFilm = stats.getFilmByRank(rank);
        cout << "Rank " << rank << ": " << rankFilm.releaseYear << " - " << rankFilm.title << endl;
      }
      break;

      case TOTAL_BY_RANGE:
      {
        int first;
        int second;
        cout << "Range: ";
        cin >> first >> second;
        cout << endl;

        streamsize initPrecision = std::cout.precision();
        cout << "Total of films " << first << " to " << second;
        cout << fixed << setprecision(2) << ": $" << stats.getTotalOfFilms(first, second) << endl;
        cout.unsetf(ios_base::fixed);
        cout << setprecision(initPrecision);
      }
      break;

      case AVERAGE_BY_RANGE:
      {
        int first;
        int second;
        cout << "Range: ";
        cin >> first >> second;
        cout << endl;

        streamsize initPrecision = std::cout.precision();
        cout << "Average of films " << first << " to " << second;
        cout << fixed << setprecision(2) << ": $" << stats.getAverageOfFilms(first, second) << endl;
        cout.unsetf(ios_base::fixed);
        cout << setprecision(initPrecision);
      }
      break;
    }

    cout << endl;
  } while (option != QUIT);

  cout << "Goodbye!\n";

  return 0;
}

void printMenu(void)
{
  cout << "1. Select input file\n";
  cout << "2. Get film by rank\n";
  cout << "3. Get total by range\n";
  cout << "4. Get average by range\n";
  cout << "5. Quit\n";
}

MenuOption getInput(void)
{
  cout << "Selection: ";

  int selection;
  cin >> selection;
  cout << endl;

  return MenuOption(selection);
}
