#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	vector<int> ans(n);
	stack<int> S;
	rep(i,n){
		if(s[i]=='('){
			S.push(i);
		}
		else{
			int j=S.top();
			S.pop();
			ans[i]=j;
			ans[j]=i;
		}
	}

	rep(i,n) printf("%d\n",ans[i]+1);

	return 0;
}
