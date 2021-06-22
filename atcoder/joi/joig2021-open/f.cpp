#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int h,w,s; scanf("%d%d%d",&h,&w,&s);
	vector B(h,vector(w,0));
	rep(i,h) rep(j,w) scanf("%d",&B[i][j]), B[i][j]--;

	int m=256;
	vector<int> t(m,INF),l(m,INF),b(m,-INF),r(m,-INF);
	rep(i,h) rep(j,w) {
		t[B[i][j]]=min(t[B[i][j]],i);
		l[B[i][j]]=min(l[B[i][j]],j);
		b[B[i][j]]=max(b[B[i][j]],i+1);
		r[B[i][j]]=max(r[B[i][j]],j+1);
	}

	vector<int> ord_t(m),ord_b(m);
	iota(ord_t.begin(),ord_t.end(),0);
	sort(ord_t.begin(),ord_t.end(),[&](int c1,int c2){ return t[c1]<t[c2]; });
	iota(ord_b.begin(),ord_b.end(),0);
	sort(ord_b.begin(),ord_b.end(),[&](int c1,int c2){ return b[c1]<b[c2]; });

	int ans=0;
	rep(c1,m) rep(c2,m) if(l[c1]<r[c2]) {
		int len=s/(r[c2]-l[c1]);
		if(len==0) continue;

		vector<int> X1,X2;
		for(int c:ord_t) if(t[c]!=INF && l[c1]<=l[c] && r[c]<=r[c2] && b[c]-t[c]<=len) X1.emplace_back(t[c]);
		for(int c:ord_b) if(t[c]!=INF && l[c1]<=l[c] && r[c]<=r[c2] && b[c]-t[c]<=len) X2.emplace_back(b[c]);
		int k=X1.size();

		for(int i1=0,i2=0;i1<k;i1++){
			while(i2<k && X2[i2]-X1[i1]<=len) i2++;
			ans=max(ans,i2-i1);
		}
	}

	ans*=-1;
	rep(c,m) if(t[c]!=INF) ans++;

	printf("%d\n",ans);

	return 0;
}
