class Solution {
public:
    int getD(vector<int>& worker, vector<int>& bike) {
        return abs(worker[0]-bike[0]) + abs(worker[1]-bike[1]);
    }
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int minD = INT_MAX;
        vector<pair<int,int>> disToPairs[1999];
        
        for(int worker = 0; worker < workers.size(); ++worker)
            for(int bike = 0; bike < bikes.size(); ++bike) {
                int distance = getD(workers[worker], bikes[bike]);
                disToPairs[distance].push_back({worker, bike});
                minD = min(minD, distance);
            }
        
        int curD = minD;
        vector<int> bikeStatus(bikes.size(), false);
        vector<int> workerStatus(workers.size(), -1);
        int pairCount = 0;
        
        while(pairCount != workers.size()) {
            for(auto [worker, bike] : disToPairs[curD]) {
                if(workerStatus[worker] == -1 && bikeStatus[bike] == false) {
                    bikeStatus[bike] = true;
                    workerStatus[worker] = bike;
                    pairCount++;
                }
            }
            curD++;
        }
        
        return workerStatus;
    }
};