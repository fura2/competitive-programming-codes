#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int i0=max_element(a.begin(),a.end())-a.begin();

	int sum1=0,sum2=0;
	rep(i,n){
		if(i<i0) sum1+=a[i];
		if(i>i0) sum2+=a[i];
	}
	printf("%d\n%d\n",sum1,sum2);

	return 0;
}
