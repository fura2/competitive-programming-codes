#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int sum=accumulate(a.begin(),a.end(),0);

	int ans=0;
	rep(i,n) if(10*a[i]<=sum) ans++;
	printf("%d\n",30*ans);

	return 0;
}
