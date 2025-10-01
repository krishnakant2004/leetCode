class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int rem = 0;
        int total = 0;
        while(numBottles != 0){
            total += numBottles;
            int emptyB = numBottles + rem;
            numBottles = emptyB / numExchange;
            rem = emptyB % numExchange;
        }
        return total;
    }
};