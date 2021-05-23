#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int Cat[]={1,1,2,5,14,42,132,429,1430,4862,16796,58786,208012,742900};

int main(){
	int n; scanf("%d",&n);
	printf("%d\n",Cat[n]);
	return 0;
}
