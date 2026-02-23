#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	lint p,q; scanf("%d%lld%lld",&n,&p,&q);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	lint ans=0;
	rep(i,n){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				for(int l=k+1;l<n;l++){
					for(int m=l+1;m<n;m++){
						lint tmp=a[i];
						tmp=tmp*a[j]%p;
						tmp=tmp*a[k]%p;
						tmp=tmp*a[l]%p;
						tmp=tmp*a[m]%p;
						if(tmp==q) ans++;
					}
				}
			}
		}
	}
	printf("%lld\n",ans);

	return 0;
}
