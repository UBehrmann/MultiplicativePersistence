//
// Created by ursbe on 09.08.2023.
//

#include "DataManagement.h"
#include <fstream>


bool DataManagement::saveToFile() {

   std::ofstream ofs(DATA_PATH);
   if (!ofs) return false;
   ofs << std::setw(4) << datas;
   return true;
}

bool DataManagement::loadFromFile() {

   std::ifstream ifs(DATA_PATH);
   if (!ifs) return false;
   ifs >> datas;
   return true;

}

const std::vector<MultiPers> &DataManagement::getNumbers() const {
   return datas.numbers;
}

MultiPers DataManagement::getNumber() const {
   return datas.number;
}

DataManagement::DataManagement() {
   datas.number = 1; // 277777788888899; // 277 777 788 888 899 11 steps
}

void DataManagement::addNumber(MultiPers number) {
   datas.numbers.push_back(number);
}

void DataManagement::numberAddOne() {
   datas.number++;
}
