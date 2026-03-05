int minimumMoves(char* s) {
   int l=strlen(s),a=0;
   for(int i=0;i<l;i++){
    if(s[i]=='X'){
        s[i]='0';
       if(i+1<l) s[i+1]='0';
     if(i+2<l)   s[i+2]='0';
        a++;i+=2;
    }
   } 
   return a;
}