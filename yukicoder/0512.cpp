#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x,y,n; scanf("%d%d%d",&x,&y,&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	rep(i,n-1) if(a[i]*y>a[i+1]*x) return puts("NO"),0;
	puts("YES");

	return 0;
}
