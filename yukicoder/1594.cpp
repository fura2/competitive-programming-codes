#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,a[12];

bool dfs(int i,int s1,int s2,int s3){
	if(i==n) return s1==s2 && s1==s3;
	return dfs(i+1,s1+a[i],s2,s3)
		|| dfs(i+1,s1,s2+a[i],s3)
		|| dfs(i+1,s1,s2,s3+a[i]);
}

int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);

	puts(dfs(0,0,0,0)?"Yes":"No");

	return 0;
}
