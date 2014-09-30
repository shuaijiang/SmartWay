#include"bus_system.h"
#include "head.h"
#include <QtGui>
#include "Extern.h"
#include "widget.h"
#include "result.h"
bool BUS_SYSTEM::add_bus(BUS &onebus,QString stationStr)	//直接在busPtr中进行添加操作
{
    int stationNum=onebus.get_station_num();
    BUS Abus;
    Abus.busCopy(onebus);
    Abus.remove();
    istringstream sstr(stationStr.toLocal8Bit().data());
    string onestation;
    for(int count=0;count<stationNum&&sstr>>onestation;count++)		//添加公交站点
    {
        Abus.to_all_station(onestation);
    }
    busPtr->push_back(Abus);
    busNum++;                       //公交线路加1
    return true;
}
void BUS_SYSTEM::sort_bus_start(BUSVP busPtr)		//将公交线路按照起点排序 
{
    //考虑使用冒泡排序
    BUS tempBus;
    for(BUSITE iter1=busPtr->begin(),iter3=busPtr->end();iter1!=busPtr->end()&&iter3!=busPtr->begin();++iter1,--iter3)
    {
        for(BUSITE iter2=busPtr->begin();iter2+1!=iter3;++iter2)	//有问题 可能是内存泄露 解决：iter3是iter2的结尾，iter2+1会产生越界，故iter3减一
        {
            if((iter2)->get_start()>(iter2+1)->get_start())
            {
                tempBus=*iter2;
                *(iter2)=*(iter2+1);
                *(iter2+1)=tempBus;
            }
        }
    }

}
QString* BUS_SYSTEM::query_onebus(QString busName)			//根据名称 查询某个公交的信息
{
    QString * busInfor=new QString;               //存放显示公交信息
    BUSITE iter=busPtr->begin();
    for(;iter!=busPtr->end();++iter)
    {
        QString str=QString::fromLocal8Bit((iter->get_name()).c_str());
        if(str==busName)
        {
            QString strTemp;       //临时存放信息

            *busInfor = QString::fromLocal8Bit(iter->get_name().c_str());
            busInfor->append("\t");
            busInfor->append(QString::fromLocal8Bit(iter->get_time().c_str()));
            busInfor->append("\t");

            strTemp = QString::number(iter->get_price());
            strTemp.append(QObject::tr(" 站点数:"));
            strTemp.append(QString::number(iter->get_station_num()));
            *busInfor=*busInfor+strTemp;
            busInfor->append(QObject::tr("\n所有站点为:"));
            SVEC station=iter->get_station();
            for(SITE iter1=station.begin();iter1!=station.end();++iter1)
            {
                busInfor->append(QString::fromLocal8Bit((*iter1).c_str()));
                if(iter1+1!=station.end())
                    busInfor->append("  ");
            }
            break; //不允许有重名
        }

    }
    if(iter!=busPtr->end())
        return busInfor;
    else
        return 0;
}
QString* BUS_SYSTEM::query_station(QString oneStation)		//查询经过某个站点的所有公交的信息
{
    QString* stationBus=new QString;                         //存放经过某个站点的所有公交线路
    stationBus->clear();
    for(BUSITE iter=busPtr->begin();iter!=busPtr->end();++iter)
    {
        SVEC station=iter->get_station();
        SITE iter1=station.begin();
        for(;iter1!=station.end();++iter1)
        {
            if(oneStation==QString::fromLocal8Bit((*iter1).c_str()))
            {
                stationBus->append(QString::fromLocal8Bit(iter->get_name().c_str()));
                if(iter+1!=busPtr->end())
                    stationBus->append("\t");
            }
        }
        station.clear();        //清空所有站点
    }
    if(stationBus->isEmpty())         //没有经过该站点的公交线路
        return 0;
    else
        return stationBus;
}
bool BUS_SYSTEM::updata(BUS &onebus,QString stationStr)
{
    BUSITE iter=busPtr->begin();
    int isFind=0;
    for(;iter!=busPtr->end();++iter)
    {
        if(iter->get_name()==onebus.get_name())
        {
            isFind=1;
            break;
        }
    }
    if(isFind==1)
    {
        iter->busCopy(onebus);
        iter->remove();
        stringstream sstr(stationStr.toLocal8Bit().data());
        string oneStation;
        for(int count=0;count<onebus.get_station_num()&&sstr>>oneStation;count++) //添加公交站点
        {
            iter->to_all_station(oneStation);
        }
        return true;
    }
    return false;
}
bool BUS_SYSTEM::deleteBus(QString busName)
{
    BUSITE iter1=busPtr->begin();
    BUSITE iter2=busPtr->end();
    for(;iter1!=iter2;++iter1)
    {
        if(busName.toLocal8Bit().data()==iter1->get_name())
        {
            busPtr->erase(iter1);
            --busNum;
            return true;
        }
    }
    return false;
}
bool BUS_SYSTEM::saveFile(BUSVP busPtr)
{
    ofstream outfile(FILENAME,ios::out);
    if(!outfile)
        return false;
    else
    {
        BUS onebus;
        for(BUSITE iter=busPtr->begin();iter!=busPtr->end();++iter)
        {
            if(iter!=busPtr->begin())			//第一行开头不需要回车
                outfile<<endl;

            onebus=*iter;
            outfile<<onebus.get_name()<<'\t'<<onebus.get_time()<<'\t'<<onebus.get_price()<<'\t';
            SVEC stationVec(onebus.get_station());
            SITE iter1=stationVec.begin();
            for(;iter1!=stationVec.end();++iter1)
            {
                outfile<<*iter1;
                if((iter1+1)!=stationVec.end())
                    outfile<<' ';
            }
        }
        outfile.close();
        return true;
    }
}

void  BUS_SYSTEM::queryOTOUnconditional(string from,string to,SVECP& pathS,SVECP& Adjbus)//考虑使用递归 完成边表的遍历
{
    OTOITE iter=(edgePtr)->begin();
    pathS->push_back(from);
    if(from==to)
    {
        //存放换乘查询结果
        Result oneResult;
        oneResult.QueryBusResult=*Adjbus;
        oneResult.QueryPathResult=*pathS;
        oneResult.distance=pathS->size();
        result.push_back(oneResult);
        pathS->pop_back();
        return ;
    }
    else
    {
        //找到起始站点
        for(;iter!=edgePtr->end();++iter)
        {
            if(from==iter->get_from())
            {
                break;
            }
        }
        if(iter==edgePtr->end())    //没有找到起点
        {
            pathS->pop_back();
            return ;
        }
        SVEC nextS=iter->get_to();
        SVEC nextB=iter->get_bus();
        SITE iter1=nextS.begin();
        SITE iter2=nextB.begin();

        for(;(iter1)!=nextS.end()&&iter2!=nextB.end();++iter1,++iter2)
        {
            //路径上站点和线路不能同时相同
            if(find(pathS->begin(),pathS->end(),*iter1)==pathS->end())   //一种换乘中不能换乘同辆车
            {
                bool flag=0;
                for(SITE iter3=Adjbus->begin();iter3!=Adjbus->end();++iter3)
                {
                    if(*iter3==*iter2){
                        flag=1;
                        break;
                    }
                }
                if(flag == 1 && *(Adjbus->end()-1)!=*iter2)
                    continue;
                Adjbus->push_back(*iter2);
                queryOTOUnconditional(*iter1,to,pathS,Adjbus);		//迭代
                Adjbus->pop_back();
            }
        }
        pathS->pop_back();
        return ;
    }
}
void BUS_SYSTEM::queryOTOChangeNumLimit(string from,string to,SVECP & pathS,SVECP & Adjbus,int changeNum) //限制换乘次数的查询
{
    OTOITE iter=(edgePtr)->begin();
    pathS->push_back(from);
    if(from==to)
    {
        //存放换乘查询的最终的一种方案
        Result oneResult;
        oneResult.QueryBusResult=*Adjbus;
        oneResult.QueryPathResult=*pathS;
        oneResult.distance=pathS->size();
        result.push_back(oneResult);
        pathS->pop_back();
        return ;
    }
    else
    {
        //找到起始站点
        for(;iter!=edgePtr->end();++iter)
        {
            if(from==iter->get_from())
            {
                break;
            }
        }
        if(iter==edgePtr->end())    //没有找到起点
        {
            pathS->pop_back();
            return ;
        }
        SVEC nextS=iter->get_to();
        SVEC nextB=iter->get_bus();
        SITE iter1=nextS.begin();
        SITE iter2=nextB.begin();

        for(;(iter1)!=nextS.end()&&iter2!=nextB.end();++iter1,++iter2)
        {
            //路径上站点和线路不能同时相同
            if(find(pathS->begin(),pathS->end(),*iter1)==pathS->end())   //一种换乘中不能换乘同辆车
            {

                if(Adjbus->size() > 0)
                {
                    bool flag=0;
                    SITE iter3=Adjbus->begin();
                    string station =*iter3;
                    int busNum=0;                          //表示换乘所乘坐的公交车数目
                    for(;iter3!=Adjbus->end();++iter3)
                    {
                        if(*iter3==*iter2&&flag!=1){
                            flag=1;
                        }
                        if(station==*iter3)
                            continue;
                        else{
                            station=*iter3;
                            ++busNum;
                        }
                    }
                    if( flag == 1 && *(Adjbus->end()-1)!=*iter2 )
                        continue;

                    if(*(Adjbus->end()-1)!=*iter2)  //添加本站点后是否超过要求数目
                    {
                        ++busNum;
                    }
                    if(busNum>changeNum){
                        continue;

                    }
                }

                Adjbus->push_back(*iter2);
                queryOTOChangeNumLimit(*iter1,to,pathS,Adjbus,changeNum);		//迭代
                Adjbus->pop_back();
            }
        }
        pathS->pop_back();
        return ;
    }
}
void BUS_SYSTEM::queryOTOChangeNumLimit(string from,string to,SVECP & pathS,SVECP & Adjbus,int changeNum,int realNum) //限制换乘次数的查询
{

    pathS->push_back(from);     //保存起点
    if(from==to)                //表示找到一条路径
    {
        Result oneResult;
        oneResult.QueryBusResult=*Adjbus;
        oneResult.QueryPathResult=*pathS;
        oneResult.distance=pathS->size();
        result.push_back(oneResult);
        pathS->pop_back();
        return ;
    }
    else
    {
        //找到起始站点
        OTOITE iter=(edgePtr)->begin();
        for(;iter!=edgePtr->end();++iter)
        {
            if(from==iter->get_from())  //找到起点直接跳出
            {
                break;
            }
        }
        if(iter==edgePtr->end())    //没有找到起点
        {
            pathS->pop_back();
            return ;
        }
        SVEC nextS=iter->get_to();
        SVEC nextB=iter->get_bus();
        SITE iter1=nextS.begin();
        SITE iter2=nextB.begin();

        for(;(iter1)!=nextS.end()&&iter2!=nextB.end();++iter1,++iter2)
        {
            //路径上站点和线路不能同时相同
            if(find(pathS->begin(),pathS->end(),*iter1)==pathS->end())   //一种换乘中不能经过同个站点
            {
                bool isAdd=false;
                if(Adjbus->size() > 0)
                {
                    bool flag=0;
                    SITE iter3=Adjbus->begin();
                    for(;iter3!=Adjbus->end();++iter3)
                    {
                        if(*iter3==*iter2){         //如果找到相同的站点
                            flag=1;
                            break;
                        }
                    }
                    if( flag == 1 && *(Adjbus->end()-1)!=*iter2 )   //一次换乘中不能换乘同辆车
                        continue;

                    if(*(Adjbus->end()-1)!=*iter2)  //添加本站点后是否增加了换乘次数
                    {
                        ++realNum;
                        isAdd=true;               // 标记是否增加换乘次数
                    }
                    if(realNum>changeNum)        //如果换乘次数超过要求
                    {
                        if(isAdd==true)         //如果已经增加了换乘次数 就减去
                            --realNum;
                        continue;
                    }

                }

                Adjbus->push_back(*iter2);      //保存经过的线路名称
                queryOTOChangeNumLimit(*iter1,to,pathS,Adjbus,changeNum,realNum);		//迭代
                Adjbus->pop_back();
                if(isAdd==true)
                    --realNum;
            }
        }
        pathS->pop_back();
        return ;
    }
}
void BUS_SYSTEM::queryOTODistance(string from,string to,SVECP & pathS,SVECP & Adjbus) //限制距离的查询
{
    //默认每两个站点之间距离相等
    OTOITE iter=(edgePtr)->begin();
    pathS->push_back(from);
    if(from==to)
    {
        Result oneResult;
        oneResult.QueryBusResult=*Adjbus;
        oneResult.QueryPathResult=*pathS;
        oneResult.distance=pathS->size()-1;     //表示两个站点间距的个数
        result.push_back(oneResult);
        pathS->pop_back();
        return ;
    }
    else
    {
        //找到起始站点
        for(;iter!=edgePtr->end();++iter)
        {
            if(from==iter->get_from())
            {
                break;
            }
        }
        if(iter==edgePtr->end())    //没有找到起点
        {
            pathS->pop_back();
            return ;
        }
        SVEC nextS=iter->get_to();
        SVEC nextB=iter->get_bus();
        SITE iter1=nextS.begin();
        SITE iter2=nextB.begin();

        for(;(iter1)!=nextS.end()&&iter2!=nextB.end();++iter1,++iter2)
        {
            //路径上站点和线路不能同时相同
            if(find(pathS->begin(),pathS->end(),*iter1)==pathS->end())   //一种换乘中不能换乘同辆车
            {

                if(Adjbus->size() > 0)
                {
                    bool flag=0;
                    SITE iter3=Adjbus->begin();
                    string station =*iter3;
                    int busNum=0;                          //表示换乘所乘坐的公交车数目
                    for(;iter3!=Adjbus->end();++iter3)
                    {
                        if(*iter3==*iter2&&flag!=1){
                            flag=1;
                        }
                        if(station==*iter3)
                            continue;
                        else{
                            station=*iter3;
                            ++busNum;
                        }
                    }
                    if( flag == 1 && *(Adjbus->end()-1)!=*iter2 )
                        continue;

                    if(*(Adjbus->end()-1)!=*iter2)  //添加本站点后是否增加换乘次数
                    {
                        ++busNum;
                    }
                }

                Adjbus->push_back(*iter2);
                queryOTODistance(*iter1,to,pathS,Adjbus);		//迭代
                Adjbus->pop_back();
            }
        }
        pathS->pop_back();
        return ;
    }
}
void BUS_SYSTEM::queryOTOPrice(string from,string to,SVECP & pathS,SVECP & Adjbus,double realPrice) //限制距离的查询
{   //默认每两个站点之间距离相等
    OTOITE iter=(edgePtr)->begin();
    pathS->push_back(from);
    if(from==to)
    {
        Result oneResult;
        oneResult.QueryBusResult=*Adjbus;
        oneResult.QueryPathResult=*pathS;
        oneResult.price=realPrice;
        result.push_back(oneResult);
        pathS->pop_back();
        return ;
    }
    else
    {
        //找到起始站点
        for(;iter!=edgePtr->end();++iter)
        {
            if(from==iter->get_from())
            {
                break;
            }
        }
        if(iter==edgePtr->end())    //没有找到起点
        {
            pathS->pop_back();
            return ;
        }
        SVEC nextS=iter->get_to();
        SVEC nextB=iter->get_bus();
        SITE iter1=nextS.begin();
        SITE iter2=nextB.begin();

        for(;(iter1)!=nextS.end()&&iter2!=nextB.end();++iter1,++iter2)
        {
            //路径上站点和线路不能同时相同
            if(find(pathS->begin(),pathS->end(),*iter1)==pathS->end())
            {
                bool addBus=0;
                bool busIsNull=1;
                if(Adjbus->size() > 0)
                {
                    busIsNull=0;
                    bool flag=0;
                    SITE iter3=Adjbus->begin();
                    for(;iter3!=Adjbus->end();++iter3)
                    {
                        if(*iter3==*iter2){     //一次换乘中不能换乘同辆车
                            flag=1;
                            break;
                        }
                    }
                    if( flag == 1 && *(Adjbus->end()-1)!=*iter2 )
                        continue;

                    if(*(Adjbus->end()-1)!=*iter2)  //添加本站点后是否增加换乘次数
                    {
                        addBus=1;
                    }
                }

                Adjbus->push_back(*iter2);
                BUSITE busiter=busPtr->begin();
                if(addBus==1||busIsNull == 1)       //如果添加了一条新的线路或者还没有线路
                {

                    for(;busiter!=busPtr->end();++busiter)
                    {
                        if((*busiter).get_name()==*iter2)
                        {
                            realPrice+=(*busiter).get_price();  //找到对应线路 增加相应票价
                            break;
                        }
                    }
                }
                queryOTOPrice(*iter1,to,pathS,Adjbus,realPrice);		//迭代
                Adjbus->pop_back();
                if(addBus==1||busIsNull == 1)
                    realPrice=realPrice-(*busiter).get_price();
            }
        }
        pathS->pop_back();
        return ;
    }
}
bool BUS_SYSTEM::isExisted(QString busName)
{
    BUSITE iter=busPtr->begin();
    BUSITE iterEnd=busPtr->end();
    for(;iter!=iterEnd;++iter)
    {
        if(iter->get_name()==busName.toLocal8Bit().data())
            return true;
    }
    return false;
}
