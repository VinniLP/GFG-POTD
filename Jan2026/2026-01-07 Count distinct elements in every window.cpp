class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        vector<int> vv;
        unordered_map<int,int> mp;
        int count=0;
        for(int i=0;i<k;i++){
            mp[arr[i]]++;
        }
        for(int i=k;i<=arr.size();i++){
            vv.push_back(mp.size());
            mp[arr[i]]++;
            if(mp[arr[i-k]]==1){
                mp.erase(arr[i-k]);
            }else{
                mp[arr[i-k]]--;
            }
        }
        return vv;
    }
};