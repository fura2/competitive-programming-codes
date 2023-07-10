#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int cnt1=1,cnt2=1;
	rep(i,n){
		int a; scanf("%d",&a);
		cnt1*=3;
		if(a%2==0) cnt2*=2;
	}
	printf("%d\n",cnt1-cnt2);
	return 0;
}
