int maxSatisfaction(int* satisfaction, int satisfactionSize) {
    for(int i=0;i<satisfactionSize;i++)
    {
        for(int j=i+1;j<satisfactionSize;j++)
        {
            if(satisfaction[i]<satisfaction[j])
            {
                int temp=satisfaction[i];
                satisfaction[i]=satisfaction[j];
                satisfaction[j]=temp;
            }
        }
    }
    int presum=0,res=0;
    for(int i=0;i<satisfactionSize;i++)
    {
        
        presum+=satisfaction[i];
        if(presum<0)
        break;
        res+=presum;
    }
    return res;
}