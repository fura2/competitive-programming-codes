#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h1,m1,h2,m2,k; cin>>h1>>m1>>h2>>m2>>k;
	int t1=60*h1+m1,t2=60*h2+m2;
	printf("%d\n",t2-t1-k);
	return 0;
}
