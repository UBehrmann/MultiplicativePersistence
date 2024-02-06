//
// Created by ursbe on 09.08.2023.
//

#include "DataManagement.h"

bool DataManagement::save() const {

    return saveToFile(*(this), dataPath);
}

bool DataManagement::load() {

    return loadFromFile(*(this), dataPath);
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

void DataManagement::addNumber(MultiPers newNumber) {
    this->numbers.push_back(newNumber);
}

void DataManagement::numberAddOne() {
    this->number++;
}