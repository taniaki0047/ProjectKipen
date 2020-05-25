#include "Interval.h"
#ifndef SET_OF_INTERVALS_H_INCLUDED
#define SET_OF_INTERVALS_H_INCLUDED
//структура, €вл€юща€с€ массивом интервалов=
typedef struct SetIntervals {
    Interval *interval_array;
    int size;
} set_intervals;
//функции, использующиес€ дл€ работы с этой структурой
set_intervals *Make_arrayof_Int(Interval *content, int length);
set_intervals    *Set_Insection(set_intervals *first, set_intervals *second);
void PrintRes3(set_intervals *res);
set_intervals   *FindElem(set_intervals *kek, Interval * b);
set_intervals    *Set_Difference(set_intervals *first, set_intervals *second);
set_intervals    *Set_Multyp(set_intervals *first, set_intervals *second);
set_intervals  *TheLenght(set_intervals *first);
#endif // SET_OF_INTERVALS_H_INCLUDED
