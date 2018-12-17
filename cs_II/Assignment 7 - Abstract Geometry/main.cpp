#include <iostream>
#include <string>
#include <vector>

#include "Geometry.h"
#include "Box.h"
#include "Sphere.h"

void report(Geometry* obj);

int main()
{
	std::vector<Geometry*> items;
	items.push_back(new Box("Box 1", 1, 2, 3));
	items.push_back(new Box("Box 2", 2, 3, 4));
	items.push_back(new Sphere("Sphere 1", 5));
	items.push_back(new Sphere("Sphere 2", 6));

	for (unsigned int i = 0; i < items.size(); i++)
	{
		std::cout << "----- Geometry Report -----" << std::endl << std::endl;
		report(items[i]);
		std::cout << std::endl;
	}

	std::cout << "Press 'enter' to exit program...";
	std::cin.get();
}

void report(Geometry* obj)
{
		std::cout << "Type: " << obj->getType() << std::endl;
		std::cout << "Name: " << obj->getName() << std::endl;
		std::cout << "Volume: " << obj->computeVolume() << std::endl;
		std::cout << "Surface Area: " << obj->computeSurface() << std::endl;
}