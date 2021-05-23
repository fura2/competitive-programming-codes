#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool check(string s){
	sort(s.begin(),s.end());
	s.erase(unique(s.begin(),s.end()),s.end());
	return s.length()==13;
}

int main(){
	string s; cin>>s;
	bool ok=false;
	rep(i,13) if(check(s+char('a'+i))) printf("%c\n",'a'+i), ok=true;
	if(!ok) puts("Impossible");
	return 0;
}
