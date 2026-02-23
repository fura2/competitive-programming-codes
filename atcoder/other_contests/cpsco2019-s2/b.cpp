#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int ans=0;
	vector<int> M;
	rep(i,n){
		char op;
		int a; scanf(" %c%d",&op,&a);
		if(op=='+') ans+=a;
		if(op=='*') M.emplace_back(a);
	}
	for(int a:M) if(a>0) ans*=a;
	printf("%d\n",ans);

	return 0;
}
