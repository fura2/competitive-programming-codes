#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string a,b; cin>>a>>b;
	int m=a.length(),n=b.length();
	if(m!=n) cout<<(m>n?a:b)<<'\n';
	else{
		int i;
		for(i=0;a[i]==b[i];i++);
		cout<<(a[i]=='4'&&b[i]=='7'?a:a[i]=='7'&&b[i]=='4'?b:a[i]>b[i]?a:b)<<'\n';
	}
	return 0;
}
