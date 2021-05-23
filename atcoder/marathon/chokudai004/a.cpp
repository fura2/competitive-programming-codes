#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

random_device seed_gen;
mt19937 rng(seed_gen());

int main(){
	int n,b[3]; scanf("%d",&n);
	rep(i,3) scanf("%d",&b[i]);
	vector l(n,vector(n,0));
	vector r(n,vector(n,0));
	rep(i,n) rep(j,n) scanf("%d",&l[i][j]);
	rep(i,n) rep(j,n) scanf("%d",&r[i][j]);

	vector b_table(50,-1);
	rep(k,3) b_table[b[k]]=k;

	vector a(n,vector(n,0));
//	rep(i,n) rep(j,n) a[i][j]=l[i][j]+rng()%(r[i][j]-l[i][j]+1);
	rep(i,n) rep(j,n) a[i][j]=l[i][j];

	auto calc_score=[&](){
		int c[3]={};
		rep(i,n) rep(j,n) {
			if(b_table[a[i][j]]!=-1) c[b_table[a[i][j]]]++;
			int sum=a[i][j];
			for(int x=i+1;x<n;x++){
				sum+=a[x][j];
				if(sum>b[2]) break;
				if(b_table[sum]!=-1) c[b_table[sum]]++;
			}
			sum=a[i][j];
			for(int y=j+1;y<n;y++){
				sum+=a[i][y];
				if(sum>b[2]) break;
				if(b_table[sum]!=-1) c[b_table[sum]]++;
			}
		}
		return c[0]*b[0]+c[1]*b[1]+c[2]*b[2];
	};

	int score=calc_score();
	// 1 マスを変更
	while(1){
		bool changed=false;
		rep(i,n) rep(j,n) {
			for(int x=l[i][j];x<=r[i][j];x++) if(x!=a[i][j]) {
				int pre=a[i][j];
				a[i][j]=x;
				int tmp=calc_score();
				if(tmp>score){
					score=tmp;
					changed=true;
				}
				else{
					a[i][j]=pre;
				}
			}
		}
		if(!changed) break;
	}
	// 縦に連続する 2 マスを変更
	while(1){
		bool changed=false;
		rep(i,n-1) rep(j,n) {
			for(int x1=l[i][j];x1<=r[i][j];x1++) if(x1!=a[i][j]) {
				for(int x2=l[i+1][j];x2<=r[i+1][j];x2++) if(x2!=a[i+1][j]) {
					int pre1=a[i][j];
					int pre2=a[i+1][j];
					a[i][j]=x1;
					a[i+1][j]=x2;
					int tmp=calc_score();
					if(tmp>score){
						score=tmp;
						changed=true;
					}
					else{
						a[i][j]=pre1;
						a[i+1][j]=pre2;
					}
				}
			}
		}
		if(!changed) break;
	}

	rep(i,n) rep(j,n) printf("%d%c",a[i][j],j<n-1?' ':'\n');

	return 0;
}
