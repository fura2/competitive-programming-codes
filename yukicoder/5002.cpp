#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; cin>>n>>k;
	vector<int> l(k);
	rep(i,k) cin>>l[i];
	vector<string> B(n);
	rep(i,n) cin>>B[i];

	rep(i,k) printf("1 1 1 %d\n",l[i]);

	return 0;
}
