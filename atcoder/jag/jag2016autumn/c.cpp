#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	map<pair<int,int>,string,greater<>> f1,f2;
	map<string,pair<int,int>> g;
	rep(i,n){
		string s;
		int a; cin>>s>>a;
		f2[{a,i}]=s;
		g[s]={a,i};
	}

	rep(_,n/5){
		auto it=f2.begin();
		f1[it->first]=it->second;
		f2.erase(it);
	}

	int q; cin>>q;
	for(int i=n;i<n+q;i++){
		char c;
		string s; cin>>c>>s;
		if(c=='+'){
			int a; cin>>a;

			int n1=f1.size(),n2=f2.size(),b,j;
			if(n1<(n1+n2+1)/5){
				tie(b,j)=f2.begin()->first;
			}
			else{
				if(f1.empty()){
					b=j=1e9;
				}
				else{
					tie(b,j)=prev(f1.end())->first;
				}
			}
			if(make_pair(a,i)>make_pair(b,j)){
				printf("%s is working hard now.\n",s.c_str());
				f1[{a,i}]=s;
			}
			else{
				printf("%s is not working now.\n",s.c_str());
				f2[{a,i}]=s;
			}
			g[s]={a,i};
		}
		else{
			int a,j; tie(a,j)=g[s];
			if(f1.count({a,j})>0) f1.erase({a,j});
			else                  f2.erase({a,j});
			g.erase(s);
		}

		int n1=f1.size(),n2=f2.size();
		if(n1<(n1+n2)/5){
			auto it=f2.begin();
			printf("%s is working hard now.\n",it->second.c_str());
			f1[it->first]=it->second;
			f2.erase(it);
		}
		else if(n1>(n1+n2)/5){
			auto it=prev(f1.end());
			printf("%s is not working now.\n",it->second.c_str());
			f2[it->first]=it->second;
			f1.erase(it);
		}
	}

	return 0;
}
