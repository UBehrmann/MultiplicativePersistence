/**
 * @file ImguiWindow.h
 * @brief This file contains the ImguiWindow class
 * @date 16.09.2023
 */

#ifndef MULTIPLICATIVEPERSISTENCE_IMGUIWINDOW_H
#define MULTIPLICATIVEPERSISTENCE_IMGUIWINDOW_H

class ImguiWindow {

public:

   virtual ~ImguiWindow() = default;

   virtual void update() = 0;

   virtual void shutdown() = 0;

};

#endif //MULTIPLICATIVEPERSISTENCE_IMGUIWINDOW_H