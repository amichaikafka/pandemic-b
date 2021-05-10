#pragma once
#include <string>
#include "Player.hpp"
namespace pandemic
{
    class FieldDoctor : public Player
    {
    private:
    public:
        FieldDoctor(Board& board, City city);
        virtual std::string role();
        virtual Player& treat(City city);
    };
}