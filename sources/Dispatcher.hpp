#pragma once
#include "Player.hpp"

using namespace pandemic;
namespace pandemic{
    class Dispatcher : public Player{
        public:
        Dispatcher(Board& board, City city);
        virtual string role() override;
        virtual Player&  fly_direct(City city) override;
    };
}