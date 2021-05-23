#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();
	int ans=0;
	rep(i,n) rep(j,n-i-1) if(s[j]>s[j+1]) swap(s[j],s[j+1]), ans++;
	printf("%d\n",ans);
	return 0;
}
