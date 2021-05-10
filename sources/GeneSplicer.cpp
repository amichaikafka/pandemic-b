#include "GeneSplicer.hpp"
using namespace pandemic;

GeneSplicer::GeneSplicer(Board &board, City city) : Player(board, city)
{
    _role="GeneSplicer";
}
std::string GeneSplicer::role()
{
    return std::string("GeneSplicer");
}

Player &GeneSplicer::discover_cure(Color color)
{

    cityData curr = this->_board.get_cityData(this->_location);
    if (!curr.research_station)
    {
        throw std::invalid_argument("there is no research station in " + curr.name);
    }

    if (this->_cards.size() < CARDS)
    {
        throw std::invalid_argument("there is no enough cards");
    }
    if (this->_board.medicine[color])
    {
        return *this;
    }


     int count = 0;
    std::set<City> to_remove;
    for (auto &&i : this->_cards)
    {
        
            to_remove.insert(i);
            count++;
        
        if (count == CARDS)
        {
            if (this->_board.medicine[color])
            {
                return *this;
            }

            for (auto &&i : to_remove)
            {
                this->_cards.erase(i);
            }
            this->_board.medicine[color] = true;
            return *this;
        }
    }
    return *this;

}