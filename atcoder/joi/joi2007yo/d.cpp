#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(2*n);
	iota(a.begin(),a.end(),0);

	rep(_,m){
		int k; scanf("%d",&k);
		vector<int> next;
		if(k==0){
			rep(i,n){
				next.emplace_back(a[i]);
				next.emplace_back(a[n+i]);
			}
		}
		else{
			rep(i,2*n-k){
				next.emplace_back(a[k+i]);
			}
			rep(i,k){
				next.emplace_back(a[i]);
			}
		}
		a=next;
	}
	rep(i,2*n) printf("%d\n",a[i]+1);

	return 0;
}
