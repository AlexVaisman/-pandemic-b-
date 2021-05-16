#pragma once
#include "Player.hpp"

using namespace pandemic;
namespace pandemic{
    class OperationsExpert : public Player{
        public:
        OperationsExpert(Board& board, City city);
        virtual Player&  build() override;
        virtual std::string role() override;
    };
}