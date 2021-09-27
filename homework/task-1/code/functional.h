#ifndef __functional__
#define __functional__

//------------------------------------------------------------------------------
// functional.h - содержит описание функционального ЯП
//------------------------------------------------------------------------------

#include <fstream>

//------------------------------------------------------------------------------
// функциональный ЯП
struct functional {
    // типизация
    enum typing {STATIC, DYNAMIC};
    // поддержка «ленивых» вычислений
    bool supportLazyCalculations;
};

// Ввод параметров функционального ЯП из файла
void In(functional &f, std::ifstream &ifst);

// Случайный ввод параметров функционального ЯП
void InRnd(functional &f);

// Вывод параметров функционального ЯП в форматируемый поток
void Out(functional &f, std::ofstream &ofst);

// Вычисление частного от деления года создания на количество
// символов в названии (действительное число)
double EvaluateUseless(functional &f);

#endif //__functional__
