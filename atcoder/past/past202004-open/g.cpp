#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	deque<pair<char,int>> Q;
	int q; scanf("%d",&q);
	rep(_,q){
		int type; scanf("%d",&type);
		if(type==1){
			char c;
			int x; scanf(" %c%d",&c,&x);
			Q.emplace_back(c,x);
		}
		else{
			int d; scanf("%d",&d);
			lint cnt[26]={};
			while(!Q.empty() && d>0){
				char c;
				int x; tie(c,x)=Q.front(); Q.pop_front();
				if(x<=d){
					cnt[c-'a']+=x;
					d-=x;
				}
				else{
					Q.emplace_front(c,x-d);
					cnt[c-'a']+=d;
					d=0;
				}
			}

			lint ans=0;
			rep(i,26) ans+=cnt[i]*cnt[i];
			printf("%lld\n",ans);
		}
	}
	return 0;
}
