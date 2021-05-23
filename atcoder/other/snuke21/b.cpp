#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int k;
	string s; cin>>k>>s;
	int n=s.length();

	int l;
	rep(i,n){
		if((i==0 || s[i-1]!='s') && s[i]=='s'){
			l=i;
		}
		else if((i>0 && s[i-1]=='s') && s[i]!='s'){
			if(s[i]<'s'){
				for(int j=l;j<i;j++) if(k>0) {
					s[j]='*';
					k--;
				}
			}
		}
	}

	for(int i=n-1;i>=0;i--) if(s[i]=='s' && k>0) {
		s[i]='*';
		k--;
	}

	rep(i,n) if(s[i]!='*') putchar(s[i]);
	puts("");

	return 0;
}
