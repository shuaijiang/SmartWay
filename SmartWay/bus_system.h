/*���幫��ϵͳ�࣬ʵ����Ϣ������ѯ�����˵Ȳ���*/
#ifndef BUS_SYSTEM_H
#define BUS_SYSTEM_H

#include "head.h"
#include "OneToOne.h"
#include "bus.h"

class BUS_SYSTEM{
public:
        bool add_bus(BUS &onebus,QString stationStr);			//���һ��������·ʱ��Ӧ���������ڴ���
        QString* query_onebus(QString busName);		//��ѯһ����·ʱ�����׼ȷ֪����·�����ļ��е�λ�ã�
        QString* query_station(QString oneStation);     //��ѯ����ĳһ��վ��ʱҪ�������еĹ���·��
        bool updata(BUS &onebus,QString stationStr);    //�޸���Ϣ	������·����
        bool deleteBus(QString busName);                //ɾ��һ����·��Ϣ
        bool saveFile(BUSVP);                           //���ڴ��е���Ϣ���浽�ļ���
        void queryOTOUnconditional(string,string,SVECP&,SVECP&);	//վ�㵽վ����������ѯ�����õݹ����ʵ��
        void queryOTOChangeNumLimit(string,string,SVECP&,SVECP&,int);	//վ�㵽վ����������ѯ���������Ļ��˴������������ƻ��˴����ĵݹ�ʵ��
        void queryOTOChangeNumLimit(string,string,SVECP&,SVECP&,int,int realNum); //���˲�ѯ realNum��ʾʵ�ʵĻ��˴���
        void queryOTODistance(string,string,SVECP&,SVECP&);//վ�㵽վ�㻻�˲�ѯ �������
        void queryOTOPrice(string,string,SVECP&,SVECP&,double realPrice);    //���˲�ѯ Ʊ������
        bool isExisted(QString busName);                //�����Ƿ��Ѿ�����
        void sort_bus_start(BUSVP);                      //ʵ����·���������
private:
};

#endif
