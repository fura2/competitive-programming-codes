#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a,b; scanf("%d%d%d",&n,&a,&b);

	int ans=0;
	while(a<b){
		ans++;
		b/=2;
	}
	printf("%d\n",a==b?ans:-1);

	return 0;
}
