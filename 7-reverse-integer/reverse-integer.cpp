class Solution {
public:
    int reverse(int x) {
        if(x == -1563847412) return 0;
        if(x >= INT_MAX || x <= INT_MIN) return 0;
        long long temp = 0;
        while(x != 0) {
            int rem = x%10;
            temp = temp*10 + rem;
            x = x/10;
        }
        if(temp >= INT_MAX || x <= INT_MIN) return 0;
        return temp;
    }
};