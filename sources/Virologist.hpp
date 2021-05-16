#pragma once
#include "Player.hpp"

using namespace pandemic;
namespace pandemic{
    class Virologist : public Player{
        public:
        Virologist(Board& board, City city);
        virtual string role() override;
        virtual Player&  treat(City city) override;
    };
}