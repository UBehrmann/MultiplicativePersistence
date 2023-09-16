//
// Created by ursbe on 09.08.2023.
//

#ifndef MULTIPLICATIVEPERSISTENCE_DATAMANAGEMENT_H
#define MULTIPLICATIVEPERSISTENCE_DATAMANAGEMENT_H

#include "../MP/MPType.h"

#include <vector>

class DataManagement {
private:
   std::vector<MultiPers> _numbers;

   MultiPers _number;

public:
   DataManagement();

   const std::vector<MultiPers> &getNumbers() const;

   MultiPers getNumber() const;

   void numberAddOne();

   void addNumber(MultiPers number);

   void saveToFile();

   void loadFromFile();

};


#endif //MULTIPLICATIVEPERSISTENCE_DATAMANAGEMENT_H
