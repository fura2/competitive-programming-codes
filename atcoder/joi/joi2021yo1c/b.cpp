#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	int ans=0;
	rep(i,n){
		if(i%2==0 && s[i]!='I') ans++;
		if(i%2==1 && s[i]!='O') ans++;
	}
	printf("%d\n",ans);

	return 0;
}
