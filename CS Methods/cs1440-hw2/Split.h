#pragma once

#include <string>

class Split{
    public:
        bool split(const std::string& s, char delimiter, std::string elements[], int expectedNumberOfElements);
};