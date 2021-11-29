//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера
container::container() {
    len = 0;
    for (size_t i = 0; i < MAX_LEN; ++i) {
        cont[i] = nullptr;
    }
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
container::~container() {
    for (size_t i = 0; i < MAX_LEN; ++i) {
        delete cont[i];
    }
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
std::istream &operator>>(std::istream &input, container &c) {
    char type[MAX_NAME_LEN];
    while (input >> type) {
        language *lang;
        if (!strcmp(type, "procedure")) {
            lang = procedure::In(input);
        } else if (!strcmp(type, "functional")) {
            lang = functional::In(input);
        } else if (!strcmp(type, "oop")) {
            lang = oop::In(input);
        } else if (strlen(type)) {
            std::cout << "ERROR: Wrong language type " << type;
            exit(1);
        } else {
            break;
        }
        c.cont[c.len] = lang;
        c.len++;
    }
    return input;
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void container::fillRandomly(int size) {
    while (len < size) {
        if ((cont[len] = language::random()) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
std::ostream &operator<<(std::ostream &output, const container &c) {
    output << "Container contains " << c.len << " elements.\n";
    for (int i = 0; i < c.len; i++) {
        output << i << ": ";
        c.cont[i]->Out(output);
    }
    return output;
}

// Сортировка контейнера методом Straight Selection
void container::sort() {
    int i = 0, j, k;
    language *temp;
    while (i < len) {
        k = i;
        for (j = i + 1; j < len; j++) {
            if (cont[j]->YearDividedByNameLength() > cont[k]->YearDividedByNameLength()) {
                k = j;
            }
        }
        temp = cont[i];
        cont[i] = cont[k];
        cont[k] = temp;
        i++;
    }
}
