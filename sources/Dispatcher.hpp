#pragma once
#include <string>
#include "Player.hpp"
namespace pandemic
{
    class Dispatcher : public Player
    {
    private:
    public:
        Dispatcher(Board& board, City city);
        virtual std::string role();
        virtual Player& fly_direct(City city);
    };
}