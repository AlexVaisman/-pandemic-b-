#include "Researcher.hpp"

using namespace std;
namespace pandemic{
    Researcher::Researcher(Board& board, City city):Player(board,city){
    }

    string Researcher::role(){
        return "Researcher";
    }

    //can discover cure without a need for reserch station.
    Player& Researcher::discover_cure(Color color){
        if(Player::check_cured(color)){//color alredy cured return.
        }else{
            bool five_cards = Player::check_five_cards(color);
                if(five_cards){
                    int color_num = Player::remove_cards_number(color,FIVE);
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
                    throw invalid_argument( "You cannot discover cure , you dont have enough cards.");
                }
        }
        return *this;
    }

}