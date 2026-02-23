#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int money[]={100000,50000,30000,20000,10000,0};

	int n; scanf("%d",&n);
	vector<int> ans(n);
	rep(i,n){
		int a; scanf("%d",&a); a--;
		ans[a]=money[min(i,5)];
	}
	rep(i,n) printf("%d\n",ans[i]);

	return 0;
}
