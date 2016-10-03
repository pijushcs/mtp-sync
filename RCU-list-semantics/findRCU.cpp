// Remove duplicate RCU list head-s

#include <iostream>
#include <set>
#include <string>
using namespace std;

set<string> sList;

int main(){
	string str;
	
	getline(cin,str);
	while(str.compare("END")!=0){
		int i,j;
		string lName="";

		for(i=0; i<str.length() && str[i]!=','; i++);
		for(j=i+1; j<str.length() && str[j]!=')'; j++) lName+=str[j];
	
		if(lName.compare("")) sList.insert(lName);
		getline(cin,str);
	}
	
	for(set<string>::iterator it=sList.begin(); it!=sList.end(); it++)
		cout<<*it<<endl;
	
	return 0;
} 
		

