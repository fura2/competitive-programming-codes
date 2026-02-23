#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

using graph=vector<vector<int>>;

void add_directed_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
}

vector<int> distance(const graph& G,int s){
	const int INF=INT_MAX;
	int n=G.size();
	vector<int> d(n,INF);
	d[s]=0;
	queue<int> Q; Q.emplace(s);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		for(int v:G[u]) if(d[v]==INF) {
			d[v]=d[u]+1;
			Q.emplace(v);
		}
	}
	return d;
}

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	auto get_index=[&](int i,int j,int k,int mem){
		return ((i*w+j)*4+k)*16+mem;
	};

	int N=h*w*4*16;
	graph G(N);
	rep(i,h) rep(j,w) rep(k,4) rep(mem,16) {
		int k2=k,mem2=mem;
		if     (B[i][j]=='<') k2=2;
		else if(B[i][j]=='>') k2=0;
		else if(B[i][j]=='^') k2=1;
		else if(B[i][j]=='v') k2=3;
		else if(B[i][j]=='_') k2=(mem==0?0:2);
		else if(B[i][j]=='|') k2=(mem==0?3:1);
		else if(B[i][j]=='.');
		else if(B[i][j]=='@') continue;
		else if(isdigit(B[i][j])) mem2=B[i][j]-'0';
		else if(B[i][j]=='+') mem2=(mem2+1)%16;
		else if(B[i][j]=='-') mem2=(mem2-1+16)%16;

		if(B[i][j]=='?'){
			rep(k2,4){
				int i2=(i+dx[k2]+h)%h;
				int j2=(j+dy[k2]+w)%w;
				add_directed_edge(G,get_index(i,j,k,mem),get_index(i2,j2,k2,mem2));
			}
		}
		else{
			int i2=(i+dx[k2]+h)%h;
			int j2=(j+dy[k2]+w)%w;
			add_directed_edge(G,get_index(i,j,k,mem),get_index(i2,j2,k2,mem2));
		}
	}

	vector<bool> goal(N);
	rep(i,h) rep(j,w) rep(k,4) rep(mem,16) if(B[i][j]=='@') {
		goal[get_index(i,j,k,mem)]=true;
	}

	auto d=distance(G,0);
	rep(u,N) if(d[u]<INT_MAX && goal[u]) {
		puts("YES");
		return 0;
	}
	puts("NO");

	return 0;
}
