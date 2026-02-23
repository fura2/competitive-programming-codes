#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d%d",&a[i],&b[i]);

	int asum=accumulate(a.begin(),a.end(),0);
	int bsum=accumulate(b.begin(),b.end(),0);
	if(asum!=bsum){
		puts("invalid");
		return 0;
	}

	bool buf[2][80001]={};
	bool* curr=&buf[0][40000];
	bool* next=&buf[1][40000];
	curr[0]=true;
	rep(i,n){
		for(int x=-bsum;x<=asum;x++) next[x]=false;
		for(int x=asum-a[i];x>=-bsum;x--) next[x+a[i]]|=curr[x];
		for(int x=-bsum+b[i];x<=asum;x++) next[x-b[i]]|=curr[x];
		swap(curr,next);
	}
	puts(curr[0]?"valid":"invalid");

	return 0;
}
