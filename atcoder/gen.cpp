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
}

int main(int argc,char** argv){
	int q=atoi(argv[1]);
	printf("%d\n",q);
	rep(id,q) generate(id);
	return 0;
}
