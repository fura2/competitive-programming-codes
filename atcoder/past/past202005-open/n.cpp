#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,q; scanf("%d%d",&n,&q);

	vector<int> a(n);
	iota(a.begin(),a.end(),0);

	set<int> S;
	auto swap_and_update=[&](int x){
		swap(a[x],a[x+1]);
		S.erase(x);
		if(x-1>=0) S.erase(x-1);
		if(x+2< n) S.erase(x+1);
		if(a[x]>a[x+1]) S.emplace(x);
		if(x-1>=0 && a[x-1]>a[ x ]) S.emplace(x-1);
		if(x+2< n && a[x+1]>a[x+2]) S.emplace(x+1);
	};

	rep(_,q){
		int type,x,y; scanf("%d%d%d",&type,&x,&y); x--;
		if(type==1){
			swap_and_update(x);
		}
		else{
			while(1){
				auto it=S.lower_bound(x);
				if(it==S.end() || *it+1>=y) break;
				swap_and_update(*it);
			}
		}
	}

	rep(i,n) printf("%d%c",a[i]+1,i<n-1?' ':'\n');

	return 0;
}
