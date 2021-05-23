#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int L;
	string s,t; cin>>L>>s>>t;

	auto f=[](string s,string t,int L){
		int n1=s.length(),n2=t.length();
		int a,b;
		for(int i=L/n1;i>=0;i--) if((L-i*n1)%n2==0) {
			a=i;
			b=(L-i*n1)/n2;
			break;
		}
		string res;
		rep(i,a) res+=s;
		rep(i,b) res+=t;
		return res;
	};

	cout<<min(f(s,t,L),f(t,s,L))<<'\n';

	return 0;
}
