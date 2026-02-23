#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

enum{NORMAL0,CHARGE0,NORMAL1,CHARGE1,NORMAL2,CHARGE2,NORMAL3,CHARGE3};
class state{
public:
	int t,type,dmg;
	state(int t,int type,int dmg=0):t(t),type(type),dmg(dmg){}
	bool operator>(const state& S)const{ return t>S.t; }
};

int main(){
	string s; cin>>s;
	int n=s.length();

	priority_queue<state,vector<state>,greater<state>> Q;
	rep(i,n) if(s[i]!='-') {
		Q.emplace(2*i,s[i]=='N'?NORMAL0:CHARGE0);
	}

	lint ans=0;
	int m=5,combo=0;
	bool frozen=false;
	while(!Q.empty()){
		state S=Q.top(); Q.pop();

		if(S.type==CHARGE1) frozen=false;
		if(frozen && (S.type==NORMAL0 || S.type==CHARGE0)) continue;

		if(S.type==NORMAL0){
			if(m<1) continue;
			Q.emplace(S.t+1,NORMAL1,10+combo/10);
		}
		else if(S.type==CHARGE0){
			if(m<3) continue;
			frozen=true;
			Q.emplace(S.t+5,CHARGE1,50+combo/10*5);
		}
		else if(S.type==NORMAL1){
			m--;
			Q.emplace(S.t+2,NORMAL2,S.dmg);
		}
		else if(S.type==CHARGE1){
			m-=3;
			Q.emplace(S.t+2,CHARGE2,S.dmg);
		}
		else if(S.type==NORMAL2){
			ans+=S.dmg;
			combo++;
			Q.emplace(S.t+10,NORMAL3);
		}
		else if(S.type==CHARGE2){
			ans+=S.dmg;
			combo++;
			Q.emplace(S.t+10,CHARGE3);
		}
		else if(S.type==NORMAL3){
			m++;
		}
		else if(S.type==CHARGE3){
			m+=3;
		}
	}

	printf("%lld\n",ans);

	return 0;
}
