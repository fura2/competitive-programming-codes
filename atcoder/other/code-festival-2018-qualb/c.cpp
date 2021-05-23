#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	vector<pair<int,int>> A;
	for(int j=-2;j<1e3+1;j+=5){
		A.emplace_back(-1,j);
	}
	rep(i,1e3+1){
		int j;
		if     (i%5==0) j=0;
		else if(i%5==1) j=2;
		else if(i%5==2) j=-1;
		else if(i%5==3) j=1;
		else            j=-2;
		for(;j<1e3+1;j+=5){
			A.emplace_back(i,j);
		}
	}

	int n; scanf("%d",&n);
	vector<string> B(n,string(n,'.'));
	for(auto p:A){
		int i,j; tie(i,j)=p;
		if     (i==-1) i++;
		else if(i== n) i--;
		if     (j==-1) j++;
		else if(j== n) j--;
		if(0<=i && i<n && 0<=j && j<n) B[i][j]='X';
	}
	rep(i,n) puts(B[i].c_str());

	return 0;
}
