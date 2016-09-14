// No of cycles wasted per core for threads waiting to get hold of the write lock
// Profile Input: [#type] [#start core] [#end core] [#clcok cycles passed]
// #type: [IRCU: Total Thread Clock] [WRCU/DRCU: Write/Delete Wait Clock Tick]

//RUN: profileX.out [#duration] [#t-gap]

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cstring>
#define NFREQ 2800102000
#define NCORE 4

using namespace std;

long long wrcu[20],wrlu[20];
int pidX;
long mrcu[20],mrlu[20];
long long crcu[20],crlu[20],cntRCU,cntRLU;
double freqC_fix,rcuAvg,rluAvg,rcuMax,rluMax;

void makeT(int nDur, int tGap){
	string str;	
	char typ[20],igns[20];
	float t,ignf;
	long s,e,k,core=0, pro_r=0, pro_w=0;
	double pro_wavg=0;
	bool flgR=false;

	long double freqC_fix=NFREQ;
	freqC_fix=1000000/freqC_fix;
	//getline(cin,str);	
	getline(cin,str);
	sscanf(str.c_str(), "[ %f] [promod %d] %s S%ld E%ld K%ld", &ignf, &pidX, typ, &s, &e, &k);

	while(str.compare("")!=0){
		if(!strcmp(typ,"WRCU:") || !strcmp(typ,"DRCU:")){
			wrcu[s]+=k; mrcu[s]=max(mrcu[s],k); crcu[s]++;
			//core=max(core,s);
		}
		
		if(!strcmp(typ,"IRCU:") && flgR==false){
			pro_r=s; pro_w=e;
			if(pro_r+pro_w>0) pro_wavg=(double)(pro_w*100.0)/(pro_r+pro_w);
			flgR=true;
		}   
		
		getline(cin,str);
		sscanf(str.c_str(),"[ %f] [promod %d] %s S%ld E%ld K%ld", &ignf, &pidX, typ, &s, &e, &k);

	}
	
	// Per timestamp output[each line]
	cout<<tGap<<" "; 
	
	// Output percore: [#tGap] [#average cycles] [#max cycles]
	for(int coreID=0;coreID<NCORE;coreID++){
		if(crcu[coreID]){		
			rcuAvg=wrcu[coreID]/(double)crcu[coreID]; 
			rcuAvg=rcuAvg*freqC_fix;
			rcuMax=mrcu[coreID]*(double)freqC_fix;
			cout<<rcuAvg<<" "<<rcuMax<<" ";
		}
		else cout<<0<<" "<<0<<" ";
	}
	
	// Output global: write-avg read-count write-count
	cout<<pro_wavg<<" "<<pro_r<<" "<<pro_w<<endl;
}

int main(int argc, char *argv[]){
    makeT(atoi(argv[1]),atoi(argv[2]));
}
