/************************
* A#: A02095542
* Course: CS1400
* CS1400 Section: 1
* CS1405 Section: 3
* HW#: 3
***********************/

#include <iostream>

using namespace std;

char var;

int main()
{
  cout << "Is it an object?" << endl;
  cin >> var;
  if (var == 'y')
  {
    cout << "Can you eat it?" << endl;
    cin >> var;
    if (var == 'y')
    {
      cout << "Eat it." << endl;
      cout << "Was it good?" << endl;
      cin >> var;
      if (var == 'y')
      {
        cout << "Wag your tail." << endl;
      }
      else
      {
        cout << "Puke it out." << endl;
        cout << "Re-eat it." << endl;
      }
    }
    else
    {
      cout << "Is it a tennis ball?" << endl;
      cin >> var;
      if(var == 'y')
      {
        cout << "Pick it up." << endl;
        cout << "Return to owner." << endl;
      }
      else
      {
        cout << "Bark at it." << endl;
      }
    }
  }
  else
  {
    cout << "Is it a sound?" << endl;
    cin >> var;
    if(var == 'y')
    {
      cout << "Bark at it." << endl;
    }
    else
    {
      cout << "Ignore it." << endl;
    }
  }

  return 0;
}


