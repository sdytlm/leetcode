/*Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

1         3     3      2      1
\       /     /      / \      \
3     2     1      1   3      2
/     /       \                 \
2     1         2                 3
*/

class Solution {
public:
    int numTrees(int n) {
        if(n==0)
            return 1;
        int *f = new int[n+1];
        f[0]=1;
        f[1]=1;
        int i;
        // 初始化f[]
        for(i=2;i<=n;i++) {
            f[i] = 0;
        }
        // f(i) = sum(f(k − 1) × f(i − k)) k: from 1 to i
        for(i=2;i<=n;i++) {
            int k;
            for(k=1;k<=i;k++) {
                f[i] += f[k-1]*f[i-k];
            }
        }
        return f[n];
    }
};