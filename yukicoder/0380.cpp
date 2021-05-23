#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	while(1){
		string s; getline(cin,s);
		if(cin.eof()) break;

		int idx=s.find(' ');
		if(idx==string::npos){
			puts("WRONG!");
			continue;
		}

		string name=s.substr(0,idx);
		s=s.substr(idx+1);
		for(char& c:s) c=tolower(c);

		if(name=="digi"){
			rep(i,3) if(!s.empty() && !isalnum(s.back())) s.pop_back();
			int m=s.length();
			puts(m>=3&&s.substr(m-3)=="nyo"?"CORRECT (maybe)":"WRONG!");
		}
		else if(name=="petit"){
			rep(i,3) if(!s.empty() && !isalnum(s.back())) s.pop_back();
			int m=s.length();
			puts(m>=3&&s.substr(m-3)=="nyu"?"CORRECT (maybe)":"WRONG!");
		}
		else if(name=="rabi"){
			while(!s.empty() && !isalnum(s.back())) s.pop_back();
			puts(!s.empty()?"CORRECT (maybe)":"WRONG!");
		}
		else if(name=="gema"){
			rep(i,3) if(!s.empty() && !isalnum(s.back())) s.pop_back();
			int m=s.length();
			puts(m>=4&&s.substr(m-4)=="gema"?"CORRECT (maybe)":"WRONG!");
		}
		else if(name=="piyo"){
			rep(i,3) if(!s.empty() && !isalnum(s.back())) s.pop_back();
			int m=s.length();
			puts(m>=3&&s.substr(m-3)=="pyo"?"CORRECT (maybe)":"WRONG!");
		}
		else{
			puts("WRONG!");
		}
	}

	return 0;
}
