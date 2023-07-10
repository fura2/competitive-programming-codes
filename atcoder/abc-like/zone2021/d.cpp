#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;

	deque<char> D;
	bool b=true;
	for(char c:s){
		if(c=='R'){
			b=!b;
		}
		else{
			if(b) D.emplace_back(c);
			else  D.emplace_front(c);
		}
	}

	stack<char> S;
	for(char c:D){
		if(!S.empty() && S.top()==c){
			S.pop();
		}
		else{
			S.emplace(c);
		}
	}

	string ans;
	while(!S.empty()) ans+=S.top(), S.pop();
	if(b) reverse(ans.begin(),ans.end());
	cout<<ans<<'\n';

	return 0;
}
