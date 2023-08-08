#include <iostream>
#include <string>
#include "MultiplicativePersistence.h"

using namespace std;

#define STEP_TO_DO ULLONG_MAX \
// 18'446'744'073'709'551'615
//        277'777'788'888'899

int main() {

   unsigned long long number = 1; // 277777788888899; // 277 777 788 888 899 11 steps
   unsigned long long steps = 0;
   unsigned long long nbOfSteps = 0;
   unsigned long long highest = 0;
   unsigned long long highestNumber = 0;

   do {

      steps = MultiplicativePersistence(number);

      if(steps > highest){
         cout << "Number : " << number << " Steps : " << steps << endl;
         highest = steps;
         highestNumber = number;
      }

      number++;
   } while (STEP_TO_DO > number);

   return 0;
}


