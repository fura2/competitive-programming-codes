#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint f(string s,int base){
	int n=s.length();
	lint res=0;
	rep(i,n) res=res*base+(s[i]-'0');
	return res;
}

int main(){
	lint n;
	string s; cin>>n>>s;

	int mx=*max_element(s.begin(),s.end())-'0';
	for(int m=max(mx+1,2);;m++) if(f(s,m)==n) { printf("%d\n",m); break; }

	return 0;
}
