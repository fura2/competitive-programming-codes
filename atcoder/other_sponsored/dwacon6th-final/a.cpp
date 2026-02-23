#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<string> solve(int h,int w){
	vector<string> B(h);
	if(h==1){
		rep(m,2000) rep(n,2000) if(2*m+5*n==w) {
			if(m-n==-1){
				B[0]="55555";
				rep(i,m) B[0]+="2255555";
				return B;
			}
			else if(m-n==0){
				rep(i,m) B[0]+="2255555";
				return B;
			}
			else if(m-n==1){
				B[0]="22";
				rep(i,n) B[0]+="5555522";
				return B;
			}
		}
	}
	else if(h==2){
		if(w%7==6){
			B[0]="555255";
			B[1]="552555";
			rep(i,w/7){
				B[0]+="2555255";
				B[1]+="2552555";
			}
		}
		else if(w%7==0){
			rep(i,w/7){
				B[0]+="2555255";
				B[1]+="2552555";
			}
		}
		else if(w%7==1){
			rep(i,w/7){
				B[0]+="2555255";
				B[1]+="2552555";
			}
			B[0]+="2";
			B[1]+="2";
		}
	}
	else if(h==3){
		if(w==3){
			B[0]="255";
			B[1]="252";
			B[2]="552";
		}
	}
	return B;
}

int main(){
	int h,w; scanf("%d%d",&h,&w);

	bool f=false;
	if(h>w) swap(h,w), f=true;

	auto B=solve(h,w);
	if(B[0].empty()) return cout<<"No\n",0;

	if(f){
		auto tmp=B;
		B=vector<string>(w,string(h,'?'));
		rep(i,h) rep(j,w) B[j][i]=tmp[i][j];
		swap(h,w);
	}

	cout<<"Yes\n";
	rep(i,h) cout<<B[i]<<'\n';

	return 0;
}
