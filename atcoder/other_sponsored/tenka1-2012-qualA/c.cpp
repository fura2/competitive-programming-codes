#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> from(m),to(m);
	rep(i,m) scanf("%d%d",&from[i],&to[i]), from[i]--, to[i]--;
	string s; cin>>s;
	int len=s.length();

	int pos=s.find("group")+5;
	int num=0;
	for(;pos<len&&isdigit(s[pos]);pos++) num=num*10+s[pos]-'0';
	num--;

	vector<bool> now(n),next(n);

	if(pos<len && s[pos]=='w'){
		rep(i,m) if(to[i]==num) now[from[i]]=true;
		pos++;
	}
	else{
		rep(u,n) now[u]=true;
		rep(i,m) if(to[i]==num) now[from[i]]=false;
	}

	while(pos<len){
		fill(next.begin(),next.end(),false);
		pos++;
		if(pos<len && s[pos]=='w'){
			rep(u,n) next[u]=false;
			rep(i,m) if(now[to[i]]) next[from[i]]=true;
			pos+=2;
		}
		else{
			int cnt1=count(now.begin(),now.end(),true);
			vector<int> cnt2(n);
			rep(i,m) if(now[to[i]]) cnt2[from[i]]++;
			rep(u,n) if(cnt2[u]<cnt1) next[u]=true;
		}
		now=next;
	}
	cout<<count(now.begin(),now.end(),true)<<'\n';

	return 0;
}
