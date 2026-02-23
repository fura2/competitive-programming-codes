#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a[20]={100,100,200};
	for(int i=3;i<=20;i++) a[i]=a[i-1]+a[i-2]+a[i-3];
	printf("%d\n",a[19]);
	return 0;
}
