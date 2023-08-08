//
// Created by ursbe on 08.08.2023.
//

#ifndef MULTIPLICATIVEPERSISTENCE_CONSOLEOUTPUT_H
#define MULTIPLICATIVEPERSISTENCE_CONSOLEOUTPUT_H

#include <vector>
#include "MPType.h"

/**
 * Shows the current stage in the console
 * @param number
 * @param numbers
 */
void showStage(MultiPers number, std::vector<MultiPers> numbers);

/**
 * Sets the cursor position in the console
 * @param x
 * @param y
 */
void setScreenPosition(size_t x = 0, size_t y = 0);



#endif //MULTIPLICATIVEPERSISTENCE_CONSOLEOUTPUT_H
