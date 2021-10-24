//------------------------------------------------------------------------------
// functional.cpp - содержит функции обработки для процедурных ЯП
//------------------------------------------------------------------------------

#include "functional.h"
#include "constants.h"
#include "rnd.h"

//------------------------------------------------------------------------------
// Ввод параметров ЯП из потока
language *functional::In(std::istream &ifst) {
    functional *func = new functional;
    ifst >> func->name >> func->tiobeRating >> func->releaseYear;
    bool isDynamicTyping, supportLazyCalculations;
    ifst >> isDynamicTyping >> supportLazyCalculations;
    func->t = isDynamicTyping ? functional::typing::DYNAMIC : functional::typing::STATIC;
    func->supportLazyCalculations = supportLazyCalculations;
    return func;
}

// Случайный ввод параметров процедурного ЯП
functional *functional::random() {
    auto func = new functional;
    for (size_t i = 0; i < MAX_NAME_LEN; ++i) {
        func->name[i] = char('a' + Random());
    }
    func->name[MAX_NAME_LEN - 1] = '\0';
    func->tiobeRating = Random() + Random() / 100.0;
    func->releaseYear = MIN_YEAR + Random();
    func->t = Random() % 2 ? functional::typing::DYNAMIC : functional::typing::STATIC;
    func->supportLazyCalculations = Random() % 2;
    return func;
}

//------------------------------------------------------------------------------
// Вывод параметров процедурного ЯП в форматируемый поток
void functional::Out(std::ostream &ofst) {
    ofst << "It is Functional language: name = "
         << name << " (" << tiobeRating << "% | " << releaseYear << "), typing = "
         << (t ? "DYNAMIC" : "STATIC")
         << ", lazy calculations = " << (supportLazyCalculations ? "true" : "false")
         << ". year / name.size() = " << YearDividedByNameLength() << "\n";
}
