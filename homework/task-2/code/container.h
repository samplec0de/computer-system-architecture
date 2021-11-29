#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "language.h"
#include "procedure.h"
#include "functional.h"
#include "oop.h"

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
class container {
public:
    static const int MAX_LEN = 10000; // максимальная длина
    int len; // текущая длина
    language *cont[MAX_LEN];
    // Инициализация контейнера
    container();
    // Очистка контейнера от элементов (освобождение памяти)
    ~container();

    // Вывод содержимого контейнера в указанный поток
    friend std::ostream &operator<<(std::ostream &output, const container &c);

    // Ввод содержимого контейнера из указанного потока
    friend std::istream &operator>>(std::istream  &input, container &c);

    // Случайный ввод содержимого контейнера
    void fillRandomly(int size);

    // Сортировка контейнера методом Straight Selection
    void sort();
};

#endif
