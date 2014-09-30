/*���幫������*/
#ifndef BUS_H
#define BUS_H

#include "head.h"
#include "OneToOne.h"

class BUS{
public:
        void bus(string name1,string time1,int station_num1,double price1); //������·������Ϣ ���� ʱ�� վ����Ŀ Ʊ��
        void busCopy(BUS &onebus);
	string get_name(void){ return name;}					//�����·����
        string get_start(void);				//������
	string get_end(void){SITE temp=allStation.end();return *temp;}					//����յ� 
	SVEC get_station(void);								//��ö�Ӧվ��ŵ�վ������	ʹ��vector����
        int get_station_num(void){return station_num;}		//�������վ����Ŀ
        double get_price(void){return price;}			//���Ʊ��
	string get_time(void){return time;}
        void to_all_station(string);				//����վ������
        void to_all_station(vector<string>&);			//�õ�����վ������
        void remove(void)                                       //�������
	{
		allStation.erase(allStation.begin(),allStation.end());
	}
	//friend bool operator>(const BUS *,const BUS*);
private:
	string name;			//����·�ߵ�����
	string time;			//��ֹʱ��
	SVEC allStation;		//����վ�� ��vector�洢
	int station_num;		//����վ����Ŀ
	double price;			//Ʊ��
        //double distance;		//�������
};
typedef vector<BUS> BUSV;
typedef vector<BUS>* BUSVP;
typedef vector<BUS>::iterator BUSITE;
#endif//BUS_H

