#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int cnt[4]={};
	rep(i,n) cnt[min(a[i],3)]++;

	if(cnt[3]>=1 || cnt[2]>=2){
		puts("B");
	}
	else{
		puts(cnt[1]%2==1?"A":"B");
	}

	return 0;
}
