// Day 3: Origami

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,h,w; scanf("%d%d%d",&n,&w,&h);
	vector<int> t(n),l(n),b(n),r(n);
	rep(i,n) scanf("%d%d%d%d",&l[i],&t[i],&r[i],&b[i]), t[i]--, l[i]--;

	vector<vector<int>> Ev(h+1);
	rep(i,n){
		Ev[t[i]].emplace_back( i+1);
		Ev[b[i]].emplace_back(-i-1);
	}
	rep(y,h+1) sort(Ev[y].begin(),Ev[y].end());

	int mx=0;
	vector<int> a(w);
	rep(y,h+1) for(int id:Ev[y]) {
		if(id>0){
			int i=id-1;
			for(int x=l[i];x<r[i];x++){
				a[x]++;
				mx=max(mx,a[x]);
			}
		}
		else{
			int i=-id-1;
			for(int x=l[i];x<r[i];x++){
				a[x]--;
			}
		}
	}

	int cnt=0;
	vector<int> pre(w);
	a.assign(w,0);
	rep(y,h+1) for(int id:Ev[y]) {
		if(id>0){
			int i=id-1;
			for(int x=l[i];x<r[i];x++){
				a[x]++;
				if(a[x]==mx) pre[x]=y;
			}
		}
		else{
			int i=-id-1;
			for(int x=l[i];x<r[i];x++){
				if(a[x]==mx) cnt+=y-pre[x];
				a[x]--;
			}
		}
	}

	printf("%d\n%d\n",mx,cnt);

	return 0;
}
