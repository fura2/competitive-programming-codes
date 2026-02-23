#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int q;
	lint L; cin>>q>>L;

	lint sz=0;
	stack<pair<int,int>> S;
	rep(_,q){
		string s; cin>>s;
		if(s=="Push"){
			int n,m; cin>>n>>m;
			if(sz+n>L){
				cout<<"FULL\n";
				return 0;
			}
			S.emplace(m,n);
			sz+=n;
		}
		else if(s=="Pop"){
			int n; cin>>n;
			if(sz<n){
				cout<<"EMPTY\n";
				return 0;
			}
			sz-=n;
			while(n>0){
				pair<int,int> p=S.top(); S.pop();
				if(p.second<=n){
					n-=p.second;
				}
				else{
					S.emplace(p.first,p.second-n);
					n=0;
				}
			}
		}
		else if(s=="Top"){
			if(sz==0){
				cout<<"EMPTY\n";
				return 0;
			}
			cout<<S.top().first<<'\n';
		}
		else{
			cout<<sz<<'\n';
		}
	}
	cout<<"SAFE\n";

	return 0;
}
