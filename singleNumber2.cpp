/* Given an array of integers, every element appears three times except for one. Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 *
 */

class Solution {

public:
    int singleNumber(int A[], int n) {
		int one=0;		// 1 个数，但是每一位都用来记录a[0]...a[N]中每个元素第[0]到[32]位是否出现1次
		int two=0;   // 1个数，同理one， 但是这个数的每一位记录的是a[]中每个元素的0-32位是否出现了两次
		int i;
		for(i=0;i<n;i++) {
			one = (one^A[i]) & ~two;  // 保留/去掉 新来的A[i]，若A[i]没出现过肯定保留，若出现过则被去掉, 同时仅保留不在two里面的位
			two = (two^A[i]) & ~one;  // 去掉/保留新来的A[i], 若A[i]出现了并且在one中没有出现，则保留，否则去掉
		}
		return one;
				        

    }

};
