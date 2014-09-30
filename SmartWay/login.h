#ifndef LOGIN_H
#define LOGIN_H

#include<map>
#include "OneToOne.h"
typedef map<string,string> SMAP;
typedef map<string,string>* SMAPP;
typedef map<string,string>::const_iterator SMAPCIT;


SMAPP createAdministratorMap(void);
bool Login(string,string,SMAPP);

#endif
