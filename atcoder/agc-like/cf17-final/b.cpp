#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;

	int na=count(s.begin(),s.end(),'a');
	int nb=count(s.begin(),s.end(),'b');
	int nc=count(s.begin(),s.end(),'c');
	puts(max({na,nb,nc})-min({na,nb,nc})<=1?"YES":"NO");

	return 0;
}
