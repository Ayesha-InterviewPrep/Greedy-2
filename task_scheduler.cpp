// Time Complexity : O(n)
// Space Complexity : O(n)
// Any problem you faced while coding this :

//Understanding repetition of the maximum frequency numbers is a bit challenging

// Your code here along with comments explaining your approach
//1. Create a hashmap with char count
//2. Get the count of the max frequencies elements
//3. Calculate partitions, empty spaces and number of idle spaces further required.
//4.if idle spaces greater than zero add it to the result

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //edge
        if(tasks.size()==0)
            return 0;
        
        
        //logic
        //Create Hashmap to store the count of th elements
        unordered_map<char, int> count_map;
        int maxfreq=0, maxcount=0;
        int size = tasks.size();
        int result=0;
        for(int i =0; i<size;i++){
            int count =count_map[tasks[i]];
            count +=1;
            count_map[tasks[i]]= count;
            maxfreq=max(maxfreq, count);
        }
        //cout<<"maxfreq "<<maxfreq<<endl;
        for(int i =0; i<count_map.size();i++){
            if(count_map[i]==maxfreq) //Hashmap elemnts can be accessed via index numbers
                maxcount++;
        }
        //cout<<"maxcount "<<maxcount<<endl;
        // get number of partitions
        int partitions = maxfreq-1;
        //cout<<"partitions "<<partitions<<endl;
        // get empty spaces in partitions
        int empty = (n-maxcount+1) * (partitions);
        //cout<<"empty "<<empty<<endl;
        //get pending spaces
        int pending = max(0,empty - (size - (maxcount*maxfreq)));
        //cout<<"pending "<<pending<<endl;
        
        result = pending+size;
        //cout<<result<<endl;
        return result;
    }
};
