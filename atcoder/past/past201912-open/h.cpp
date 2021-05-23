#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> c(n);
	rep(i,n) scanf("%d",&c[i]);

	multiset<int> E,O;
	rep(i,n){
		if(i%2==0) O.emplace(c[i]);
		else       E.emplace(c[i]);
	}
	int e_ofs=0,o_ofs=0;

	lint ans=0;
	int q; scanf("%d",&q);
	rep(_,q){
		int t; scanf("%d",&t);
		if(t==1){
			int x,a; scanf("%d%d",&x,&a); x--;
			if(x%2==0){
				if(c[x]>=a+o_ofs){
					O.erase(O.find(c[x]));
					c[x]-=a; ans+=a;
					O.emplace(c[x]);
				}
			}
			else{
				if(c[x]>=a+e_ofs){
					E.erase(E.find(c[x]));
					c[x]-=a; ans+=a;
					E.emplace(c[x]);
				}
			}
		}
		else if(t==2 || (t==3 && n==1)){
			lint a; scanf("%lld",&a);
			if(*O.begin()>=a+o_ofs){
				o_ofs+=a;
				ans+=O.size()*a;
			}
		}
		else{
			lint a; scanf("%lld",&a);
			if(*E.begin()>=a+e_ofs && *O.begin()>=a+o_ofs){
				e_ofs+=a;
				o_ofs+=a;
				ans+=n*a;
			}
		}
	}
	printf("%lld\n",ans);

	return 0;
}
