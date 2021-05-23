#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m,h,k; scanf("%d%d%d%d",&n,&m,&h,&k);
	vector<int> score(n);
	rep(x,n) scanf("%d",&score[x]);
	vector<pair<int,int>> bar(m);
	rep(i,m) scanf("%d%d",&bar[i].second,&bar[i].first), bar[i].second--;

	sort(bar.begin(),bar.end());

	vector<int> p(n),p_inv;
	iota(p.begin(),p.end(),0);
	p_inv=p;
	rep(i,m){
		int x=bar[i].second;
		swap(p[p_inv[x]],p[p_inv[x+1]]);
		swap(p_inv[x],p_inv[x+1]);
	}

	int sum=0;
	rep(x,k) sum+=score[p[x]];

	int ans=sum;
	vector<int> q(n),q_inv;
	iota(q.begin(),q.end(),0);
	q_inv=q;
	rep(i,m){
		int x=bar[i].second;

		int tmp=sum;
		if(q_inv[x]<k){
			tmp+=score[p[q_inv[x+1]]]-score[p[q_inv[x]]];
		}
		if(q_inv[x+1]<k){
			tmp+=score[p[q_inv[x]]]-score[p[q_inv[x+1]]];
		}
		ans=min(ans,tmp);

		swap(q[q_inv[x]],q[q_inv[x+1]]);
		swap(q_inv[x],q_inv[x+1]);
	}
	printf("%d\n",ans);

	return 0;
}
