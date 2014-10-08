class Solution {
public:
    void sortColors(int A[], int n) {
        if (n==0 || n==1)
            return ;
        int redIndex = 0;   // 指向最后一个红色的位置
        int blueIndex = n-1; // 指向第一个一个蓝色的位置
        int i=0;
        while(i<=blueIndex) {
            switch (A[i]) {
                case 0:
                    swap(A[i++],A[redIndex++]);  // swap A[i] and A[redIndex] then increase i and redIndex
                    break;
                case 2:
                    swap(A[i],A[blueIndex--]);   // swap A[i] and A[blueIndex] but only decrease blueIndex, because we need to check the new A[i]
                    break;
                default:
                    i++;
                    
            }
        }
        return ;
    }
};

