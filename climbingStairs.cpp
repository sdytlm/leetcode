/*
 You are climbing a stair case. It takes n steps to reach to the top.
 Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

class Solution {
public:
    int climbStairs(int n) {
        int *f = new int[n+1];
        f[0]=1;
        f[1]=1;
        f[2]=2;
        int i;
        for(i=3;i<=n;i++) {
            f[i] = f[i-1]+f[i-2];
        }
        return f[n];
    }
};