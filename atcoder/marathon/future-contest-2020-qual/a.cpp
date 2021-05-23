#include <bits/stdc++.h>
#include <sys/time.h>

#define rep(i,n) for(int i=0;i<(n);i++)
#define dbg(S) { int f=1; for(auto x:S) cerr<<(f?"[":", ")<<x, f=0; cerr<<"]\n"; }

using namespace std;
using lint=long long;

//const int dx[]={1,0,-1,0};
//const int dy[]={0,-1,0,1};
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
const int INF=1<<29;

lint gettime(){
	struct timeval tv;
	gettimeofday(&tv,NULL);
	return 1000000LL*tv.tv_sec+tv.tv_usec;
}

int distg[40][40];

class point{
public:
	int x,y;
	point():x(),y(){}
	point(int x,int y):x(x),y(y){}
	bool operator==(const point& p)const{ return x==p.x && y==p.y; }
	bool operator!=(const point& p)const{ return x!=p.x || y!=p.y; }
};

class robot{
public:
	point p;
	char d;
	robot(){}
	robot(const point& p,char d):p(p),d(d){}
	bool operator==(const robot& r)const{ return p==r.p && d==r.d; }
	bool operator!=(const robot& r)const{ return p!=r.p || d!=r.d; }
	bool operator<(const robot& r)const{ return distg[p.y][p.x]>distg[r.p.y][r.p.x]; }
};

int n;
point g;
vector<robot> R;

char B[40][41];
int DIR[128];
char DIRinv[4];

void calc_dist_from_g(){
	rep(i,n) rep(j,n) distg[i][j]=INF;
	distg[g.y][g.x]=0;
	queue<point> Q; Q.push(g);
	while(!Q.empty()){
		point p=Q.front(); Q.pop();
		rep(k,4){
			int x2=(p.x+dx[k]+n)%n;
			int y2=(p.y+dy[k]+n)%n;
			if(B[y2][x2]!='#' && distg[y2][x2]==INF){
				distg[y2][x2]=distg[p.y][p.x]+1;
				Q.emplace(x2,y2);
			}
		}
	}
}

bool go(const robot& r){
	int x0=r.p.x,y0=r.p.y;
	char d0=r.d;

	static int dist[40][40][4];
	static robot pre[40][40][4];
	rep(i,n) rep(j,n) rep(k,4) {
		dist[i][j][k]=INF;
	}
	dist[y0][x0][DIR[d0]]=0;

	// deque<robot> Q;
	// Q.emplace_back(r);
	static robot Q[40*40*4*2];
	int left=40*40*4;
	int right=left;
	Q[right++]=r;
//	while(!Q.empty()){
	while(left<right){
//		robot q=Q.front(); Q.pop_front();
		robot q=Q[left]; left++;
		int x=q.p.x,y=q.p.y;
		int cost=dist[y][x][DIR[q.d]];

		if(q.p==g) continue;

		rep(k,4){
			int x2=(x+dx[k]+n)%n;
			int y2=(y+dy[k]+n)%n;
			char d2=DIRinv[k];
			int cost2=cost;

			if(strchr("RULD",B[y][x])){
				if(DIR[B[y][x]]!=k) continue;
			}
			else{
				if(DIR[q.d]!=k) cost2++;
			}

			if(B[y2][x2]!='#' && dist[y2][x2][DIR[d2]]==INF){
				pre[y2][x2][DIR[d2]]=q;
				dist[y2][x2][DIR[d2]]=cost2;
				if(cost2==cost){
//					Q.emplace_front(point{x2,y2},d2);
					Q[--left]={point{x2,y2},d2};
				}
				else{
//					Q.emplace_back(point{x2,y2},d2);
					Q[right++]={point{x2,y2},d2};
				}
			}
		}
	}

	int k1=0;
	rep(k,4) if(dist[g.y][g.x][k]<dist[g.y][g.x][k1]) k1=k;
	if(dist[g.y][g.x][k1]==INF) return false;

//	vector<robot> path;
	static robot path[40*40];
	int len=0;
	robot q{g,DIRinv[k1]};
	do{
//		path.emplace_back(q);
		path[len++]=q;
		q=pre[q.p.y][q.p.x][DIR[q.d]];
	}while(q!=r);
//	path.emplace_back(r);
//	reverse(path.begin(),path.end());
	path[len++]=r;
	rep(i,len/2) swap(path[i],path[len-i-1]);

	bool updated=false;
//	for(int i=0;i+1<path.size();i++){
	rep(i,len-1){
		if(path[i].d!=path[i+1].d){
			if(B[path[i].p.y][path[i].p.x]==' '){
				B[path[i].p.y][path[i].p.x]=path[i+1].d;
				updated=true;
			}
			else{
				assert(B[path[i].p.y][path[i].p.x]==path[i+1].d);
			}
		}
	}

	return updated;
}

int simulate(){
	int score=0;

	bool vis0[40][40]={};
	for(const robot& r:R){
		int x=r.p.x,y=r.p.y;
		char d=r.d;
		bool vis[40][40]={};
		while(1){
			if(B[y][x]=='#' || vis[y][x]) break;
			vis[y][x]=true;
			if(point{x,y}==g){
				score+=1000;
				break;
			}
			if(B[y][x]!=' ') d=B[y][x];
			x=(x+dx[DIR[d]]+n)%n;
			y=(y+dy[DIR[d]]+n)%n;
		}

		rep(i,n) rep(j,n) vis0[i][j]|=vis[i][j];
	}

	rep(i,n) rep(j,n) {
		if(strchr("RULD",B[i][j])) score-=10;
		if(vis0[i][j]) score++;
	}

	return score;
}

void input(){
	int m,nb;
	scanf("%d%d%d%d%d",&n,&m,&nb,&g.y,&g.x);
	rep(i,n) rep(j,n) B[i][j]=' ';

	R.resize(m);
	rep(i,m){
		char c;
		scanf("%d%d %c",&R[i].p.y,&R[i].p.x,&c);
		R[i].d=c;
	}

	rep(i,nb){
		int bx,by;
		scanf("%d%d",&by,&bx);
		B[by][bx]='#';
	}
}

void print_answer(){
	vector<pair<point,char>> ans;
	rep(i,n) rep(j,n) if(strchr("RULD",B[i][j])) {
		ans.emplace_back(point{j,i},B[i][j]);
	}
	printf("%lu\n",ans.size());
	for(auto a:ans){
		printf("%d %d %c\n",a.first.y,a.first.x,a.second);
	}
}

int main(){
	lint T0=gettime();
	random_device seed_gen;
	mt19937 engine(seed_gen());

	DIR['R']=0;
	DIR['U']=1;
	DIR['L']=2;
	DIR['D']=3;
	DIRinv[0]='R';
	DIRinv[1]='U';
	DIRinv[2]='L';
	DIRinv[3]='D';

	input();

	calc_dist_from_g();

	rep(i,R.size()) if(distg[R[i].p.y][R[i].p.x]==INF) R.erase(R.begin()+i), i--;

	int score_mx=0;
	char B_mx[40][41];

	for(int t=0;;t++){
		if(gettime()-T0>2880000) break;

		rep(i,n) rep(j,n) if(strchr("RULD",B[i][j])) B[i][j]=' ';

		if     (t==0) sort(R.begin(),R.end());
		else if(t==1) sort(R.rbegin(),R.rend());
		else{
			shuffle(R.begin(),R.end(),engine);

			pair<int,int> p[4];
			rep(k,4) p[k]={dx[k],dy[k]};
			shuffle(p,p+4,engine);
			rep(k,4) tie(dx[k],dy[k])=p[k];
			DIR['R']=find(p,p+4,make_pair( 1, 0))-p;
			DIR['U']=find(p,p+4,make_pair( 0,-1))-p;
			DIR['L']=find(p,p+4,make_pair(-1, 0))-p;
			DIR['D']=find(p,p+4,make_pair( 0, 1))-p;
			for(char c:string("RULD")) DIRinv[DIR[c]]=c;
		}

		while(1){
			bool updated=false;
			for(const robot& r:R) if(go(r)) updated=true;
			if(!updated) break;
		}

		int score=simulate();
//		fprintf(stderr,"t = %2d: score = %d\n",t,score);
		if(score>score_mx){
			score_mx=score;
			rep(i,n) rep(j,n) B_mx[i][j]=B[i][j];
		}
	}

	while(1){
		rep(i,n) rep(j,n) B[i][j]=B_mx[i][j];

		bool updated=false;
		rep(i,n) rep(j,n) if(strchr("RULD",B[i][j])) {
			char c=B[i][j];
			B[i][j]=' ';
			int score=simulate();
			if(score>score_mx){
				score_mx=score;
				rep(y,n) rep(x,n) B_mx[y][x]=B[y][x];
				updated=true;
			}
			B[i][j]=c;
		}
		if(!updated) break;
	}

	rep(i,n) rep(j,n) B[i][j]=B_mx[i][j];

	rep(i,n) fprintf(stderr,"%s\n",B[i]);
	fprintf(stderr,"score = %d\n",score_mx);

	print_answer();

	return 0;
}
