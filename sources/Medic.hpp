#pragma once
#include "Player.hpp"

using namespace pandemic;
namespace pandemic{
    class Medic : public Player{
        public:
        Medic(Board& board, City city);
        virtual string role() override;
        virtual Player&  treat(City city) override;
        virtual Player&  drive(City city) override;
        virtual Player&  fly_direct(City city) override;
        virtual Player&  fly_charter(City city) override;
        virtual Player&  fly_shuttle(City city) override;
        private:
        bool check_cured(string color);        
    };
}