#ifndef RESULT_H
#define RESULT_H
#include "OneToOne.h"
typedef struct result{                           //��Ż��˲�ѯ���
    SVEC QueryPathResult;  //��Ż��˲�ѯ��վ��
    SVEC QueryBusResult;   //��Ż��˾���������·
    double distance;       //·�ߵľ���
    double price;
} Result;

#endif // RESULT_H
