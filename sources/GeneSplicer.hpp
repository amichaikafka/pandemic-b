#pragma once
#include <string>
#include "Player.hpp"
namespace pandemic
{
    class GeneSplicer : public Player
    {
    private:
    public:
        GeneSplicer(Board& board, City city);
        virtual std::string role();
        virtual Player& discover_cure(Color color);
    };
}