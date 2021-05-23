#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int q; scanf("%d",&q);
	vector<string> want[20];
	rep(_,q){
		int type; scanf("%d",&type);
		if(type==0){
			int id,m; scanf("%d%d",&id,&m); id--;
			want[id].resize(m);
			rep(j,m) cin>>want[id][j];
		}
		else if(type==1){
			string s; cin>>s;
			int i0=-1;
			rep(i,20){
				auto it=find(want[i].begin(),want[i].end(),s);
				if(it!=want[i].end()){
					want[i].erase(it);
					i0=i+1;
					break;
				}
			}
			printf("%d\n",i0);
		}
		else{
			int id; scanf("%d",&id); id--;
			want[id].clear();
		}
	}
	return 0;
}
