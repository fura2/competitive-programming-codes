#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	for(int a=1;a<=n;a++) for(int b=a;b<=n;b++) {
		int c=n-a-b;
		if(b<=c && c<=n){
			printf("%d %d %d\n",a,b,c);
		}
	}
	return 0;
}
