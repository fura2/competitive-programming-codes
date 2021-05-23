#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	pair<int,int> a[10];
	rep(i,n) scanf("%d%d",&a[i].first,&a[i].second);
	sort(a,a+n,[](pair<int,int> x,pair<int,int> y){ return x.first*y.second>y.first*x.second; });
	rep(i,n) printf("%d %d\n",a[i].first,a[i].second);
	return 0;
}
