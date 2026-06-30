class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int answer;
        int left = 1;
        int maxpile = INT_MIN;
        for(int i = 0; i<n; i++){
            maxpile=max(piles[i], maxpile);
        }
        int right = maxpile;

        while(left<=right){
            int mid = (left+right)/2;
            int hours = 0;
            for(int i: piles){
                hours+=(i+mid-1)/mid;
            }
            if(hours > h){

                left = mid + 1;
            }
            if(hours <= h){
                answer = mid;
                right = mid -1;
            }
        }

        return answer;
    }
};
