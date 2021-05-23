#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T>
vector<pair<T,int>> run_length_encoding(const vector<T>& a){
	vector<pair<T,int>> res;
	int n=a.size(),pre=0;
	rep(i,n) if(i==n-1 || a[i]!=a[i+1]) res.emplace_back(a[i],i-pre+1), pre=i+1;
	return res;
}

int main(){
	string s; cin>>s;
	vector<bool> a;
	rep(i,s.length()/3){
		a.emplace_back(s[3*i]==-30 && s[3*i+1]==-128 && s[3*i+2]==-90);
	}

	int ans=0;
	for(auto p:run_length_encoding(a)) if(p.first) ans=max(ans,p.second);
	printf("%d\n",ans);

	return 0;
}
