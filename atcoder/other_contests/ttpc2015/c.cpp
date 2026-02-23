#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	for(int i=6;i<=n;i++){
		if(s.substr(i-6,6)=="kayama"){
			int j=i-7;
			while(j>=0 && s[j]=='o') j--;
			j++;

			int len=(i-6)-j;
			if(len<=2) continue;

			string res;
			if     (len%3==1) res="o";
			else if(len%3==2) res="O";
			else              res="Oo";
			for(int x=j;x<i-6;x++) s[x]='-';
			rep(k,res.length()) s[j+k]=res[k];
		}
	}

	for(auto c:s) if(c!='-') putchar(c);
	puts("");

	return 0;
}
