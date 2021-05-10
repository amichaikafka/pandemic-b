#include "Dispatcher.hpp"
using namespace pandemic;

Dispatcher::Dispatcher(Board& board, City city) : Player(board, city){
            _role="Dispatcher";

}
std::string Dispatcher::role(){
    return std::string("Dispatcher");
}

Player& Dispatcher::fly_direct(City city){
    if (this->_location==city)
    {
        throw std::invalid_argument("you are allready here");
    }
    cityData curr = this->_board.get_cityData(this->_location);
    if (curr.research_station)
    {
        this->_location=city;
  
    return *this;
    }
    
   Player::fly_direct(city);
   return *this;
}