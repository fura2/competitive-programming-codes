#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	string t1,t2;
	for(char& c:s){
		if(c=='7'){
			t1+=c-1;
			t2+='1';
		}
		else{
			t1+=c;
			t2+='0';
		}
	}
	cout<<stoi(t1)<<' '<<stoi(t2)<<'\n';
	return 0;
}
