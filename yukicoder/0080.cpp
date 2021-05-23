#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int d; scanf("%d",&d);
	int ans=0;
	for(int i=1;i<=d;i++){
		if(d-2*i>0) ans=max(ans,(d-2*i)/2*i);
	}
	printf("%d\n",ans);
	return 0;
}
