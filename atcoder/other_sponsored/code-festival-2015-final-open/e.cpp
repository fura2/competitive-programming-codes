#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;

	int cnt=count(s.begin(),s.end(),'!');
	int pos=find(s.begin(),s.end(),'!')-s.begin();

	if(pos%2==1) putchar('-');
	if     (cnt==0)   puts("");
	else if(cnt%2==0) puts("!!");
	else              puts("!");

	return 0;
}
