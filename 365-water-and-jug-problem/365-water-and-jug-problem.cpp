class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
       return targetCapacity%__gcd(jug1Capacity,jug2Capacity) == 0 && targetCapacity<=jug1Capacity+jug2Capacity;  
    }
};