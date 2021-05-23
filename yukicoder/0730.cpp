#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	sort(s.begin(),s.end());
	string t=s;
	t.erase(unique(t.begin(),t.end()),t.end());
	puts(s==t?"YES":"NO");
	return 0;
}
