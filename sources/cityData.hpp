#pragma once
#include <map>
#include <set>
#include "City.hpp"
#include "Color.hpp"

namespace pandemic {

  class cityData{
      public:
        City city;
        Color color;
         std::string name;
        int cubes;
        bool research_station;
        std::set<City> neighbors;
       
    
    

        cityData(const City city): city(city), research_station(false), name(names[city]), cubes(0), neighbors(connections[city]), color(citiesColors[city]) {}
        cityData(){}

     
        

  };
}