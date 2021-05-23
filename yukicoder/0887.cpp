#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int mx=0;
	for(int i=0;;i++){
		mx=max(mx,n);
		if(n==1) return printf("%d\n%d\n",i,mx),0;
		if(n%2==0) n/=2;
		else       n=3*n+1;
	}
}
