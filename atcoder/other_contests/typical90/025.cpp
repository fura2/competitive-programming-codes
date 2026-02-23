#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint n,b;

int dfs(int nxt,lint mul,string& S){
	if(S.size()>=12) return 0;

	int res=0;
	if(b+mul<=n){
		string s=to_string(b+mul);
		sort(s.begin(),s.end());
		if(s==S) res++;
	}

	for(int d=nxt;d<10;d++){
		S+='0'+d;
		res+=dfs(d,mul*d,S);
		S.pop_back();
	}
	return res;
}

int main(){
	scanf("%lld%lld",&n,&b);

	string S;
	printf("%d\n",dfs(0,1,S));

	return 0;
}
