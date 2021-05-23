#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

vector<int> solve(vector<int> X,vector<int> Y){
	int n=X.size();
	set<pair<int,int>> S={{0,INF},{INF,0}};

	vector<int> res(n);
	rep(i,n){
		if(i>0) res[i]=res[i-1];

		auto it=S.lower_bound({X[i],Y[i]});
		int x1,y1; tie(x1,y1)=*it;
		if(Y[i]<=y1) continue;

		--it;
		int x2,y2; tie(x2,y2)=*it;
		res[i]-=(X[i]-x2)*y1;
		while(y2<=Y[i]){
			it=--S.erase(it);
			x1=x2; y1=y2;
			tie(x2,y2)=*it;
			res[i]-=(x1-x2)*y1;
		}
		res[i]+=(X[i]-it->first)*Y[i];
		S.emplace(X[i],Y[i]);
	}
	return res;
}

int main(){
	int n; scanf("%d",&n);
	vector<int> x1(n),y1(n),x2(n),y2(n);
	rep(i,n) scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);

	vector<int> ans(n);
	rep(t,4){
		vector<int> X(n),Y(n);
		rep(i,n){
			if(t==0) X[i]= x2[i], Y[i]= y2[i];
			if(t==1) X[i]=-x1[i], Y[i]= y2[i];
			if(t==2) X[i]=-x1[i], Y[i]=-y1[i];
			if(t==3) X[i]= x2[i], Y[i]=-y1[i];
		}
		auto res=solve(X,Y);
		rep(i,n) ans[i]+=res[i];
	}
	for(int i=n-1;i>0;i--) ans[i]-=ans[i-1];

	rep(i,n) printf("%d\n",ans[i]);

	return 0;
}
