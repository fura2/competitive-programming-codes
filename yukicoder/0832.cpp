#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool check3(string s){
	int n=s.length();
	if(n==0) return true;
	rep(i,n) for(int j=i+1;j<n;j++) for(int k=j+1;k<n;k++) {
		if((s[i]==s[j] && s[i]==s[k])
		|| (s[i]+1==s[j] && s[i]+2==s[k])){
			return check3(s.substr(0,i)+s.substr(i+1,j-i-1)+s.substr(j+1,k-j-1)+s.substr(k+1));
		}
	}
	return false;
}

bool check(string s){
	string t[7];
	rep(i,7) t[i]=s.substr(2*i,2);
	bool ok=true;
	rep(i,7){
		if(t[i][0]!=t[i][1]) ok=false;
		rep(j,i) if(t[i]==t[j]) ok=false;
	}
	if(ok) return true;

	rep(i,13) if(s[i]==s[i+1]) {
		string t=s.substr(0,i)+s.substr(i+2);
		if(check3(t)) return true;
	}
	return false;
}

int main(){
	string s; cin>>s;
	for(char c='1';c<='9';c++){
		if(count(s.begin(),s.end(),c)<4){
			string t=s+c;
			sort(t.begin(),t.end());
			if(check(t)) printf("%c\n",c);
		}
	}
	return 0;
}
