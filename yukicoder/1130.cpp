#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; scanf("%d%d",&h,&w);
	vector<int> a(h*w);
	rep(i,h*w) scanf("%d",&a[i]);

	sort(a.begin(),a.end());

	rep(i,h) rep(j,w) printf("%d%c",a[i*w+j],j<w-1?' ':'\n');

	return 0;
}
