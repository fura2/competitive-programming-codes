#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,n; scanf("%d%d%d",&h,&w,&n);
	vector<char> type(n);
	vector<int> pos(n);
	rep(i,n) scanf(" %c%d",&type[i],&pos[i]);

	int x=0,y=0;
	for(int i=n-1;i>=0;i--){
		if(type[i]=='R'){
			if(pos[i]==y) x=(x+w-1)%w;
		}else{
			if(pos[i]==x) y=(y+h-1)%h;
		}
	}
	puts((x+y)%2==0?"white":"black");

	return 0;
}
