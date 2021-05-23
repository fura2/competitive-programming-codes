#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> d(n);
	rep(i,n) scanf("%d",&d[i]);
	int x,y; scanf("%d%d",&x,&y);

	int g=max(abs(x),abs(y));
	if(g==0) return puts("0"),0;
	rep(i,n) if(d[i]==g) return puts("1"),0;

	int mx=*max_element(d.begin(),d.end());
	printf("%d\n",max((g+mx-1)/mx,2));

	return 0;
}
