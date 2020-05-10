int kmpPre(string str)
{
    int n=str.size();
    vi lps(n,0);
    int idx=0,i=1;

    while(i<n)
    {
        if(str[i]==str[idx])
        {
            lps[i]=++idx;
            i++;
        }
        else
        {
            if(idx)
            {
                idx=lps[idx-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }

    return lps[n-1];
}