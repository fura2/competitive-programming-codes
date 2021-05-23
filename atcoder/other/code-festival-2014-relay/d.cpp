#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	string B[100];
	rep(i,n) cin>>B[i];

	int c=0;
	rep(j,n){
		rep(i,n) if(B[i][j]=='X') c+=i;
		rep(i,n) if(B[i][j]=='Y') c-=n-1-i;
	}
	puts(c>0?"X":c<0?"Y":"Impossible");

	return 0;
}
