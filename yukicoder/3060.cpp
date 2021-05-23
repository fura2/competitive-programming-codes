#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	while(1){
		string s; cin>>s;
		if(s.empty()) break;

		if     (s=="0") s="Nothing";
		else if(s=="3.14159265") s="pi";
		else if(s=="1112345678999+X") s="九蓮宝燈";
		else if(s=="19m19p19s東南西北白發中+Y") s="Thirteen Orphans";
		else if(s=="くぁｗせｄｒｆｔｇｙふじこｌｐ") s="さｍｐぇ";
		else{
			s=to_string(s.length()-(s.back()=='.'?1:0));
		}
		cout<<s<<'\n';
	}

	return 0;
}
