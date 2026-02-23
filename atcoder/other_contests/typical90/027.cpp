#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	set<string> S;
	rep(i,n){
		string s; cin>>s;
		if(S.count(s)==0){
			S.emplace(s);
			printf("%d\n",i+1);
		}
	}
	return 0;
}
