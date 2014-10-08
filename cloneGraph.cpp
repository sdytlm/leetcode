/* Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 *
 *
 * OJ's undirected graph serialization:
 * Nodes are labeled uniquely.
 *
 * We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
 * As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 *
 * The graph has a total of three nodes, and therefore contains three parts as separated by #.
 *
 * First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 * Second node is labeled as 1. Connect node 1 to node 2.
 * Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
 *
 *
 */

/**
 *
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {

public:

	    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
			if(node == NULL)
				return NULL;
			unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash; // if this node is copied? hash<oldNode, newNode>
			dfs(node,hash);
			return hash[node];

	    }
		UndirectedGraphNode * dfs(UndirectedGraphNode *curNode, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &hash) {
			if(hash.find(curNode) != hash.end())	// This node has been copied
			  return hash[curNode];
		    UndirectedGraphNode *newNode = new UndirectedGraphNode(curNode->label); // create new node
			hash[curNode] = newNode;
			vector<UndirectedGraphNode *>::iterator it; // push newNode's neighbor
			for(it=curNode->neighbors.begin(); it!=curNode->neighbors.end();it++) {
				newNode->neighbors.push_back(dfs(*it,hash));
			}
			
			return newNode;

		}

};
