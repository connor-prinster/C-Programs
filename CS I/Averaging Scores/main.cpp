/************************
* A#: A02095542
* Course: CS1400
* CS1400 Section: 1
* CS1405 Section: 3
* HW#: 2
***********************/

#include <iostream>
using namespace std;

int main()
{
  cout << "Score 1: ";
  float score1;
  cin >> score1;
  cout << endl;

  cout << "Score 2: ";
  float score2;
  cin >>  score2;
  cout << endl;

  cout << "Score 3: ";
  float score3;
  cin >> score3;
  cout << endl;

  cout << "Score 4: ";
  float score4;
  cin >> score4;
  cout << endl;

  cout << "Average: " << float((score1 + score2 + score3 + score4)/4) << endl;


  return 0;
}