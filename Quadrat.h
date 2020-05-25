#include "Set_of_intervals.h"
#ifndef QUADRAT_H_INCLUDED
#define QUADRAT_H_INCLUDED
//типы данных для квадратных неравенств
enum type_of_sign{
    greater,
    less,
    greater_equal,
    less_equal,
    equal,
    not_equal,

};

//структура, задающая квадратное уравнение вида а*х**2 + б*х + с = 0
typedef struct s_quadratic_inequalities
{
    int a;
    int b;
    int c;
    enum type_of_sign sign;
}               QuadraticInequalities;

QuadraticInequalities   *SetIneq(float a, float b, float c, enum type_of_sign sign);
set_intervals *Make_set(QuadraticInequalities test);
set_intervals* find_solution(set_intervals* ints1, set_intervals* ints2);


#endif // QUADRAT_H_INCLUDED
