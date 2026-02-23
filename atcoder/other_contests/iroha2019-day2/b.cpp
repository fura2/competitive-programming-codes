#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int w,h,a,b,sx,sy,tx,ty;
	cin>>w>>h>>a>>b>>sx>>sy>>tx>>ty;

	bool bs=(sy*w<a*w+(b-a)*sx);
	bool bt=(ty*w<a*w+(b-a)*tx);
	puts(bs==bt?"No":"Yes");

	return 0;
}
