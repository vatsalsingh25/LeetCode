class RandomizedSet {
public:
    vector<int>arr;
    unordered_map<int,int>mpp;   

    RandomizedSet() {
     
    }
    
    bool insert(int val) {
        if(mpp.find(val)==mpp.end()){        // if val not present in arr
            arr.push_back(val);              //insert to last
            mpp[val]= arr.size()-1;          //store index in map
            return true;                     //marks completition
        }
        return false;                       
    }
    
    bool remove(int val) {
        if(mpp.find(val)!=mpp.end()){      // if val is present
            int lastInd = arr.size()-1;    
            arr[mpp[val]]=arr[lastInd];    //replace the value to be replaced with last value
            arr.pop_back();                // delete the last value
            mpp[arr[lastInd]]=mpp[val];    //create new entry for last element that is replaced with val its index as mpp[val]
            mpp.erase(val);                //delete val entry from map
            return true;                   //marks successful execution
        } 
        return false;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */