#pragma once
#include <string>
#include "Player.hpp"
namespace pandemic
{
    class Researcher : public Player
    {
    private:
    public:
        Researcher(Board& board, City city);
        virtual std::string role();
        virtual Player& discover_cure(Color color);
    };
}