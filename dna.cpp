int lpf[N];
map<int,vi> dna;

void pre() {
    for (int i=1;i<N;i++) {
        lpf[i]=i;
    }

    for (int i=4;i<N;i+=2) {
        lpf[i]=2;
    }

    for (int i=3;i*i<N;i+=2) {
        if (lpf[i]==i) {
            for (int j=i*i;j<N;j+=i) {
                if (lpf[j]==j) {
                    lpf[j]=i;
                }
            }
        }
    }

    for (int i=1;i<N;i++) {
        if (floor(sqrt(i)) == ceil(sqrt(i))) {
            dna[i].pb(1);
            continue;
        }
        map<int,int> m;
        int j=i;
        while (j!=1) {
            m[lpf[j]]++;
            j/=lpf[j];
        }
        for (auto it=m.begin();it!=m.end();it++) {
            int val=it->s;
            if (val%2) {
                dna[i].pb(it->f);
            }
        }
    }
}