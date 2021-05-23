#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	int sum=0;
	rep(i,n){
		int a; scanf("%d",&a);
		sum+=a;
		if(sum>=k){ printf("%d\n",i+1); break; }
	}
	return 0;
}
