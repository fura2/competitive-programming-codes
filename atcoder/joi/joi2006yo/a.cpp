#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int ans1=0,ans2=0;
	rep(i,n){
		int a,b; scanf("%d%d",&a,&b);
		if     (a>b) ans1+=a+b;
		else if(a<b) ans2+=a+b;
		else         ans1+=a, ans2+=b;
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}
