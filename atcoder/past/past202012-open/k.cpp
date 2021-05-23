#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={0,0,-1,0,1},dy[]={0,1,0,-1,0};

double memo[1<<16];

double dfs(int S){
	double& res=memo[S];
	if(res!=-1) return res;

	if(S==(1<<16)-1) return 0;

	res=1e9;
	rep(i,4) rep(j,4) {
		int cnt=0;
		double tmp=0;
		rep(k,5){
			int x=i+dx[k],y=j+dy[k];
			if(0<=x && x<4 && 0<=y && y<4){
				int S2=S|1<<(x*4+y);
				if(S2==S){
					cnt++;
				}
				else{
					tmp+=dfs(S2)/5;
				}
			}
			else{
				cnt++;
			}
		}
		if(cnt<5) res=min(res,(tmp+1)/(1-cnt/5.0));
	}
	return res;
}

int main(){
	string s;
	rep(i,4){
		string t; cin>>t;
		s+=t;
	}

	int S0=0;
	rep(i,16) if(s[i]=='.') S0|=1<<i;

	rep(S,1<<16) memo[S]=-1;
	printf("%.9f\n",dfs(S0));

	return 0;
}
