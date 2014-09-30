#include "widget.h"
#include "ui_widget.h"
#include "Extern.h"
#include "createBusList.h"
bool cmp1(const Result &a,const Result & b)         //�ȽϾ���
{
    return a.distance<b.distance;
}
bool cmp2(const Result &a,const Result & b)         //�Ƚ�Ʊ��
{
    return a.price<b.price;
}
Widget::Widget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lineEdit_Code->setEchoMode(QLineEdit::Password);    //���ǺŴ�������
}

Widget::~Widget()
{
    delete ui;
}
void Widget::on_pushButton_Login_clicked()      //��¼
{
    QString name = ui->lineEdit_Name->text();
    QString code = ui->lineEdit_Code->text();
    SMAPP tempPtr = createAdministratorMap();
    if(tempPtr==0)
    {
        QMessageBox box;
        box.setWindowTitle(tr("��ʾ"));
        box.setIcon(QMessageBox::Information);
        box.setText(tr("û�й���Ա��Ϣ"));
        box.setStandardButtons(QMessageBox::Yes);
        box.exec();
    }
    else if(Login(name.toStdString(),code.toStdString(),tempPtr) == true){
        isLogin = 1;
        QMessageBox box;
        box.setWindowTitle(tr("��ʾ"));
        box.setIcon(QMessageBox::Information);
        box.setText(tr(" ��½�ɹ�"));
        box.setStandardButtons(QMessageBox::Yes);
        box.exec();
    }else{
        isLogin = 0;
        QMessageBox box;
        box.setWindowTitle(tr("��ʾ"));
        box.setIcon(QMessageBox::Information);
        box.setText(tr(" ������û�������"));
        box.setStandardButtons(QMessageBox::Yes);
        box.exec();
        ui->lineEdit_Code->setText("");         //�������������
        ui->lineEdit_Name->setText("");
    }
}

void Widget::on_pushButton_Quit_clicked()       //�˳�
{
    if(isChange==1)
    {
        QMessageBox box;
        box.setWindowTitle(tr("��ʾ"));
        box.setIcon(QMessageBox::Information);
        box.setText(tr("�ļ������Ѿ����ģ��Ƿ񱣴��ļ���"));
        box.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        box.setDefaultButton(QMessageBox::Save);
        int ret = box.exec();
        switch (ret) {
          case QMessageBox::Yes:
              // Save was clicked
            BUS_SYSTEM bus_system;
            bus_system.saveFile(busPtr);
            delete busPtr;
            busPtr=0;
            qApp->quit();
            break;
          case QMessageBox::No:
              // Don't Save was clicked
            delete busPtr;
            busPtr=0;
            qApp->quit();
            break;
          case QMessageBox::Cancel:
              // Cancel was clicked
              break;
          default:
              // should never be reached
              break;
        }

    }
    else{
        delete busPtr;
        busPtr=0;
        qApp->quit();
    }
}

void Widget::on_pushButton_Logout_clicked()     //ע��
{
    isLogin=0;
    QMessageBox box;
    box.setWindowTitle(tr("��ʾ"));
    box.setIcon(QMessageBox::Information);
    box.setText(tr("ע���ɹ�"));
    box.setStandardButtons(QMessageBox::Yes);
    ui->lineEdit_Code->setText("");         //�������������
    ui->lineEdit_Name->setText("");
    box.exec();
}

void Widget::on_pushButton_QueryAll_clicked()       //��ѯ���й�����·��Ϣ
{
    ui->textBrowser_AllBus->setText(QObject::tr("��������Ϊ: %1").arg(busNum));
    if(busNum>0)                                                    //�ж��Ƿ��й�����·
    {
        if(isSort!=1)                                           //�ж��Ƿ�������
        {
            BUS_SYSTEM bus_system;
            bus_system.sort_bus_start(busPtr);                  //�����������
            isSort=1;                                           //��ʾ�Ѿ�����
            isChange=1;
        }
        for(BUSITE iter=busPtr->begin();iter!=busPtr->end();++iter)
        {
            QString str;            //�����ʾ������Ϣ
            QString strTemp1;       //��ʱ���

            str = QString::fromLocal8Bit(iter->get_name().c_str());
            str.append("\t");
            str.append(QString::fromLocal8Bit(iter->get_time().c_str()));
            str.append("\t");

            strTemp1 = QString::number(iter->get_price());
            strTemp1.append(tr(" վ����:"));
            strTemp1.append(QString::number(iter->get_station_num()));

            ui->textBrowser_AllBus->append(str+strTemp1);
            if(iter->get_station_num()>0)
            {
                SVEC station=iter->get_station();
                QString stationStr;
                stationStr.clear();             //���ַ������
                for(SITE iter1=station.begin();iter1!=station.end();++iter1)       //�ҵ�����վ��
                {
                    stationStr.append(QString::fromLocal8Bit((*iter1).c_str()));
                    if(iter1+1!=station.end())
                        stationStr.append("  ");
                }
                stationStr.append("\n");
                ui->textBrowser_AllBus->append(stationStr);
                //������ղ���
                if(!station.empty())
                    station.clear();
            }
            else
                ui->textBrowser_AllBus->append(tr("û��վ��\n"));
        }
    }
}

void Widget::on_pushButton_StationQuery_clicked()   //��ѯ����ĳ��վ��Ĺ�����·
{
    BUS_SYSTEM bus_system;
    QString station=ui->lineEdit_Station->text();
    QString* stationBusPtr=bus_system.query_station(station);
    if(stationBusPtr!=0)
        ui->textBrowser_SomeBus->setText(*stationBusPtr);
    else
        ui->textBrowser_SomeBus->setText(tr("û����·������վ��"));
}

void Widget::on_pushButton_OneBus_clicked()     //��ѯĳ��������·
{
    QString busName;
    busName=ui->lineEdit_OneBus->text();
    BUS_SYSTEM bus_system;
    QString * busResultPtr=bus_system.query_onebus(busName);
    if(busResultPtr==0)
        ui->textBrowser_OneBus->setText(tr("û�и���·��Ϣ!"));
    else
        ui->textBrowser_OneBus->setText(*busResultPtr);
}

void Widget::on_pushButton_Add_clicked()        //���һ��������Ϣ
{
    if(isLogin==0)              //û�е�¼ ���ܽ������
    {
        QMessageBox box;
        box.setWindowTitle(tr("��ʾ"));
        box.setIcon(QMessageBox::Information);
        box.setText(tr("δ��¼�����ȵ�¼"));
        box.setStandardButtons(QMessageBox::Yes);
        box.exec();
    }
    else
    {
        BUS_SYSTEM bus_system;
        QString name;
        name=ui->lineEdit_AddBus->text();
        if(bus_system.isExisted(name))
        {
            QMessageBox box;
            box.setWindowTitle(tr("��ʾ"));
            box.setIcon(QMessageBox::Information);
            box.setText(tr("�ù�����·�Ѿ����ڣ����ʧ��"));
            box.setStandardButtons(QMessageBox::Yes);
            box.exec();
        }
        else
        {
            QString time;
            time=ui->lineEdit_AddTime->text();
            QString stationStr=ui->plainTextEdit_AddBus->toPlainText();
            if(name.isEmpty()||time.isEmpty())//||stationStr.isEmpty())
            {
                QMessageBox box;
                box.setWindowTitle(tr("��ʾ"));
                box.setIcon(QMessageBox::Information);
                box.setText(tr("��Ϣ��ȫ�����ʧ��"));
                box.setStandardButtons(QMessageBox::Yes);
                box.exec();
            }
            else
            {
                double price=ui->doubleSpinBox_AddPrice->value();
                int stationNum=ui->spinBox_StationNum->value();
                BUS onebus;
                onebus.bus(name.toLocal8Bit().data(),time.toLocal8Bit().data(),stationNum,price);

                if(bus_system.add_bus(onebus,stationStr))   //��ӳɹ� ��������
                {
                    isSort=0;
                    isChange=1;
                }
                QMessageBox box;
                box.setWindowTitle(tr("��ʾ"));
                box.setIcon(QMessageBox::Information);
                box.setText(tr("��ӳɹ�"));
                box.setStandardButtons(QMessageBox::Yes);
                box.exec();
            }
        }
    }
}

void Widget::on_pushButton_DeleteBus_clicked()
{
    if(isLogin==0)
    {
        QMessageBox box;
        box.setWindowTitle(tr("��ʾ"));
        box.setIcon(QMessageBox::Information);
        box.setText(tr("δ��¼�����ȵ�¼"));
        box.setStandardButtons(QMessageBox::Yes);
        box.exec();
    }
    else
    {
        QString busName=ui->lineEdit_DeleteBus->text();
        BUS_SYSTEM bus_system;
        if(!bus_system.isExisted(busName))
        {
            QMessageBox box;
            box.setWindowTitle(tr("��ʾ"));
            box.setIcon(QMessageBox::Information);
            box.setText(tr("�����ڸù�����·"));
            box.setStandardButtons(QMessageBox::Yes);
            box.exec();
        }
        else
        {
            if(bus_system.deleteBus(busName))
            {
                QMessageBox box;
                box.setWindowTitle(tr("��ʾ"));
                box.setIcon(QMessageBox::Information);
                box.setText(tr("ɾ���ɹ�"));
                box.setStandardButtons(QMessageBox::Yes);
                box.exec();
            }
            else
            {
                QMessageBox box;
                box.setWindowTitle(tr("��ʾ"));
                box.setIcon(QMessageBox::Information);
                box.setText(tr("ɾ��ʧ��"));
                box.setStandardButtons(QMessageBox::Yes);
                box.exec();
            }
        }
    }
}

void Widget::on_pushButton_Update_clicked()
{
    if(isLogin==0)              //û�е�¼ ���ܽ��и���
    {
        QMessageBox box;
        box.setWindowTitle(tr("��ʾ"));
        box.setIcon(QMessageBox::Information);
        box.setText(tr("δ��¼�����ȵ�¼"));
        box.setStandardButtons(QMessageBox::Yes);
        box.exec();
    }
    else
    {
        QString busName;
        busName=ui->lineEdit_UpdateBus->text();
        BUS_SYSTEM bus_system;
        if(!bus_system.isExisted(busName))
        {
            QMessageBox box;
            box.setWindowTitle(tr("��ʾ"));
            box.setIcon(QMessageBox::Information);
            box.setText(tr("�����ڸù�����·"));
            box.setStandardButtons(QMessageBox::Yes);
            box.exec();
        }
        else
        {
            QString time=ui->lineEdit_UpdateTime->text();
            if(time.isEmpty())
            {
                QMessageBox box;
                box.setWindowTitle(tr("��ʾ"));
                box.setIcon(QMessageBox::Information);
                box.setText(tr("��Ϣ��ȫ������ʧ��"));
                box.setStandardButtons(QMessageBox::Yes);
                box.exec();
            }
            else
            {
                QString stationStr = ui->plainTextEdit_UpdateStation->toPlainText();
                int stationNum=ui->spinBox_UpdateStationNum->value();
                double price=ui->doubleSpinBox_UpdatePrice->value();
                BUS onebus;
                onebus.bus(busName.toLocal8Bit().data(),time.toLocal8Bit().data(),stationNum,price);
                if(bus_system.updata(onebus,stationStr))
                {
                    QMessageBox box;
                    box.setWindowTitle(tr("��ʾ"));
                    box.setIcon(QMessageBox::Information);
                    box.setText(tr("���³ɹ�"));
                    box.setStandardButtons(QMessageBox::Yes);
                    box.exec();
                }
                else
                {
                    QMessageBox box;
                    box.setWindowTitle(tr("��ʾ"));
                    box.setIcon(QMessageBox::Information);
                    box.setText(tr("����ʧ��"));
                    box.setStandardButtons(QMessageBox::Yes);
                    box.exec();
                }
            }
        }
    }
}

void Widget::on_pushButton_BusChange_clicked()
{
    QString start=ui->lineEdit_Start->text();
    QString end=ui->lineEdit_End->text();
    if(start.isEmpty()||end.isEmpty())
    {
        QMessageBox box;
        box.setWindowTitle(tr("��ʾ"));
        box.setIcon(QMessageBox::Information);
        box.setText(tr("�����յ���Ϣ��ȫ"));
        box.setStandardButtons(QMessageBox::Yes);
        box.exec();
    }
    else
    {
        SVECP pathS=new SVEC;		//���ڱ��滻�˵�·�� pathS���վ�� Adjbus��Ź���·����
        SVECP Adjbus=new SVEC;
        BUS_SYSTEM bus_system;
        Create create;
        if(hasEdge==0||isChange==1)      //���û�д����߱������Ϣ�ı� �ʹ����߱�
        {
            create.createStation();
            create.edgeList();
            hasEdge=1;
            isChange=0;
        }
        if(ui->radioButton_Unconditional->isChecked() == true)  //һ������������
        {
            pathS->clear();
            Adjbus->clear();
            result.clear();
            bus_system.queryOTOUnconditional(start.toLocal8Bit().data(),end.toLocal8Bit().data(),pathS,Adjbus);
           // sort(result.begin(),result.end(),cmp1);       //���Բ�������
            showOTO();

        }
        if(ui->radioButton_ChangeLess->isChecked()==true)       //�������ƻ��˴�����ѯ
        {
            pathS->clear();
            Adjbus->clear();
            int changeNum=ui->spinBox_ChangeNum->value();
            result.clear();
            bus_system.queryOTOChangeNumLimit(start.toLocal8Bit().data(),end.toLocal8Bit().data(),pathS,Adjbus,changeNum,0);
            sort(result.begin(),result.end(),cmp1);             //���ջ��˴������ٵ�������
            showOTO();
        }
        if(ui->radioButton_DistanceLess->isChecked()==true)     //����������̲�ѯ
        {
            pathS->clear();
            Adjbus->clear();
            result.clear();
            bus_system.queryOTODistance(start.toLocal8Bit().data(),end.toLocal8Bit().data(),pathS,Adjbus);
            sort(result.begin(),result.end(),cmp1);            //���վ����ɽ���Զ����
            showOTODistance();
        }
        if(ui->radioButton_PriceLess->isChecked()==true)     //�ġ�Ʊ�����ٲ�ѯ
        {
            pathS->clear();
            Adjbus->clear();
            result.clear();
            bus_system.queryOTOPrice(start.toLocal8Bit().data(),end.toLocal8Bit().data(),pathS,Adjbus,0);
            sort(result.begin(),result.end(),cmp2);         //����Ʊ�����ٵ�������
            showOTOPrice();
        }
    }
}
void Widget::showOTO()
{

    vector<Result>::iterator  iter=result.begin();
    vector<Result>::iterator iterEnd=result.end();
    int sum=result.size();
    ui->textBrowser_BusChange->setText(tr("����%1�ַ���:\n").arg(sum));
    int count=1;
    for(;iter!=iterEnd;++iter,++count)
    {
        ui->textBrowser_BusChange->append(tr("��%1�ַ���").arg(count));
        SITE siter1=((*iter).QueryPathResult).begin();
        SITE siterEnd1=((*iter).QueryPathResult).end();
        SITE siter2=((*iter).QueryBusResult).begin();
        SITE siterEnd2=((*iter).QueryBusResult).end();
        string busChange=*siter2;
        string resultStr;
        int change=0;                   //�ܵĻ��˴���
        for(;siter1!=siterEnd1 && siter2!=siterEnd2;++siter1,++siter2)
        {
            resultStr.append(*siter1);
            resultStr.append("\t");
            resultStr.append(*siter2);
            resultStr.append("\t");
            if(busChange!=*siter2)
            {
                busChange=*siter2;
                ++change;
            }
        }
        resultStr.append(*siter1);
        ui->textBrowser_BusChange->append(QString::fromLocal8Bit(resultStr.c_str()));
        ui->textBrowser_BusChange->append(tr("�˷�����Ҫ���˴���Ϊ:%1\n").arg(change));
    }
}
void Widget::showOTODistance()                      //���վ����ѯ�����ʾ
{

    vector<Result>::iterator  iter=result.begin();
    vector<Result>::iterator iterEnd=result.end();
    int sum=result.size();
    ui->textBrowser_BusChange->setText(tr("����%1�ַ���:\n").arg(sum));
    int count=1;
    for(;iter!=iterEnd;++iter,++count)
    {
        ui->textBrowser_BusChange->append(tr("��%1�ַ���").arg(count));
        SITE siter1=((*iter).QueryPathResult).begin();
        SITE siterEnd1=((*iter).QueryPathResult).end();
        SITE siter2=((*iter).QueryBusResult).begin();
        SITE siterEnd2=((*iter).QueryBusResult).end();
        string busChange=*siter2;
        string resultStr;
        int change=0;                   //�ܵĻ��˴���
        for(;siter1!=siterEnd1 && siter2!=siterEnd2;++siter1,++siter2)
        {
            resultStr.append(*siter1);
            resultStr.append("\t");
            resultStr.append(*siter2);
            resultStr.append("\t");
            if(busChange!=*siter2)
            {
                busChange=*siter2;
                ++change;
            }
        }
        resultStr.append(*siter1);
        ui->textBrowser_BusChange->append(QString::fromLocal8Bit(resultStr.c_str()));
        ui->textBrowser_BusChange->append(tr("�˷�����Ҫ���˴���Ϊ:%1").arg(change));
        ui->textBrowser_BusChange->append(tr("�˷�����Ҫ�ܾ���Ϊ:%1\n").arg((*iter).distance));
    }
}
void Widget::showOTOPrice()
{

    vector<Result>::iterator  iter=result.begin();
    vector<Result>::iterator iterEnd=result.end();
    int sum=result.size();
    ui->textBrowser_BusChange->setText(tr("����%1�ַ���:\n").arg(sum));
    int count=1;
    for(;iter!=iterEnd;++iter,++count)
    {
        ui->textBrowser_BusChange->append(tr("��%1�ַ���").arg(count));
        SITE siter1=((*iter).QueryPathResult).begin();
        SITE siterEnd1=((*iter).QueryPathResult).end();
        SITE siter2=((*iter).QueryBusResult).begin();
        SITE siterEnd2=((*iter).QueryBusResult).end();
        string busChange=*siter2;
        string resultStr;
        int change=0;                   //�ܵĻ��˴���
        for(;siter1!=siterEnd1 && siter2!=siterEnd2;++siter1,++siter2)
        {
            resultStr.append(*siter1);
            resultStr.append("\t");
            resultStr.append(*siter2);
            resultStr.append("\t");
            if(busChange!=*siter2)
            {
                busChange=*siter2;
                ++change;
            }
        }
        resultStr.append(*siter1);
        ui->textBrowser_BusChange->append(QString::fromLocal8Bit(resultStr.c_str()));
        ui->textBrowser_BusChange->append(tr("�˷�����Ҫ���˴���Ϊ:%1").arg(change));
        ui->textBrowser_BusChange->append(tr("�˷�����Ҫ��Ʊ��Ϊ:%1\n").arg((*iter).price));
    }
}
/*void Widget::showOTO(int changeNum)
{

    vector< vector<string> >::iterator  iter1=QueryPathResult->begin();
    SVVITER iterEnd1=QueryPathResult->end();
    SVVITER iter2=QueryBusResult->begin();
    SVVITER iterEnd2=QueryBusResult->end();
    int sum=0;
    for(;iter2!=iterEnd2;++iter2)
    {
        int busNumTemp=1;
        SITE iterTemp=iter2->begin();
        string busNameTemp=*iterTemp;
        for(;iterTemp!=iter2->end();++iterTemp)
        {
            if(busNameTemp!=*iterTemp)
            {
                busNameTemp=*iterTemp;
                ++busNumTemp;
            }
        }
        if(busNumTemp<=changeNum+1)
            ++sum;
    }
    ui->textBrowser_BusChange->setText(tr("����%1�ַ���:\n").arg(sum));

    iter2=QueryBusResult->begin();

    int count=1;
    for(;iter1!=iterEnd1&&iter2!=iterEnd2;++iter1,++iter2,++count)
    {
        //ui->textBrowser_BusChange->append(tr("��%1�ַ���").arg(count));
        SITE siter1=(*iter1).begin();
        SITE siterEnd1=(*iter1).end();
        SITE siter2=(*iter2).begin();
        SITE siterEnd2=(*iter2).end();
        string busChange=*siter2;
        string result;
        int change=0;                   //���˴���
        for(;siter1!=siterEnd1 && siter2!=siterEnd2;++siter1,++siter2)
        {
            result.append(*siter1);
            result.append("\t");
            result.append(*siter2);
            result.append("\t");
            if(busChange!=*siter2)
            {
                busChange=*siter2;
                ++change;
            }
        }
        result.append(*siter1);
        if(change<=changeNum)
        {
            ui->textBrowser_BusChange->append(QString::fromLocal8Bit(result.c_str()));
            ui->textBrowser_BusChange->append(tr("�˷�����Ҫ���˴���Ϊ:%1\n").arg(change));
        }
    }
}*/
