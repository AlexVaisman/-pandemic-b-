#include "Virologist.hpp"

using namespace std;
namespace pandemic{
    Virologist::Virologist(Board& board, City city):Player(board,city){ 
    }

    string Virologist::role(){
        return "Virologist";
    }

    Player& Virologist::treat(City city){
        if(current_city == city){//if Virologist want to treat the city he is in 
            Player::treat(city);
        }else{//if Virologist wants to treat a diffrent city check if he has card then treat.
             auto it = find(this->cards.begin(),this->cards.end(), city);
             if(it != cards.end()){//
                City start_city = current_city;
                current_city = city;
                Player::treat(city);
                current_city = start_city;
                cards.erase(it);
             }else{
                 throw invalid_argument( "You cannot treat a city when you dont have the city card");
             }
        }
        return *this;
    }
}