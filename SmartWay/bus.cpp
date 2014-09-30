#include"bus.h"
#include "Extern.h"

void BUS::bus(string name1,string time1,int station_num1,double price1)
{
    name=name1;
    time=time1;
    station_num=station_num1;
    price=price1;
} 
void BUS::busCopy(BUS &onebus)  //¿½±´¹¹Ôìº¯Êý
{
    name=onebus.get_name();
    time=onebus.get_time();
    station_num=onebus.get_station_num();
    price=onebus.get_price();
    allStation=onebus.get_station();
}
string BUS::get_start()
{
    if(allStation.empty())
        return "";
    SITE temp=allStation.begin();
    return *temp;
}
void BUS::to_all_station(SVEC& station)
{
    allStation=station;
}
void BUS::to_all_station(string str)
{
    allStation.push_back(str);
}

SVEC BUS::get_station()
{
    return allStation;
}
