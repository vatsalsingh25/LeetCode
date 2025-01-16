class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setNum2 = 0;
        for(int i=0; i<32; i++){
            if( (num2&(1<<i))!=0 ) setNum2++;
        }
        int setNum1 = 0;
        for(int i=0; i<32; i++){
            if( (num1&(1<<i))!=0 ) setNum1++;
        }        

        if(setNum2==setNum1) return num1;
        if(setNum2<setNum1){
            int diff = setNum1-setNum2;
            for(int i=0; i<32; i++){
                if( (num1&(1<<i))!=0 ){
                    num1&=~(1<<i); 
                    diff--;
                    if(diff==0) break;
                }
            }
        } 
        else{
            int diff = setNum2-setNum1;
            for(int i=0; i<32; i++){
                if( (num1&(1<<i))==0 ){
                    num1|=(1<<i); 
                    diff--;
                    if(diff==0) break;
                }
            }
        } 
        return num1;
    }
};