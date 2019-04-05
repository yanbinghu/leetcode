int firstUniqChar(char* s) {
    if(NULL == s)
        return -1;
    char *temp =s;
    int tag[26] = {0};
    int i = 0;
    while(0 != *temp)
    {
        tag[*temp-'a']++;
        //printf("%d\n",*temp-'a');
        temp++;
    }
    while(0 != s[i])
    {
        
        if(tag[s[i]-'a'] == 1)
            return i;
        i++;
    }
    return -1;
    
}