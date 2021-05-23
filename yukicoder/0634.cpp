#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	vector<int> T;
	for(int i=1;i*(i+1)/2<=n;i++) T.emplace_back(i*(i+1)/2);

	if(T.back()==n) return puts("1"),0;
	rep(i,T.size()) rep(j,i+1) if(T[i]+T[j]==n) return puts("2"),0;
	puts("3");

	return 0;
}
