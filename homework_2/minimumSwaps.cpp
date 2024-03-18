int minimumSwaps(std::vector<int>& arr)
{
    int swaps = 0;
    int n = arr.size();
    
    for (int i = 0; i < n; ++i)
    {
        while (arr[i] != i + 1)
        {
            std::swap(arr[i], arr[arr[i] - 1]);
            ++swaps;
        }
    }
    return swaps;
}
