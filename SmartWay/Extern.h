#ifndef EXTERN_H
#define EXTERN_H
#include "OneToOne.h"
#include "bus.h"
#include "widget.h"
#include "result.h"
extern int busNum;			//表示总的公交线路数
extern int isSort;			//标记是否已经排序
extern int isSaved;			//标记是否已经保存到文件
extern int isChange;			//标记公交信息是否被改变
extern int hasEdge;			//标记是否已经建立边表
extern OTOVP edgePtr;       //边表指针
extern int isLogin;			//标记是否登录
extern BUSVP busPtr;          //存放所有公交线路信息
extern SVECP busName;         //所有线路名称
extern SVECP stationList;     //所有站点名称
//extern SVECP pathS;		//用于保存换乘的路径 pathS存放站点名称
//extern SVECP Adjbus;          //用于保存换乘的路径 Adjbus存放公交路线名
//extern SVVECPP QueryPathResult;     //存放换乘查询的站点
//extern SVVECPP QueryBusResult;      //存放换乘经过公交线路
extern vector<Result> result;
#endif // EXTERN_H
