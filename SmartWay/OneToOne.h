#ifndef ONETOONE_H
#define ONETOONE_H
#include "head.h"

typedef vector<string> SVEC;
typedef vector<string>* SVECP;
typedef vector<string>::iterator SITE;
typedef vector<string>::const_iterator SCITE;
typedef vector<SVEC> SVVECP;           //存放字符串容器
//typedef vector<SVEC>* SVVECPP;          //存放字符串容器的指针
typedef vector<SVEC>::iterator SVVITER;
//从一个站点到相邻的另外一个站点
class OneToOne{
public:
        //OneToOne();						//构造函数
	OneToOne(string station)
	{
		from=station;
	}
	string get_from(void)			
	{
		return from;
	}
	SVEC get_to(void)			
	{
		return to;
	}
	SVEC get_bus(void)
	{
		return busName;
	}
	void toTo(string to1)
	{
		to.push_back(to1);
	}
	void toBus(string name)
	{
		busName.push_back(name);
	}
private:
	string from;			//边的起始站点
	//两容器结合使用 按顺序对应
        SVEC to;			//容器 经过起点的所有边的终止站点
	SVEC busName;			//容器 经过该边的公交车
        vector<double> distance;        //容器 该边的距离
};

typedef vector<OneToOne> OTOV;			//容器 存放每个站点 作为边的起点
typedef vector<OneToOne>* OTOVP;
typedef vector<OneToOne>::iterator OTOITE;
typedef vector<OneToOne>::const_iterator OTOCITE;
#endif
