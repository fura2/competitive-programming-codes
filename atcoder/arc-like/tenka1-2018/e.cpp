#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	vector cum1(h,vector(w,0)); // \ 方向の累積和
	vector cum2(h,vector(w,0)); // / 方向の累積和
	rep(i,h) rep(j,w) {
		if(i>0 && j>0)   cum1[i][j]+=cum1[i-1][j-1];
		if(i>0 && j<w-1) cum2[i][j]+=cum2[i-1][j+1];
		if(B[i][j]=='#'){
			cum1[i][j]++;
			cum2[i][j]++;
		}
	}

	auto f1=[&](int i1,int j1,int i2,int j2){
		if(i1<0){
			j1-=i1;
			i1=0;
		}
		if(j1<0){
			i1-=j1;
			j1=0;
		}
		if(i2>=h){
			j2-=i2-h+1;
			i2=h-1;
		}
		if(j2>=w){
			i2-=j2-w+1;
			j2=w-1;
		}
		if(0<=i1 && i1<h && 0<=j1 && j1<w && 0<=i2 && i2<h && 0<=j2 && j2<w){
			return cum1[i2][j2]-(i1>0&&j1>0?cum1[i1-1][j1-1]:0);
		}
		else{
			return 0;
		}
	};

	auto f2=[&](int i1,int j1,int i2,int j2){
		if(i1<0){
			j1+=i1;
			i1=0;
		}
		if(j1>=w){
			i1+=j1-w+1;
			j1=w-1;
		}
		if(i2>=h){
			j2+=i2-h+1;
			i2=h-1;
		}
		if(j2<0){
			i2+=j2;
			j2=0;
		}
		if(0<=i1 && i1<h && 0<=j1 && j1<w && 0<=i2 && i2<h && 0<=j2 && j2<w){
			return cum2[i2][j2]-(i1>0&&j1<w-1?cum2[i1-1][j1+1]:0);
		}
		else{
			return 0;
		}
	};

	lint ans=0;
	rep(i,h) rep(j,w) if(B[i][j]=='#') {
		for(int d=1;i+d<h&&j+d<w;d++) if(B[i+d][j+d]=='#') {
			ans+=f1(i-d,j+d,i,j+2*d)
				+f1(i+d,j-d,i+2*d,j);
			// 重複カウント分を排除
			ans-=f1(i-d,j+d,i-d,j+d)
				+f1(i,j+2*d,i,j+2*d)
				+f1(i+d,j-d,i+d,j-d)
				+f1(i+2*d,j,i+2*d,j);
		}
		for(int d=1;i+d<h&&j-d>=0;d++) if(B[i+d][j-d]=='#') {
			ans+=f2(i-d,j-d,i,j-2*d)
				+f2(i+d,j+d,i+2*d,j);
		}
	}
	cout<<ans<<'\n';

	return 0;
}
