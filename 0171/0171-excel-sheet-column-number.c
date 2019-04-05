int titleToNumber(char* s) {
    int num = 0;
    if(NULL == s)
        return 0;
    int i = 0;
    int temp = 0;
    while(0 != *s)
    {
        temp = toupper(*s) - 'A' + 1;
        num=26 * num + temp;
        s++;
    }
    return num;
    
}