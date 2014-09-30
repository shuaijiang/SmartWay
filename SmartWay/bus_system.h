/*定义公交系统类，实现信息管理、查询、换乘等操作*/
#ifndef BUS_SYSTEM_H
#define BUS_SYSTEM_H

#include "head.h"
#include "OneToOne.h"
#include "bus.h"

class BUS_SYSTEM{
public:
        bool add_bus(BUS &onebus,QString stationStr);			//添加一条公交线路时，应将其存放在内存中
        QString* query_onebus(QString busName);		//查询一个线路时，如何准确知道该路线在文件中的位置？
        QString* query_station(QString oneStation);     //查询经过某一个站点时要遍历所有的公交路线
        bool updata(BUS &onebus,QString stationStr);    //修改信息	根据线路名称
        bool deleteBus(QString busName);                //删除一条线路信息
        bool saveFile(BUSVP);                           //将内存中的信息保存到文件中
        void queryOTOUnconditional(string,string,SVECP&,SVECP&);	//站点到站点无条件查询，采用递归遍历实现
        void queryOTOChangeNumLimit(string,string,SVECP&,SVECP&,int);	//站点到站点有条件查询，限制最多的换乘次数，利用限制换乘次数的递归实现
        void queryOTOChangeNumLimit(string,string,SVECP&,SVECP&,int,int realNum); //换乘查询 realNum表示实际的换乘次数
        void queryOTODistance(string,string,SVECP&,SVECP&);//站点到站点换乘查询 距离最短
        void queryOTOPrice(string,string,SVECP&,SVECP&,double realPrice);    //换乘查询 票价最少
        bool isExisted(QString busName);                //公交是否已经存在
        void sort_bus_start(BUSVP);                      //实现线路按起点排序
private:
};

#endif
