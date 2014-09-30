#include "widget.h"
#include "ui_widget.h"
#include "Extern.h"
#include "createBusList.h"
bool cmp1(const Result &a,const Result & b)         //比较距离
{
    return a.distance<b.distance;
}
bool cmp2(const Result &a,const Result & b)         //比较票价
{
    return a.price<b.price;
}
Widget::Widget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lineEdit_Code->setEchoMode(QLineEdit::Password);    //用星号代替密码
}

Widget::~Widget()
{
    delete ui;
}
void Widget::on_pushButton_Login_clicked()      //登录
{
    QString name = ui->lineEdit_Name->text();
    QString code = ui->lineEdit_Code->text();
    SMAPP tempPtr = createAdministratorMap();
    if(tempPtr==0)
    {
        QMessageBox box;
        box.setWindowTitle(tr("提示"));
        box.setIcon(QMessageBox::Information);
        box.setText(tr("没有管理员信息"));
        box.setStandardButtons(QMessageBox::Yes);
        box.exec();
    }
    else if(Login(name.toStdString(),code.toStdString(),tempPtr) == true){
        isLogin = 1;
        QMessageBox box;
        box.setWindowTitle(tr("提示"));
        box.setIcon(QMessageBox::Information);
        box.setText(tr(" 登陆成功"));
        box.setStandardButtons(QMessageBox::Yes);
        box.exec();
    }else{
        isLogin = 0;
        QMessageBox box;
        box.setWindowTitle(tr("提示"));
        box.setIcon(QMessageBox::Information);
        box.setText(tr(" 密码或用户名错误"));
        box.setStandardButtons(QMessageBox::Yes);
        box.exec();
        ui->lineEdit_Code->setText("");         //清空输入行内容
        ui->lineEdit_Name->setText("");
    }
}

void Widget::on_pushButton_Quit_clicked()       //退出
{
    if(isChange==1)
    {
        QMessageBox box;
        box.setWindowTitle(tr("提示"));
        box.setIcon(QMessageBox::Information);
        box.setText(tr("文件内容已经更改，是否保存文件？"));
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

void Widget::on_pushButton_Logout_clicked()     //注销
{
    isLogin=0;
    QMessageBox box;
    box.setWindowTitle(tr("提示"));
    box.setIcon(QMessageBox::Information);
    box.setText(tr("注销成功"));
    box.setStandardButtons(QMessageBox::Yes);
    ui->lineEdit_Code->setText("");         //清空输入行内容
    ui->lineEdit_Name->setText("");
    box.exec();
}

void Widget::on_pushButton_QueryAll_clicked()       //查询所有公交线路信息
{
    ui->textBrowser_AllBus->setText(QObject::tr("公交总数为: %1").arg(busNum));
    if(busNum>0)                                                    //判断是否有公交线路
    {
        if(isSort!=1)                                           //判断是否还须排序
        {
            BUS_SYSTEM bus_system;
            bus_system.sort_bus_start(busPtr);                  //按照起点排序
            isSort=1;                                           //表示已经排序
            isChange=1;
        }
        for(BUSITE iter=busPtr->begin();iter!=busPtr->end();++iter)
        {
            QString str;            //存放显示公交信息
            QString strTemp1;       //临时存放

            str = QString::fromLocal8Bit(iter->get_name().c_str());
            str.append("\t");
            str.append(QString::fromLocal8Bit(iter->get_time().c_str()));
            str.append("\t");

            strTemp1 = QString::number(iter->get_price());
            strTemp1.append(tr(" 站点数:"));
            strTemp1.append(QString::number(iter->get_station_num()));

            ui->textBrowser_AllBus->append(str+strTemp1);
            if(iter->get_station_num()>0)
            {
                SVEC station=iter->get_station();
                QString stationStr;
                stationStr.clear();             //把字符串清空
                for(SITE iter1=station.begin();iter1!=station.end();++iter1)       //找到所有站点
                {
                    stationStr.append(QString::fromLocal8Bit((*iter1).c_str()));
                    if(iter1+1!=station.end())
                        stationStr.append("  ");
                }
                stationStr.append("\n");
                ui->textBrowser_AllBus->append(stationStr);
                //容器清空操作
                if(!station.empty())
                    station.clear();
            }
            else
                ui->textBrowser_AllBus->append(tr("没有站点\n"));
        }
    }
}

void Widget::on_pushButton_StationQuery_clicked()   //查询经过某个站点的公交线路
{
    BUS_SYSTEM bus_system;
    QString station=ui->lineEdit_Station->text();
    QString* stationBusPtr=bus_system.query_station(station);
    if(stationBusPtr!=0)
        ui->textBrowser_SomeBus->setText(*stationBusPtr);
    else
        ui->textBrowser_SomeBus->setText(tr("没有线路经过该站点"));
}

void Widget::on_pushButton_OneBus_clicked()     //查询某个公交线路
{
    QString busName;
    busName=ui->lineEdit_OneBus->text();
    BUS_SYSTEM bus_system;
    QString * busResultPtr=bus_system.query_onebus(busName);
    if(busResultPtr==0)
        ui->textBrowser_OneBus->setText(tr("没有该线路信息!"));
    else
        ui->textBrowser_OneBus->setText(*busResultPtr);
}

void Widget::on_pushButton_Add_clicked()        //添加一条公交信息
{
    if(isLogin==0)              //没有登录 不能进行添加
    {
        QMessageBox box;
        box.setWindowTitle(tr("提示"));
        box.setIcon(QMessageBox::Information);
        box.setText(tr("未登录，请先登录"));
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
            box.setWindowTitle(tr("提示"));
            box.setIcon(QMessageBox::Information);
            box.setText(tr("该公交线路已经存在，添加失败"));
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
                box.setWindowTitle(tr("提示"));
                box.setIcon(QMessageBox::Information);
                box.setText(tr("信息不全，添加失败"));
                box.setStandardButtons(QMessageBox::Yes);
                box.exec();
            }
            else
            {
                double price=ui->doubleSpinBox_AddPrice->value();
                int stationNum=ui->spinBox_StationNum->value();
                BUS onebus;
                onebus.bus(name.toLocal8Bit().data(),time.toLocal8Bit().data(),stationNum,price);

                if(bus_system.add_bus(onebus,stationStr))   //添加成功 重新排序
                {
                    isSort=0;
                    isChange=1;
                }
                QMessageBox box;
                box.setWindowTitle(tr("提示"));
                box.setIcon(QMessageBox::Information);
                box.setText(tr("添加成功"));
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
        box.setWindowTitle(tr("提示"));
        box.setIcon(QMessageBox::Information);
        box.setText(tr("未登录，请先登录"));
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
            box.setWindowTitle(tr("提示"));
            box.setIcon(QMessageBox::Information);
            box.setText(tr("不存在该公交线路"));
            box.setStandardButtons(QMessageBox::Yes);
            box.exec();
        }
        else
        {
            if(bus_system.deleteBus(busName))
            {
                QMessageBox box;
                box.setWindowTitle(tr("提示"));
                box.setIcon(QMessageBox::Information);
                box.setText(tr("删除成功"));
                box.setStandardButtons(QMessageBox::Yes);
                box.exec();
            }
            else
            {
                QMessageBox box;
                box.setWindowTitle(tr("提示"));
                box.setIcon(QMessageBox::Information);
                box.setText(tr("删除失败"));
                box.setStandardButtons(QMessageBox::Yes);
                box.exec();
            }
        }
    }
}

void Widget::on_pushButton_Update_clicked()
{
    if(isLogin==0)              //没有登录 不能进行更新
    {
        QMessageBox box;
        box.setWindowTitle(tr("提示"));
        box.setIcon(QMessageBox::Information);
        box.setText(tr("未登录，请先登录"));
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
            box.setWindowTitle(tr("提示"));
            box.setIcon(QMessageBox::Information);
            box.setText(tr("不存在该公交线路"));
            box.setStandardButtons(QMessageBox::Yes);
            box.exec();
        }
        else
        {
            QString time=ui->lineEdit_UpdateTime->text();
            if(time.isEmpty())
            {
                QMessageBox box;
                box.setWindowTitle(tr("提示"));
                box.setIcon(QMessageBox::Information);
                box.setText(tr("信息不全，更新失败"));
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
                    box.setWindowTitle(tr("提示"));
                    box.setIcon(QMessageBox::Information);
                    box.setText(tr("更新成功"));
                    box.setStandardButtons(QMessageBox::Yes);
                    box.exec();
                }
                else
                {
                    QMessageBox box;
                    box.setWindowTitle(tr("提示"));
                    box.setIcon(QMessageBox::Information);
                    box.setText(tr("更新失败"));
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
        box.setWindowTitle(tr("提示"));
        box.setIcon(QMessageBox::Information);
        box.setText(tr("起点或终点信息不全"));
        box.setStandardButtons(QMessageBox::Yes);
        box.exec();
    }
    else
    {
        SVECP pathS=new SVEC;		//用于保存换乘的路径 pathS存放站点 Adjbus存放公交路线名
        SVECP Adjbus=new SVEC;
        BUS_SYSTEM bus_system;
        Create create;
        if(hasEdge==0||isChange==1)      //如果没有创建边表或者信息改变 就创建边表
        {
            create.createStation();
            create.edgeList();
            hasEdge=1;
            isChange=0;
        }
        if(ui->radioButton_Unconditional->isChecked() == true)  //一、无条件换乘
        {
            pathS->clear();
            Adjbus->clear();
            result.clear();
            bus_system.queryOTOUnconditional(start.toLocal8Bit().data(),end.toLocal8Bit().data(),pathS,Adjbus);
           // sort(result.begin(),result.end(),cmp1);       //可以不用排序
            showOTO();

        }
        if(ui->radioButton_ChangeLess->isChecked()==true)       //二、限制换乘次数查询
        {
            pathS->clear();
            Adjbus->clear();
            int changeNum=ui->spinBox_ChangeNum->value();
            result.clear();
            bus_system.queryOTOChangeNumLimit(start.toLocal8Bit().data(),end.toLocal8Bit().data(),pathS,Adjbus,changeNum,0);
            sort(result.begin(),result.end(),cmp1);             //按照换乘次数由少到多排序
            showOTO();
        }
        if(ui->radioButton_DistanceLess->isChecked()==true)     //三、距离最短查询
        {
            pathS->clear();
            Adjbus->clear();
            result.clear();
            bus_system.queryOTODistance(start.toLocal8Bit().data(),end.toLocal8Bit().data(),pathS,Adjbus);
            sort(result.begin(),result.end(),cmp1);            //按照距离由近到远排序
            showOTODistance();
        }
        if(ui->radioButton_PriceLess->isChecked()==true)     //四、票价最少查询
        {
            pathS->clear();
            Adjbus->clear();
            result.clear();
            bus_system.queryOTOPrice(start.toLocal8Bit().data(),end.toLocal8Bit().data(),pathS,Adjbus,0);
            sort(result.begin(),result.end(),cmp2);         //按照票价由少到多排序
            showOTOPrice();
        }
    }
}
void Widget::showOTO()
{

    vector<Result>::iterator  iter=result.begin();
    vector<Result>::iterator iterEnd=result.end();
    int sum=result.size();
    ui->textBrowser_BusChange->setText(tr("共有%1种方案:\n").arg(sum));
    int count=1;
    for(;iter!=iterEnd;++iter,++count)
    {
        ui->textBrowser_BusChange->append(tr("第%1种方案").arg(count));
        SITE siter1=((*iter).QueryPathResult).begin();
        SITE siterEnd1=((*iter).QueryPathResult).end();
        SITE siter2=((*iter).QueryBusResult).begin();
        SITE siterEnd2=((*iter).QueryBusResult).end();
        string busChange=*siter2;
        string resultStr;
        int change=0;                   //总的换乘次数
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
        ui->textBrowser_BusChange->append(tr("此方案需要换乘次数为:%1\n").arg(change));
    }
}
void Widget::showOTODistance()                      //按照距离查询结果显示
{

    vector<Result>::iterator  iter=result.begin();
    vector<Result>::iterator iterEnd=result.end();
    int sum=result.size();
    ui->textBrowser_BusChange->setText(tr("共有%1种方案:\n").arg(sum));
    int count=1;
    for(;iter!=iterEnd;++iter,++count)
    {
        ui->textBrowser_BusChange->append(tr("第%1种方案").arg(count));
        SITE siter1=((*iter).QueryPathResult).begin();
        SITE siterEnd1=((*iter).QueryPathResult).end();
        SITE siter2=((*iter).QueryBusResult).begin();
        SITE siterEnd2=((*iter).QueryBusResult).end();
        string busChange=*siter2;
        string resultStr;
        int change=0;                   //总的换乘次数
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
        ui->textBrowser_BusChange->append(tr("此方案需要换乘次数为:%1").arg(change));
        ui->textBrowser_BusChange->append(tr("此方案需要总距离为:%1\n").arg((*iter).distance));
    }
}
void Widget::showOTOPrice()
{

    vector<Result>::iterator  iter=result.begin();
    vector<Result>::iterator iterEnd=result.end();
    int sum=result.size();
    ui->textBrowser_BusChange->setText(tr("共有%1种方案:\n").arg(sum));
    int count=1;
    for(;iter!=iterEnd;++iter,++count)
    {
        ui->textBrowser_BusChange->append(tr("第%1种方案").arg(count));
        SITE siter1=((*iter).QueryPathResult).begin();
        SITE siterEnd1=((*iter).QueryPathResult).end();
        SITE siter2=((*iter).QueryBusResult).begin();
        SITE siterEnd2=((*iter).QueryBusResult).end();
        string busChange=*siter2;
        string resultStr;
        int change=0;                   //总的换乘次数
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
        ui->textBrowser_BusChange->append(tr("此方案需要换乘次数为:%1").arg(change));
        ui->textBrowser_BusChange->append(tr("此方案需要总票价为:%1\n").arg((*iter).price));
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
    ui->textBrowser_BusChange->setText(tr("共有%1种方案:\n").arg(sum));

    iter2=QueryBusResult->begin();

    int count=1;
    for(;iter1!=iterEnd1&&iter2!=iterEnd2;++iter1,++iter2,++count)
    {
        //ui->textBrowser_BusChange->append(tr("第%1种方案").arg(count));
        SITE siter1=(*iter1).begin();
        SITE siterEnd1=(*iter1).end();
        SITE siter2=(*iter2).begin();
        SITE siterEnd2=(*iter2).end();
        string busChange=*siter2;
        string result;
        int change=0;                   //换乘次数
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
            ui->textBrowser_BusChange->append(tr("此方案需要换乘次数为:%1\n").arg(change));
        }
    }
}*/
