#include "Medic.hpp"
using namespace pandemic;

Medic::Medic(Board &board, City city) : Player(board, city)
{
    cure();
    _role="Medic";
}

std::string Medic::role()
{
    return std::string("Medic");
}

Player &Medic::treat(City city)
{

    cityData c1 = this->_board.get_cityData(city);
    cityData curr = this->_board.get_cityData(this->_location);
    if (city != this->_location)
    {
        throw std::invalid_argument("You have to be found in the city you want to treat (" + c1.name + ") you are in " + curr.name);
    }

    if (curr.cubes == 0)
    {
        throw std::invalid_argument("this city doesn't need to be treat(" + curr.name + ")");
    }
    this->_board[this->_location] = 0;

    return *this;
}
Player &Medic::drive(City city){
    this->cure();
    Player::drive(city);
     this->cure();
      return *this;

}
Player &Medic::fly_direct(City city){
    cure();
    Player::fly_direct(city);
    cure();
     return *this;
}
Player &Medic::fly_charter(City city){
     cure();
    Player::fly_charter(city);
    cure();
     return *this;
}
Player &Medic::fly_shuttle(City city){
      cure();
    Player::fly_shuttle(city);
    cure();
     return *this;
}
Player &Medic::build(){
     cure();
    Player::build();
     return *this;
}
Player &Medic::discover_cure(Color color){
     cure();
    Player::discover_cure(color);
     return *this;
}
void Medic::cure(){
    if (this->_board.medicine[citiesColors[this->_location]])
    {
        this->_board[this->_location]=0;
    }
    
}