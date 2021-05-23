#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;

	int k=sqrt(1e9+1);
	char c='a';
	while(n>0){
		while(k*k>n) k--;
		rep(i,k){
			putchar(c);
			if(i<k-1) putchar(c+1);
		}
		n-=k*k;
		c+=2;
	}
	puts("");

	return 0;
}
