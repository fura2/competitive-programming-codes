#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> x(n);
	rep(i,n) scanf("%d",&x[i]);

	sort(x.begin(),x.end());

	if(x[1]-x[0]==0) return puts("NO"),0;

	rep(i,n-1) if(x[i+1]-x[i]!=x[1]-x[0]) return puts("NO"),0;
	puts("YES");

	return 0;
}
