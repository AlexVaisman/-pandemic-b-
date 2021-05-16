#include "FieldDoctor.hpp"

using namespace std;
namespace pandemic{
    FieldDoctor::FieldDoctor(Board& board, City city):Player(board,city){ 
    }

    string FieldDoctor::role(){
        return "FieldDoctor";
    }

    Player& FieldDoctor::treat(City city){
        if(city == current_city){ //if player in the same city he want to treat then treat.
            Player::treat(city);
        }else{ // check if city has direct connection to target city, if it dose treat it , else throw invalid_argument.
            City start_city = current_city;
            try{
                 Player::drive(city);
            }
            catch(const exception& ex){
                throw invalid_argument( "Can not treat city ,it has no direct connection");
            }
            Player::treat(city);
            Player::drive(start_city);
            current_city = start_city;
        }
    return *this;

    }
}