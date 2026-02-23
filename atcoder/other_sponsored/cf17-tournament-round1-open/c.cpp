#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,q; scanf("%d%d",&n,&q);
	n*=2;
	vector<lint> a(n),b(n);
	rep(i,n) scanf("%lld",&a[i]);
	rep(i,n) scanf("%lld",&b[i]);

	multiset<lint,greater<>> A,B;
	for(int i=1;i<n-1;i++) A.emplace(b[i]-a[i]);

	lint ans=accumulate(a.begin(),a.end(),0LL);
	rep(_,q){
		int p;
		lint x,y; scanf("%d%lld%lld",&p,&x,&y); p--;

		if(p==0 || p==n-1){
			ans+=x-a[p];
		}
		else{
			if(A.find(b[p]-a[p])!=A.end()){
				A.erase(A.find(b[p]-a[p]));
				A.emplace(y-x);
				ans+=x-a[p];
			}
			else if(B.find(a[p]-b[p])!=B.end()){
				B.erase(B.find(a[p]-b[p]));
				B.emplace(x-y);
				ans+=y-b[p];
			}
			else assert(0);
		}
		a[p]=x;
		b[p]=y;

		while(1){
			if(A.size()>=2){ // A -> B
				lint mx1=*A.begin();
				lint mx2=*next(A.begin());
				if(mx1+mx2>0){
					A.erase(A.begin());
					A.erase(A.begin());
					B.emplace(-mx1);
					B.emplace(-mx2);
					ans+=mx1+mx2;
					continue;
				}
			}
			if(B.size()>=2){ // B -> A
				lint mx1=*B.begin();
				lint mx2=*next(B.begin());
				if(mx1+mx2>0){
					B.erase(B.begin());
					B.erase(B.begin());
					A.emplace(-mx1);
					A.emplace(-mx2);
					ans+=mx1+mx2;
					continue;
				}
			}
			if(A.size()>=1 && B.size()>=1){ // swap
				lint mx1=*A.begin();
				lint mx2=*B.begin();
				if(mx1+mx2>0){
					A.erase(A.begin());
					B.erase(B.begin());
					A.emplace(-mx2);
					B.emplace(-mx1);
					ans+=mx1+mx2;
					continue;
				}
			}
			break;
		}
		printf("%lld\n",ans);
	}

	return 0;
}
