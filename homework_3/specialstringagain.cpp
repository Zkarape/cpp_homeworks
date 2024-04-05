long substrCount(int n, string s) {
    long count = 0;
    
    for (int i = 0; i < n; ) {
        char current_char = s[i];
        int j = i;
        while (j < n && s[j] == current_char) {
            j++;
        }
        int length = j - i;
        count += (length * (length + 1)) / 2;
        i = j;
    }
    
    for (int i = 1; i < n - 1; ++i) {
        if (s[i - 1] == s[i + 1] && s[i] != s[i - 1]) {
            int length = 1;
            while (i - length >= 0 && i + length < n && s[i - length] == s[i - 1] && s[i + length] == s[i - 1]) {
                count++;
                length++;
            }
        }
    }
    
    return count;
}

