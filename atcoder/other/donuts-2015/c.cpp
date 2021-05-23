#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	stack<int> S;
	rep(i,n){
		printf("%ld\n",S.size());
		while(!S.empty() && S.top()<a[i]){
			S.pop();
		}
		S.emplace(a[i]);
	}

	return 0;
}
