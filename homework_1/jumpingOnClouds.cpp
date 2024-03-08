int jumpingOnClouds(vector<int> c)
{
    int i = 0;
    int len = c.size();
    int jumps = 0;
    
    while (i < len - 1)
    {
        if (c[i] == 0)
        {
            if (i + 2 < len && c[i + 2] == 0)
                i += 2;
            else
                i++;
            jumps++;
        }
    }
    return jumps;
}

