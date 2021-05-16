#include "Medic.hpp"

using namespace std;
namespace pandemic{
    Medic::Medic(Board& board, City city):Player(board,city){
    }
    
    string Medic::role(){
        return "Medic";
    }


    Player&  Medic::treat(City city){
        if(board.citys.at((int)current_city).disease == 0){
           throw invalid_argument( "You cannot treat a city with disease lvl 0");
        }
        board.citys.at((int)current_city).disease = 0;
        return *this;
    }

    Player& Medic::drive(City city){
        bool cured = Player::check_cured(board.citys.at((int)city).color);//check if target city color is cured.
        Player::drive(city);
        if(cured){
            board.citys.at((int)city).disease = 0;
        }
        return *this;
    }

    Player& Medic::fly_direct(City city){
        bool cured = Player::check_cured(board.citys.at((int)city).color);//check if target city color is cured.
        Player::fly_direct(city);
        if(cured){
            board.citys.at((int)city).disease = 0;
        }
        return *this;
    }

    Player& Medic::fly_charter(City city){
        bool cured = Player::check_cured(board.citys.at((int)city).color);//check if target city color is cured.
        Player::fly_charter(city);
        if(cured){
            board.citys.at((int)city).disease = 0;
        }
        return *this;
    }
    
    Player& Medic::fly_shuttle(City city){
        bool cured = Player::check_cured(board.citys.at((int)city).color);//check if target city color is cured.
        Player::fly_shuttle(city);
        if(cured){
            board.citys.at((int)city).disease = 0;
        }
        return *this;
    }
}