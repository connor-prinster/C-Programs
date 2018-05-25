#include <iostream>
#include <map>

/*
 * A simple example program of how one uses a std::map.
 * 
 * This program begins by creating a map and filling it with some information.
 *
 * It retrieves a few of the values one-by-one using a known key.
 *
 * Next it iterates over all items in the collection. This can be useful for
 * debugging or when you want to know what values have been stored in the map.
 *
 * Then it checks for the presence or absence of a particular key.
 *
 * Finally, I pass the collection to a function which modifies it, and then
 * passes it back. This mimics the behavior your recursive crawl() function
 * will exhibit - it will take as a parameter a map of URLs you've already
 * visited, and pass that back up to the caller.
 *
 */


// A function which modifies a std::map and returns it
std::map<std::string, std::string>
modifyMap(std::string k, std::string v, std::map<std::string, std::string> b) {
    b[k] = v;
    return b;
}


int main(int, char**) {

    std::cout << "Creating a map and populating it with key-value pairs" << std::endl
        << "=====================================================" << std::endl << std::endl;
    std::map<std::string, std::string> scottStappMap;
    scottStappMap["one"] = "Are You Ready?";
    scottStappMap["two"] = "What If";
    scottStappMap["three"] = "Beautiful";
    scottStappMap["four"] = "Say I";
    scottStappMap["five"] = "Wrong Way";
    scottStappMap["six"] = "Faceless Man";
    scottStappMap["seven"] = "Never Die";
    scottStappMap["eight"] = "With Arms Wide Open";
    scottStappMap["nine"] = "Higher";
    scottStappMap["ten"] = "Wash Away Those Years";
    scottStappMap["eleven"] = "Inside Us All";
    std::cout << "Done" << std::endl;
    std::cout << "\n\n";



    std::cout << "Retrieving single values by key" << std::endl
        << "===============================" << std::endl;
    std::cout << "scottStappMap['one'] = " << scottStappMap["one"] << std::endl;
    std::cout << "scottStappMap['two'] = " << scottStappMap["two"] << std::endl;
    std::cout << "scottStappMap['three'] = " << scottStappMap["three"] << std::endl;
    std::cout << "\n\n";



    std::cout << "Iterating over contents of the map" << std::endl
        << "(notice that they are not in order)" << std::endl
        << "===================================" << std::endl;
    for (auto iter = scottStappMap.begin(); iter != scottStappMap.end(); iter++)
        std::cout << "scottStappMap['" << iter->first << "'] = " << iter->second << std::endl;
    std::cout << "\n\n";



    std::cout << "Checking whether the key 'fake news' is present in the map" << std::endl
        << "==========================================================" << std::endl;
    std::string k = "fake news",
                v = "Scott Stapp is a cool dude";

    if (scottStappMap.count(k) > 0)
        std::cout << "key '" << k << "' is in the dictionary\n";
    else
        std::cout << "key '" << k << "' is NOT in the dictionary\n";
    std::cout << "\n\n";



    std::cout << "Calling a function which modifies the map" << std::endl
        << "I pass the map in the ordinary fashion, and return it again" << std::endl
        << "===========================================================" << std::endl;
    scottStappMap = modifyMap(k, v, scottStappMap);
    std::cout << "scottStappMap['fake news'] = " << scottStappMap["fake news"] << std::endl;
    std::cout << "\n\n";



    std::cout << "I have added 'fake news' to this map" << std::endl
        << "====================================" << std::endl;
    if (scottStappMap.count(k) > 0)
        std::cout << "key '" << k << "' is in the dictionary\n";
    else
        std::cout << "key '" << k << "' is NOT in the dictionary\n";


    return 0;
}
