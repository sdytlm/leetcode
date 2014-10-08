class Solution{
	public:
		int reverse(int x)
		{
			int pos;
			pos = x>0? 1 : -1;
			x = x>0? x : -x;
			int result = 0;
			while(x>0)
			{
				int digit = x % 10;
				result = digit+10*result;
				x = x/10;
			}
			if (result < 0)
			  return -1;
			else if(pos==-1)
			  return -1*result;
			else
			  return result;

		}
