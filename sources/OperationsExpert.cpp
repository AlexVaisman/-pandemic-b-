#include "OperationsExpert.hpp"

using namespace std;
namespace pandemic{
    OperationsExpert::OperationsExpert(Board& board, City city):Player(board,city){
    }

    string OperationsExpert::role(){
        return "OperationsExpert";
    }
    //Build a reserch station
    Player& OperationsExpert::build(){
        this->board.citys.at((int)current_city).station = true;
        return *this;
    }
}