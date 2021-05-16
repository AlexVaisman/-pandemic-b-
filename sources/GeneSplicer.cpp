#include "GeneSplicer.hpp"

using namespace std;
namespace pandemic{
    GeneSplicer::GeneSplicer(Board& board, City city):Player(board,city){
    }

    string GeneSplicer::role(){
        return "GeneSplicer";
    }

    Player& GeneSplicer::discover_cure(Color color){
        if(cards.size()<FIVE){//checking at least 5 cards.
             throw invalid_argument( "Not enough cards, you need at least 5. you have: "+to_string(cards.size()));
        }
        if(!board.citys.at((int)current_city).station){//checking if there is a station.
            throw invalid_argument( "There is no reserch station in this city.");
        }
        if( Player::check_cured(Color::Black) || Player::check_cured(Color::Blue) || 
            Player::check_cured(Color::Red) ||Player::check_cured(Color::Yellow)){
        }else{
            cure(color);
        }
        return *this;
    }



    void GeneSplicer::cure(Color color){
        if((int)color == 0){//Black
            board.Black_cure = true;
            pop_cards(FIVE);
        }else if((int)color == 1){//Red
            board.Red_cure = true;
            pop_cards(FIVE);
        }else if((int)color == 2){//Blue
            board.Blue_cure = true;
            pop_cards(FIVE);
        }else if((int)color == 3){//Yellow
            board.Yellow_cure = true;
            pop_cards(FIVE);
        }
    }

    void GeneSplicer::pop_cards(int how_many){
        for(int i = 0 ;i<how_many; i++){
            cards.pop_back();
        }
    }

}

