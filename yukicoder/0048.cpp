#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x,y,l; cin>>x>>y>>l;
	int ans=0;
	if(y>0) ans+=(y+l-1)/l;
	if(y<0) ans+=(-y+l-1)/l+(x==0?2:1);
	if(x>0) ans+=(x+l-1)/l+1;
	if(x<0) ans+=(-x+l-1)/l+1;
	cout<<ans<<'\n';
	return 0;
}
