#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n=100;
	vector<int> x(n+1),y(n+1);
	rep(i,n) scanf("%d%d",&x[i+1],&y[i+1]);

	string ans;
	rep(i,n){
		if(x[i]<=x[i+1]){
			rep(_,x[i+1]-x[i]) ans+='D';
		}
		else{
			rep(_,x[i]-x[i+1]) ans+='U';
		}
		if(y[i]<=y[i+1]){
			rep(_,y[i+1]-y[i]) ans+='R';
		}
		else{
			rep(_,y[i]-y[i+1]) ans+='L';
		}
		ans+='I';
	}
	cout<<ans<<'\n';

	return 0;
}
