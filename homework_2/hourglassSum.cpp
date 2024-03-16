int eachHourglassSum(vector<vector<int>> &arr, int i, int j)
{
    int sum = 0;
    int ii = i;
    int jj = j;

    while (ii <= i + 2)
    {
        jj = j;
        while (jj <= j + 2)
        {
           if ((ii == i + 1 && jj == j + 1) || ii != i + 1)
                sum += arr[ii][jj];
            jj++;
        }
        ii++;
    }
    return sum;
}

int hourglassSum(vector<vector<int>> arr)
{
    int sumi = 0;
    int sums[16] = {0};
    int i = 0;
    int j = 0;

    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            sums[sumi] = eachHourglassSum(arr, i, j);
            j++;
            sumi++;
        }
        i++;
    }
    int max_val = sums[0];
    
    for (int i = 1; i < 16; ++i) {
        if (sums[i] > max_val) {
            max_val = sums[i];
        }
    }
    return (max_val);
}
