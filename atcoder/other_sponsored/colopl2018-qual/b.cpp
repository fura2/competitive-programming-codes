#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,x;
	string s; cin>>n>>x>>s;

	int ans=0;
	rep(i,n){
		int a; scanf("%d",&a);
		if(s[i]=='0') ans+=a;
		else          ans+=min(a,x);
	}
	printf("%d\n",ans);

	return 0;
}
