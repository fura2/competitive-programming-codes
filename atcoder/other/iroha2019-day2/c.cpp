#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	auto X=a;
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());

	rep(i,n) printf("%d\n",lower_bound(X.begin(),X.end(),a[i])-X.begin()+1);

	return 0;
}
