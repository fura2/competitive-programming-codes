#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b; cin>>a>>b;
	printf("%d\n",max(a+b,a-b));
	printf("%d\n",min(a+b,a-b));
	return 0;
}
