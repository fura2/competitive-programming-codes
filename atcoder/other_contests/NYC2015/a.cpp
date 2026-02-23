#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	string s;
	while(n>0){
		s+='0'+n%2;
		n/=2;
	}
	string t=s;
	reverse(t.begin(),t.end());
	cout<<(s==t?"Yes":"No")<<'\n';

	return 0;
}
