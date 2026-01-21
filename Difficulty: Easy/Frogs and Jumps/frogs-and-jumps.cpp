// User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
       
       //vector for trak leaves
       vector<bool>trackLeaves(leaves+1,false);
       trackLeaves[0] = 1;
       //track the strength to prevent duplicate strength
       unordered_set<int>checkStrength;
       
       for(int i = 0;i<N;i++){
           //all leaves will coverd
           if(frogs[i] == 1)return 0;
           
           //if frogs strength is greater than leaves 
           if(frogs[i] > leaves) continue;
           
           //if same strength repeat
           if(checkStrength.find(frogs[i])!=checkStrength.end())continue;
           
           checkStrength.insert(frogs[i]);
           
           int k = frogs[i];
           
           for(int j = k;j<=leaves;j = j+k){
               trackLeaves[j] = true;
           }
           
       }
       
       int count = 0;
       for(auto it:trackLeaves){
           if(!it)count++;
       }
       
       return count;
        
    }
};
