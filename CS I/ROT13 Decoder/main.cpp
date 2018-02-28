/************************
* A#: A02095542
* Course: CS1400
* CS1400 Section: 1
* CS1405 Section: 3
* HW#: 6
***********************/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ofstream exitfile;
  ifstream enterfile;
  char secretMessage;
  enterfile.open("secretMessage.txt");
  exitfile.open("decodedMessage.txt");
  do
  {
    enterfile.get(secretMessage);
    if(!enterfile.eof())
    {
      if (secretMessage >= 'a' && secretMessage <= 'm')
      {
        exitfile << static_cast<char>(secretMessage + 13);
      } else if (secretMessage >= 'n' && secretMessage <= 'z')
      {
        exitfile << static_cast<char>(secretMessage - 13);
      } else if (secretMessage >= 'A' && secretMessage <= 'M')
      {
        exitfile << static_cast<char>(secretMessage + 13);
      } else if (secretMessage >= 'N' && secretMessage <= 'Z')
      {
        exitfile << static_cast<char>(secretMessage - 13);
      } else
      {
        exitfile << secretMessage;
      }
    }
  } while (enterfile);
  exitfile.close();
  return 0;
}