#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint choose[30][30]={};
	rep(i,30) choose[i][0]=1;
	rep(i,29) rep(j,i+1) choose[i+1][j+1]=choose[i][j]+choose[i][j+1];

	lint num[30]={};
	rep(len,30){
		for(int five=3;five<=len;five+=3){
			num[len]+=choose[len-1][five-1];
		}
	}

	int n; scanf("%d",&n);
	n--;

	int len;
	for(len=0;n>=num[len];len++) n-=num[len];

	int m=len/3;
	vector seq(m,vector(len,3));
	rep(i,m) rep(j,3*(i+1)) seq[i][len-1-j]=5;

	vector<bool> over(m);
	while(1){
		int idx=-1;
		rep(i,m) if(!over[i] && (idx==-1 || seq[idx]>seq[i])) idx=i;
		assert(idx!=-1);
		if(n==0){
			rep(j,len) printf("%d",seq[idx][j]);
			puts("");
			break;
		}
		over[idx]=!next_permutation(seq[idx].begin(),--seq[idx].end());
		n--;
	}

	return 0;
}
