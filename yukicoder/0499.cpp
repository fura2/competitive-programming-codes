#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	if(n==0) return puts("0"),0;

	string s;
	while(n>0) s+='0'+n%7, n/=7;
	reverse(s.begin(),s.end());
	cout<<s<<'\n';

	return 0;
}
