#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k;
	string s; cin>>n>>k>>s;

	stack<int> S;
	rep(i,n){
		if(s[i]=='(') S.emplace(i);
		else{
			int a=S.top();
			if     (k==i+1) printf("%d\n",a+1);
			else if(k==a+1) printf("%d\n",i+1);
			S.pop();
		}
	}

	return 0;
}
