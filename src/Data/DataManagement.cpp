//
// Created by ursbe on 09.08.2023.
//

#include "DataManagement.h"
#include <fstream>

bool DataManagement::saveToFile() {

   std::ofstream ofs(DATA_PATH);
   if (!ofs) return false;
   ofs << std::setw(4) << *(this);
   return true;
}

bool DataManagement::loadFromFile() {

   std::ifstream ifs(DATA_PATH);
   if (!ifs) return false;
   ifs >> *(this);
   return true;
}

const std::vector<MultiPers> &DataManagement::getNumbers() const {
   return this->numbers;
}

MultiPers DataManagement::getNumber() const {
   return this->number;
}

DataManagement::DataManagement() {
	this->number = 1; // 277777788888899; // 277 777 788 888 899 11 steps
}

void DataManagement::addNumber(MultiPers number) {
	this->numbers.push_back(number);
}

void DataManagement::numberAddOne() {
	this->number++;
}