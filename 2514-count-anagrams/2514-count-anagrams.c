#define MOD 1000000007
long pow_mod(long x, int n, int mod) {
    long res = 1L;
    while (n > 0) {
        if (n % 2 == 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n /= 2;
    }  return res;
}
int countAnagrams(char* s) {
    long ans = 1, mul = 1;
    char* token = strtok(s, " "); 
    while (token != NULL) {
        int cnt[26] = {0};
        int len = strlen(token);     
        for (int i = 1; i <= len; ++i) {
            int c = token[i - 1] - 'a';
            ++cnt[c];
            ans = ans * i % MOD;
            mul = mul * cnt[c] % MOD;
        }      
        token = strtok(NULL, " ");
    }
    return ans * pow_mod(mul, MOD - 2, MOD) % MOD;
}
