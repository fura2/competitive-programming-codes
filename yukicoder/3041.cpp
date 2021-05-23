#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	bool f[1001]={};
	f[0]=(n%2==0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++) if(i-j>=0 && !f[i-j]) f[i]=true;
	}
	puts(f[n]?"Yes":"No");

	return 0;
}
