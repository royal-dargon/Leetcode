int lengthOfLongestSubstring(char * s){
    int lenth = strlen(s);
    int i,k;
    int max = 0;
    for(i = 0;i < lenth;i ++)
    {
        for(k = i+1;k <= lenth;k ++)
        {
            if(canPlace(s,i,k))
            {
				max = (k - i) > max ? (k - i) : max;
			}
			else
			{
            	max = (k - i) > max ? (k - i) : max;
				break;
            }
        }
    }
    return max;
}

int canPlace(char *s,int j,int i)
{
    int k;
    for(k = j;k < i;k ++)
    {
        if(s[k] == s[i])
            return 0;
    }
    return 1;
}