#include "Board.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
namespace pandemic{
    

    Board::
    //constructor
    Board::Board(): Black_cure(false) ,Blue_cure(false) ,Red_cure(false) ,Yellow_cure(false){
        init_board();
    }
    
    //This function checks if the board is clean from disease.
    bool Board::is_clean(){
        auto it = this->citys.begin();
        while(it!=this->citys.end()){
            if(it->second.disease > 0){
                return false;
            }
        it++;
        }
        return true;
    }
    //This fucntion sets all cures to false.
    void Board::remove_cures(){
        this->Black_cure = false;
        this->Blue_cure = false;
        this->Red_cure = false;
        this->Yellow_cure = false;
    }
    //This function removes all research stations from board.
    void Board::remove_stations(){
        auto it = this->citys.begin();
        while(it!=this->citys.end()){
            it->second.station = false;
        }
    }

    //This function reads from "cities_map.txt" and adds the citys,their color and connections to the board.
    void Board::init_board(){
        ifstream file{"cities_map.txt"};
        string name;
        string color;
        string line;
        vector<string> connections;
        int word_counter = 0;
        int city_counter = 0;
        //reading each line in file and adding to board
        while(getline(file,line)){
            stringstream stream(line);
            while(stream.good()){
                string sub;
                getline(stream,sub,' ');
                if(word_counter == 0){
                    name = sub;
                }
                if(word_counter == 1){
                    color = sub;
                }
                if(word_counter > 1){
                    connections.push_back(sub);
                }
                word_counter++;
            }
            //adding to board
            CityData city{name,color,0,false,connections};
            citys[city_counter] = city;
            //adding trnaslation of enum to city name in string
            enum_tocity[city_counter] = name;
            city_counter++;
            //reseting varibales
            connections.clear();
            word_counter = 0;
        }
        file.close();
    }  

    // operators 
    int Board::operator[](pandemic::City city) const{
        return citys.size();
    }

    int& Board::operator[](pandemic::City city){
        auto it = citys.find((int)city);
        return it->second.disease;
    }

    std::ostream& operator<< (std::ostream& os, const Board& board){
        os<<"How to print? that comes later";
        return os;
    };


};