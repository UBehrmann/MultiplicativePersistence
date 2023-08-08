//
// Created by ursbe on 08.08.2023.
//

#include "MultiplicativePersistence.h"
#include <iostream>

using namespace std;

unsigned long long MultiplicativePersistence(unsigned long long number) {

   if( number <= 9){
      return 0;
   }else{
      return 1 + MultiplicativePersistence(addNumber(number));
   }
}

unsigned long long addNumber(unsigned long long number) {
   unsigned long long toReturn = 1;
   string strNumber = to_string(number);

   for (int i = 0; i < strNumber.length(); i++) {
      toReturn *= strNumber[i] - '0';
   }

   return toReturn;
}