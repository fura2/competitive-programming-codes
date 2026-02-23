#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	rep(_,n){
		string s; cin>>s;
		cout<<(regex_match(s,regex("[a-z]*okyo[a-z]*ech[a-z]*"))?"Yes":"No")<<endl;
	}

	return 0;
}
