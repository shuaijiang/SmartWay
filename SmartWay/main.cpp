#include <QtGui/QApplication>
#include <QtGui>
#include "widget.h"
#include "OneToOne.h"
#include "bus.h"
#include "bus_system.h"
#include "login.h"
#include "createBusList.h"
#include "result.h"
int busNum=-1;			//表示总的公交线路数
int isSort=-1;			//标记是否已经排序
int isSaved=-1;			//标记是否已经保存到文件
int isChange=0;			//标记公交信息是否被改变
int hasEdge=0;			//标记是否已经建立边表
OTOVP edgePtr=new OTOV();       //边表指针
int isLogin=0;			//标记是否登录
BUSVP busPtr=new BUSV;          //存放所有公交线路信息
SVECP busName=new SVEC;         //所有线路名称
SVECP stationList=new SVEC;     //所有站点名称
vector<Result> result;
int main(int argc, char *argv[])
{
    Create create;
    create.createBuslist();             //从文件中读入数据保存在内存中
    //create.createStation();             //创建所有站点 容器
    //create.edgeList();                  //创建边表
    //hasEdge=1;

    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());       //中文显示
    Widget w;
    w.show();

    return a.exec();
}
