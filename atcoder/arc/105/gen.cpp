/*
	first argument: number of testcases
*/

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

random_device seed_gen;
mt19937 rng(seed_gen());

void generate(int id){
	int n=5;
	int d[30][30]={};
	vector<pair<int,int>> E;
	rep(i,n) rep(j,i) {
		d[i][j]=d[j][i]=(rng()%8==0?1:0);
		if(d[i][j]==1) E.emplace_back(j,i);
	}

	printf("%d %u\n",n,E.size());
	for(auto [u,v]:E) printf("%d %d\n",u+1,v+1);
}

int main(int argc,char** argv){
	int q=atoi(argv[1]);
	printf("%d\n",q);
	rep(id,q) generate(id);
	return 0;
}
