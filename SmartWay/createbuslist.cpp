#include "createBusList.h"
#include "Extern.h"
//将相应文件中的数据写入内存
void Create::createBuslist(void)
{
    //BUSVP busPtr=new BUSV;				//指向容器的指针
    SVEC allStation;					//容器 处理拆分字符串
    string tempstring;
    string name,time;
    int station_num;
    double price;
    ifstream infile(FILENAME,ios::in);
    if(!infile)
    {
        cerr<<"Can't open the file!";
    }
    else
    {
        int fileRow=0;

        for(;infile.good();++fileRow)
        {
            getline(infile,tempstring,'\n');		//得到fileRow为文件行数，即公交线路数
            stringstream sstr;
            sstr<<tempstring;           //字符串流
            sstr>>name>>time>>price;    //得到每条线路的名称、时间和票价
            string station;
            while(sstr>>station)
            {
                allStation.push_back(station);
            }
            BUS onebus;
            station_num=allStation.size();              //站点数目
            onebus.bus(name,time,station_num,price);
            onebus.to_all_station(allStation);
            busPtr->push_back(onebus);			//存放到容器中

            while(!allStation.empty())			//每次都要进行清空操作
                allStation.pop_back();
        }
        if(tempstring=="\0")				//根据tempstring判断 如果文件为空
        {
            fileRow=0;
        }
        busNum=fileRow;
    }
}
void Create::createStation(void)
{
    int flag=0;
    int station_num=0;
    //建立包含所有线路的邻接表和包含所有站点的邻接表
    for(BUSITE iter=busPtr->begin();iter!=busPtr->end();++iter)
    {
        busName->push_back(iter->get_name());
        SVEC allStation=iter->get_station();
        for(SITE iter1=allStation.begin();iter1!=allStation.end();++iter1)
        {
            for(SITE iter2=stationList->begin();iter2!=stationList->end();++iter2)
            {
                if(*iter2==*iter1)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                ++station_num;
                 stationList->push_back(*iter1);
            }
            else
                flag=0;
        }
    }
}
void Create::edgeList(void)			//创建图的边表
{
    for(SITE iter1=stationList->begin();iter1!=stationList->end();++iter1)
    {
        edgePtr->push_back(*iter1);					//起点 构造函数
        for(BUSITE iter2=busPtr->begin();iter2!=busPtr->end();++iter2)
        {
            SVEC stationV=iter2->get_station();
            string busName=iter2->get_name();
            for(SITE iter3=stationV.begin();iter3!=stationV.end();++iter3)
            {
                if(*iter3==*iter1&&(iter3+1)!=stationV.end())	//找到所有的起点
                {
                    OTOITE iter=edgePtr->end();
                    --iter;
                    iter->toTo(*(iter3+1));			//将与起点相连的站点找到
                    iter->toBus(busName);			//并将路线名一并保存
                }
            }
        }
    }
}

