#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

string s;
int idx;

void number(){
	while(idx<s.length() && isdigit(s[idx])){
		putchar(s[idx]);
		idx++;
	}
}

void expr(){
	if(isdigit(s[idx])){
		number();
	}
	else{
		char op=s[idx];
		idx+=2;
		putchar('(');
		while(1){
			expr();
			if(s[idx]==')'){
				putchar(')');
				idx++;
				break;
			}
			else if(s[idx]==','){
				putchar(op);
				idx++;
			}
		}
	}
}

int main(){
	cin>>s;
	expr();
	puts("");
	return 0;
}
