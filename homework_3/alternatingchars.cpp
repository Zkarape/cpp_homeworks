int alternatingCharacters(string s)
{
    int i = -1;
    int res = 0;
    int len = s.length();

    while (++i < len)
        if (s[i] == s[i + 1])
            res++;
    return res;
}
