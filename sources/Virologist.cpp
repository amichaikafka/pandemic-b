#include "Virologist.hpp"
using namespace pandemic;

Virologist::Virologist(Board &board, City city) : Player(board, city)
{
        _role="Virologist";

}
std::string Virologist::role()
{
    return std::string("Virologist");
}

Player &Virologist::treat(City city)
{
    if (this->_location==city)
    {
        Player::treat(city);
        return *this;
    }

    cityData c1 = this->_board.get_cityData(city);
    cityData curr = this->_board.get_cityData(this->_location);

    if (c1.cubes == 0)
    {
        throw std::invalid_argument("this city doesn't need to be treat(" + curr.name + ")");
    }
    if (this->_cards.count(c1.city) == 0)
    {

        throw std::invalid_argument("missing city card of " + c1.name);
    }
    this->_cards.erase(c1.city);

    Color c = citiesColors[city];
    if (this->_board.medicine[c])
    {
        this->_board[city] = 0;
    }
    else
    {
        this->_board[city]--;
    }

    return *this;
}