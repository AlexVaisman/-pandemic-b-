#pragma once
#include "Player.hpp"

using namespace pandemic;
namespace pandemic{
    class Scientist : public Player{
        public:
        int card_to_cure;
        Scientist(Board& board, City city ,int num);
        virtual string role() override;
        virtual Player&  discover_cure(Color color) override; 
    };
}