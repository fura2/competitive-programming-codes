#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int ans=0;
	while(n>1){
		ans++;
		if(n%2==0) n/=2;
		else       n++;
	}
	printf("%d\n",ans);
	return 0;
}
