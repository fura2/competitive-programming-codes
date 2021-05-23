#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;

	int ans=0;
	while(a<b){
		if(a<0){
			ans+=c;
		}
		else if(a==0){
			ans+=d+e;
		}
		else{
			ans+=e;
		}
		a++;
	}
	cout<<ans<<'\n';

	return 0;
}
