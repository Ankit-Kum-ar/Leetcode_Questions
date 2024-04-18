class Solution {
public:
    bool isHappy(int n) {
       if(n == 1 || n == 7) return true;
       if(n < 10) return false;
       int x = n;
       int sum = 0;
       while(x != 0) {
            int rem = x%10;
            sum += (rem*rem);
            x = x/10;
       } 
       n = sum;
       return isHappy(n);
    }
};