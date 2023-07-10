#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	multiset<int> S;
	rep(i,n){
		int a; scanf("%d",&a);
		S.emplace(a);
	}

	int m; scanf("%d",&m);
	rep(i,m){
		int a; scanf("%d",&a);
		auto it=S.find(a);
		if(it==S.end()) return puts("NO"),0;
		S.erase(it);
	}
	puts("YES");

	return 0;
}
