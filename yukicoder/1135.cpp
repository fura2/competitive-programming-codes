#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	stack<int> S;
	rep(_,n){
		string s; cin>>s;
		if(s=="+"){
			int a=S.top(); S.pop();
			int b=S.top(); S.pop();
			S.push(b+a);
		}
		else if(s=="-"){
			int a=S.top(); S.pop();
			int b=S.top(); S.pop();
			S.push(b-a);
		}
		else{
			S.push(stoi(s));
		}
	}
	printf("%d\n",S.top());
	return 0;
}
