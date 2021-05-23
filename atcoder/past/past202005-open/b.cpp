#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m,q; scanf("%d%d%d",&n,&m,&q);

	vector<int> score(m,n);
	vector<vector<bool>> solved(n,vector<bool>(m));
	rep(_,q){
		int type,x; scanf("%d%d",&type,&x); x--;
		if(type==1){
			int res=0;
			rep(y,m) if(solved[x][y]) res+=score[y];
			printf("%d\n",res);
		}
		else{
			int y; scanf("%d",&y); y--;
			score[y]--;
			solved[x][y]=true;
		}
	}

	return 0;
}
