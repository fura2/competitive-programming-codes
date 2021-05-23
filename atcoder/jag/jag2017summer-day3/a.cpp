#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool check(string s){
	int n=s.length();
	int cnt=0;
	rep(i,n){
		if(s[i]=='(') cnt++;
		else          cnt--;
		if(cnt<0) return false;
	}
	return cnt==0;
}

int main(){
	string s; cin>>s;
	int n=s.length();

	int p;
	for(p=0;s[p]!='*';p++);
	s=s.substr(0,p)+s.substr(p+1);
	n--;

	int ans=0;
	rep(l,n) for(int r=l+2;r<=n;r++) if(l<p && p<r && s[l]=='(' && s[r-1]==')') {
		if(check(s.substr(l+1,r-l-2))) ans++;
	}
	printf("%d\n",ans);

	return 0;
}
