#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s,t; cin>>s>>t;

	int m=s.length(),n=t.length();
	if(n==1){
		if(count(s.begin(),s.end(),t[0])>0) return puts("-1"),0;
		else                                return puts("0"),0;
	}
	if(m<n) return puts("0"),0;

	int ans=0;
	rep(i,m-n+1) if(s.substr(i,n)==t) {
		i+=n-2;
		ans++;
	}
	printf("%d\n",ans);

	return 0;
}
