#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	vector<int> p;
	rep(i,31) if(n>>i&1) p.emplace_back(i);

	if(p.size()==1){
		puts("-1 -1 -1");
	}
	else{
		int x=n&~(1<<p[0]);
		printf("%d %d %d\n",n,x,n^x);
	}

	return 0;
}
