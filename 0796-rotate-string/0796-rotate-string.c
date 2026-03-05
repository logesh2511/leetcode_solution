bool rotateString(char* s, char* goal) {
    int len=strlen(s),len2=strlen(goal);

        int i,j;
        for(i=0;i<len;i++){
            if(strcmp(s,goal)==0)
                return true;

            char temp=s[0];
            for(j=0;j<len-1;j++)
                s[j]=s[j+1];

            s[len-1]=temp;
        }
    
    return false;
}