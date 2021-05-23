#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int solve(string a,string b,string c){
	auto build=[](string x,string y){
		int nx=x.length(),ny=y.length();
		vector<bool> flag(nx+1,true);
		rep(i,nx+1){
			rep(j,ny){
				if(i+j>=nx) break;
				if(x[i+j]!='?' && y[j]!='?' && x[i+j]!=y[j]){ flag[i]=false; break; }
			}
		}
		return flag;
	};

	int na=a.length(),nb=b.length(),nc=c.length();
	vector<bool> flag_ab=build(a,b);
	vector<bool> flag_ac=build(a,c);
	vector<bool> flag_bc=build(b,c);
	vector<bool> flag_cb=build(c,b);

	int res=INF;
	rep(i,na+1) if(flag_ab[i]) {
		rep(j,na+1) if(flag_ac[j]) {
			if(j<=i && i-j<=nc && flag_cb[i-j]) res=min(res,max({na,i+nb,j+nc}));
			if(j>=i){
				if((j-i<=nb && flag_bc[j-i]) || j-i>=nb) res=min(res,max({na,i+nb,j+nc}));
			}
		}
		for(int j=na;j<=i+nb;j++){
			if(flag_bc[j-i]) res=min(res,max(i+nb,j+nc));
		}
	}
	return res;
}

int main(){
	string s[3];
	rep(i,3) cin>>s[i];

	sort(s,s+3);

	int ans=INF;
	do{
		ans=min(ans,solve(s[0],s[1],s[2]));
	}while(next_permutation(s,s+3));
	printf("%d\n",ans);

	return 0;
}
