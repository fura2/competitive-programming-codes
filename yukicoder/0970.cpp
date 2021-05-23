#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> y(n);
	rep(i,n) scanf("%d",&y[i]);

	int sum=accumulate(y.begin(),y.end(),0);
	rep(i,n) printf("%d%c",sum-(n-1)*y[i],i<n-1?' ':'\n');

	return 0;
}
