//
// Created by ursbe on 08.08.2023.
//

#ifndef MULTIPLICATIVEPERSISTENCE_MULTIPLICATIVEPERSISTENCE_H
#define MULTIPLICATIVEPERSISTENCE_MULTIPLICATIVEPERSISTENCE_H

#define STEP_TO_DO ULLONG_MAX
#define UPDATE_CONSOLE_EVERY_X_STEPS 100000

typedef unsigned long long MultiPers;

MultiPers MultiplicativePersistence(MultiPers number);

MultiPers addNumber(MultiPers number);

void runMultiplicativePersistence();

#endif //MULTIPLICATIVEPERSISTENCE_MULTIPLICATIVEPERSISTENCE_H
