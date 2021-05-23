#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	for(int i=30;i>=0;i--){
		if(n>=(1<<i)-1) n-=(1<<i)-1;
	}
	puts(n==0?"YES":"NO");
	return 0;
}
