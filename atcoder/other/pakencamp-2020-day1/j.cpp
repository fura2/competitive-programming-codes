#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int cnt=0;
	for(int m=1;m<=1000;m++){
		for(int n=1;n<m;n++){
			if(gcd(m,n)==1 && m%2!=n%2){
				int a=m*m-n*n;
				int b=2*m*n;
				int c=m*m+n*n;
				if(a>b) swap(a,b);
				printf("%d %d %d\n",a,b,c);
				cnt++;
				if(cnt==100000) return 0;
			}
		}
	}

	return 0;
}
