#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math.h"
#include "stdbool.h"

#ifndef INTARVAL_H_INCLUDED
#define INTARVAL_H_INCLUDED
enum type_interval{
    Empty,
    SingleDot,
    Closed,
    HalfClosedLeft,
    HalfClosedRight,
    Opened,
    InfiniteLeft_RightOpen,
    InfiniteLeft_RightClosed,
    InfiniteRight_LeftOpen,
    InfiniteRight_LeftClosed,
    Infinite
} ;

//конструктор структуры интервал
typedef struct s_interval{
    int a;
    int b;
    enum type_interval type;
}               Interval;


//функции, относящиеся к этой структуре
Interval  *SetInterval(int a, int b, enum type_interval type);
char  WhatTypeLeft(Interval *test);
char WhatTypeRight(Interval *test);
char Whatisreasltype(bool a, bool b);
enum type_interval FinilType(bool a, bool b);
void    PrintInterval(Interval *interval);
Interval    *DivideIntervals(Interval *first, Interval *second);
char Whatisreasltype1(char a, char b);
Interval *Multiplication_Int(Interval *first, Interval *second);
void PrintRes1(Interval *res);
char Type_dif(bool a);
Interval *Difference_Int(Interval *first, Interval *second);

#endif // INTARVAL_H_INCLUDED
