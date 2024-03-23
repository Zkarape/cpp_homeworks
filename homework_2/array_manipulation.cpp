long arrayManipulation(int n, vector<vector<int> > queries)
{
    vector<long> arr(n, 0);
    for (int i = 0; i < queries.size(); ++i) 
    {
        int a = queries[i][0] - 1;
        int b = queries[i][1] - 1;
        int k = queries[i][2];
        arr[a] += k;
        if (b + 1 < n)
            arr[b + 1] -= k;
    }

    long max_val = 0;
    long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        max_val = max(max_val, sum);
    }

    return max_val;
}
