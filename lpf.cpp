int lpf[N];

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
}