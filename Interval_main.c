#include "Intarval.h"
#include "Set_of_Int.h"
#include "Quadrat_Savchuk.h"
#include "Savchuk_Quadra.c"


//���� � ����� ���������� �������� ��� �������, �� � ����������������� � �������
// ���, �������� �� ���� ������ ��� ���� ��������
//���������� � ����� �� ���� ������, ����� ���������� � ��������� �� � ������ �������� ������ �������� ���������
// ����� ����� � ������������� � ��� �������
// ��� ����������� ������ ������ ��������� ��������������� �������� �������,�� ������ ���� � ������ �������
// � ������ ������� �������� �������� ���� (� ����� ����� ���� ���� ������������� �� �������� �������� ���'��
// ����� �������� ���� ���� ������������ � ������ ����� (��������� �������� ����������� �� ����� �� ������
// �������. �������� ������ ������� ����,�� ���� � ����������� ��� ��������� ���� ������,����� �� ������� �����
// ���� � ���������, ��� ���� ���� �� ������ �����.

int main()
{
    // ����� ��� �������� ���������
    Interval *first2 = SetInterval(4, -1, InfiniteLeft_RightClosed);
    Interval *second2 = SetInterval(4, 1, InfiniteLeft_RightClosed);
    PrintInterval(DivideIntervals(first2, second2));


    Interval *first = SetInterval(0, 21, Opened);
    Interval *second = SetInterval(0, 21, Closed);
    PrintInterval(DivideIntervals(first, second));

    Interval *first1 = SetInterval(0, 10, HalfClosedRight);
    Interval *second1 = SetInterval(0, 10, Closed);
    PrintInterval(DivideIntervals(first1, second1));

    Interval *first3 = SetInterval(-5, INFINITY, Opened);
    Interval *second3 = SetInterval(0, INFINITY, Opened);
    PrintInterval(DivideIntervals(first3, second3));

    printf("---------------\n");
    //���� ��'������� ���������
    // -------------------------------------------

    Interval *first123 = SetInterval(-1, 110, Opened);
    Interval *second123 = SetInterval(0, 21, HalfClosedRight);
    PrintRes1(Multiplication_Int(first123, second123));

    Interval *first1233 = SetInterval(0, 11, HalfClosedRight);
    Interval *second1233 = SetInterval(-1, 11, Closed);
    PrintRes1(Multiplication_Int(first1233, second1233));

    Interval *first22 = SetInterval(18, 23, Opened);
    Interval *second22 = SetInterval(27, 27, Closed);
    PrintRes1(Multiplication_Int(first22, second22));

    Interval *first33 = SetInterval(-1, 7, Opened);
    Interval *second33 = SetInterval(8, 12, Opened);
    PrintRes1(Multiplication_Int(first33, second33));

    printf(" ------------------------------\n");
    //���� ������
    // -------------------------------------------------

    Interval *first111 = SetInterval(0, 11, HalfClosedLeft);
    Interval *second111 = SetInterval(12, 13, Opened);
    PrintRes1(Difference_Int(first111, second111));

    printf(" ------------------------------\n");


    //���� �������� ������� ���������
    //-----------------------------------------------------------------------------------------
    //

    Interval *f2 = SetInterval(0, -1, InfiniteLeft_RightClosed);
    Interval *s2 = SetInterval(4, 12, InfiniteRight_LeftClosed);
//    Interval *first = SetInterval(14, 15, Opened);
//    Interval *second = SetInterval(0, 21, Closed);
    Interval *gh = (Interval*) malloc(sizeof(Interval) * 2);
    gh[0] = *f2;
    gh[1] = *s2;


    Interval *ft1 = SetInterval(0, 1, InfiniteLeft_RightClosed);
    Interval *s1 = SetInterval(4, 12, InfiniteRight_LeftClosed);
    Interval *erty = (Interval *) malloc(sizeof(Interval) * 2);
    erty[0] = *ft1;
    erty[1] = *s1;
//
    set_intervals *Test = Make_arrayof_Int(gh,2);
    set_intervals *Test2 = Make_arrayof_Int(erty, 2);

    PrintRes(Set_Insection(Test, Test2));

    printf(" ------------------------------\n");

    //���� ������ ������� ���������
    // -------------------------------------------------------------


    Interval *fir2 = SetInterval(0, 11, HalfClosedLeft);
//    Interval *second2 = SetInterval(15, 16, Closed);
//    Interval *first = SetInterval(14, 15, Opened);
//    Interval *second = SetInterval(0, 21, Closed);
    Interval *gh1 = (Interval*) malloc(sizeof(Interval) );
    gh1[0] = *fir2;
//    gh[1] = *second2;
//    gh[2] = *first;


    Interval *fir1 = SetInterval(0, 10, Opened);
    Interval *sec1 = SetInterval(12, 13, Closed);
    Interval *erty1 = (Interval *) malloc(sizeof(Interval) * 3);
    erty1[0] = *fir1;
    erty1[1] = *sec1;

    set_intervals *Test12 = Make_arrayof_Int(gh1,1);
    set_intervals *Test22 = Make_arrayof_Int(erty1, 2);

    PrintRes3(Set_Difference(Test12, Test22));


    printf(" ------------------------------\n");

    //���� ���������� ������� ���������
    // ----------------------------------------------------------------------------------------------
    PrintRes3(Test22);
    PrintRes1(Multiplication_Int(&gh1[0],&erty1[1]));
    PrintRes3(Set_Multyp(Test12, Test22));

    //���� ������� ������� ���������
     //--------------------------------------------------------------------

    Interval *l1 = SetInterval(0, 10, Opened);
    Interval *l2 = SetInterval(12, 13, Infinite);
    Interval *L1 = (Interval *) malloc(sizeof(Interval) * 3);
    L1[0] = *l1;
    L1[1] = *l2;

    set_intervals *TestLen = Make_arrayof_Int(L1,2);

    TheLenght(TestLen);


    // ���� �������� ������ ������� ���������� ������
    //-------------------------------------------------------


    QuadraticInequalities *sch = SetIneq(1 , -3, -4, greater_equal);
    QuadraticInequalities *sch1 = SetIneq(1, -5, 4, greater_equal);
    set_intervals * Ar = Make_set(*sch);
    set_intervals * Ar2 = Make_set(*sch1);
    PrintRes(find_solution(Ar, Ar2));

}
