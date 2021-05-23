#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	int ans=1,pos=0;
	for(int i=1;i<n;i++) if(s[pos]>=s[i]) {
		ans++;
		pos=i;
	}
	printf("%d\n",ans);

	return 0;
}
