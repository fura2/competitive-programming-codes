// Day 1: Ramen

#include <bits/stdc++.h>
#include "ramen.h"

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

void Ramen(int n){
	if(n==1){
		Answer(0,0);
		return;
	}

	int mn,mx;
	if(Compare(0,1)==1) mn=1, mx=0;
	else                mn=0, mx=1;

	for(int i=2;i<n-1;i+=2){
		if(Compare(i,i+1)==1){
			if(Compare( i ,mx)== 1) mx=i;
			if(Compare(i+1,mn)==-1) mn=i+1;
		}
		else{
			if(Compare(i+1,mx)== 1) mx=i+1;
			if(Compare( i ,mn)==-1) mn=i;
		}
	}
	if(n%2==1){
		if(Compare(n-1,mx)== 1) mx=n-1;
		if(Compare(n-1,mn)==-1) mn=n-1;
	}
	Answer(mn,mx);
}
