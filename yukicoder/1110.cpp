#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,d; scanf("%d%d",&n,&d);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	auto b=a;
	sort(b.begin(),b.end());

	rep(i,n) printf("%ld\n",upper_bound(b.begin(),b.end(),a[i]-d)-b.begin());

	return 0;
}
