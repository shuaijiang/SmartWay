#include "createBusList.h"
#include "Extern.h"
//����Ӧ�ļ��е�����д���ڴ�
void Create::createBuslist(void)
{
    //BUSVP busPtr=new BUSV;				//ָ��������ָ��
    SVEC allStation;					//���� �������ַ���
    string tempstring;
    string name,time;
    int station_num;
    double price;
    ifstream infile(FILENAME,ios::in);
    if(!infile)
    {
        cerr<<"Can't open the file!";
    }
    else
    {
        int fileRow=0;

        for(;infile.good();++fileRow)
        {
            getline(infile,tempstring,'\n');		//�õ�fileRowΪ�ļ���������������·��
            stringstream sstr;
            sstr<<tempstring;           //�ַ�����
            sstr>>name>>time>>price;    //�õ�ÿ����·�����ơ�ʱ���Ʊ��
            string station;
            while(sstr>>station)
            {
                allStation.push_back(station);
            }
            BUS onebus;
            station_num=allStation.size();              //վ����Ŀ
            onebus.bus(name,time,station_num,price);
            onebus.to_all_station(allStation);
            busPtr->push_back(onebus);			//��ŵ�������

            while(!allStation.empty())			//ÿ�ζ�Ҫ������ղ���
                allStation.pop_back();
        }
        if(tempstring=="\0")				//����tempstring�ж� ����ļ�Ϊ��
        {
            fileRow=0;
        }
        busNum=fileRow;
    }
}
void Create::createStation(void)
{
    int flag=0;
    int station_num=0;
    //��������������·���ڽӱ�Ͱ�������վ����ڽӱ�
    for(BUSITE iter=busPtr->begin();iter!=busPtr->end();++iter)
    {
        busName->push_back(iter->get_name());
        SVEC allStation=iter->get_station();
        for(SITE iter1=allStation.begin();iter1!=allStation.end();++iter1)
        {
            for(SITE iter2=stationList->begin();iter2!=stationList->end();++iter2)
            {
                if(*iter2==*iter1)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                ++station_num;
                 stationList->push_back(*iter1);
            }
            else
                flag=0;
        }
    }
}
void Create::edgeList(void)			//����ͼ�ı߱�
{
    for(SITE iter1=stationList->begin();iter1!=stationList->end();++iter1)
    {
        edgePtr->push_back(*iter1);					//��� ���캯��
        for(BUSITE iter2=busPtr->begin();iter2!=busPtr->end();++iter2)
        {
            SVEC stationV=iter2->get_station();
            string busName=iter2->get_name();
            for(SITE iter3=stationV.begin();iter3!=stationV.end();++iter3)
            {
                if(*iter3==*iter1&&(iter3+1)!=stationV.end())	//�ҵ����е����
                {
                    OTOITE iter=edgePtr->end();
                    --iter;
                    iter->toTo(*(iter3+1));			//�������������վ���ҵ�
                    iter->toBus(busName);			//����·����һ������
                }
            }
        }
    }
}

