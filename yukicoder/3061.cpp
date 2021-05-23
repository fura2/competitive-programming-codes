#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; getline(cin,s);
	int n=s.length();

	rep(l,n) for(int r=l+2;r<=n;r++) {
		bool del[128]={};
		rep(i,n) if(i<l || r<=i || (i-l)%2==1) del[s[i]]=true;
		bool ok=true;
		rep(i,n) if(l<=i && i<r && (i-l)%2==0 && del[s[i]]) ok=false;
		if(ok) return puts("Yes"),0;
	}
	puts("NO");

	return 0;
}
