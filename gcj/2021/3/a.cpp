#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint dfs2(string t1,string t2,string s){ // t1 > t2
	if(s.empty()) return abs(stoll(t1)-stoll(t2));
	t1+=s[0];
	t2+=s.back();
	s.pop_back();
	s.erase(s.begin());
	return dfs2(t1,t2,s);
}

map<string,lint> memo;

lint dfs1(string t,string s){ // t1 = t2 (= t)
	if(s.empty()) return 0;

	if(memo.count(s)>0){
		return memo[s];
	}

	int n=s.length();
	lint res=LLONG_MAX;
	rep(i,n-1){
		if(t.empty() && s[i]=='0') continue;

		if(s[i]<s[i+1]){
			string u1=t,u2=t,s2=s;
			u1+=s[i+1];
			u2+=s[i];
			s2.erase(s2.begin()+i+1);
			s2.erase(s2.begin()+i);
			res=min(res,dfs2(u1,u2,s2));
		}
		else{
			string u=t,s2=s;
			u+=s[i];
			s2.erase(s2.begin()+i+1);
			s2.erase(s2.begin()+i);
			res=min(res,dfs1(u,s2));
		}
	}
	return memo[s]=res;
}

void solve(){
	string s; cin>>s;
	int n=s.length();

	sort(s.begin(),s.end());

	lint ans;
	memo.clear();
	if(n%2==0){
		ans=dfs1("",s);
	}
	else{
		int i;
		for(i=0;s[i]=='0';i++);
		string t(1,s[i]);
		s.erase(s.begin()+i);
		ans=dfs2(t,"",s);
	}
	printf("%lld\n",ans);
}

int main(){
	int t; scanf("%d",&t);
	rep(_,t){
		printf("Case #%d: ",_+1);
		solve();
	}
	return 0;
}
