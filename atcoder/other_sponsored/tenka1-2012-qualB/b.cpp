#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	int l=0,r=n;
	while(l<n && s[l]=='_') l++;
	while(r>0 && s[r-1]=='_') r--;

	if(l>=r){
		cout<<s<<'\n';
		return 0;
	}
	s=s.substr(l,r-l);

	cout<<string(l,'_');

	if(count(s.begin(),s.end(),'_')>0){
		bool ok=true;
		rep(i,s.length()){
			if(isupper(s[i])) ok=false;
			if((i==0 || (i>0 && s[i-1]=='_')) && !islower(s[i])) ok=false;
		}
		if(ok){ // snake -> camel
			rep(i,s.length()){
				if(s[i]=='_'){
					i++;
					putchar(toupper(s[i]));
				}
				else{
					putchar(s[i]);
				}
			}
		}
		else{
			cout<<s;
		}
	}
	else{
		if(!isupper(s[0])){ // camel -> snake
			for(char c:s){
				if(isupper(c)){
					printf("_%c",tolower(c));
				}
				else{
					putchar(c);
				}
			}
		}
		else{
			cout<<s;
		}
	}

	cout<<string(n-r,'_')<<'\n';

	return 0;
}
