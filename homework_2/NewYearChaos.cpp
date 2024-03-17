void minimumBribes(std::vector<int>& q)
{
    for (int i = 0; i < q.size(); ++i)
    {
        if (q[i] > i + 1 + 2)
        {
            std::cout << "Too chaotic" << std::endl;
            return;
        }
    }

    int cnt = 0;        
    for (int i = 0; i < q.size(); ++i)
    {    
        for (int j = i + 1; j < q.size(); ++j)
        {
            if (q[i] > i + 1)
            {
                std::swap(q[i], q[j]);
                ++cnt;
            }
            if (q[i] == i + 1) break;
        }
    }
    std::cout << cnt << std::endl;
}
