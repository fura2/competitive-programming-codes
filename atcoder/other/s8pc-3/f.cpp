#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,q; scanf("%d%d",&n,&q);

	set<pair<int,lint>> S;
	S.emplace(n,0);
	S.emplace(0,5e13);
	rep(_,q){
		int a;
		lint b; scanf("%d%lld",&a,&b); a--;

		while(1){
			int x1,x2;
			lint y1,y2;
			auto it=S.upper_bound(make_pair(a+1,-1));
			tie(x1,y1)=*it;
			if(a+1<x1){
				it=S.emplace(a+1,y1).first;
				tie(x1,y1)=*it;
			}
			tie(x2,y2)=*prev(it);

			int w=x1-x2;
			if(w*(y2-y1)>=b){
				if(w*(y2-y1-1)>=b){
					S.erase(it);
					S.emplace(x1,y1+b/w);
					if(b%w!=0){
						S.emplace(x2+b%w,y1+b/w+1);
					}
				}
				else{
					it=S.erase(it);
					S.erase(--it);
					S.emplace(x1,y1+b/w);
					if(w*(y2-y1)>b){
						S.emplace(x2+b%w,y1+b/w+1);
					}
				}
				break;
			}

			it=S.erase(it);
			S.erase(--it);
			S.emplace(x1,y2);
			b-=w*(y2-y1);
		}
	}

	vector<lint> ans(n);
	int p=0;
	for(auto [x,y]:S){
		while(p<x) ans[p]=y, p++;
	}
	rep(i,n) printf("%lld\n",ans[i]);

	return 0;
}
