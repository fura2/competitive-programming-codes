#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<bool> f(2*n);
	rep(i,n){
		int x; scanf("%d",&x); x--;
		f[x]=true;
	}

	vector<int> a,b;
	rep(x,2*n){
		if(f[x]) a.emplace_back(x);
		else     b.emplace_back(x);
	}

	int pre=-1;
	auto update=[&](vector<int>& c){
		rep(i,c.size()) if(pre<c[i]) {
			pre=c[i];
			c.erase(c.begin()+i);
			return;
		}
		pre=-1;
	};
	while(1){
		if(a.empty() || b.empty()) break;
		update(a);
		if(a.empty() || b.empty()) break;
		update(b);
	}
	printf("%ld\n%ld\n",b.size(),a.size());

	return 0;
}
