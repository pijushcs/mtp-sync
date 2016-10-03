// No of cycles wasted per core for threads waiting to get hold of write lock
// Profile Input: [#type] [#start core] [#end core] [#clcok cycles passed]

//RUN: profileX.out [#cur-t-gap]

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cstring>
#define NFREQ 2799952000 // freq fixed to high-performance
#define NCORE 4

using namespace std;

long long wrcu[20];
long mrcu[20];
long long crcu[20],cntRCU;
double rcuAvg,rcuMax;

void makeT(int tGap){
	string str;	
	char typ[20],igns[20];
	float t,ignf;
	long s,e,k,core=0, pro_r=0, pro_w=0;
	double pro_wavg=0;

	long double freqC_fix=NFREQ;
	freqC_fix=1000/freqC_fix;
	//getline(cin,str);	
	getline(cin,str);
	sscanf(str.c_str(), "[ %f] [profmod %s %s S%ld E%ld K%ld", &ignf, igns, typ, &s, &e, &k);
	
	while(str.compare("")!=0){
		if(!strcmp(typ,"PRCU:")){
			wrcu[s]+=k; mrcu[s]=max(mrcu[s],k); crcu[s]++; pro_w++;
			//core=max(core,s);
		}
		
		if(!strcmp(typ,"RRCU:")) pro_r++;
		
		getline(cin,str);
		sscanf(str.c_str(),"[ %f] [profmod %s %s S%ld E%ld K%ld", &ignf, igns, typ, &s, &e, &k);

	}

	if(pro_w) pro_wavg=pro_w/(double)(pro_w+pro_r);

	// Output percore: [#tGap] [#average cycles] [#max cycles]
	// Output global : [#write-avg] [#read-count] [#write-count]
	cout<<tGap<<" ";
	for(int coreID=0;coreID<NCORE;coreID++){
		if(crcu[coreID]){		
			rcuAvg=wrcu[coreID]; //(double)crcu[coreID]; 
			rcuAvg=rcuAvg*freqC_fix;
			rcuMax=mrcu[coreID]*(double)freqC_fix;
			cout<<rcuAvg<<" "<<rcuMax<<" ";
		}
		else cout<<0<<" "<<0<<" ";
	}
	cout<<pro_wavg<<" "<<pro_r<<" "<<pro_w<<endl;
}

int main(int argc, char *argv[]){
    makeT(atoi(argv[1]));
}
