int sockMerchant(int n, vector<int> ar)
{
    int i = 0;
    int pairs = 0;
    int count = 1;
    
    std::sort(ar.begin(), ar.end());
    while (i < n - 1)
    {
        count = 1;
        while (i < n - 1 && ar[i] == ar[i + 1])
        {
            count++;
            ++i;
        }
        pairs += count / 2;
        ++i;
    }
    return pairs;  
}

