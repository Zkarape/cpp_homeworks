long repeatedString(string s, long n)
{
    long quotient = 0;
    long i = -1;
    long len = s.length();
    long retval = 0;
    long count = 0;
    
    while (++i < len)
        if (s[i] == 'a')
            count++;
    retval += (n / len) * count;
    quotient = n % len;
    i = -1;
    while (++i < quotient)
    {
        if (s[i] == 'a')
            retval++;
    }
    return (retval);
}

