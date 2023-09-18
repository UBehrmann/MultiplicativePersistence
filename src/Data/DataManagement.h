//
// Created by ursbe on 09.08.2023.
//

#ifndef MULTIPLICATIVEPERSISTENCE_DATAMANAGEMENT_H
#define MULTIPLICATIVEPERSISTENCE_DATAMANAGEMENT_H

#include "../MP/MPType.h"
#include <vector>
#include "../Libs/json/json_util.h"
#include <iostream>

#define DATA_PATH "./Data/data.json"

struct MultiPersStruct {
   MultiPers number;
   std::vector<MultiPers> numbers;

   NLOHMANN_DEFINE_TYPE_INTRUSIVE(MultiPersStruct, number, numbers)

   JSON_DEFINE_FLUX_OPERATORS(MultiPersStruct)
};

class DataManagement {
private:

   MultiPersStruct datas;

public:
   DataManagement();

   const std::vector<MultiPers> &getNumbers() const;

   MultiPers getNumber() const;

   void numberAddOne();

   void addNumber(MultiPers number);

   bool saveToFile();

   bool loadFromFile();

};


#endif //MULTIPLICATIVEPERSISTENCE_DATAMANAGEMENT_H
