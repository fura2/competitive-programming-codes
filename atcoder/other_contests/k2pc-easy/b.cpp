#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<pair<char,int>> run_length_encoding(const string& s){
	vector<pair<char,int>> res;
	int n=s.length(),pre=0;
	rep(i,n) if(i==n-1 || s[i]!=s[i+1]) res.emplace_back(s[i],i-pre+1), pre=i+1;
	return res;
}

int main(){
	int n,a[10]; cin>>n;
	rep(i,10) cin>>a[i];
	string B[100];
	rep(i,n) cin>>B[i];

	int mx[7]={};
	rep(j,7){
		string s;
		rep(i,n) s+=B[i][j];
		for(auto p:run_length_encoding(s)) if(p.first=='X') mx[j]=max(mx[j],p.second);
	}

	sort(a,a+10);
	reverse(a,a+10);

	int p[7]={0,1,2,3,4,5,6};
	do{
		bool ok=true;
		rep(i,7) if(a[p[i]]<mx[i]) ok=false;
		if(ok) return puts("YES"),0;
	}while(next_permutation(p,p+7));

	puts("NO");

	return 0;
}
