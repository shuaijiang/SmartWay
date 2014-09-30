#include "result.h"

bool cmp(const Result &a,const Result & b)
{
    return a.distance<b.distance;
}

