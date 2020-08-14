// Time Complexity : O(n) // O(4n)
// Space Complexity : O(n)
// Any problem you faced while coding this :

//Understand that during the right to left movement take max., of curr and next candy count.

// Your code here along with comments explaining your approach
//1. Create initial array with each kid having one candy
//2. Traverse left to right and increment the count when moving
//3. Traverse right to left and take max of curr candy candy count and next one

class Solution {
public:
    int candy(vector<int>& ratings) {
        //edge
        if(ratings.size()==0)
            return 0;
        
        //logic
        int size = ratings.size();
        vector<int> candy_count(size, 1);
        int result=0;
        for(int i=1; i<size;i++){
            if(ratings[i]>ratings[i-1]){
                candy_count[i]=candy_count[i-1]+1;
            }
        }
        for(int i=size-2; i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                candy_count[i] =max(candy_count[i] , candy_count[i+1]+1);
            }
        }
        for(int i=0; i<size;i++){
            result += candy_count[i];
        }
        
        return result;
    }
};
