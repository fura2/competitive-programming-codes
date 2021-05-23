#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	map<string,int> f;
	map<int,string> g;
	f[   "I"]= 1; g[ 1]=   "I";
	f[  "II"]= 2; g[ 2]=  "II";
	f[ "III"]= 3; g[ 3]= "III";
	f["IIII"]= 4; g[ 4]="IIII";
	f[   "V"]= 5; g[ 5]=   "V";
	f[  "VI"]= 6; g[ 6]=  "VI";
	f[ "VII"]= 7; g[ 7]= "VII";
	f["VIII"]= 8; g[ 8]="VIII";
	f[  "IX"] =9; g[ 9]=  "IX";
	f[   "X"]=10; g[10]=   "X";
	f[  "XI"]=11; g[11]=  "XI";
	f[ "XII"]=12; g[12]= "XII";

	string s;
	int t; cin>>s>>t;

	int x=(f[s]+t)%12;
	if(x<=0) x+=12;
	cout<<g[x]<<'\n';

	return 0;
}
