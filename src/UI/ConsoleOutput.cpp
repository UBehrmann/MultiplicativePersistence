//
// Created by ursbe on 08.08.2023.
//

#include <cstdlib>
#include <iostream>
#include <windows.h>
#include "ConsoleOutput.h"

using namespace std;

void showStage(MultiPers number, vector<MultiPers> numbers) {

   static size_t lastSize = 0;
   size_t currentSize = numbers.size();

   //Clear console
   setScreenPosition(0, lastSize);

   if(lastSize < currentSize){
      // Show all the lowest numbers for each step
      for (size_t i = lastSize; i < currentSize; i++) {
         cout << "Step " << i << ": " << numbers[i]  << "                                                    "<< endl;
      }
      lastSize = currentSize;
   }

   // Show current number
   cout << "Current number: " << number << endl;

   // % done to ULLONG_MAX
   cout << "Progress: " << (static_cast<double>(number) / static_cast<double>(ULLONG_MAX)) * 100 << "%" << endl;
}

void setScreenPosition(size_t x, size_t y){

   COORD cursorPosition;

   cursorPosition.X = (short)x;
   cursorPosition.Y = (short)y;

   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}
