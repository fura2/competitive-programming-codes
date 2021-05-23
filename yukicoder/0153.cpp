#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int gr[101]={-1,0,1};
	for(int x=3;x<=n;x++){
		set<int> S;
		if(x%2==0) S.emplace(gr[x/2]^gr[x/2]);
		if(x%2==1) S.emplace(gr[x/2]^gr[x/2+1]);
		if(x%3==0) S.emplace(gr[x/3]);
		if(x%3==1) S.emplace(gr[x/3+1]);
		if(x%3==2) S.emplace(gr[x/3]);
		for(gr[x]=0;S.count(gr[x])>0;gr[x]++);
	}
	puts(gr[n]>0?"A":"B");

	return 0;
}
