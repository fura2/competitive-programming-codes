#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

bool dfs2(int a,int b,int x);

bool dfs1(int a,int b,int x){
	if(a==0 && b==0) return x==1;
	if(b>0 && !dfs2(a,b-1,1-x)) return true;
	if(a>0 && !dfs2(a-1,b, x )) return true;
	return false;
}

bool dfs2(int a,int b,int x){
	if(a==0 && b==0) return x==0;
	if(b>0 && !dfs1(a,b-1,x)) return true;
	if(a>0 && !dfs1(a-1,b,x)) return true;
	return false;
}

int main(){
// experiment
//	rep(a,16) rep(b,16) printf(dfs1(a,b,0)?"o%c":"x%c",b<15?' ':'\n');

	lint a,b; cin>>a>>b;
	puts(b%4==1||b%4==2||(b%4==3&&a%2==1)?"Angel":"Devil");

	return 0;
}
