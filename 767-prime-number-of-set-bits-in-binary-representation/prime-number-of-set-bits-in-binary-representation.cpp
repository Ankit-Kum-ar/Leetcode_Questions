class Solution {
public:
    bool prime(int x){
        if(x==0||x==1) return false;
        for(int i=2;i<=sqrt(x);i++){
            if(x%i==0) return false;
        }
        return true;
    }
    int setBits(int x) {
        int count = 0;
        while(x!=0){
            int rem = x%2;
            if(rem == 1) count++;
            x = x/2;
        }
        return count;
    }
    int countPrimeSetBits(int left, int right) {
        int sum = 0;
        for(int i=left;i<=right;i++) {
            int count = setBits(i);
            if(prime(count) == true) sum++;
        }
        return sum;
    }
};