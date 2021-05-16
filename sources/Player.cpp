#include "Player.hpp"

using namespace pandemic;
namespace pandemic{


        Player::Player(Board& board, City city):board(board),current_city(city){
        };
        //Returns the player role
        std::string Player::role(){
            return "Player";
        };
        //Player takes card
        Player&  Player::take_card(City city){
            auto it = find(this->cards.begin(), this->cards.end(), city);
            if(it == cards.end()){
                cards.push_back(city);
            }
            
            return *this;
        };
        //Player moves to a connected city , if city is not connected trhows invalid_argument 
        Player&  Player::drive(City city){
            auto it = board.citys.at((int)this->current_city);
            string target_city = translate_enum(city);
            string cor_city = translate_enum(this->current_city);
            auto con_it = find(it.connections.begin(), it.connections.end(), target_city);
            if(con_it != it.connections.end()){
                this->current_city = city;
            }
            else{
                throw invalid_argument( cor_city+" has no direct connection to "+target_city );
            }
            return *this;
        };
        //Player will move to the city if he has that citys card ,else throws invalid_argument.
        Player&  Player::fly_direct(City city){
            if(city == current_city){
                throw invalid_argument( "You cannot fly from a city to itself");
            }
            auto it = find(this->cards.begin(),this->cards.end(), city);
            if(it != cards.end()){
                cards.erase(it);
                this->current_city = city;
            }
            else{
                throw invalid_argument( "You dont have the currect card to fly to this city.");
            }
            return *this;
        };
        //Player will move to a target city only if he has the card for the city he is currently in
        //if not will throw invalid_argument.
        Player&  Player::fly_charter(City city){
            if(city == current_city){
                throw invalid_argument( "You cannot fly from a city to itself");
            }
            auto it = find(this->cards.begin(),this->cards.end(), this->current_city);
            if(it != cards.end()){
                cards.erase(it);
                this->current_city = city;
            }
            else{
                throw invalid_argument( "You cant fly to that city becouse you dont have the card for the city you are in.");
            }
            return *this;
        };
        //Player can move to a diffrent city only if current city has a research station and target city hase a research station.
        Player&  Player::fly_shuttle(City city){
            if(city == current_city){
                throw invalid_argument( "You cannot fly from a city to itself");
            }
            if(this->board.citys.at((int)this->current_city).station && this->board.citys.at((int)city).station){
                this->current_city = city;
            }else{
                throw invalid_argument( "You cannot use the shuttle, the city you are in or the target city lack a reserch station.");
            }
            return *this;
        };
        //Build a reserch station in the current city. can be done only if the player has the city card. 
        Player&  Player::build(){
            //if there is alredy a station return.
            auto it = find(this->cards.begin(),this->cards.end(), this->current_city);
            if(this->board.citys.at((int)current_city).station){
            }else if(it != this->cards.end()){ //if player has a card build a station.
                this->board.citys.at((int)current_city).station = true;
                cards.erase(it);
            }else{
                throw invalid_argument( "You cannot build a reserch station in this city ,you lack this citys card.");
            }
            return *this;
        };
        //Discover a cure for a disease based on color, player must be in a city with a station
        //Plyaer must have 5 cards of the same color as the deisease , will throw invalid_argument.
        Player&  Player::discover_cure(Color color){

            if(check_cured(color)){
            }
            else if(this->board.citys.at((int)current_city).station){ //current city has a station.
                bool five_cards = check_five_cards(color);
                if(five_cards){
                    int color_num = remove_cards_number(color,FIVE);
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
            }else{
                throw invalid_argument( "You cannot discover cure , there is no reserch station.");
            }
            return *this;
        };
        //Player will decrease city disease lvl by 1 if there is no cure
        //if there is a cure will reduce it to 0
        //if city disease lvl is alredy at 0 will throw invalid_argument
        Player&  Player::treat(City city){
            if(board.citys.at((int)current_city).disease == 0){// no disease in this city
                throw invalid_argument( "You cannot treat a city with no disease in it.");
            }
            string color = board.citys.at((int)city).color;
            bool cure = false;
            if(color == "Black"){
                cure  = board.Black_cure;
            }else if(color == "Red"){
                cure  = board.Red_cure;
            }else if(color == "Blue"){
                cure  = board.Blue_cure;
            }else if(color == "Yellow"){
                cure  = board.Yellow_cure;
            }

            if(cure){// there is a cure , set disease lvl to 0
                board.citys.at((int)current_city).disease = 0;
            }else{// there is no cure remove one lvl.
                board.citys.at((int)current_city).disease --;
            }
            return *this;
        };

        string Player::translate_enum(City city){
            auto it_target = this->board.enum_tocity.find((int)city);
            string target_city = it_target->second;
            return target_city;
        }

        bool Player::check_five_cards(Color color){
            bool flag = true;
            int counter = 0;
            if((int)color == 0){
                counter = count_cards("Black");
            }else if((int)color == 1){
                counter = count_cards("Red");
            }else if((int)color == 2){
                counter = count_cards("Blue");
            }else if((int)color == 3){
                counter = count_cards("Yellow");
            }
            if(counter >= FIVE){
                return flag;
            }
            return false;
        }

        int Player::count_cards(string const &color){
            int counter = 0;
            for(uint i = 0 ; i<cards.size();i++){
                City city = cards.at(i);
                auto it = board.citys.at((int)city);
                if(it.color == color){
                    counter++;
                }
            }
            return counter;
        }

        int Player::remove_cards_number(Color color , int how_many){
            int ans = 0;
            if((int)color == 0){
                remove_cards_helper("Black",how_many);
                ans = 0;
            }else if((int)color == 1){
                remove_cards_helper("Red",how_many);
                ans = 1;
            }else if((int)color == 2){
                remove_cards_helper("Blue",how_many);
                ans =  2;
            }else if((int)color == 3){
                remove_cards_helper("Yellow",how_many);
                ans =  3;
            }
            return ans;
        }
        
        void Player::remove_cards_helper(string const &color , int how_many){
            int counter = 0;
            for(uint i = 0 ; i<cards.size();i++){
                City city = cards.at(i);
                auto it = board.citys.at((int)city);
                if(it.color == color){
                    if(counter < how_many){
                        cards.erase(cards.begin()+i);
                        counter++;
                    }
                }
            }
        }


        void Player::remove_cards(){
            this->cards.clear();
        }


    //this function retruns true if there is a cure.
    bool Player::check_cured(string const &color)const{
        bool flag = false;
        if(((color == "Black") && board.Black_cure) || ((color == "Red") && board.Red_cure) 
          || ((color == "Blue") && board.Blue_cure) || ((color == "Yellow") && board.Yellow_cure)){ // there is alredy a black cure
            flag = true;
        }
        return flag;
    }

    bool Player::check_cured(Color const &color)const{
        bool flag = false;
        if( (((int)color == 0) && board.Black_cure) || (((int)color == 1) && board.Red_cure) || 
             (((int)color == 2) && board.Blue_cure) || (((int)color == 3) && board.Yellow_cure)){ 
            flag =  true;
        }
        return flag;
    }
}