// From the log of all accessed DS, this code finds and sorts them on the basis of the most accessed DS.

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

map<string, int> sMap,hMap,qMap;
vector<pair<int, string> > sVec,hVec,qVec;

int main(){
	string str;
	float ign;
	char typ[100],toParse[100];
	
	getline(cin,str);
	while(str.compare("END")!=0){
		int i,j;
		string lName="";
		sscanf(str.c_str(),"[ %f] [promod] %s %s",&ign, typ, toParse);

		for(i=str.length()-1;i>0;i--) if(str[i]==',' || str[i]==' ') break;
		for(j=i+1;j<str.length();j++) lName+=str[j];

		if(!strcmp(typ,"SRCU:") && lName.compare("")) sMap[lName]++;
		if(!strcmp(typ,"HRCU:") && lName.compare("")) hMap[lName]++;
		if(!strcmp(typ,"QRCU:") && lName.compare("")) qMap[lName]++;

		getline(cin,str);
	}
	
	for(map<string, int>::iterator it=sMap.begin(); it!=sMap.end(); it++)
		sVec.push_back(pair<int,string>(it->second,it->first));
	sort(sVec.begin(),sVec.end(),greater<pair<int,string> >());

	for(map<string, int>::iterator it=hMap.begin(); it!=hMap.end(); it++)
		hVec.push_back(pair<int,string>(it->second,it->first));
	sort(hVec.begin(),hVec.end(),greater<pair<int,string> >());

	for(map<string, int>::iterator it=qMap.begin(); it!=qMap.end(); it++)
		qVec.push_back(pair<int,string>(it->second,it->first));
	sort(qVec.begin(),qVec.end(),greater<pair<int,string> >());
	
	cout<<"list_add_rcu:"<<endl;
	for(int i=0;i<sVec.size();i++)
		cout<<sVec[i].second<<" "<<sVec[i].first<<endl;
	cout<<endl;
	
	cout<<"list_add_tail_rcu:"<<endl;
	for(int i=0;i<qVec.size();i++)
		cout<<qVec[i].second<<" "<<qVec[i].first<<endl;
	cout<<endl;

	cout<<"hlist_add_head_rcu:"<<endl;
	for(int i=0;i<hVec.size();i++)
		cout<<hVec[i].second<<" "<<hVec[i].first<<endl;

	return 0;
} 
		

