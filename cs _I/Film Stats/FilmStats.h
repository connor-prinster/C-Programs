/************************
* A#: A02095542
* Course: CS1400
* CS1400 Section: 1
* CS1405 Section: 3
* HW#: 12
***********************/

//
// Created by Connor Prinster on 4/8/2017.
//
#ifndef HW12_FILM_STATS_FILMSTATS_H
#define HW12_FILM_STATS_FILMSTATS_H

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

struct Film{
  string title;
  double worldWideGross;
  int releaseYear;
};


class FilmStats
{
public:
  bool processFile(string file);
  //Read file contents into a member array of structs,
  //return true if successful, false if file could not be opened
  Film getFilmByRank(int rank);
  //Get film details by rank 1-50, return a Film
  //struct with title "Invalid", 0.0 gross, and 0 year if out of bounds
  double getTotalOfFilms(int startRank, int endRank);
  //Get the TOTAL gross for the films in the provided inclusive range,
  //but only count values within the range of your array
  double getAverageOfFilms(int startRank, int endRank);
  //Get the AVERAGE gross for the films in the provided inclusive
  //range, but only count values within the range of your array

private:
  static const int NUM_FILMS = 50;
  Film stats[NUM_FILMS];
};

//1) When reading from the file you will need to use a combination of
// getline(), ifstream >> statements, and ignore

//2) The films are already in order from highest to least grossing in the
// input file

//3) Remember an array of size 50 starts at index 0 and ends at index 49!

//4) A requested range of ranks -10 to 54 should produce the same
// results as a range of 0 to 50, but you should never access an
// array index < 0 or >= 50!


#endif //HW12_FILM_STATS_FILMSTATS_H
