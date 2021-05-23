#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int ans=1;
	rep(i,3){
		string s; cin>>s;
		int l=(s.length()+1)/2;
		ans*=(s=="NONE"?256:(16-l)*(16-l));
	}
	printf("%d\n",ans);
	return 0;
}
