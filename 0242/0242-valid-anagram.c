int isAnagram(char* s, char* t) {
    if(NULL == s ||  NULL == t)
        return false;
    
    /*记录频率，s的字符串频率加1，t字符串频率减
    查看最终频率*/
    int tag[128] = {0};
    int index = 0;
    while(0 != *s && 0 !=*t)
    {
        index = *s;
        tag[index] +=1;
        index = *t;
        tag[index]-=1;
        s++;
        t++;
    }
    int i = 0;
    for(;i<128;i++)
    {
        if(tag[i] != 0)
            return false;
    }
    if(0 == *s && 0 == *t )
        return true;
    return false;
    
}