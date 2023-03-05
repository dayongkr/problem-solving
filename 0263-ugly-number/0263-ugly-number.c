bool isUgly(int n){
    int pn[3]={2,3,5};
    return n < 1? 0 : find(n, pn);
}

int find(int n, int* pn) {
    if(n<= 1) {
        return n;
    } else {
        for(int i = 0; i < 3; i++) {
            if(n % pn[i] == 0) {
                return find(n / pn[i], pn);
            }
        }
        return 0;
    }
}