#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	double mean=accumulate(a.begin(),a.end(),0.0)/n;
	rep(i,n) printf("%d\n",int(50-(mean-a[i])/2));

	return 0;
}
