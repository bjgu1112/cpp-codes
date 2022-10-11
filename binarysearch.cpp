int search(vector<int>& nums, int target) {
        int l=0;
        int h=nums.size()-1;
        while(h>=l){
            int mid=l+(h-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                h=mid-1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
        }
        return -1;
}

int main(){
  int n;
  cin>>n;
  vector<int> nums;
  int target;
  cin>>n>>target;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    nums.push_back(x);
  }
  
  int ans = search(nums, target);
  cout<<ans<<endl;
  return 0;
}



