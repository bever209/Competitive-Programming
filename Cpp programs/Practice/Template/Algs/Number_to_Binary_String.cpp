string to_bin(long long x)
{
    if(x == 0)
        return "";
    else
    {
        string s = to_bin(x / 2);
        s.push_back(char('0' + x % 2));
        return s;
    }
}