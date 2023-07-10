#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	int ans=n;
	int bcnt=0,wcnt=count(s.begin(),s.end(),'.');
	rep(i,n+1){
		ans=min(ans,bcnt+wcnt);
		if(i<n){
			if(s[i]=='#') bcnt++;
			else          wcnt--;
		}
	}
	printf("%d\n",ans);

	return 0;
}
