#include "MP/MultiplicativePersistence.h"
#include "Data/DataManagement.h"
#include "UI/UI.h"

int main(int argc, char** argv) {

//   DataManagement dataManagement;
//
//   runMultiplicativePersistence(dataManagement);

   UI uI;

   if (uI.Init() != 0)
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


