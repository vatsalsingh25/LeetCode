class NumberContainers {
    unordered_map<int,int>indexToNum;         //stores the value for the index
    unordered_map<int,set<int>>numberToIndex;      //stores all the indexes for a value
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(indexToNum.find(index)==indexToNum.end()){
            indexToNum[index]=number;
            numberToIndex[number].insert(index);
        }
        else{
            int prev = indexToNum[index];
            numberToIndex[prev].erase(index);
            if (numberToIndex[prev].empty()) {
                numberToIndex.erase(prev);
            }
            indexToNum[index]=number;
            numberToIndex[number].insert(index);          
        }
        
    }
    
    int find(int number) {
        if(numberToIndex.find(number)!=numberToIndex.end()){
            return *numberToIndex[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

