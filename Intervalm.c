#include "Interval.h"
//�������, �������� ��������
Interval  *SetInterval(int a, int b, enum type_interval type)
{
    Interval * interval = (Interval*)malloc(sizeof(Interval));
    interval->a = a;
    interval->b = b;
    interval->type = type;
    return interval;
}
/* �������, ������������ ��� ������ ����� ��������:true - ��������, false - �������� */
char  WhatTypeLeft(Interval *test)
{
    if (test->type == Closed || test->type == SingleDot || test->type == HalfClosedLeft ||
    test->type == InfiniteRight_LeftClosed)
    {
        return true;
    }else
    {
        return false;
    }
}
/*���������� ��� ������� �����*/
char WhatTypeRight(Interval *test)
{
    if (test->type == Closed || test->type == SingleDot || test->type == HalfClosedRight ||
            test->type == InfiniteLeft_RightClosed)
    {
        return true;
    }else
    {
        return false;
    }
}
/* ������� ��� ����������� ���� ��������� ���� **(�������� ��� �������� �������� � ��������)*/
char Whatisreasltype(bool a, bool b)
{
    if (a == true &&  b == true)
    {
        return true;
    }else
    {
        return false;
    }
}
//�������, ������������ ����� ��� ���������
enum type_interval FinilType(bool a, bool b)
{
    Interval *Result = (Interval*) malloc(sizeof(Interval));

    if (a == false && b == false)
    {
        Result->type = Opened;
    }

    if (a == true && b == true)
    {
        Result->type = Closed;
    }

    if (a == false && b == true)
    {
        Result->type = HalfClosedRight;
    }
    if (a == true && b == false)
    {
        Result->type = HalfClosedLeft;
    }
    return Result->type;
}
//����� �� �����
void    PrintInterval(Interval *interval)
{
    switch (interval->type)
    {
        case Empty:
            printf("");
            break;
        case Opened:
            printf("(%d, %d)\n", interval->a, interval->b);
            break;
        case SingleDot:
            printf("[%d, %d]\n ", interval->a, interval->b);
            break;
        case Closed:
            printf("[%d, %d]\n", interval->a, interval->b);
            break;
        case HalfClosedLeft:
            printf("[%d, %d)\n", interval->a, interval->b);
            break;
        case HalfClosedRight:
            printf("(%d, %d]\n", interval->a, interval->b);
            break;
        default:
            break;
    }
}
//������������ 2 ���������� + ��������� ��� ����������� ������ ���������
Interval    *DivideIntervals(Interval *first, Interval *second)
{
    Interval *Result = (Interval*) malloc(sizeof(Interval));
    float  k = 999999999; //�������������
    if (first->type == Infinite || first->type == InfiniteLeft_RightClosed || first->type == InfiniteLeft_RightOpen) {
        first->a = -1 *  k;
    }
    if (first->type == Infinite || first->type == InfiniteRight_LeftClosed || first->type == InfiniteRight_LeftOpen) {
        first->b =  k;
    }
    if (second->type == Infinite || second->type == InfiniteLeft_RightOpen || second->type == InfiniteLeft_RightClosed)
    {
        second->a = -1 * k;
    }
    if (second->type == Infinite || second->type == InfiniteRight_LeftOpen || second->type == InfiniteRight_LeftClosed)
    {
        second->b = k;
    }

    // ��������: 1 �������� ������� ��� �� ����� ����������� �� ����������
    if (first->type == Empty || second->type == Empty || first->a > second->b || first->b < second->a) {
        Result->a = 0;
        Result->b = 0;
        Result->type = Empty;
        return Result;
    }

    //1 �������� ��������� ����������� 2
    if (first->a < second->a && second->b < first->b) {
        Result->a = second->a;
        Result->b = second->b;
        Result->type = second->type;
        return Result;
    }

    // 2 �������� ��������� ����������� 1
    if (first->a > second->a && second->b > first->b) {
        Result->a = first->a;
        Result->b = first->b;
        Result->type = second->type;
        return Result;
    }

    if (first->b == second->a && first->a == second->b) {
        if (WhatTypeRight(first) == WhatTypeLeft(second) && WhatTypeLeft(second) == true) {
            Result->a = first->b;
            Result->b = second->a;
            Result->type = Closed;
        } else {
            Result->a = 0;
            Result->b = 0;
            Result->type = Empty;
        }
        return Result;
    }

    // ��������� ���������
    if (first->a == second->a && second->b == first->b) {
        Result->a = first->a;
        Result->b = first->b;
        Result->type = FinilType(Whatisreasltype(WhatTypeLeft(first), WhatTypeLeft(second)),
                                 Whatisreasltype(WhatTypeRight(first), WhatTypeRight(second)));
        return Result;
    }
    // 2 �������� ����������� 1
    if (first->a < second->a && second->b > first->b) {
        Result->a = second->a;
        Result->b = first->b;
        Result->type = FinilType(WhatTypeLeft(second), WhatTypeRight(first));
        return Result;
    }
    // ���������� ��� 1
    if (first->a > second->a && first->a < second->b && second->b < first->b)
    {
        Result->a = first->a;
        Result->b = second->b;
        Result->type = FinilType(WhatTypeLeft(first),WhatTypeRight(second));
        return Result;
    }
    // ����� ���������� � 1
    if (first->a == second->a && second->b < first->b)
    {
        Result->a = first->a;
        Result->b = second->b;
        Result->type = FinilType(Whatisreasltype(WhatTypeLeft(first),WhatTypeLeft(second)),WhatTypeRight(second));
        return Result;
    }
    //����� ���������� � 2
    if (first->a == second->a && second->b > first->b)
    {
        Result->a = first->a;
        Result->b = first->b;
        Result->type = FinilType(Whatisreasltype(WhatTypeLeft(first),WhatTypeLeft(second)),WhatTypeRight(first));
        return Result;
    }

    //������ ���������� � 2
    if (first->a > second->a && second->b == first->b)
    {
        Result->a = first->a;
        Result->b = first->b;
        Result->type = FinilType(WhatTypeLeft(first), Whatisreasltype(WhatTypeRight(first),WhatTypeRight(second)));
        return Result;
    }
    //������ ���������� � 1
    if (first->a < second->a && second->b == first->b)
    {
        Result->a = second->a;
        Result->b = first->b;
        Result->type = FinilType(WhatTypeRight(second),Whatisreasltype(WhatTypeRight(first),WhatTypeRight(second)));
        return Result;
    }
}
//�������, ������������ ���� �� ����� ������ �������� ��� �����������
char Whatisreasltype1(char a, char b)
{
    if (a == false &&  b == false)
    {
        return false;
    }else
    {
        return true;
    }
}
/*�������, ������������ ���������� 2 ����������;
����� ���������� ������*/
Interval *Multiplication_Int(Interval *first, Interval *second)
{
    Interval *res = (Interval*) malloc(sizeof(Interval)*2) ;
    //������ ������������
    float  k = INFINITY;
    if (first->type == Infinite || first->type == InfiniteLeft_RightClosed || first->type == InfiniteLeft_RightOpen) {
        first->a = -1 * k;
    }
    if (first->type == Infinite || first->type == InfiniteRight_LeftClosed || first->type == InfiniteRight_LeftOpen) {
        first->b = k;
    }
    if (second->type == Infinite || second->type == InfiniteLeft_RightOpen || second->type == InfiniteLeft_RightClosed)
    {
        second->a = -1 * k;
    }
    if (second->type == Infinite || second->type == InfiniteRight_LeftOpen || second->type == InfiniteRight_LeftClosed)
    {
        second->b = k;
    }
    //���������� ���������
    if (first->a == second->a && first->b == second->b) {
        res->a = first->a;
        res->b = second->b;
        res->type = FinilType(Whatisreasltype1(WhatTypeLeft(first), WhatTypeLeft(second)),
                              Whatisreasltype1(WhatTypeRight(second), WhatTypeRight(first)));
        return res;
    }
    //���������� ����� first->a � second->b
    if (first->a == second->b)
    {
        res->a = second->a;
        res->b = first->b;
        res->type = FinilType(WhatTypeLeft(second), WhatTypeRight(first));
        return res;
    }

    //1 ����� � 2
    if (first->a < second->a && first->b > second->b)
    {
        res->a = first->a;
        res->b = first->b;
        res->type = FinilType(WhatTypeLeft(first), WhatTypeRight(first));
        return res;
    }

    //2 ����� � 1
    if (first->a > second->a && first->b < second->b)
    {
        res->a = second->a;
        res->b = second->b;
        res->type = FinilType(WhatTypeLeft(second), WhatTypeRight(second));
        return res;
    }


    // ���������� ����� first->b � second->a
    if (first->b == second->a)
    {
        res->a = first->a;
        res->b = second->b;
        res->type = FinilType(WhatTypeLeft(first), WhatTypeRight(second));
        return res;
    }

    // ���������� ����� first->b � second->a
    if (first->a < second->a && first->b > second->a && second->b > first->b)
    {
        res->a = first->a;
        res->b = second->b;
        res->type = FinilType(WhatTypeLeft(first), WhatTypeRight(second));
        return res;
    }

    // ���������� ����� first->a � second->b
    if (first->a > second->a && first->a < second->b && second->b < first->b)
    {
        res->a = second->a;
        res->b = first->b;
        res->type = FinilType(WhatTypeLeft(second), WhatTypeRight(first));
        return res;
    }


    //����� ���� ��������� � 2 ������
    if(first->a == second->a && first->b < second->b)
    {
        res->a = first->a;
        res->b = second->b;
        res->type = FinilType(Whatisreasltype1(WhatTypeLeft(first),WhatTypeLeft(second)), WhatTypeRight(second));
        return res;
    }

    //����� ��������� � ������ ������
    if(first->a == second->a && first->b > second->b)
    {
        res->a = first->a;
        res->b = first->b;
        res->type = FinilType(Whatisreasltype1(WhatTypeLeft(first),WhatTypeLeft(second)), WhatTypeRight(first));
        return res;
    }

    //������ ��������� ����� ������
    if(first->a < second->a && first->b == second->b)
    {
        res->a = first->a;
        res->b = first->b;
        res->type = FinilType(WhatTypeLeft(first),Whatisreasltype1(WhatTypeRight(first), WhatTypeRight(second)));
        return res;
    }

    //������ ��������� � ����� ������
    if(first->a > second->a && first->b == second->b)
    {
        res->a = second->a;
        res->b = first->b;
        res->type = FinilType(WhatTypeLeft(second),Whatisreasltype1(WhatTypeRight(first), WhatTypeRight(second)));
        return res;
    }

    // ��� ������, ����� ���� ������ 2 ���������
    if (second->b < first->a || first->b < second->a || ((first->a == second->b && Whatisreasltype1(WhatTypeLeft(first),
            WhatTypeRight(second) == false))) || (first->b == second->a && Whatisreasltype1(WhatTypeRight(first),
                                                                                                                                                                                    WhatTypeLeft(second) == false)))
    {
        res[0] = *first;
        res[1] = *second;
        return res;
    }
}
// ����� ������� ����������
void PrintRes1(Interval *res)
{
    for (int i = 0; i < sizeof(res)/ sizeof(int) + 1; i ++)
    {
        PrintInterval(&res[i]);
    }
}
// �������, ������������ ����� ������� ����������
char Type_dif(bool a)
{
    if (a == true)
    {
        return false;
    }else
    {
        return true;
    }
}
//������� ��� ����������� ������� 2 ����������; ����� ���������� ������

Interval *Difference_Int(Interval *first, Interval *second)
{
    Interval *res = (Interval *) malloc(sizeof(Interval) * 2);
    Interval *res_test ;
    float  k = INFINITY;
    if (first->type == Infinite || first->type == InfiniteLeft_RightClosed || first->type == InfiniteLeft_RightOpen) {
        first->a = -1 * k;
    }
    if (first->type == Infinite || first->type == InfiniteRight_LeftClosed || first->type == InfiniteRight_LeftOpen) {
        first->b = k;
    }
    if (second->type == Infinite || second->type == InfiniteLeft_RightOpen || second->type == InfiniteLeft_RightClosed)
    {
        second->a = -1 * k;
    }
    if (second->type == Infinite || second->type == InfiniteRight_LeftOpen || second->type == InfiniteRight_LeftClosed)
    {
        second->b = k;
    }
    res_test = DivideIntervals(first,second);
    //������� ����������� ��� ���
    if(res_test->type == Empty)
    {
        res->a = first->a;
        res->b = first->b;
        res->type = first->type;
        return res;
    }
    // �� � ���� ������������
    if(res_test->type == first->type && res_test->a == first->a && res_test->b == first->b)
    {
        res->a = 0;
        res->b = 0;
        res->type = Empty;
        return res;
    }
    // 2 ���� �� ��������
    if (res_test->a == first->a && res_test->b == first->b && WhatTypeLeft(res_test) != WhatTypeLeft(first) &&
        WhatTypeRight(res_test) != WhatTypeRight(first))
    {
        res[0].a = first->a;
        res[0].b = first->a;
        res[0].type = Closed;
        res[1].a = first->b;
        res[1].b = first->b;
        res[1].type = Closed;
        return res;
    }
    //����� �� ��������
    if (res_test->a == first->a && res_test->b == first->b && WhatTypeLeft(res_test) != WhatTypeLeft(first))
    {
        res->a = first->a;
        res->b = first->a;
        res->type = Closed;
        return res;
    }
    //������ �� ��������
    if (res_test->a == first->a && res_test->b == first->b && WhatTypeRight(res_test) != WhatTypeRight(first))
    {
        res->a = first->b;
        res->b = first->b;
        res->type = Closed;
        return res;
    }
    //����������� - ����� ��������� ��� ������
    if (res_test->a > first->a && res_test->b < first->b)
    {
        res[0].a = first->a;
        res[0].b = res_test->a;
        res[0].type = FinilType(WhatTypeLeft(first), Type_dif(WhatTypeLeft(res_test)));
        res[1].a = res_test->b;
        res[1].b = first->b;
        res[1].type = FinilType(Type_dif(WhatTypeRight(res_test)), WhatTypeRight(first));
        return res;
    }
    // ����� ����������, ������ ������
    if(res_test->a == first->a && res_test->b < first->b)
    {
        if(WhatTypeLeft(res_test) == WhatTypeLeft(first))
        {
            res->a = res_test->b;
            res->b = first->b;
            res->type = FinilType(Type_dif(WhatTypeRight(res_test)), WhatTypeRight(first));
        } else
        {
            res[0].a = first->a;
            res[0].b = first->a;
            res[0].type = Closed;
            res[1].a = res_test->b;
            res[1].b = first->b;
            res[1].type = FinilType(Type_dif(WhatTypeRight(res_test)), WhatTypeRight(first));
        }
        return res;
    }
    // ����� ���������, ����� ������
    if(res_test->a < first->a && res_test->b == first->b)
    {
        if(WhatTypeRight(res_test) == WhatTypeRight(first))
        {
            res->a = first->a;
            res->b = res_test->a;
            res->type = FinilType(WhatTypeLeft(first), Type_dif(WhatTypeLeft(res)));
        } else
        {
            res[0].a = first->b;
            res[0].b = first->b;
            res[0].type = Closed;
            res[1].a = res_test->b;
            res[1].b = first->b;
            res[1].type = FinilType(WhatTypeLeft(first), Type_dif(WhatTypeLeft(res)));
        }
        return res;
    }
}
