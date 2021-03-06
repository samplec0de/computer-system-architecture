#ifndef __language__
#define __language__

//------------------------------------------------------------------------------
// programming_language.h - содержит описание обобщающего языка программирования (ЯП),
//------------------------------------------------------------------------------

#include <iostream>

#include "constants.h"

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся ЯП
class language {
public:
    // имя, ограничимся лимитом для упрощения архитектуры
    char name[MAX_NAME_LEN];
    // год создания языка
    int releaseYear;
    // популярность в процентах (TIOBE)
    double tiobeRating;

    // Вывод обобщенного ЯП
    static language *In(std::istream &ifst);

    // Ввод обобщенного ЯП
    virtual void Out(std::ostream &ofst) = 0;

    // Вычисление частного от деления года создания на количество
    // символов в названии (действительное число)
    double YearDividedByNameLength() const;

    // Случайный ввод обобщенного ЯП
    static language *random();
};

#endif
