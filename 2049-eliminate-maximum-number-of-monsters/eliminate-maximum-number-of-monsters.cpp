class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<float> v;
        int n=dist.size();

        for(int i=0;i<n;i++){
            v.push_back(((float)dist[i]/(float)speed[i]));
        }

        sort(v.begin(),v.end());

        int count=1;
        int t=1;
        for(int i=1;i<v.size();i++){
            if(v[i]>t){
                count++;
                t++;
            }
            else break;
        }
        return count;

    }
};