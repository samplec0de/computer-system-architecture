//------------------------------------------------------------------------------
// language.cpp - содержит процедуры связанные с обработкой обобщенного ЯП
// и создания одной из альтернатив (ООП/функциональный/процедурный)
//------------------------------------------------------------------------------

#include "language.h"
#include "procedure.h"
#include "functional.h"
#include "oop.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенного ЯП
language *language::In(std::istream &ifst) {
    char type[MAX_NAME_LEN];
    ifst >> type;
    if (!strcmp(type, "procedure")) {
        return procedure::In(ifst);
    } else if (!strcmp(type, "functional")) {
        return functional::In(ifst);
    } else if (!strcmp(type, "oop")) {
        return oop::In(ifst);
    } else {
        std::cout << "ERROR: Wrong language type " << type;
        exit(1);
    }
}

// Случайный ввод обобщенного ЯП
language *language::random() {
    language *lang;
    auto type = rand() % 3;
    if (type == 0) {
        lang = procedure::random();
    } else if (type == 2) {
        lang = functional::random();
    } else {
        lang = oop::random();
    }
    return lang;
}

//------------------------------------------------------------------------------
// Вычисление частного от деления года создания на количество
// символов в названии (действительное число)
double language::YearDividedByNameLength() const {
    return releaseYear / double(strlen(name));
}
