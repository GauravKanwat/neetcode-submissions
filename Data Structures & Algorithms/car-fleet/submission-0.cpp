class Solution {
    static bool cmp(pair<int,double>& a, pair<int,double>& b) {
        return a.first < b.first;
    }
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> timer;
        int n = position.size();
        for(int i=0; i<n; i++) {
            double t = (double)(target - position[i]) / speed[i];
            timer.push_back({position[i], t});
        }
        sort(timer.begin(), timer.end(), cmp);
        int fleet = 1;
        double curr = timer[n-1].second;
        for(int i=n-2; i>=0; i--) {
            if(timer[i].second > curr) {
                fleet++;
                curr = timer[i].second;
            }
        }
        return fleet;
    }
};
