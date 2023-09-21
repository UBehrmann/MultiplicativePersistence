//
// Created by ursbe on 09.08.2023.
//

#ifndef MULTIPLICATIVEPERSISTENCE_DATAMANAGEMENT_H
#define MULTIPLICATIVEPERSISTENCE_DATAMANAGEMENT_H

#include "../MP/MPType.h"
#include <vector>
#include "../Libs/json/json_util.h"
#include <iostream>
#include <string>

class DataManagement {
private:

	MultiPers number;
	std::vector<MultiPers> numbers;

	std::string dataPath = "./Data/data.json";

public:
   DataManagement();

	const std::vector<MultiPers>& getNumbers() const;

   MultiPers getNumber() const;

   void numberAddOne();

   void addNumber(MultiPers number);

   bool save() const;

   bool load();

	// For JSON conversion
	NLOHMANN_DEFINE_TYPE_INTRUSIVE(DataManagement, number, numbers)

	JSON_DEFINE_FLUX_OPERATORS(DataManagement)
};

#endif //MULTIPLICATIVEPERSISTENCE_DATAMANAGEMENT_H
