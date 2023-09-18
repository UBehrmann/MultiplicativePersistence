//
// Created by ursbe on 18.09.2023.
//

#ifndef MULTIPLICATIVEPERSISTENCE_MAINWINDOW_H
#define MULTIPLICATIVEPERSISTENCE_MAINWINDOW_H

#include "ImguiWindow.h"

class MainWindow : public ImguiWindow {

public:

   ~MainWindow() override = default;

   void update() override;

   void shutdown() override;

};

#endif //MULTIPLICATIVEPERSISTENCE_MAINWINDOW_H