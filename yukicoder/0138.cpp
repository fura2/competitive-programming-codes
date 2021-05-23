#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x[2];
	rep(i,2){
		int a,b,c; scanf("%d.%d.%d",&a,&b,&c);
		x[i]=1000000*a+1000*b+c;
	}
	puts(x[0]>=x[1]?"YES":"NO");
	return 0;
}
