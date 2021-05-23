#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	for(int i=1;i<2*n-3;i++){
		rep(p,i+1){
			int q=i-p;
			if(q<n && p<q){
				if(a[p]>a[q]) swap(a[p],a[q]);
			}
		}
	}

	rep(i,n) printf("%d%c",a[i],i<n-1?' ':'\n');

	return 0;
}
