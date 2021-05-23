#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

inline int popcount(int x){
	x=((x>>1)&0x55555555)+(x&0x55555555);
	x=((x>>2)&0x33333333)+(x&0x33333333);
	x=((x>>4)+x)&0x0f0f0f0f;
	x+=(x>>8);
	x+=(x>>16);
	return x&0x3f;
}

lint modpow(lint a,lint k,int m){
	lint r=1;
	for(lint x=a%m;k>0;k>>=1,x=x*x%m) if(k&1) r=r*x%m;
	return r;
}

int f(int a){
	if(a==0) return 0;
	return f(a%popcount(a))+1;
}

int main(){
	int n;
	string s; cin>>n>>s;

	int pc=0;
	rep(i,n) if(s[i]=='1') pc++;

	lint fs[2]={};
	rep(i,n){
		fs[0]=(fs[0]*2+s[i]-'0')%(pc+1);
		if(pc>1) fs[1]=(fs[1]*2+s[i]-'0')%(pc-1);
	}

	rep(i,n){
		int ans;
		if(s[i]=='0'){
			ans=f((fs[0]+modpow(2,n-1-i,pc+1))%(pc+1))+1;
		}
		else{
			if(pc==1){
				ans=0;
			}
			else{
				ans=f((fs[1]-modpow(2,n-1-i,pc-1)+pc-1)%(pc-1))+1;
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}
