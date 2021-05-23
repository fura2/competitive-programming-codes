#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b; scanf("%d%d",&a,&b);
	set<int> S;
	rep(i,a+1) rep(j,b+1) if(i+j>0) S.emplace(i+5*j);
	for(int x:S) printf("%d\n",x);
	return 0;
}
