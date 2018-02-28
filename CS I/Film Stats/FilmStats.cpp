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

#include "FilmStats.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool FilmStats::processFile(string filedata)
{
  ifstream fin;
  fin.open(filedata);
  if(fin.is_open())
  {
    for(int i = 0; i < NUM_FILMS; i++)
    {
      getline(fin, stats[i].title, '#');
      fin >> stats[i].worldWideGross;
      fin >> stats[i].releaseYear;
      fin.ignore();
    }
    return true;
  }
  else
  {
    return false;
  }
}
//Read file contents into a member array of structs,
//return true if successful, false if file could not be opened


Film FilmStats::getFilmByRank(int ranked)
//Get film details by rank 1-50, return a Film
//struct with title "Invalid", 0.0 gross, and 0 year if out of bounds
{
  ranked--;
  if(ranked > 50 || ranked < 0)
  {
    Film broken;
    broken.title = "Invalid";
    broken.worldWideGross = 0.0;
    broken.releaseYear = 0;
    return broken;
  }
  return stats[ranked];
}

double FilmStats::getTotalOfFilms(int startRank, int endRank)
//Get the TOTAL gross for the films in the provided inclusive range,
//but only count values within the range of your array
{
  double total = 0;

  if(startRank < 1)
  {
    startRank = 1;
  }
  if(endRank > NUM_FILMS)
  {
    endRank = NUM_FILMS;
  }

  for(int i = startRank-1; i < endRank; i++)
  {
    double temp = 0;
    {
      temp = stats[i].worldWideGross;
      total += temp;
    }
  }
  return total;
}

double FilmStats::getAverageOfFilms(int startRank, int endRank)
//Get the AVERAGE gross for the films in the provided inclusive
//range, but only count values within the range of your array
{
  {
    double total = 0;

    if (startRank < 1)
    {
      startRank = 1;
    }
    if (endRank > NUM_FILMS)
    {
      endRank = NUM_FILMS;
    }

    for (int i = startRank - 1; i < endRank; i++)
    {
      double temp = 0;
      {
        temp = stats[i].worldWideGross;
        total += temp;
      }
    }

    double diff = (endRank-startRank)+1;

    return total / diff;
  }
}


//Avatar#	2787965087	2009