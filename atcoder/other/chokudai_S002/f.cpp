#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	set<pair<int,int>> S;
	rep(i,n){
		int a,b; scanf("%d%d",&a,&b);
		if(a>b) swap(a,b);
		S.emplace(a,b);
	}
	printf("%ld\n",S.size());
	return 0;
}
