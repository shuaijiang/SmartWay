#include "login.h"
#include "widget.h"
#include "ui_widget.h"
#include "Extern.h"
SMAPP createAdministratorMap()		//���ļ��й���Ա����Ϣ�����ڴ沢����map
{
	string name,password;
        SMAPP Admap=new SMAP;
        ifstream infile(FILENAME1,ios::in);
        ///QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
	if(!infile)
	{
            QMessageBox box;
            box.setWindowTitle(QObject::tr("Warning"));
            box.setIcon(QMessageBox::Information);
            box.setText(("Can't open file of administrator!"));
            box.setStandardButtons(QMessageBox::Yes);
            box.exec();
	}
	else
	{
		while(infile>>name>>password)
		{
			(*Admap)[name]=password;
		}
		return Admap;
	}
        return 0;   //��������Աmapʧ��
}
bool Login(string name,string password,SMAPP Admap)			//�ж��Ƿ���ȷ��¼
{
	int flag=0;
	SMAPCIT iter=Admap->begin();
	for(;iter!=Admap->end();++iter)
	{
		if(name==(iter)->first&&password==iter->second)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		return true;
	else
		return false;
}
