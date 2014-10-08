/* Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 *
 */

class Solution {
public:
    bool isValid(string s) {
        string leftPar = "({[";
		string rightPar = ")}]";
		
		stack<char> st;
		for(string::iterator p = s.begin(); p!=s.end();p++) {
			string::size_type pos = leftPar.find(*p);
			string::size_type pos1 = rightPar.find(*p);
			if(pos==string::npos && pos1==string::npos)  // p is not one of ({[ or )}] 
			  continue;
			if(pos!=string::npos) { // p is in ({[
				st.push(*p);  // push p in stack
				continue;
			}
			if(pos1!=string::npos) { // p is in )}]
				if(st.empty())
				  return false;
				if(pos1==0 && st.top() == '(') {    // ()
				  st.pop();
				  continue;
				}
				else if (pos1==1 && st.top() == '{') { // {}
				    st.pop();
				    continue;
				}
				else if (pos1==2 && st.top() == '[') { // []
				    st.pop();
				    continue;
				}
				else
				  return false;
				  
			}

		}
		if(st.empty()==1)
		    return true;
		else
		    return false;
    }
};
