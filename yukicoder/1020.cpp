#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k;
	string s; cin>>n>>k>>s;
	string t1=s.substr(k-1);
	string t2=s.substr(0,k-1);
	if((n-k)%2==0){
		reverse(t2.begin(),t2.end());
	}
	cout<<t1<<t2<<'\n';
	return 0;
}
