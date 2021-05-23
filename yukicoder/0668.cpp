#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();
	int a=s[0]-'0',b=s[1]-'0';
	if(s[2]-'0'>=5){
		b++;
		if(b==10){
			b=0;
			a++;
			if(a==10) a=1, b=0, n++;
		}
	}
	printf("%d.%d*10^%d\n",a,b,n-1);
	return 0;
}
