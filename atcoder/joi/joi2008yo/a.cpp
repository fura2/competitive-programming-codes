#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	n=1000-n;

	int ans=0;
	for(int x:{500,100,50,10,5,1}){
		ans+=n/x;
		n%=x;
	}
	printf("%d\n",ans);

	return 0;
}
