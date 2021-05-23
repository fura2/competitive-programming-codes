#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	puts(s.length()>=5&&s.substr(0,5)=="MUJIN"?"Yes":"No");
	return 0;
}
