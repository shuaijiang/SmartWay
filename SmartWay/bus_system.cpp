#include"bus_system.h"
#include "head.h"
#include <QtGui>
#include "Extern.h"
#include "widget.h"
#include "result.h"
bool BUS_SYSTEM::add_bus(BUS &onebus,QString stationStr)	//ֱ����busPtr�н�����Ӳ���
{
    int stationNum=onebus.get_station_num();
    BUS Abus;
    Abus.busCopy(onebus);
    Abus.remove();
    istringstream sstr(stationStr.toLocal8Bit().data());
    string onestation;
    for(int count=0;count<stationNum&&sstr>>onestation;count++)		//��ӹ���վ��
    {
        Abus.to_all_station(onestation);
    }
    busPtr->push_back(Abus);
    busNum++;                       //������·��1
    return true;
}
void BUS_SYSTEM::sort_bus_start(BUSVP busPtr)		//��������·����������� 
{
    //����ʹ��ð������
    BUS tempBus;
    for(BUSITE iter1=busPtr->begin(),iter3=busPtr->end();iter1!=busPtr->end()&&iter3!=busPtr->begin();++iter1,--iter3)
    {
        for(BUSITE iter2=busPtr->begin();iter2+1!=iter3;++iter2)	//������ �������ڴ�й¶ �����iter3��iter2�Ľ�β��iter2+1�����Խ�磬��iter3��һ
        {
            if((iter2)->get_start()>(iter2+1)->get_start())
            {
                tempBus=*iter2;
                *(iter2)=*(iter2+1);
                *(iter2+1)=tempBus;
            }
        }
    }

}
QString* BUS_SYSTEM::query_onebus(QString busName)			//�������� ��ѯĳ����������Ϣ
{
    QString * busInfor=new QString;               //�����ʾ������Ϣ
    BUSITE iter=busPtr->begin();
    for(;iter!=busPtr->end();++iter)
    {
        QString str=QString::fromLocal8Bit((iter->get_name()).c_str());
        if(str==busName)
        {
            QString strTemp;       //��ʱ�����Ϣ

            *busInfor = QString::fromLocal8Bit(iter->get_name().c_str());
            busInfor->append("\t");
            busInfor->append(QString::fromLocal8Bit(iter->get_time().c_str()));
            busInfor->append("\t");

            strTemp = QString::number(iter->get_price());
            strTemp.append(QObject::tr(" վ����:"));
            strTemp.append(QString::number(iter->get_station_num()));
            *busInfor=*busInfor+strTemp;
            busInfor->append(QObject::tr("\n����վ��Ϊ:"));
            SVEC station=iter->get_station();
            for(SITE iter1=station.begin();iter1!=station.end();++iter1)
            {
                busInfor->append(QString::fromLocal8Bit((*iter1).c_str()));
                if(iter1+1!=station.end())
                    busInfor->append("  ");
            }
            break; //������������
        }

    }
    if(iter!=busPtr->end())
        return busInfor;
    else
        return 0;
}
QString* BUS_SYSTEM::query_station(QString oneStation)		//��ѯ����ĳ��վ������й�������Ϣ
{
    QString* stationBus=new QString;                         //��ž���ĳ��վ������й�����·
    stationBus->clear();
    for(BUSITE iter=busPtr->begin();iter!=busPtr->end();++iter)
    {
        SVEC station=iter->get_station();
        SITE iter1=station.begin();
        for(;iter1!=station.end();++iter1)
        {
            if(oneStation==QString::fromLocal8Bit((*iter1).c_str()))
            {
                stationBus->append(QString::fromLocal8Bit(iter->get_name().c_str()));
                if(iter+1!=busPtr->end())
                    stationBus->append("\t");
            }
        }
        station.clear();        //�������վ��
    }
    if(stationBus->isEmpty())         //û�о�����վ��Ĺ�����·
        return 0;
    else
        return stationBus;
}
bool BUS_SYSTEM::updata(BUS &onebus,QString stationStr)
{
    BUSITE iter=busPtr->begin();
    int isFind=0;
    for(;iter!=busPtr->end();++iter)
    {
        if(iter->get_name()==onebus.get_name())
        {
            isFind=1;
            break;
        }
    }
    if(isFind==1)
    {
        iter->busCopy(onebus);
        iter->remove();
        stringstream sstr(stationStr.toLocal8Bit().data());
        string oneStation;
        for(int count=0;count<onebus.get_station_num()&&sstr>>oneStation;count++) //��ӹ���վ��
        {
            iter->to_all_station(oneStation);
        }
        return true;
    }
    return false;
}
bool BUS_SYSTEM::deleteBus(QString busName)
{
    BUSITE iter1=busPtr->begin();
    BUSITE iter2=busPtr->end();
    for(;iter1!=iter2;++iter1)
    {
        if(busName.toLocal8Bit().data()==iter1->get_name())
        {
            busPtr->erase(iter1);
            --busNum;
            return true;
        }
    }
    return false;
}
bool BUS_SYSTEM::saveFile(BUSVP busPtr)
{
    ofstream outfile(FILENAME,ios::out);
    if(!outfile)
        return false;
    else
    {
        BUS onebus;
        for(BUSITE iter=busPtr->begin();iter!=busPtr->end();++iter)
        {
            if(iter!=busPtr->begin())			//��һ�п�ͷ����Ҫ�س�
                outfile<<endl;

            onebus=*iter;
            outfile<<onebus.get_name()<<'\t'<<onebus.get_time()<<'\t'<<onebus.get_price()<<'\t';
            SVEC stationVec(onebus.get_station());
            SITE iter1=stationVec.begin();
            for(;iter1!=stationVec.end();++iter1)
            {
                outfile<<*iter1;
                if((iter1+1)!=stationVec.end())
                    outfile<<' ';
            }
        }
        outfile.close();
        return true;
    }
}

void  BUS_SYSTEM::queryOTOUnconditional(string from,string to,SVECP& pathS,SVECP& Adjbus)//����ʹ�õݹ� ��ɱ߱�ı���
{
    OTOITE iter=(edgePtr)->begin();
    pathS->push_back(from);
    if(from==to)
    {
        //��Ż��˲�ѯ���
        Result oneResult;
        oneResult.QueryBusResult=*Adjbus;
        oneResult.QueryPathResult=*pathS;
        oneResult.distance=pathS->size();
        result.push_back(oneResult);
        pathS->pop_back();
        return ;
    }
    else
    {
        //�ҵ���ʼվ��
        for(;iter!=edgePtr->end();++iter)
        {
            if(from==iter->get_from())
            {
                break;
            }
        }
        if(iter==edgePtr->end())    //û���ҵ����
        {
            pathS->pop_back();
            return ;
        }
        SVEC nextS=iter->get_to();
        SVEC nextB=iter->get_bus();
        SITE iter1=nextS.begin();
        SITE iter2=nextB.begin();

        for(;(iter1)!=nextS.end()&&iter2!=nextB.end();++iter1,++iter2)
        {
            //·����վ�����·����ͬʱ��ͬ
            if(find(pathS->begin(),pathS->end(),*iter1)==pathS->end())   //һ�ֻ����в��ܻ���ͬ����
            {
                bool flag=0;
                for(SITE iter3=Adjbus->begin();iter3!=Adjbus->end();++iter3)
                {
                    if(*iter3==*iter2){
                        flag=1;
                        break;
                    }
                }
                if(flag == 1 && *(Adjbus->end()-1)!=*iter2)
                    continue;
                Adjbus->push_back(*iter2);
                queryOTOUnconditional(*iter1,to,pathS,Adjbus);		//����
                Adjbus->pop_back();
            }
        }
        pathS->pop_back();
        return ;
    }
}
void BUS_SYSTEM::queryOTOChangeNumLimit(string from,string to,SVECP & pathS,SVECP & Adjbus,int changeNum) //���ƻ��˴����Ĳ�ѯ
{
    OTOITE iter=(edgePtr)->begin();
    pathS->push_back(from);
    if(from==to)
    {
        //��Ż��˲�ѯ�����յ�һ�ַ���
        Result oneResult;
        oneResult.QueryBusResult=*Adjbus;
        oneResult.QueryPathResult=*pathS;
        oneResult.distance=pathS->size();
        result.push_back(oneResult);
        pathS->pop_back();
        return ;
    }
    else
    {
        //�ҵ���ʼվ��
        for(;iter!=edgePtr->end();++iter)
        {
            if(from==iter->get_from())
            {
                break;
            }
        }
        if(iter==edgePtr->end())    //û���ҵ����
        {
            pathS->pop_back();
            return ;
        }
        SVEC nextS=iter->get_to();
        SVEC nextB=iter->get_bus();
        SITE iter1=nextS.begin();
        SITE iter2=nextB.begin();

        for(;(iter1)!=nextS.end()&&iter2!=nextB.end();++iter1,++iter2)
        {
            //·����վ�����·����ͬʱ��ͬ
            if(find(pathS->begin(),pathS->end(),*iter1)==pathS->end())   //һ�ֻ����в��ܻ���ͬ����
            {

                if(Adjbus->size() > 0)
                {
                    bool flag=0;
                    SITE iter3=Adjbus->begin();
                    string station =*iter3;
                    int busNum=0;                          //��ʾ�����������Ĺ�������Ŀ
                    for(;iter3!=Adjbus->end();++iter3)
                    {
                        if(*iter3==*iter2&&flag!=1){
                            flag=1;
                        }
                        if(station==*iter3)
                            continue;
                        else{
                            station=*iter3;
                            ++busNum;
                        }
                    }
                    if( flag == 1 && *(Adjbus->end()-1)!=*iter2 )
                        continue;

                    if(*(Adjbus->end()-1)!=*iter2)  //��ӱ�վ����Ƿ񳬹�Ҫ����Ŀ
                    {
                        ++busNum;
                    }
                    if(busNum>changeNum){
                        continue;

                    }
                }

                Adjbus->push_back(*iter2);
                queryOTOChangeNumLimit(*iter1,to,pathS,Adjbus,changeNum);		//����
                Adjbus->pop_back();
            }
        }
        pathS->pop_back();
        return ;
    }
}
void BUS_SYSTEM::queryOTOChangeNumLimit(string from,string to,SVECP & pathS,SVECP & Adjbus,int changeNum,int realNum) //���ƻ��˴����Ĳ�ѯ
{

    pathS->push_back(from);     //�������
    if(from==to)                //��ʾ�ҵ�һ��·��
    {
        Result oneResult;
        oneResult.QueryBusResult=*Adjbus;
        oneResult.QueryPathResult=*pathS;
        oneResult.distance=pathS->size();
        result.push_back(oneResult);
        pathS->pop_back();
        return ;
    }
    else
    {
        //�ҵ���ʼվ��
        OTOITE iter=(edgePtr)->begin();
        for(;iter!=edgePtr->end();++iter)
        {
            if(from==iter->get_from())  //�ҵ����ֱ������
            {
                break;
            }
        }
        if(iter==edgePtr->end())    //û���ҵ����
        {
            pathS->pop_back();
            return ;
        }
        SVEC nextS=iter->get_to();
        SVEC nextB=iter->get_bus();
        SITE iter1=nextS.begin();
        SITE iter2=nextB.begin();

        for(;(iter1)!=nextS.end()&&iter2!=nextB.end();++iter1,++iter2)
        {
            //·����վ�����·����ͬʱ��ͬ
            if(find(pathS->begin(),pathS->end(),*iter1)==pathS->end())   //һ�ֻ����в��ܾ���ͬ��վ��
            {
                bool isAdd=false;
                if(Adjbus->size() > 0)
                {
                    bool flag=0;
                    SITE iter3=Adjbus->begin();
                    for(;iter3!=Adjbus->end();++iter3)
                    {
                        if(*iter3==*iter2){         //����ҵ���ͬ��վ��
                            flag=1;
                            break;
                        }
                    }
                    if( flag == 1 && *(Adjbus->end()-1)!=*iter2 )   //һ�λ����в��ܻ���ͬ����
                        continue;

                    if(*(Adjbus->end()-1)!=*iter2)  //��ӱ�վ����Ƿ������˻��˴���
                    {
                        ++realNum;
                        isAdd=true;               // ����Ƿ����ӻ��˴���
                    }
                    if(realNum>changeNum)        //������˴�������Ҫ��
                    {
                        if(isAdd==true)         //����Ѿ������˻��˴��� �ͼ�ȥ
                            --realNum;
                        continue;
                    }

                }

                Adjbus->push_back(*iter2);      //���澭������·����
                queryOTOChangeNumLimit(*iter1,to,pathS,Adjbus,changeNum,realNum);		//����
                Adjbus->pop_back();
                if(isAdd==true)
                    --realNum;
            }
        }
        pathS->pop_back();
        return ;
    }
}
void BUS_SYSTEM::queryOTODistance(string from,string to,SVECP & pathS,SVECP & Adjbus) //���ƾ���Ĳ�ѯ
{
    //Ĭ��ÿ����վ��֮��������
    OTOITE iter=(edgePtr)->begin();
    pathS->push_back(from);
    if(from==to)
    {
        Result oneResult;
        oneResult.QueryBusResult=*Adjbus;
        oneResult.QueryPathResult=*pathS;
        oneResult.distance=pathS->size()-1;     //��ʾ����վ����ĸ���
        result.push_back(oneResult);
        pathS->pop_back();
        return ;
    }
    else
    {
        //�ҵ���ʼվ��
        for(;iter!=edgePtr->end();++iter)
        {
            if(from==iter->get_from())
            {
                break;
            }
        }
        if(iter==edgePtr->end())    //û���ҵ����
        {
            pathS->pop_back();
            return ;
        }
        SVEC nextS=iter->get_to();
        SVEC nextB=iter->get_bus();
        SITE iter1=nextS.begin();
        SITE iter2=nextB.begin();

        for(;(iter1)!=nextS.end()&&iter2!=nextB.end();++iter1,++iter2)
        {
            //·����վ�����·����ͬʱ��ͬ
            if(find(pathS->begin(),pathS->end(),*iter1)==pathS->end())   //һ�ֻ����в��ܻ���ͬ����
            {

                if(Adjbus->size() > 0)
                {
                    bool flag=0;
                    SITE iter3=Adjbus->begin();
                    string station =*iter3;
                    int busNum=0;                          //��ʾ�����������Ĺ�������Ŀ
                    for(;iter3!=Adjbus->end();++iter3)
                    {
                        if(*iter3==*iter2&&flag!=1){
                            flag=1;
                        }
                        if(station==*iter3)
                            continue;
                        else{
                            station=*iter3;
                            ++busNum;
                        }
                    }
                    if( flag == 1 && *(Adjbus->end()-1)!=*iter2 )
                        continue;

                    if(*(Adjbus->end()-1)!=*iter2)  //��ӱ�վ����Ƿ����ӻ��˴���
                    {
                        ++busNum;
                    }
                }

                Adjbus->push_back(*iter2);
                queryOTODistance(*iter1,to,pathS,Adjbus);		//����
                Adjbus->pop_back();
            }
        }
        pathS->pop_back();
        return ;
    }
}
void BUS_SYSTEM::queryOTOPrice(string from,string to,SVECP & pathS,SVECP & Adjbus,double realPrice) //���ƾ���Ĳ�ѯ
{   //Ĭ��ÿ����վ��֮��������
    OTOITE iter=(edgePtr)->begin();
    pathS->push_back(from);
    if(from==to)
    {
        Result oneResult;
        oneResult.QueryBusResult=*Adjbus;
        oneResult.QueryPathResult=*pathS;
        oneResult.price=realPrice;
        result.push_back(oneResult);
        pathS->pop_back();
        return ;
    }
    else
    {
        //�ҵ���ʼվ��
        for(;iter!=edgePtr->end();++iter)
        {
            if(from==iter->get_from())
            {
                break;
            }
        }
        if(iter==edgePtr->end())    //û���ҵ����
        {
            pathS->pop_back();
            return ;
        }
        SVEC nextS=iter->get_to();
        SVEC nextB=iter->get_bus();
        SITE iter1=nextS.begin();
        SITE iter2=nextB.begin();

        for(;(iter1)!=nextS.end()&&iter2!=nextB.end();++iter1,++iter2)
        {
            //·����վ�����·����ͬʱ��ͬ
            if(find(pathS->begin(),pathS->end(),*iter1)==pathS->end())
            {
                bool addBus=0;
                bool busIsNull=1;
                if(Adjbus->size() > 0)
                {
                    busIsNull=0;
                    bool flag=0;
                    SITE iter3=Adjbus->begin();
                    for(;iter3!=Adjbus->end();++iter3)
                    {
                        if(*iter3==*iter2){     //һ�λ����в��ܻ���ͬ����
                            flag=1;
                            break;
                        }
                    }
                    if( flag == 1 && *(Adjbus->end()-1)!=*iter2 )
                        continue;

                    if(*(Adjbus->end()-1)!=*iter2)  //��ӱ�վ����Ƿ����ӻ��˴���
                    {
                        addBus=1;
                    }
                }

                Adjbus->push_back(*iter2);
                BUSITE busiter=busPtr->begin();
                if(addBus==1||busIsNull == 1)       //��������һ���µ���·���߻�û����·
                {

                    for(;busiter!=busPtr->end();++busiter)
                    {
                        if((*busiter).get_name()==*iter2)
                        {
                            realPrice+=(*busiter).get_price();  //�ҵ���Ӧ��· ������ӦƱ��
                            break;
                        }
                    }
                }
                queryOTOPrice(*iter1,to,pathS,Adjbus,realPrice);		//����
                Adjbus->pop_back();
                if(addBus==1||busIsNull == 1)
                    realPrice=realPrice-(*busiter).get_price();
            }
        }
        pathS->pop_back();
        return ;
    }
}
bool BUS_SYSTEM::isExisted(QString busName)
{
    BUSITE iter=busPtr->begin();
    BUSITE iterEnd=busPtr->end();
    for(;iter!=iterEnd;++iter)
    {
        if(iter->get_name()==busName.toLocal8Bit().data())
            return true;
    }
    return false;
}
