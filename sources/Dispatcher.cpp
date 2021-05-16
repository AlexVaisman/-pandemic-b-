#include "Dispatcher.hpp"

using namespace std;
namespace pandemic{
    Dispatcher::Dispatcher(Board& board, City city):Player(board,city){
    }

    string Dispatcher::role(){
        return "Dispatcher";
    }

    Player&  Dispatcher::fly_direct(City city){
        if(city == current_city){
            throw invalid_argument( "You cannot fly from a city to itself");
        }
        if(board.citys.at((int)current_city).station){
            current_city = city;
        }else{
            Player::fly_direct(city);
        }
        return *this;
        
    }
}