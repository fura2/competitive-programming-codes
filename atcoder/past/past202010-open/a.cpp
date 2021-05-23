#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	pair<int,char> a[3];
	rep(i,3){
		scanf("%d",&a[i].first);
		a[i].second='A'+i;
	}
	sort(a,a+3);
	printf("%c\n",a[1].second);
	return 0;
}
