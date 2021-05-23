#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;

	set<pair<int,int>> S={{0,0}};
	int x=0,y=0,dir=0;
	for(char c:s){
		if((x+y)%2==0){ // 上三角のマスにいる
			if(c=='a'){
				if     (dir==0) x++, dir=5;
				else if(dir==1) y--, dir=3;
				else if(dir==2) x--, dir=4;
				else if(dir==3) x++, dir=2;
				else if(dir==4) y--, dir=0;
				else            x--, dir=1;
			}
			else if(c=='b'){
				if     (dir==0) y--, dir=4;
				else if(dir==1) x--, dir=5;
				else if(dir==2) x++, dir=3;
				else if(dir==3) x--, dir=0;
				else if(dir==4) x++, dir=1;
				else            y--, dir=2;
			}
			else{
				if     (dir==0) x--, dir=3;
				else if(dir==1) x++, dir=4;
				else if(dir==2) y--, dir=5;
				else if(dir==3) y--, dir=1;
				else if(dir==4) x--, dir=2;
				else            x++, dir=0;
			}
		}
		else{ // 下三角のマスにいる
			if(c=='a'){
				if     (dir==0) y++, dir=4;
				else if(dir==1) x++, dir=5;
				else if(dir==2) x--, dir=3;
				else if(dir==3) y++, dir=1;
				else if(dir==4) x++, dir=2;
				else            x--, dir=0;
			}
			else if(c=='b'){
				if     (dir==0) x++, dir=3;
				else if(dir==1) x--, dir=4;
				else if(dir==2) y++, dir=5;
				else if(dir==3) x--, dir=2;
				else if(dir==4) y++, dir=0;
				else            x++, dir=1;
			}
			else{
				if     (dir==0) x--, dir=5;
				else if(dir==1) y++, dir=3;
				else if(dir==2) x++, dir=4;
				else if(dir==3) x++, dir=0;
				else if(dir==4) x--, dir=1;
				else            y++, dir=2;
			}
		}
		S.emplace(x,y);
	}
	printf("%ld\n",S.size());

	return 0;
}
