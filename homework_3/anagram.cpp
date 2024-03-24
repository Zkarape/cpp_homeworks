void fillArr(vector<int> &arr, string s)
{
    int i = 0;
    
    while (i < s.length())
    {
        arr[s[i] - 97]++;
        i++;
    }
	printVector(arr);
}

int checkArr(vector<int> &arra, vector<int> &arrb)
{
    int res = 0;

    for (int i = 0; i < 26; i++)
    {
	if (arra[i] > arrb[i])
	    res += arra[i] - arrb[i];
	else if (arra[i] < arrb[i])
	    res += arrb[i] - arra[i];
    }
    return res;
}

int makeAnagram(string a, string b)
{
    vector<int> arra(26, 0);
    vector<int> arrb(26, 0);
    
    fillArr(arra, a);
    fillArr(arrb, b);
    return checkArr(arra, arrb);
}
