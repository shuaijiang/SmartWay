#ifndef EXTERN_H
#define EXTERN_H
#include "OneToOne.h"
#include "bus.h"
#include "widget.h"
#include "result.h"
extern int busNum;			//��ʾ�ܵĹ�����·��
extern int isSort;			//����Ƿ��Ѿ�����
extern int isSaved;			//����Ƿ��Ѿ����浽�ļ�
extern int isChange;			//��ǹ�����Ϣ�Ƿ񱻸ı�
extern int hasEdge;			//����Ƿ��Ѿ������߱�
extern OTOVP edgePtr;       //�߱�ָ��
extern int isLogin;			//����Ƿ��¼
extern BUSVP busPtr;          //������й�����·��Ϣ
extern SVECP busName;         //������·����
extern SVECP stationList;     //����վ������
//extern SVECP pathS;		//���ڱ��滻�˵�·�� pathS���վ������
//extern SVECP Adjbus;          //���ڱ��滻�˵�·�� Adjbus��Ź���·����
//extern SVVECPP QueryPathResult;     //��Ż��˲�ѯ��վ��
//extern SVVECPP QueryBusResult;      //��Ż��˾���������·
extern vector<Result> result;
#endif // EXTERN_H
