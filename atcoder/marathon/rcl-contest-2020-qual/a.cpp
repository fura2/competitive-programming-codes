#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

random_device seed_gen;
mt19937 rng(seed_gen());

int n,w,color[1000],v[1000];

int simulate(const vector<int>& seq){
	static int B[8][1000],idx[8];
	rep(x,w) idx[x]=0;
	rep(i,n) B[seq[i]][idx[seq[i]]++]=i;

	int height=*min_element(idx,idx+w);

	int score=0;
	rep(y,height){
		int sum[6]={};
		rep(x,w) sum[color[B[x][y]]]+=v[B[x][y]];
		score+=*max_element(sum,sum+6);
	}
	return score;
}

int main(){
	auto start=std::chrono::system_clock::now();

	scanf("%d%d%*d%*d",&n,&w);
	rep(i,n) scanf("%d%d",&color[i],&v[i]);

	const int T=5;
	vector<int> seq(n);

	int idx=0,i0=0;
	while(idx<n){
		int next[6]={n,n,n,n,n,n};
		rep(c,6){
			int cnt=0;
			for(int i=idx;i<n;i++) if(color[i]==c) {
				cnt++;
				if(cnt==w-T){
					next[c]=i;
					break;
				}
			}
		}

		int c_next=min_element(next,next+6)-next;
		if(next[c_next]==n){
			int i=0;
			while(idx<n){
				seq[idx++]=T+i;
				i=(i+1)%(w-T);
			}
		}
		else{
			int i=0;
			while(1){
				if(color[idx]==c_next){
					seq[idx++]=T+i;
					i++;
					if(i==w-T) break;
				}
				else{
					seq[idx++]=i0;
					i0=(i0+1)%T;
				}
			}
		}
	}

	int hist[8]={};
	rep(i,n) hist[seq[i]]++;
	int hist_min=*min_element(hist,hist+w);

	vector<int> I;
	int cnt[8]={};
	rep(i,n){
		cnt[seq[i]]++;
		if(cnt[seq[i]]>hist_min) I.emplace_back(i);
	}
	for(int i:I){
		if(count(hist,hist+w,n/8)==w) break;
		int x=min_element(hist,hist+w)-hist;
		hist[seq[i]]--;
		hist[x]++;
		seq[i]=x;
	}

	int best=simulate(seq);

	for(int t=0;;t++){
		if(t%20==0){
			auto now=std::chrono::system_clock::now();
			if(std::chrono::duration_cast<std::chrono::milliseconds>(now-start).count()>1990) break;
		}

		int i=rng()%n;
		int d=rng()%100+1;
		int j=(i+d<n?i+d:i-d);

		swap(seq[i],seq[j]);

		int score=simulate(seq);
		if(score>best){
			best=score;
		}
		else{
			swap(seq[i],seq[j]);
		}
	}

	rep(i,n) printf("%d\n",seq[i]);

	return 0;
}
