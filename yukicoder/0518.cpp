#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int decode(string s){
	int n=s.length();
	int res=0;
	rep(i,n){
		if(s[i]=='M'){
			res+=1000;
		}
		else if(i<n-1 && s[i]=='C' && s[i+1]=='M'){
			res+=900;
			i++;
		}
		else if(s[i]=='D'){
			res+=500;
		}
		else if(i<n-1 && s[i]=='C' && s[i+1]=='D'){
			res+=400;
			i++;
		}
		else if(s[i]=='C'){
			res+=100;
		}
		else if(i<n-1 && s[i]=='X' && s[i+1]=='C'){
			res+=90;
			i++;
		}
		else if(s[i]=='L'){
			res+=50;
		}
		else if(i<n-1 && s[i]=='X' && s[i+1]=='L'){
			res+=40;
			i++;
		}
		else if(s[i]=='X'){
			res+=10;
		}
		else if(i<n-1 && s[i]=='I' && s[i+1]=='X'){
			res+=9;
			i++;
		}
		else if(s[i]=='V'){
			res+=5;
		}
		else if(i<n-1 && s[i]=='I' && s[i+1]=='V'){
			res+=4;
			i++;
		}
		else if(s[i]=='I'){
			res+=1;
		}
	}
	return res;
}

string encode(int x){
	if(x>=4000) return "ERROR";
	string res;
	while(x>=1000) res+="M", x-=1000;
	if(x>=900) res+="CM", x-=900;
	if(x>=500) res+="D",  x-=500;
	if(x>=400) res+="CD", x-=400;
	while(x>=100) res+="C", x-=100;
	if(x>=90) res+="XC", x-=90;
	if(x>=50) res+="L",  x-=50;
	if(x>=40) res+="XL", x-=40;
	while(x>=10) res+="X", x-=10;
	if(x>=9) res+="IX", x-=9;
	if(x>=5) res+="V",  x-=5;
	if(x>=4) res+="IV", x-=4;
	while(x>=1) res+="I", x-=1;
	return res;
}

int main(){
	int n; scanf("%d",&n);
	int ans=0;
	rep(i,n){
		string s; cin>>s;
		ans+=decode(s);
	}
	cout<<encode(ans)<<'\n';
	return 0;
}
