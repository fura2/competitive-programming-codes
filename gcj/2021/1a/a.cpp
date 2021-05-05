#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

void solve(){
	int n; cin>>n;
	vector<string> s(n);
	rep(i,n) cin>>s[i];

	int ans=0;
	for(int i=1;i<n;i++){
		int l0=s[i-1].length(),l=s[i].length();
		if(l0<l){
			continue;
		}
		else if(s[i-1].substr(0,l)<s[i]){
			s[i]+=string(l0-l,'0');
			ans+=l0-l;
		}
		else if(s[i-1].substr(0,l)==s[i]){
			string t=s[i-1].substr(l);
			if(count(t.begin(),t.end(),'9')<l0-l){
				// t++
				int carry=1;
				for(int j=int(t.length())-1;j>=0;j--){
					int x=(t[j]-'0')+carry;
					if(x<10){
						t[j]=x+'0';
						carry=0;
					}
					else{
						t[j]='0';
						carry=1;
					}
				}
				s[i]+=t;
				ans+=l0-l;
			}
			else{
				s[i]+=string(l0-l+1,'0');
				ans+=l0-l+1;
			}
		}
		else{ // s[i-1].substr(0,l)>s[i]
			s[i]+=string(l0-l+1,'0');
			ans+=l0-l+1;
		}
	}
	cout<<ans<<'\n';
}

int main(){
	int t; scanf("%d",&t);
	rep(_,t){
		printf("Case #%d: ",_+1);
		solve();
	}
	return 0;
}
