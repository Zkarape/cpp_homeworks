int countingValleys(int steps, string path)
{
    int i = 0;
    int len = path.length();
    int gained_ups_and_downs = 0;
    int valley = 0;
    
    while(i < len)
    {
        if (path[i] == 'U')
            gained_ups_and_downs++;
        else if (path[i] == 'D')
            gained_ups_and_downs--;
        else
        {
            std::cout << "Enter only U and D in a string" << std::endl;
            return 0;
        }
        if (gained_ups_and_downs == 0 && path[i] == 'U')
            valley++;
        i++;
    }
    return valley;
}

