#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c; cin>>a>>b>>c;
	cout<<set<int>({a,b,c}).size()<<'\n';
	return 0;
}
