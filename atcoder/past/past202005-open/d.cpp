#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string P[5]={
		".###..#..###.###.#.#.###.###.###.###.###.",
		".#.#.##....#...#.#.#.#...#.....#.#.#.#.#.",
		".#.#..#..###.###.###.###.###...#.###.###.",
		".#.#..#..#.....#...#...#.#.#...#.#.#...#.",
		".###.###.###.###...#.###.###...#.###.###."};

	int n; cin>>n;
	string B[5];
	rep(i,5) cin>>B[i];

	rep(i,n){
		rep(d,10){
			bool ok=true;
			rep(y,5) if(B[y].substr(1+4*i,3)!=P[y].substr(1+4*d,3)) ok=false;
			if(ok) printf("%d",d);
		}
	}
	puts("");

	return 0;
}
