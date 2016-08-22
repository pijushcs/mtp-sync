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
long mrcu[20],mrlu[20];
long long crcu[20],crlu[20],freqC[20],cntRCU,cntRLU;
long double rcuAvg,rluAvg,rcuMax,rluMax;
void makeT(char cX){
	string str;	
	char typ[20];
	float t;
	long s,e,k,core=0;
	
	getline(cin,str);	
	getline(cin,str);
	sscanf(str.c_str(), "%s S%ld E%ld K%ld", typ, &s, &e, &k);

	while(str.compare("")!=0){
		if(!strcmp(typ,"BCU:")){
			freqC[s]=k;
		}

		if(!strcmp(typ,"WRCU:") || !strcmp(typ,"DRCU:")){
			wrcu[s]+=k; mrcu[s]=max(mrcu[s],k); crcu[s]++;
			core=max(core,s);
		}  
		
		if(!strcmp(typ,"WRLU:") || !strcmp(typ,"DRLU:")){
			wrlu[s]+=k; mrlu[s]=max(mrlu[s],k); crlu[s]++;
			core=max(core,s);
		}
		
		getline(cin,str);
		sscanf(str.c_str(), "%s S%ld E%ld K%ld", typ, &s, &e, &k);

	}

	// Output: [#core] [#average cycles] [#max cycles]
	for(int i=0;i<=core;i++){
		if(freqC[i] && (crcu[i] || crlu[i])){
			if(cX=='C'){
				rcuAvg=wrcu[i]/crcu[i]; 
				rcuAvg=(rcuAvg/freqC[i])*100;
				rcuMax=((long double)mrcu[i]/freqC[i])*100;
				cout<<"C"<<i<<" A"<<rcuAvg<<" M"<<rcuMax<<endl;
			}
			else{
				rluAvg=wrlu[i]/crlu[i];
				rluAvg=(rluAvg/freqC[i])*100;	
				rluMax=((long double)mrlu[i]/freqC[i])*100;
				cout<<"C"<<i<<" A"<<rluAvg<<" M"<<rluMax<<endl;
			}
		}
	}
}

int main(int argc, char *argv[]){
    makeT(*argv[1]);
}
 
