#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

int main(){
	string s;
	int gx,gy; cin>>s>>gx>>gy;

	int p[]={0,1,2,3};
	do{
		bool ok=(gx==0&&gy==0);
		int x=0,y=0;
		rep(i,s.length()){
			if(s[i]=='W') x+=dx[p[0]], y+=dy[p[0]];
			if(s[i]=='X') x+=dx[p[1]], y+=dy[p[1]];
			if(s[i]=='Y') x+=dx[p[2]], y+=dy[p[2]];
			if(s[i]=='Z') x+=dx[p[3]], y+=dy[p[3]];
			if(x==gx && y==gy) ok=true;
		}
		if(ok){
			puts("Yes");
			return 0;
		}
	}while(next_permutation(p,p+4));
	puts("No");

	return 0;
}
