#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<pair<int,int>> a(n);
	rep(i,n){
		int x;
		char c; scanf("%d %c",&x,&c);
		a[i]={-c,x};
	}
	sort(a.begin(),a.end());

	rep(i,n) printf("%d\n",a[i].second);

	return 0;
}
