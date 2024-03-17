vector<int> rotLeft(vector<int> a, int d)
{
    int i = 0;
    int movingItem = 0;
    int size = a.size();
    
    while (d)
    {
        movingItem = a[0];
        i = -1;
        while (++i < size)
            a[i] = a[i + 1];
        a[size - 1] = movingItem;
        --d;
    }
    return a;
}
