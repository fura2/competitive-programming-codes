#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	int L[10]={},R[10]={};
	rep(i,n-1) R[s[i+1]-'0']++;

	bool ans[1000]={};
	rep(i,n-2){
		L[s[i]-'0']++;
		R[s[i+1]-'0']--;

		int c=s[i+1]-'0';
		rep(d,10) if(L[d]>0) rep(e,10) if(R[e]>0) ans[d*100+c*10+e]=true;
	}

	printf("%ld\n",count(ans,ans+1000,true));

	return 0;
}
