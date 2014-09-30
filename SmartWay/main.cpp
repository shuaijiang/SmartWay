#include <QtGui/QApplication>
#include <QtGui>
#include "widget.h"
#include "OneToOne.h"
#include "bus.h"
#include "bus_system.h"
#include "login.h"
#include "createBusList.h"
#include "result.h"
int busNum=-1;			//��ʾ�ܵĹ�����·��
int isSort=-1;			//����Ƿ��Ѿ�����
int isSaved=-1;			//����Ƿ��Ѿ����浽�ļ�
int isChange=0;			//��ǹ�����Ϣ�Ƿ񱻸ı�
int hasEdge=0;			//����Ƿ��Ѿ������߱�
OTOVP edgePtr=new OTOV();       //�߱�ָ��
int isLogin=0;			//����Ƿ��¼
BUSVP busPtr=new BUSV;          //������й�����·��Ϣ
SVECP busName=new SVEC;         //������·����
SVECP stationList=new SVEC;     //����վ������
vector<Result> result;
int main(int argc, char *argv[])
{
    Create create;
    create.createBuslist();             //���ļ��ж������ݱ������ڴ���
    //create.createStation();             //��������վ�� ����
    //create.edgeList();                  //�����߱�
    //hasEdge=1;

    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());       //������ʾ
    Widget w;
    w.show();

    return a.exec();
}
