#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,q; scanf("%d%d",&n,&q);

	vector<int> row(n),col(n);
	iota(row.begin(),row.end(),0);
	iota(col.begin(),col.end(),0);

	bool tr=false;
	rep(_,q){
		int type; scanf("%d",&type);
		if(type==1){
			int a,b; scanf("%d%d",&a,&b); a--; b--;
			if(!tr) swap(row[a],row[b]);
			else    swap(col[a],col[b]);
		}
		else if(type==2){
			int a,b; scanf("%d%d",&a,&b); a--; b--;
			if(!tr) swap(col[a],col[b]);
			else    swap(row[a],row[b]);
		}
		else if(type==3){
			tr=!tr;
		}
		else{
			int a,b; scanf("%d%d",&a,&b); a--; b--;
			if(!tr) printf("%lld\n",1LL*row[a]*n+col[b]);
			else    printf("%lld\n",1LL*row[b]*n+col[a]);
		}
	}

	return 0;
}
