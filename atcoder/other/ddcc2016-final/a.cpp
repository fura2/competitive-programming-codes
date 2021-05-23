#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int r,c; scanf("%d%d",&r,&c);

	auto f=[&](int x,int y){
		return x*x+y*y<=r*r;
	};

	int ans=0;
	for(int x=0;x<=r;x+=c){
		for(int y=0;y<=r;y+=c){
			if(f(x,y) && f(x+c,y) && f(x,y+c) && f(x+c,y+c)) ans++;
		}
	}
	ans*=4;
	printf("%d\n",ans);

	return 0;
}
