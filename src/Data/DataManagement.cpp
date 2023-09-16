//
// Created by ursbe on 09.08.2023.
//

#include "DataManagement.h"
#include <fstream>


void DataManagement::saveToFile() {

   std::ofstream file;
   file.open("save.txt");

   file << _number << std::endl;

   for(MultiPers i : _numbers){
      file << i << std::endl;
   }

   file.close();

}

void DataManagement::loadFromFile() {

   std::ifstream file;
   file.open("save.txt");

   std::string line;

   std::getline(file, line);

   for(char i : line){
      _number *= 10;
      _number += static_cast<MultiPers>(i - '0');
   }

   file.close();

}

const std::vector<MultiPers> &DataManagement::getNumbers() const {
   return _numbers;
}

MultiPers DataManagement::getNumber() const {
   return _number;
}

DataManagement::DataManagement() {
   _number = 1; // 277777788888899; // 277 777 788 888 899 11 steps
}

void DataManagement::addNumber(MultiPers number) {
   _numbers.push_back(number);
}

void DataManagement::numberAddOne() {
   _number++;
}
