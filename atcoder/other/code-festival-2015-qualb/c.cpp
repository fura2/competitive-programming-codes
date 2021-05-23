#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n),b(m);
	rep(i,n) scanf("%d",&a[i]);
	rep(j,m) scanf("%d",&b[j]);

	sort(b.begin(),b.end());

	multiset<int> S(a.begin(),a.end());
	rep(j,m){
		auto it=S.lower_bound(b[j]);
		if(it==S.end()){
			puts("NO");
			return 0;
		}
		S.erase(it);
	}
	puts("YES");

	return 0;
}
