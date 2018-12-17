/************************
* A#: A02095542
* Course: CS1400
* CS1400 Section: 1
* CS1405 Section: 3
* HW#: 8
***********************/

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Color
{
  int red;
  int green;
  int blue;
};

void smoosh(int rows, int cols, Color leftColor, Color rightColor, string filename);

int main()
{
  // TODO: Add your code here to get user input
  Color leftColor;
  Color rightColor;
  int height;
  int width;
  string filename;

  cout << "Write in your colors for left side: red, green, blue." << endl;
  leftColor.red;
  leftColor.green;
  leftColor.blue;
  cin >> leftColor.red;
  cin >> leftColor.green;
  cin >> leftColor.blue;

  cout << "Write in your colors for right side: red, green, blue." << endl;
  rightColor.red;
  rightColor.green;
  rightColor.blue;
  cin >> rightColor.red;
  cin >> rightColor.green;
  cin >> rightColor.blue;


  cout << "Enter height by width" << endl;
  cin >> height;
  cin >> width;

  cout << "Enter File name (ending in .ppm)" << endl;
  cin >> filename;

  smoosh(height, width, leftColor, rightColor, filename);

  return 0;
}

void smoosh(int rows, int cols, Color leftColor, Color rightColor, string filename)
{
  // TODO: Complete this function

  ofstream fout;
  fout.open(filename);
  fout << "P3" << endl;
  fout << cols << " " << rows << endl;
  fout << "255" << endl;

  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < cols; j++)
    {
      fout << left << setw(4) << (leftColor.red - static_cast<int>((static_cast<double>(leftColor.red-rightColor.red) / cols) * j)) << left << setw(4) << (leftColor.green - static_cast<int>((static_cast<double>(leftColor.green-rightColor.green) / cols) *j)) << left << setw(4) << (leftColor.blue - static_cast<int>((static_cast<double>(leftColor.blue-rightColor.blue) / cols) *j)) << left << setw(2) << " ";
    }
    fout << endl;
  }
  fout.close();
}
