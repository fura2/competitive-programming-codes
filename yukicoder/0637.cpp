#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int ans=0;
	rep(i,5){
		int a; scanf("%d",&a);
		if(a%15==0) ans+=8;
		else if(a%3==0) ans+=4;
		else if(a%5==0) ans+=4;
		else ans+=to_string(a).length();
	}
	printf("%d\n",ans);
	return 0;
}
