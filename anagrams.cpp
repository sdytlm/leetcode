/*
 * Given an array of strings, return all groups of strings that are anagrams.
 *
 * Note: All inputs will be in lower-case.
 */

class Solution {

public:
		vector<string> result;
	    vector<string> anagrams(vector<string> &strs) {
			if(strs.empty())
			  return result;
			int i;
			unordered_map<string, vector<string> > hash;
			for(i=0;i<strs.size();i++) {
				string tmp = strs[i];
				sort(tmp.begin(),tmp.end());  // 把字符串按字母顺序排好
				if(hash.find(tmp)!=hash.end()){ // find an anagram
					hash[tmp].push_back(strs[i]);
				}
				else {
					hash.insert(make_pair(tmp,vector<string>(1,strs[i]))); // 若hashtable没有这个单词，则产生一个新的映射
					}
			
			}

			// 在hash里找到重复的然后插入result
		    unordered_map<string,vector<string> >::iterator it;
			for(it=hash.begin();it!=hash.end();it++) {
				if(it->second.size()>=2){
					while(!it->second.empty()) {
						result.push_back(it->second.back());
						it->second.pop_back();
					}
				}
			
			}
			return result;

	    }

};
