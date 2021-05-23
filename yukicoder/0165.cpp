#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,ub; scanf("%d%d",&n,&ub);
	vector<int> x(n),y(n),a(n);
	rep(i,n) scanf("%d%d%d",&x[i],&y[i],&a[i]);

	vector<int> X=x,Y=y;
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());
	sort(Y.begin(),Y.end());
	Y.erase(unique(Y.begin(),Y.end()),Y.end());
	rep(i,n){
		x[i]=lower_bound(X.begin(),X.end(),x[i])-X.begin();
		y[i]=lower_bound(Y.begin(),Y.end(),y[i])-Y.begin();
	}

	int cum1[401][401]={};
	int cum2[401][401]={};
	rep(i,n){
		cum1[y[i]+1][x[i]+1]++;
		cum2[y[i]+1][x[i]+1]+=a[i];
	}
	rep(i,Y.size()) rep(j,X.size()) {
		cum1[i+1][j+1]+=cum1[i+1][j]+cum1[i][j+1]-cum1[i][j];
		cum2[i+1][j+1]+=cum2[i+1][j]+cum2[i][j+1]-cum2[i][j];
	}

	int ans=0;
	rep(i,Y.size()) for(int j=i+1;j<=Y.size();j++) {
		int seq1[401]={};
		int seq2[401]={};
		rep(k,X.size()){
			seq1[k+1]=cum1[j][k+1]-cum1[i][k+1];
			seq2[k+1]=cum2[j][k+1]-cum2[i][k+1];
		}

		int r=0;
		rep(l,X.size()){
			while(r<X.size() && seq2[r]-seq2[l]<=ub) r++;
			if(seq2[r]-seq2[l]<=ub) ans=max(ans,seq1[r]-seq1[l]);
			else                    ans=max(ans,seq1[r-1]-seq1[l]);
		}
	}
	printf("%d\n",ans);

	return 0;
}
