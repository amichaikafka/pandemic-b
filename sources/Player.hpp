
#pragma once
#include "Board.hpp"
#include "cityData.hpp"
#include <string>
#include <set>
const int CARDS=5;
namespace pandemic
{
    class Player
    {
    protected:
        Board& _board;
        City _location;
        std::set<City> _cards;
        std::string _role="Player";
 

    public:
        Player(Board& board, City city);
        Player& take_card(City city);
        Player& remove_cards();
        virtual Player& drive(City city);
        virtual Player& fly_direct(City city);
        virtual Player& fly_charter(City city);
        virtual Player& fly_shuttle(City city);
        virtual Player& build();
        virtual Player& discover_cure(Color color);
        virtual Player& treat(City city);
        virtual std::string role();
        friend std::ostream &operator<<(std::ostream &out, const Player &p);
    };
}