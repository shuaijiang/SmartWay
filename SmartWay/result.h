#ifndef RESULT_H
#define RESULT_H
#include "OneToOne.h"
typedef struct result{                           //存放换乘查询结果
    SVEC QueryPathResult;  //存放换乘查询的站点
    SVEC QueryBusResult;   //存放换乘经过公交线路
    double distance;       //路线的距离
    double price;
} Result;

#endif // RESULT_H
