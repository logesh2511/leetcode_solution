

char*** partition(char* s, int* returnSize, int** returnColumnSizes) 
{
    char ***result;
    char **subStrings;
    char *data;
    int n;
    int i, j, k, l;
    int m;  //really crazy trick
    bool allPalendrome;
    int onesCount;

    *returnSize = 0;

    n = strlen(s);

    m = 0;

    result = malloc(sizeof (char **) * 1<<(n-1) + 1);  //there can be a maximum of 1<<(n-1) partitions
    subStrings = malloc(640000*sizeof(char *));//malloc(sizeof (char*) * (1<<(n-1)) * n + 6);
    data = malloc(6400000*sizeof(char)); //malloc((1<<(n-1)) * 2 * n * sizeof(char)); //each string is of at most length 2n 
    *returnColumnSizes = malloc(sizeof(int) * 1<<(n-1));

    for (i=0; i< (1<<n-1); i++)
    {
        k=0;
        onesCount = 0;

        allPalendrome = true;

        subStrings[m] = data;
        
        for (j=0; j<n; j++)
        {
            subStrings[m][k] = s[j];

            data++;

            if ( ((1<<j) & i)  || (j==n-1) )
            {
                subStrings[m][k+1] = NULL;
                data++;


                for (l=0; l<k; l++, k--)
                {
                    if (subStrings[m][l]!=subStrings[m][k])
                    {
                        
                        allPalendrome = false;
                        break;  //goto would work better
                    }
                }
                //we have a valid substring palendrome
                onesCount++;
                
                k=0;
                m++;
                subStrings[m] = data;
                }
            else
            {
                k++;
            }

            if (allPalendrome == false)
            {
                break;  //increment i
            }


        }

        if (allPalendrome == false)
        {
            continue;  //increment i
        }

        //i is a palindrome partition
        (*returnColumnSizes)[*returnSize] = onesCount;

        

        result[*returnSize] = &(subStrings[m - onesCount]);
        
        (*returnSize)++;
    }

    return result;
}