#pragma once
#include "Color.hpp"
#include "cityData.hpp"

#include <map>
#include <set>
#include <iostream>

using namespace std;

namespace pandemic
{

    class Board
    {

    public:
        std::map<const City, cityData> gameMap;
        Board();

        int &operator[](City city);
        bool is_clean();
        friend std::ostream &operator<<(std::ostream &out, const Board &b);
        cityData get_cityData(City city);
        std::map<Color, bool> medicine;
        void remove_stations();
        void remove_cures();
    };
}