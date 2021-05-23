#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h1,m1,h,m; cin>>h1>>m1>>h>>m;

	bool ok=false;
	while(h<12){
		if(min(h*60+m,(h+6)%12*60+(m+30)%60)<=h1*60+m1) ok=true;
		m++;
		if(m==60) m=0, h++;
	}
	puts(ok?"Yes":"No");

	return 0;
}
