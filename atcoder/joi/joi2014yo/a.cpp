#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a[5];
	rep(i,5){
		cin>>a[i];
		a[i]=max(a[i],40);
	}
	cout<<(a[0]+a[1]+a[2]+a[3]+a[4])/5<<'\n';
	return 0;
}
