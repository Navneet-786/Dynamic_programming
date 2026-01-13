class Solution {
  public:
  
 
    int numberOfPaths(int m, int n) {
       vector<int>prevRow(n,0);
       for(int i = 0;i< n;i++){
           prevRow[i] = 1;
       }
      
       
       for(int i = 1;i<m;i++){
          vector<int>currRow(n,0);
           for(int j = 0;j< n;j++){
               int up  = prevRow[j];
               int left = 0;
               if(j>0){
                   left = currRow[j-1];
               }
               currRow[j] = up + left;
           }
           prevRow = currRow;
       }
       return prevRow[n-1];
    }
};
