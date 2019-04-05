char* reverseString(char* s) {
    if (NULL == s)
    {
        return;
    }
    int len = strlen(s);
    int loop = 0;
    char temp = 0;
    for(loop = 0; loop < len/2;loop++)
    {
        temp = *(s+loop);
        *(s+loop) = *(s+(len-1-loop));
        *(s+(len-1-loop)) = temp;
    }
    return s;
}