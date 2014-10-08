/* There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 *
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
 *
 * Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 *
 * Note:
 * The solution is guaranteed to be unique.
 *
 */



class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int gasNum = gas.size();
        if(gasNum==0)       // Boundary cases
            return -1;
        if(gasNum==1) {
            if(gas[0]>=cost[0])
                return 0;
            else
                return -1;
        }
        int tank=0;          // How much gas left in tank
        int i;
        for(i=0;i<gasNum;i++) {   // i is start point
            
            int nextIndex = (i==gasNum-1?0:i+1);     // in case i+1==gasNum, we need to set nextIndex = 0
            int curIndex = i;                        // Used to retrieve
            bool found=true;
            while(nextIndex!=i) {
                tank += gas[curIndex];           // Fill in the gas
                if(tank>=cost[curIndex]) {       // If Car can arrive from curIndex place to nextIndex place
                    tank = tank-cost[curIndex];
                    curIndex = nextIndex;
                    nextIndex = (nextIndex==gasNum-1?0:nextIndex+1);
                    
                }
                else {                          // Can't reach, find another start point
                    tank=0;
                    found=false;
                    break;
                }
            }
            
            if(found && nextIndex==i) {     // The above loop cann't check the last step.
                tank += gas[curIndex];
                if(tank<cost[curIndex])
                    found=false; 
            }
            if(found)
                return i;
            
        }
        return -1;
        
        
        
    }
};



