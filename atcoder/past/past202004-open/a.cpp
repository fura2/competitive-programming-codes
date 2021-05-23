#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	map<string,int> f;
	f["B9"]=0;
	f["B8"]=1;
	f["B7"]=2;
	f["B6"]=3;
	f["B5"]=4;
	f["B4"]=5;
	f["B3"]=6;
	f["B2"]=7;
	f["B1"]=8;
	f["1F"]=9;
	f["2F"]=10;
	f["3F"]=11;
	f["4F"]=12;
	f["5F"]=13;
	f["6F"]=14;
	f["7F"]=15;
	f["8F"]=16;
	f["9F"]=17;

	string s,t; cin>>s>>t;
	cout<<abs(f[s]-f[t])<<'\n';

	return 0;
}
