class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int index = 0;
        int i;
        int count = 1;
        if ((n==0) || (n==1))
            return n;
        for(i=1;i<n;i++)
        {
            if(A[i]!=A[index])
            {
                A[++index] = A[i];
                count = 1;
            }
            else // A[i] == A[index]
            {
                if(count < 2)
                {
                    A[++index] = A[i];
                    count++;
                }
                else
                    count++;
            }
        }
        return index+1;
    }
    
};
