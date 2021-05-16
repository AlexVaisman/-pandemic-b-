#include "Scientist.hpp"

using namespace std;
namespace pandemic{
    Scientist::Scientist(Board& board, City city , int num):Player(board,city){
        card_to_cure = num;
    }

    string Scientist::role(){
        return "Scientist";
    }

    Player&  Scientist::discover_cure(Color color){
        string color_string;
        if((int)color == 0){
        color_string = "Black";
        }else if((int)color == 1){
        color_string = "Red";
        }else if((int)color == 2){
        color_string = "Blue";
        }else if((int)color == 3){
        color_string = "Yellow";
        }

        if(Player::check_cured(color)){//check if there is a cure.
        }
        else if(this->board.citys.at((int)current_city).station){ //current city has a station.
            int num_of_cards = Player::count_cards(color_string);
            if(num_of_cards >= card_to_cure){
                int color_num = remove_cards_number(color,card_to_cure);
                    if(color_num == 0){ //black cure
                        board.Black_cure = true;
                        
                    }else if(color_num == 1){ //red cure
                        board.Red_cure = true;
                        
                    }else if(color_num == 2){ //Blue cure
                        board.Blue_cure = true;
                        
                    }else if(color_num == 3){ //Yello cure
                        board.Yellow_cure = true;
                        
                    }
                        
                }else{
                    throw invalid_argument( "You cannot discover cure , you dont have enough cards, you have: "+to_string(cards.size()));
                }
            }else{
                throw invalid_argument( "You cannot discover cure , there is no reserch station.");
            }
        return *this;
    }  


}