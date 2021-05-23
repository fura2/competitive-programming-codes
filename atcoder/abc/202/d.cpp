#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint nCr[61][61]={};
	rep(i,61){
		nCr[i][0]=1;
		for(int j=1;j<=i;j++){
			nCr[i][j]=nCr[i-1][j-1]+nCr[i-1][j];
		}
	}

	int a,b;
	lint k; cin>>a>>b>>k;

	string ans;
	int x=a,y=b;
	rep(i,a+b){
		if(x==0){
			ans+='b';
			y--;
		}
		else if(y==0){
			ans+='a';
			x--;
		}
		else{
			if(nCr[x+y-1][y]<k){
				k-=nCr[x+y-1][y];
				ans+='b';
				y--;
			}
			else{
				ans+='a';
				x--;
			}
		}
	}
	cout<<ans<<'\n';

	return 0;
}
