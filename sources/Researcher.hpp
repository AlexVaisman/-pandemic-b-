#pragma once
#include "Player.hpp"

using namespace pandemic;
namespace pandemic{
    class Researcher : public Player{
        public:
        Researcher(Board& board, City city);
        virtual string role() override;
        virtual Player&  discover_cure(Color color) override;  
    };
}