// Day 1: JOI Poster

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; cin>>n>>k; k--;

	string ans;
	while(n>=0){
		if(n==0){
			ans+='J';
			break;
		}
		else if(k<(1<<n-1)){
			ans+=string(1<<n-1,'J')+string(1<<n-1,'O');
			break;
		}
		else{
			ans+=string(1<<n-1,'I');
			k-=1<<n-1;
			n--;
		}
	}
	cout<<ans<<'\n';

	return 0;
}
