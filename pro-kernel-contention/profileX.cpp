// No of cycles wasted per core for threads waiting to get hold of the write lock
// Profile Input: [#type] [#start core] [#end core] [#clcok cycles passed]
// #type: [BCU: Total Thread Clock] [WRCU/DRCU: Write/Delete Wait Clock Tick]

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cstring>

using namespace std;

long long wrcu[20],wrlu[20];
int pidX;
long mrcu[20],mrlu[20];
long long crcu[20],crlu[20],freqC_fix,cntRCU,cntRLU;
long double rcuAvg,rluAvg,rcuMax,rluMax;
void makeT(char *cX){
	string str;	
	char typ[20],igns[20];
	float t,ignf;
	long s,e,k,core=0, pro_r, pro_w;
	double pro_wavg;
	
	freqC_fix=2800102000*atoi(cX);
	//getline(cin,str);	
	getline(cin,str);
	sscanf(str.c_str(), "[ %f] [promod %d] %s S%ld E%ld K%ld", &ignf, &pidX, typ, &s, &e, &k);

	while(str.compare("")!=0){
		if(!strcmp(typ,"WRCU:") || !strcmp(typ,"DRCU:")){
			wrcu[s]+=k; mrcu[s]=max(mrcu[s],k); crcu[s]++;
			core=max(core,s);
		}
		
		if(!strcmp(typ,"IRCU:")){
			pro_r=s; pro_w=e;
			pro_wavg=(double)(pro_w*100.0)/(pro_r+pro_w);
		}   
		
		getline(cin,str);
		sscanf(str.c_str(),"[ %f] [promod %d] %s S%ld E%ld K%ld", &ignf, &pidX, typ, &s, &e, &k);

	}

	// Output: [#core] [#average cycles] [#max cycles]
	for(int i=0;i<=core;i++){
		if(crcu[i]){
			rcuAvg=wrcu[i]/crcu[i]; 
			rcuAvg=(rcuAvg/freqC_fix)*100;
			rcuMax=((long double)mrcu[i]/freqC_fix)*100;
			cout<<"C"<<i<<" A"<<rcuAvg<<" M"<<rcuMax<<endl;
		}

	}
	cout<<"I"<<": A"<<pro_wavg<<" R"<<pro_r<<" W"<<pro_w<<endl;
}

int main(int argc, char *argv[]){
    makeT(argv[1]);
}
