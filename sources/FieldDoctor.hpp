#pragma once
#include "Player.hpp"

using namespace pandemic;
namespace pandemic{
    class FieldDoctor : public Player{
        public:
        FieldDoctor(Board& board, City city);
        virtual string role() override;
        virtual Player&  treat(City city) override;
    };
}