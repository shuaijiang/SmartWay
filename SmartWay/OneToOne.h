#ifndef ONETOONE_H
#define ONETOONE_H
#include "head.h"

typedef vector<string> SVEC;
typedef vector<string>* SVECP;
typedef vector<string>::iterator SITE;
typedef vector<string>::const_iterator SCITE;
typedef vector<SVEC> SVVECP;           //����ַ�������
//typedef vector<SVEC>* SVVECPP;          //����ַ���������ָ��
typedef vector<SVEC>::iterator SVVITER;
//��һ��վ�㵽���ڵ�����һ��վ��
class OneToOne{
public:
        //OneToOne();						//���캯��
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
	string from;			//�ߵ���ʼվ��
	//���������ʹ�� ��˳���Ӧ
        SVEC to;			//���� �����������бߵ���ֹվ��
	SVEC busName;			//���� �����ñߵĹ�����
        vector<double> distance;        //���� �ñߵľ���
};

typedef vector<OneToOne> OTOV;			//���� ���ÿ��վ�� ��Ϊ�ߵ����
typedef vector<OneToOne>* OTOVP;
typedef vector<OneToOne>::iterator OTOITE;
typedef vector<OneToOne>::const_iterator OTOCITE;
#endif
