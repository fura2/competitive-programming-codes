#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

inline int digital_root(long long n,long long base=10){
	if(n==0) return 0;
	else     return n%(base-1)!=0?n%(base-1):base-1;
}

int main(){
	int n; scanf("%d",&n);
	printf("%d\n",digital_root(n));
	return 0;
}
