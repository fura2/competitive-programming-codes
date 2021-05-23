#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n) scanf("%d",&b[i]);

	int score[101]={};
	rep(i,n) score[b[i]]+=a[i];
	puts(score[0]>=*max_element(score+1,score+101)?"YES":"NO");

	return 0;
}
