class NumberContainers {
    unordered_map<int,int>indexToNum;         //stores the value for the index
    unordered_map<int,set<int>>numberToIndex;      //stores all the indexes for a value, set automatically sort the indexes
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(indexToNum.find(index)==indexToNum.end()){           //if index not in map ie index empty
            indexToNum[index]=number;                           //insert value in index
            numberToIndex[number].insert(index);                //mark index for the value
        }
        else{                                                   // number already present at index
            int prev = indexToNum[index];                      
            numberToIndex[prev].erase(index);                   // delete the number already present
            if (numberToIndex[prev].empty()) {                  //if the set for number becomes empty, remove the number
                numberToIndex.erase(prev);
            }
            indexToNum[index]=number;                          //insert new value in index
            numberToIndex[number].insert(index);               //mark index for the value
        }
        
    }
    
    int find(int number) {
        if(numberToIndex.find(number)!=numberToIndex.end()){     // if number present 
            return *numberToIndex[number].begin();               //return the first(smallest due to set usage) element
        }
        return -1;                                               //if not present return -1
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

