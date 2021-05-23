#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m;
	string s,t; cin>>n>>m>>s>>t;
	int cnt1=min(count(s.begin(),s.end(),'A'),count(t.begin(),t.end(),'A'));
	int cnt2=min(count(s.begin(),s.end(),'B'),count(t.begin(),t.end(),'B'));
	printf("%d\n",cnt1+cnt2);
	return 0;
}
