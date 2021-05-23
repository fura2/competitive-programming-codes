#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k,t; scanf("%d%d%d",&n,&k,&t);
	puts((abs(n)+k-1)/k<=t?"Yes":"No");
	return 0;
}
