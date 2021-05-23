#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c,d,e,f,g; cin>>a>>b>>c>>d>>e>>f>>g;
	g-=min(a,g/500)*500;
	g-=min(b,g/100)*100;
	g-=min(c,g/ 50)* 50;
	g-=min(d,g/ 10)* 10;
	g-=min(e,g/  5)*  5;
	g-=min(f,g/  1)*  1;
	puts(g==0?"YES":"NO");
	return 0;
}
