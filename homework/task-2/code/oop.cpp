//------------------------------------------------------------------------------
// oop.cpp - содержит функции обработки для объектно-ориентированных ЯП
//------------------------------------------------------------------------------

#include "oop.h"
#include "constants.h"
#include "rnd.h"

//------------------------------------------------------------------------------
// Ввод параметров ЯП из потока
language *oop::In(std::istream &ifst) {
    oop *ooplang = new oop;
    int inheritance;
    ifst >> ooplang->name >> ooplang->tiobeRating >> ooplang->releaseYear >> inheritance;
    if (inheritance == 0) {
        ooplang->inhType = oop::inheritance::SINGLE;
    } else if (inheritance == 1) {
        ooplang->inhType = oop::inheritance::MULTIPLE;
    } else {
        ooplang->inhType = oop::inheritance::INTERFACE;
    }
    return ooplang;
}

// Случайный ввод параметров объектно-ориентированного ЯП
oop *oop::random() {
    auto o = new oop;
    for (size_t i = 0; i < MAX_NAME_LEN; ++i) {
        o->name[i] = char('a' + Random());
    }
    o->name[MAX_NAME_LEN - 1] = '\0';
    o->tiobeRating = Random() + Random() / 100.0;
    o->releaseYear = MIN_YEAR + Random();
    int inheritance = Random() % 3;
    if (inheritance == 0) {
        o->inhType = oop::inheritance::SINGLE;
    } else if (inheritance == 1) {
        o->inhType = oop::inheritance::MULTIPLE;
    } else {
        o->inhType = oop::inheritance::INTERFACE;
    }
    return o;
}

//------------------------------------------------------------------------------
// Вывод параметров объектно-ориентированного ЯП в форматируемый поток
void oop::Out(std::ostream &ofst) {
    ofst << "It is Object-oriented language: name = "
         << name << " (" << tiobeRating << "% | " << releaseYear
         << "), inheritance = "
         << (inhType == 0 ? "SINGLE" : (inhType == 1 ? "MULTIPLE" : "INTERFACE"))
         << ". year / name.size() = " << YearDividedByNameLength() << "\n";
}
