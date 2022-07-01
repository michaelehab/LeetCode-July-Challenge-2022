class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b){
            return a[1] > b[1];
        });
        int i = 0, units = 0;
        while(i < boxTypes.size() && truckSize){
            units += boxTypes[i][1] * min(boxTypes[i][0], truckSize);
            truckSize -= min(boxTypes[i][0], truckSize);
            i++;
        }
        return units;
    }
};