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

class DataManagement {
private:

	MultiPers number;
	std::vector<MultiPers> numbers;

public:
   DataManagement();

	const std::vector<MultiPers>& getNumbers() const;

   MultiPers getNumber() const;

   void numberAddOne();

   void addNumber(MultiPers number);

   bool save();

   bool load();

	// For JSON convertion
	NLOHMANN_DEFINE_TYPE_INTRUSIVE(DataManagement, number, numbers)

	JSON_DEFINE_FLUX_OPERATORS(DataManagement)
};

#endif //MULTIPLICATIVEPERSISTENCE_DATAMANAGEMENT_H
