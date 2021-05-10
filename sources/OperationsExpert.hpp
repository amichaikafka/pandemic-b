#pragma once
#include <string>
#include "Player.hpp"
namespace pandemic
{
    class OperationsExpert : public Player
    {
    private:
    public:
        OperationsExpert(Board& board, City city);
        virtual std::string role();
        virtual Player& build();
    };
}