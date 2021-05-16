#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include <tuple>
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>

namespace pandemic{
    class Board{
        public:
        struct CityData{
            string name;
            string color;
            int disease;
            bool station;
            vector<string> connections; 
        };
        //varibalse
        bool Black_cure;
        bool Blue_cure;
        bool Yellow_cure;
        bool Red_cure;

        unordered_map<int,CityData> citys;
        unordered_map<int,std::string> enum_tocity;

        Board();

        bool is_clean();
        void remove_cures();
        void remove_stations(); 
        //operators
        int operator[](pandemic::City city) const;
        int& operator[](pandemic::City city);
        friend std::ostream& operator<< (std::ostream& os, const Board& board);


        private:
        void init_board();

    };


};
