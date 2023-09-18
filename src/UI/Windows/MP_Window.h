//
// Created by ursbe on 16.09.2023.
//

#ifndef MULTIPLICATIVEPERSISTENCE_MP_WINDOW_H
#define MULTIPLICATIVEPERSISTENCE_MP_WINDOW_H

#include "../src/Data/DataManagement.h"
#include "ImguiWindow.h"

class MP_Window : public ImguiWindow {

public:
   MP_Window();

   void update() override;

   void shutdown() override;

private:
   void menuBar();

   DataManagement data;

   MultiPers highest;
};


#endif //MULTIPLICATIVEPERSISTENCE_MP_WINDOW_H
