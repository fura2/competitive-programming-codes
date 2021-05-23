#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int q; scanf("%d",&q);
	rep(_,q){
		string s; cin>>s;
		while(s.length()>1){
			string t;
			rep(i,s.length()-1){
				int a=s[i]-'0';
				int b=s[i+1]-'0';
				t+='0'+((a+b)/10+(a+b)%10);
			}
			s=t;
		}
		cout<<s<<'\n';
	}
	return 0;
}
