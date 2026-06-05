class Solution {
   public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int minShipCapacity = high;

        while (low <= high) {
            int daysTaken = 1, currentCapacity = 0;
            int shipCapacity = low + (high - low) / 2;

            for (int& weight : weights) {
                if (currentCapacity + weight > shipCapacity) {
                    daysTaken++;
                    currentCapacity = weight;
                } else {
                    currentCapacity += weight;
                }
            }

            if (daysTaken <= days) {
                minShipCapacity = shipCapacity;
                high = shipCapacity - 1;
            } else {
                low = shipCapacity + 1;
            }
        }

        return minShipCapacity;
    }
};