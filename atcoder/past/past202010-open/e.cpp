#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	string t=s;
	sort(t.begin(),t.end());
	do{
		string r=s;
		reverse(r.begin(),r.end());
		if(t!=s && t!=r){
			cout<<t<<'\n';
			return 0;
		}
	}while(next_permutation(t.begin(),t.end()));
	cout<<"None\n";

	return 0;
}
