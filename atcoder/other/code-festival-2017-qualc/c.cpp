#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	{
		string t;
		rep(i,n) if(s[i]!='x') t+=s[i];
		string r=t;
		reverse(r.begin(),r.end());
		if(t!=r) return puts("-1"),0;
	}

	int ans=0,l=0,r=n-1;
	while(l<r){
		if(s[l]=='x' && s[r]=='x'){
			l++;
			r--;
		}
		else if(s[l]=='x'){
			l++;
			ans++;
		}
		else if(s[r]=='x'){
			r--;
			ans++;
		}
		else{
			assert(s[l]==s[r]);
			l++;
			r--;
		}
	}
	printf("%d\n",ans);

	return 0;
}
