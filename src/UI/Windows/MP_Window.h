//
// Created by ursbe on 16.09.2023.
//

#ifndef MULTIPLICATIVEPERSISTENCE_MP_WINDOW_H
#define MULTIPLICATIVEPERSISTENCE_MP_WINDOW_H

#include "../src/Data/DataManagement.h"
#include "ImguiWindow.h"
#include "imgui.h"

class MP_Window : public ImguiWindow {

public:
   MP_Window();

   void update() override;

   void shutdown() override;

private:
   void menuBar();
   void dataTable();
   void doMultiplicativePersistence();

   ImGuiWindowFlags window_flags;

   DataManagement data;

   MultiPers highest;

   ImFont* font;

	bool startMP = false;
};

#endif //MULTIPLICATIVEPERSISTENCE_MP_WINDOW_H