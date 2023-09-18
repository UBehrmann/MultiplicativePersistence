#include "MP/MultiplicativePersistence.h"
#include "Data/DataManagement.h"
#include "UI/UI.h"

int main(int argc, char** argv) {

   DataManagement dataManagement;

   dataManagement.loadFromFile();

   dataManagement.addNumber(dataManagement.getNumber() + 1);

   dataManagement.numberAddOne();

   dataManagement.saveToFile();

   return EXIT_SUCCESS;


   UI uI;

   if (uI.Init("Multiplicative Persistence") != 0)
      return EXIT_FAILURE;

   while(uI.windowShouldClose()){
      // Poll events from mouse and keyboard
      uI.pollEvents();

      uI.newFrame();

      uI.Update();

      uI.Render();
   }

   uI.Shutdown();

   return EXIT_SUCCESS;

   return 0;
}


