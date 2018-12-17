/************************
* A#: A02095542
* Course: CS1400
* CS1400 Section: 1
* CS1405 Section: 3
* HW#: 9
***********************/

#include <cmath>
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

struct MandelbrotConfig
{
  int width;
  int height;
  double xComplexMin;
  double xComplexMax;
  double yComplexMin;
  double yComplexMax;
  int maxIterations;
  Color colorOne;
  Color colorTwo;
  string outputFileName;
};

void drawMandelbrot(MandelbrotConfig config);


void readConfig(double height, double width, double xmin, double xmax, double ymin, double ymax, double maxiters,
Color color1, Color color2, string filename);


int main()
{
  cout << "Mandelbrot Config File: " << endl;
  string configfile;
  cin >> configfile;
  ifstream fin;
  fin.open(configfile);

  Color colorfirst;
  Color colorsecond;
  int iterations;
  int maxiterations;
  double height;
  double width;
  double xComplexMin;
  double xComplexMax;
  double yComplexMin;
  double yComplexMax;
  string filename;
  fin >> height;
  fin >> width;
  fin >> xComplexMin;
  fin >> xComplexMax;
  fin >> yComplexMin;
  fin >> yComplexMax;
  fin >> maxiterations;
  fin >> colorfirst.red;
  fin >> colorfirst.green;
  fin >> colorfirst.blue;
  fin >> colorsecond.red;
  fin >> colorsecond.green;
  fin >> colorsecond.blue;
  fin >> filename;

  readConfig(height, width, xComplexMin, xComplexMax, yComplexMin, yComplexMax, maxiterations, colorfirst, colorsecond, filename);
}

void readConfig(double height, double width, double xmin, double xmax, double ymin, double ymax, double maxiters, Color color1, Color color2, string filename)
{
  ofstream fout;
  fout.open(filename);

  double pixelWidth = (xmax - xmin) / width;
  double pixelHeight = (ymax - ymin) / height;
  double x0;
  double y0;
  double x;
  double y;
  double iterations;
  double xtemp;

  fout << "P3" << endl;
  fout << width << " " << height << endl;
  fout << "255" << endl;

  for (int i = 0; i < width; i++)
  {
    for (int j = 0; j < height; j++)
    {
      x0 = xmin + j * pixelWidth;
      y0 = ymin + i * pixelHeight;

      x = 0;
      y = 0;
      iterations = 0;

      while (x * x + y * y < 2 * 2 && iterations < maxiters)
      {
        xtemp = x * x - y * y + x0;
        y = 2 * x * y + y0;
        x = xtemp;
        iterations = iterations + 1;
      }
      fout << left << setw(4) << (static_cast<int>(color1.red - (color1.red - color2.red) * static_cast<float>(iterations / maxiters))) << left << setw(4) << (static_cast<int>(color1.green - (color1.green- color2.green) * static_cast<float>(iterations / maxiters))) << left << setw(4) << (static_cast<int>(color1.blue - (color1.blue - color2.blue) * static_cast<float>(iterations / maxiters))) << left << setw(2) << " ";
    }
  }
  fout.close();
}
