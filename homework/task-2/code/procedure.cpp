//------------------------------------------------------------------------------
// procedure.cpp - содержит функции обработки для процедурных ЯП
//------------------------------------------------------------------------------

#include "procedure.h"

//------------------------------------------------------------------------------
// Ввод параметров процедурного ЯП из потока
language *procedure::In(std::istream &ifst) {
    procedure *proc = new procedure;
    ifst >> proc->name >> proc->tiobeRating >> proc->releaseYear >> proc->supportAbstractTypes;
    return proc;
}

// Случайный ввод параметров процедурного ЯП
procedure *procedure::random() {
    auto* proc = new procedure;
    for (size_t i = 0; i < MAX_NAME_LEN; ++i) {
        proc->name[i] = char('a' + Random());
    }
    proc->name[MAX_NAME_LEN - 1] = '\0';
    proc->tiobeRating = Random() + Random() / 100.0;
    proc->releaseYear = MIN_YEAR + Random();
    proc->supportAbstractTypes = Random() % 2;
    return proc;
}

//------------------------------------------------------------------------------
// Вывод параметров процедурного ЯП в форматируемый поток
void procedure::Out(std::ostream &ofst) {
    ofst << "It is Procedure language: name = "
         << name << " (" << tiobeRating << "% | " << releaseYear
         << "), abstract types support = "
         << (supportAbstractTypes ? "true" : "false")
         << ". year / name.size() = " << YearDividedByNameLength() << "\n";
}
