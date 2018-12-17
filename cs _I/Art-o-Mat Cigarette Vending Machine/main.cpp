/************************
* A#: A02095542
* Course: CS1400
* CS1400 Section: 1
* CS1405 Section: 3
* HW#: 5
***********************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  setprecision(2);
  cout << fixed;

  int luckystrike;                                         //Cigarette variables and their original counts
  luckystrike = 5;                                         //Quarters initialized as 0
  int camels;
  camels = 7;
  int gauloises;
  gauloises = 1;
  int pallmalls;
  pallmalls = 6;
  double quarters;
  quarters = 0;
  double bank;
  bank = 24.50;                                           //Where change is initialized as 0
  char maininput;

  cout << "s - report the machine status" << endl;          //Main menu
  cout << "d - drop in a quarter" << endl;
  cout << "1 - pull the 1st knob" << endl;
  cout << "2 - pull the 2nd knob" << endl;
  cout << "3 - pull the 3rd knob" << endl;
  cout << "4 - pull the 4th knob" << endl;
  cout << "r - restock the machine" << endl;
  cout << "q - quit" << endl;

  do
  {
    cin >> maininput;                                          //First variable "maininput"

    double totalchange;                                         //totalchange is the CHANGE (.25) value
    totalchange = quarters * .25;

    switch (maininput)                                        //Switch statement based on "maininput"
    {
      case 's':                                               //Report the machine status
        {
          cout << "1: " << luckystrike << " packs of Lucky Strikes" << endl;
          cout << "2: " << camels << " packs of Camels" << endl;
          cout << "3: " << gauloises << " packs of Gauloises" << endl;
          cout << "4: " << pallmalls << " packs of Pall Malls" << endl;
          cout << "You have " << fixed << setprecision(0) << quarters << " quarters to spend" << endl;
          cout << "There is $" << fixed << setprecision(2) << bank << " in the machine" << endl;
          break;
      }





      case 'd':                                              //Drop in a quarter
        {
          quarters++;
          cout << "ching" << endl;
          break;
      }





      case '1':                                              //Pull the 1st knob for Lucky Strikes
        {
          if(totalchange >= .75 && luckystrike >= 1)           //If there is enough money and enough Lucky Strikes
          {
            cout << "A pack of Lucky Strikes slides into view. It's your lucky day!" << endl;
            luckystrike = luckystrike-1;
            bank = (bank + (quarters * .25));
            quarters=0;
          }
          else if(totalchange >= .75)                          //If there is not enough Lucky Strikes
          {
            cout << "You hear mechanical clanking, but no cigarettes appear." << endl;
            bank = (bank + (quarters * .25));
            quarters=0;
          }
          else                                                 //If you don't have enough money for Lucky Strikes
          {
            cout << "(nothing happens)" << endl;
          }
          break;
      }





      case '2':                                             //Pull the 2nd knob for Camels
        {
          if(totalchange >= .75 && camels >= 1)           //If there is enough money and enough Camels
          {
            cout << "A pack of Camels slides into view. Watch out, they spit!" << endl;
            camels = camels-1;
            bank = (bank + (quarters * .25));
            quarters=0;
          }
          else if(totalchange >= .75)                          //If there is not enough Camels
          {
            cout << "You hear mechanical clanking, but no cigarettes appear." << endl;
            bank = (bank + (quarters * .25));
            quarters=0.00;
          }
          else                                                 //If you don't have enough money for Camels
          {
            cout << "(nothing happens)" << endl;
          }
          break;
      }




      case '3':                                             //Pull the 3rd knob for Gauloises
        {
          if(totalchange >= .75 && gauloises >= 1)           //If there is enough money and enough Gauloises
          {
            cout << "A pack of Gauloises slides into view. Gauloises? Really?" << endl;
            gauloises = gauloises-1;
            bank = (bank + (quarters * .25));
            quarters=0;
          }
          else if(totalchange >= .75)                          //If there is not enough Gauloises
          {
            cout << "You hear mechanical clanking, but no cigarettes appear." << endl;
            bank = (bank + (quarters * .25));
            quarters=0;
          }
          else                                                 //If you don't have enough money for Gauloises
          {
            cout << "(nothing happens)" << endl;
          }
          break;
      }




      case '4':                                             //Pull the 4th knob for Pall Malls
        {
          if(totalchange >= .75 && pallmalls >= 1)           //If there is enough money and enough Pall Malls
          {
            cout << "A pack of Pall Malls slides into view. They rhyme!" << endl;
            pallmalls = pallmalls-1;
            bank = (bank + (quarters * .25));
            quarters=0;
          }
          else if(totalchange >= .75)                          //If there is not enough Pall Malls
          {
            cout << "You hear mechanical clanking, but no cigarettes appear." << endl;
            bank = (bank + (quarters * .25));
            quarters=0;
          }
          else                                                 //If you don't have enough money for Pall Malls
          {
            cout << "(nothing happens)" << endl;
          }
          break;
      }




      case 'r':                                            //restock the machine
        {
          luckystrike = 10;
          camels = 10;
          gauloises = 10;
          pallmalls = 10;
          bank = 0.00;
          cout << "A grouchy-looking attendant shows up and restocks the machine."  << endl;
          break;
      }





      case 'q':                                            //quit statement
        {
          cout << "So long!" << endl;
          maininput = 'q';
          break;
      }





      default:
        {
          cout << "I do not understand." << endl;
          break;
      }
    }
  }
  while(maininput != 'q');
  return 0;
}

