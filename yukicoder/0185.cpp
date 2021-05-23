#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	set<int> S;
	rep(i,n){
		int x,y; scanf("%d%d",&x,&y);
		S.emplace(y-x);
	}

	printf("%d\n",S.size()==1&&*S.begin()>0?*S.begin():-1);

	return 0;
}
