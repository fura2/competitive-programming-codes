#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

int id,n;
vector<string> B(100);

vector<tuple<int,int,int>> solve(int x0,int y0){
	auto B_tmp=B;

	vector<tuple<int,int,int>> res;
	while(1){
		int cnt=0;
		rep(i,n) rep(j,n) if(B[i][j]==B[x0][y0]) cnt++;
		if(cnt==n*n) break;

		vector vis(n,vector(n,false));
		vis[x0][y0]=true;

		map<int,int> C;
		queue<pair<int,int>> Q;
		Q.emplace(x0,y0);
		while(!Q.empty()){
			int x,y; tie(x,y)=Q.front();
			Q.pop();
			rep(k,4){
				int x2=x+dx[k],y2=y+dy[k];
				if(0<=x2 && x2<n && 0<=y2 && y2<n && !vis[x2][y2]){
					vis[x2][y2]=true;
					if(B[x2][y2]==B[x0][y0]){
						Q.emplace(x2,y2);
					}
					else{
						++C[B[x2][y2]-'0'];
					}
				}
			}
		}

		int next,prev;
		{
			int mx=0;
			for(auto p:C) if(p.second>mx) {
				mx=p.second;
				next=p.first;
			}
			prev=B[x0][y0];
		}
		res.emplace_back(x0,y0,next);

		rep(i,n) rep(j,n) vis[i][j]=false;
		vis[x0][y0]=true;
		Q.emplace(x0,y0);
		while(!Q.empty()){
			int x,y; tie(x,y)=Q.front();
			Q.pop();
			B[x][y]=next+'0';
			rep(k,4){
				int x2=x+dx[k],y2=y+dy[k];
				if(0<=x2 && x2<n && 0<=y2 && y2<n && !vis[x2][y2]){
					vis[x2][y2]=true;
					if(B[x2][y2]==prev){
						Q.emplace(x2,y2);
					}
				}
			}
		}
	}

	B=B_tmp;

	return res;
}

int main(){
	scanf("%d%d%*d",&id,&n);
	rep(i,n) cin>>B[i];

// local run
/*
	int mn=n*n,i_ans,j_ans;
	for(int i=45;i<55;i++) for(int j=45;j<55;j++) {
		auto tmp=solve(i,j);
		if(tmp.size()<mn){
			mn=tmp.size();
			i_ans=i;
			j_ans=j;
		}
	}
	printf("if(id==%2d) x0=%d, y0=%d;\n",id,i_ans,j_ans);
*/

	int x0,y0;
	if(id== 1) x0=52, y0=45;
	if(id== 2) x0=48, y0=52;
	if(id== 3) x0=48, y0=47;
	if(id== 4) x0=49, y0=50;
	if(id== 5) x0=49, y0=52;
	if(id== 6) x0=50, y0=47;
	if(id== 7) x0=46, y0=51;
	if(id== 8) x0=49, y0=48;
	if(id== 9) x0=47, y0=52;
	if(id==10) x0=51, y0=47;
	if(id==11) x0=47, y0=48;
	if(id==12) x0=51, y0=52;
	if(id==13) x0=51, y0=46;
	if(id==14) x0=45, y0=51;
	if(id==15) x0=46, y0=45;
	if(id==16) x0=54, y0=46;
	if(id==17) x0=50, y0=54;
	if(id==18) x0=52, y0=50;
	if(id==19) x0=51, y0=53;
	if(id==20) x0=47, y0=52;
	if(id==21) x0=51, y0=45;
	if(id==22) x0=52, y0=53;
	if(id==23) x0=51, y0=49;
	if(id==24) x0=45, y0=45;
	if(id==25) x0=50, y0=53;
	if(id==26) x0=47, y0=53;
	if(id==27) x0=47, y0=51;
	if(id==28) x0=45, y0=50;
	if(id==29) x0=51, y0=52;
	if(id==30) x0=52, y0=53;
	if(id==31) x0=51, y0=48;
	if(id==32) x0=50, y0=50;
	if(id==33) x0=50, y0=51;
	if(id==34) x0=50, y0=48;
	if(id==35) x0=45, y0=53;
	if(id==36) x0=47, y0=52;
	if(id==37) x0=49, y0=49;
	if(id==38) x0=46, y0=50;
	if(id==39) x0=54, y0=49;
	if(id==40) x0=46, y0=48;
	if(id==41) x0=48, y0=52;
	if(id==42) x0=48, y0=50;
	if(id==43) x0=50, y0=47;
	if(id==44) x0=51, y0=50;
	if(id==45) x0=47, y0=50;
	if(id==46) x0=49, y0=48;
	if(id==47) x0=54, y0=54;
	if(id==48) x0=49, y0=50;
	if(id==49) x0=48, y0=50;
	if(id==50) x0=49, y0=52;

	auto ans=solve(x0,y0);

	printf("%ld\n",ans.size());
	for(auto [x,y,c]:ans) printf("%d %d %d\n",x+1,y+1,c);

	return 0;
}
