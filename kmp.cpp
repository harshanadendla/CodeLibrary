#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

void pre(vi &lps,string pat) {
	int m=pat.size();
	int idx=0,i=1;
	while (i<m) {
		if (pat[idx] == pat[i]) {
			lps[i]=idx;
			i++;
			idx++;
		} else {
			if (idx) {
				idx=lps[idx-1]+1;
			} else {
				i++;
			}
		}
	}
	return;
}

bool knuthMorrisPrattAlgorithm(string str, string pat) {
	int n=str.size();
	int m=pat.size();
	vi lps(m,-1);
	pre(lps,pat);
	int i=0,j=0;
	while (i+m-j<=n) {
		if(pat[j]==str[i]) {
			i++;
			j++;
			if (j==m) {
				return true;
			}
		} else {
			if (j>0) {
				j=lps[j-1]+1;
			} else {
				i++;
			}
		}
	}
	return false;
}
