/* Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 *
 * Some examples:
 *   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *     ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<string> s;
			string op = "+-*/";
			int i;
			int result;
			for(i=0;i<tokens.size();i++) {
				string::size_type pos = op.find(tokens[i]);
				if(pos==string::npos) { // tokens[i] is a number
					s.push(tokens[i]);
				}
				else {  // tokens[i] is a operator
					// Find the operand 
					string tmp = s.top();
					s.pop();
					int right = atoi(tmp.c_str());
					tmp = s.top();
					s.pop();
					int left = atoi(tmp.c_str());

					if (tokens[i] == "+") {
						result = left+right;
						string newVal = std::to_string(result);
						s.push(newVal);
					}
					if(tokens[i] == "-") {
						result = left-right;
						string newVal = std::to_string(result);
						s.push(newVal);
					}
					if(tokens[i] == "*") {
						result = left*right;
						string newVal = std::to_string(result);
						s.push(newVal);
					}
					if(tokens[i] == "/") {
						result = left/right;
						string newVal = std::to_string(result);
						s.push(newVal);
					}
				}

			}
			return atoi(s.top().c_str());
    }
};
