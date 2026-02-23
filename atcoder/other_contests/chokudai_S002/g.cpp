#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T> T gcd(const T& a,const T& b){ return b==0?a:gcd(b,a%b); }

int main(){
	int n; scanf("%d",&n);
	rep(i,n){
		int a,b; scanf("%d%d",&a,&b);
		printf("%d\n",gcd(a,b));
	}
	return 0;
}
