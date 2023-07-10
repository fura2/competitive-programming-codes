#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int x=0;
	set<int> S;
	rep(i,n){
		int a; scanf("%d",&a);
		S.emplace(a);
		while(S.count(x)>0) x++;
		printf("%d\n",x);
	}

	return 0;
}
