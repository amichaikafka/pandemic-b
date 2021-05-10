#pragma once
#include <string>
#include "Player.hpp"
namespace pandemic
{
    class Scientist : public Player
    {
    private:
    int n;
    public:
        Scientist(Board& board, City city,int n);
        virtual std::string role();
        virtual Player& discover_cure(Color color);
    };
}