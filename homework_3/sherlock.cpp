void fillArr(vector<int> &arr, string &s)
{
    int i = -1;
    int len = s.length();
    
    while (++i < len)
        arr[s[i] - 97]++;
}

string isValid(string s) {
  int i = 0;
  int j = 0;
  int max_count = 0;
  int min_count = INT_MAX;
  int diff_count = 0;
  int diff = 0;
  vector<int> arr(26, 0);

  fillArr(arr, s);

  for (int freq : arr)
  {
    max_count = max(max_count, freq);
    if (freq)
        min_count = min(min_count, freq);
  }
  if (max_count == min_count)
  {
    return "YES";
  }
  diff = max_count - min_count;
  if (diff == 1 || diff == -1)
  {
    for (int count : arr)
    {
      if (abs(count - max_count) == 0)
        diff_count++;
    }
    return diff_count <= 1 ? "YES" : "NO";
  }
  return "NO";
}

