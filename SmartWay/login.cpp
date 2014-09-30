#include "login.h"
#include "widget.h"
#include "ui_widget.h"
#include "Extern.h"
SMAPP createAdministratorMap()		//把文件中管理员的信息读到内存并创建map
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
        return 0;   //创建管理员map失败
}
bool Login(string name,string password,SMAPP Admap)			//判读是否正确登录
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
