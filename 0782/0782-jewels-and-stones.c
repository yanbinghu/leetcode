int numJewelsInStones(char* J, char* S) {
    if(NULL  == J || NULL == S)
        return 0;
    char *je = J;
    char *sa = S;
    int num = 0;
    //char jechar[255] = {0};
    while(0 != *je)
    { 
        sa = S;
        while(0 != *sa )
        {
            if(*je == *sa)
                {
                    num++;
  
                }
            sa++;
        }
        //jechar[*je] = 1;
        je++;
    }
    return num;
}