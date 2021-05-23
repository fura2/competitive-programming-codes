#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

random_device seed_gen;
mt19937 rng(seed_gen());

int d,c[26],a[365][26];

int score[26],last[26],t[365];

int calc_score(){
	return accumulate(score,score+26,0);
}

void update(int x,int t2){
	int t1=t[x];
	t[x]=t2;
	score[t1]=last[t1]=0;
	score[t2]=last[t2]=0;
	rep(i,d){
		if(t[i]==t1 || t[i]==t2){
			score[t[i]]+=a[i][t[i]];
			last[t[i]]=i+1;
		}
		score[t1]-=c[t1]*(i+1-last[t1]);
		score[t2]-=c[t2]*(i+1-last[t2]);
	}
}

int main(){
	scanf("%d",&d);
	rep(j,26) scanf("%d",&c[j]);
	rep(i,d) rep(j,26) scanf("%d",&a[i][j]);

	// greedy
	rep(i,d){
		int j_max=0;
		for(int j=1;j<26;j++) if(a[i][j_max]<a[i][j]) j_max=j;
		t[i]=j_max;
		score[t[i]]+=a[i][t[i]];
		last[t[i]]=i+1;
		rep(j,26) score[j]-=c[j]*(i+1-last[j]);
	}

	int score_curr=calc_score();

	rep(k,10000){
		int x=k%d;
		rep(t2,26) if(t[x]!=t2) {
			int t1=t[x];
			update(x,t2);

			int score_tmp=calc_score();
			if(score_tmp>score_curr){
				score_curr=score_tmp;
				break;
			}
			else{
				update(x,t1);
			}
		}
	}

	rep(i,d) printf("%d\n",t[i]+1);

	return 0;
}
