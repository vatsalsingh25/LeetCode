class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int s = 0, t = 0;
        
        // Step 1: Compare the relative order of non-'_' characters
        while (s < n || t < n) {
            // Find the next non-'_' character in start
            while (s < n && start[s] == '_') s++;
            // Find the next non-'_' character in target
            while (t < n && target[t] == '_') t++;
            
            // If one pointer reaches the end, the other must too
            if ((s < n) != (t < n)) return false;
            
            // If both are still in range, compare characters
            if (s < n && t < n) {
                if (start[s] != target[t]) return false;
                // Check movement constraints
                if (start[s] == 'L' && s < t) return false; // 'L' can't move right
                if (start[s] == 'R' && s > t) return false; // 'R' can't move left
            }
            
            // Move to the next characters
            s++;
            t++;
        }
        
        // Step 2: Ensure no unmatched characters remain
        return true;
    }
};

// class Solution {
// public:
//     bool canChange(string start, string target) {
//         int n = start.size();
//         int s=0, t=0;
        
//         if(start==target) return true;

//         while(s<n && t<n){
//             string S = "";
//             string T = "";
//             while(s<n){
//                 if(start[s]!='_'){
//                     S+=start[s];
//                     s++;
//                     break;
//                 } 
//                 else s++;
//             }
//             while(t<n){
//                 if(target[t]!='_'){
//                     T+=target[t];
//                     t++;
//                     break;
//                 } 
//                 else t++;
//             }
//             if(S!=T) return false;
//         }

//         bool flag = false;
//         for(int i=0; i<n; i++){
//             int curr = target[i];
//             if(curr=='L'){
//                 for(int j=i; j<n; j++){
//                     if(start[j]=='L'){
//                         flag=true;
//                         break;
//                     }
//                     else if(start[j]=='R') return false;
//                     else continue;
//                 }
//             }
//             else if(curr=='R'){
//                 for(int j=i; j>=0; j--){
//                     if(start[j]=='R') {
//                         flag=true;
//                         break;
//                     }
//                     else if(start[j]=='L') return false;
//                     else continue;
//                 }
//             }
//             else{
//                 continue;
//             }
//         }
//         if(flag==true) return true;
//         else return false;
//     }
// };


