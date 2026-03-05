char* addBinary(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int maxlen = len_a > len_b ? len_a : len_b;


    char* result = (char*)malloc((maxlen + 2) * sizeof(char));
    result[maxlen + 1] = '\0';


    int carry = 0;
    int i = len_a - 1;
    int j = len_b - 1;
    int k = maxlen;


    while (i >= 0 || j >= 0) {
        int sum = carry;
        if (i >= 0) {
            sum += (a[i] - '0');
            i--;
        }
        if (j >= 0) {
            sum += (b[j] - '0');
            j--;
        }
        result[k] = (sum % 2) + '0';
        carry = sum / 2;
        k--;
    }


    if (carry == 1) {
        result[0] = '1';
        return result;
    } else {
        return result + 1;
    }
}
