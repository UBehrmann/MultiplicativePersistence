//
// Created by ursbe on 08.08.2023.
//

#include <fstream>
#include "FileManagement.h"

void saveToFile(MultiPers number, std::vector<MultiPers> numbers) {

   std::ofstream file;
   file.open("save.txt");

   file << number << std::endl;

   for(MultiPers i : numbers){
      file << i << std::endl;
   }

   file.close();
}

void loadFromFile(MultiPers &number, std::vector<MultiPers> &numbers) {

   std::ifstream file;
   file.open("save.txt");

   std::string line;

   std::getline(file, line);

   for(char i : line){
      number *= 10;
      number += static_cast<MultiPers>(i - '0');
   }

   file.close();

}
