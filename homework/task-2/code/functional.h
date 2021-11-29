#ifndef __functional__
#define __functional__

//------------------------------------------------------------------------------
// functional.h - содержит описание функционального ЯП
//------------------------------------------------------------------------------

#include <fstream>
#include "constants.h"
#include "rnd.h"
#include "language.h"

//------------------------------------------------------------------------------
// функциональный ЯП
class functional : public language {
public:
    // типизация: статическая, динамическая
    enum typing {STATIC, DYNAMIC};
    typing t;
    // поддержка «ленивых» вычислений
    bool supportLazyCalculations;

    // Вывод параметров функционального ЯП в форматируемый поток
    void Out(std::ostream &ofst) override;

    // Ввод параметров функционального ЯП
    static language *In(std::istream &ifst);

    // Случайный ввод параметров функционального ЯП
    static functional *random();
};

#endif //__functional__
