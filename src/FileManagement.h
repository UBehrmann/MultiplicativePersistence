//
// Created by ursbe on 08.08.2023.
//

#ifndef MULTIPLICATIVEPERSISTENCE_FILEMANAGEMENT_H
#define MULTIPLICATIVEPERSISTENCE_FILEMANAGEMENT_H

#include "MPType.h"

#include <vector>

void saveToFile(MultiPers number, std::vector<MultiPers> numbers);

void loadFromFile(MultiPers &number, std::vector<MultiPers> &numbers);

#endif //MULTIPLICATIVEPERSISTENCE_FILEMANAGEMENT_H
