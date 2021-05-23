#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	reverse(s.begin(),s.end());

	int ans[2]={};
	rep(i,n) ans[(i+1)%2]+=s[i]-'0';
	printf("%d %d\n",ans[0],ans[1]);

	return 0;
}
