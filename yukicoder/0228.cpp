#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

bool dfs(vector<int> a,int used){
	bool end=true;
	rep(i,15) if(a[i]!=i+1) end=false;
	if(end) return true;

	int i=find(a.begin(),a.end(),0)-a.begin();
	int y=i/4,x=i%4;
	rep(k,4){
		int yy=y+dy[k],xx=x+dx[k];
		int ii=yy*4+xx;
		if(0<=yy && yy<4 && 0<=xx && xx<4 && !(used>>a[ii]&1)){
			swap(a[i],a[ii]);
			if(dfs(a,used|1<<a[i])) return true;
			swap(a[i],a[ii]);
		}
	}
	return false;
}

int main(){
	vector<int> a(16);
	rep(i,16) scanf("%d",&a[i]);
	puts(dfs(a,0)?"Yes":"No");
	return 0;
}
