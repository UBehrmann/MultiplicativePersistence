#include "MP/MultiplicativePersistence.h"
#include "Data/DataManagement.h"
#include "UI/UI.h"
#include "UI/Windows/MP_Window.h"

int main(int argc, char** argv) {

   UI uI;

   MP_Window mP_UI;

   if (uI.Init("Multiplicative Persistence"))
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


