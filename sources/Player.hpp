#pragma once
#include "Board.hpp"

using namespace pandemic;
namespace pandemic{
    class Player{

        public:
        Board& board;
        City current_city;
        std::vector<City> cards;
        int FIVE = 5;

        
        Player(Board& board, City city);
        virtual std::string role();
        virtual Player&  take_card(City city); 
        virtual Player&  drive(City city);
        virtual Player&  fly_direct(City city);
        virtual Player&  fly_charter(City city);
        virtual Player&  fly_shuttle(City city); 
        virtual Player&  build();
        virtual Player&  discover_cure(Color color); 
        virtual Player&  treat(City city);
        bool check_cured(string const &color)const;
        bool check_cured(Color const &color)const;
        bool check_five_cards(Color color);
        int count_cards(std::string const &color);
        int remove_cards_number(Color color , int how_many);
        void remove_cards_helper(string const &color,int how_many);

        private:
        void remove_cards ();
        string translate_enum(City city);


    };

}