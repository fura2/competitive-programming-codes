#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	map<int,int> f;
	rep(i,n){
		int a; scanf("%d",&a);
		++f[a];
	}

	int ans=0;
	for(auto p:f) if(p.second==1) ans++;
	printf("%d\n",ans);

	return 0;
}
