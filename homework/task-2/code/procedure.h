#ifndef __procedure__
#define __procedure__

//------------------------------------------------------------------------------
// procedure.h - содержит описание функционального ЯП
//------------------------------------------------------------------------------

#include <fstream>
#include "constants.h"
#include "rnd.h"
#include "language.h"

//------------------------------------------------------------------------------
// процедурный ЯП
class procedure : public language {
public:
    // флаг поддержки абстрактных типов данных
    bool supportAbstractTypes;

    // Вывод процедурного ЯП
    void Out(std::ostream &ofst) override;

    // Ввод параметров процедурного ЯП
    static language *In(std::istream &ifst);

    // Случайный ввод параметров процедурного ЯП
    static procedure *random();
};

#endif //__procedure__
