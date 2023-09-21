//
// Created by ursbe on 09.08.2023.
//

#include "DataManagement.h"
#include <fstream>
#include "../Libs/json/json_util.h"

bool DataManagement::save() {

	return saveToFile(*(this), DATA_PATH);
}

bool DataManagement::load() {

	return loadFromFile(*(this), DATA_PATH);
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