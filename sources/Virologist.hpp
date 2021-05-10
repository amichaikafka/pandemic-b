#pragma once
#include <string>
#include "Player.hpp"
namespace pandemic
{
    class Virologist : public Player
    {
    private:
    public:
        Virologist(Board& board, City city);
        virtual std::string role();
        virtual Player& treat(City city);
    };
}