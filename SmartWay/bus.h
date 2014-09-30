/*定义公交车类*/
#ifndef BUS_H
#define BUS_H

#include "head.h"
#include "OneToOne.h"

class BUS{
public:
        void bus(string name1,string time1,int station_num1,double price1); //创建线路基本信息 名称 时间 站点数目 票价
        void busCopy(BUS &onebus);
	string get_name(void){ return name;}					//获得线路名称
        string get_start(void);				//获得起点
	string get_end(void){SITE temp=allStation.end();return *temp;}					//获得终点 
	SVEC get_station(void);								//获得对应站点号的站点名称	使用vector容器
        int get_station_num(void){return station_num;}		//获得所有站点数目
        double get_price(void){return price;}			//获得票价
	string get_time(void){return time;}
        void to_all_station(string);				//单个站点的添加
        void to_all_station(vector<string>&);			//得到各个站点名称
        void remove(void)                                       //清空容器
	{
		allStation.erase(allStation.begin(),allStation.end());
	}
	//friend bool operator>(const BUS *,const BUS*);
private:
	string name;			//公交路线的名称
	string time;			//起止时间
	SVEC allStation;		//所有站点 用vector存储
	int station_num;		//公交站点数目
	double price;			//票价
        //double distance;		//公交里程
};
typedef vector<BUS> BUSV;
typedef vector<BUS>* BUSVP;
typedef vector<BUS>::iterator BUSITE;
#endif//BUS_H

