// Day 4: Contest

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m,T,x,y; cin>>n>>m>>T>>x>>y;
	vector<int> p(m);
	rep(j,m) scanf("%d",&p[j]);

	vector<int> ans(n);
	vector O(n,vector(m,0)),WA(n,vector(m,0));
	rep(_,y){
		int t,i,j;
		string s; cin>>t>>i>>j>>s; i--; j--;
		if(s=="open"){
			O[i][j]=t;
		}
		else if(s=="incorrect"){
			WA[i][j]++;
		}
		else{
			ans[i]+=max(p[j]-(t-O[i][j])-120*WA[i][j],x);
		}
	}

	rep(i,n) printf("%d\n",ans[i]);

	return 0;
}
