#pragma once
#include "Player.hpp"

using namespace pandemic;
namespace pandemic{
    class GeneSplicer : public Player{
        public:
        GeneSplicer(Board& board, City city);
        virtual string role() override;
        virtual Player&  discover_cure(Color color) override; 
        void cure(Color color);
        void pop_cards(int how_many);
    };
}