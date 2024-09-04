int size=nums2.size(); 
stack s; 
s.push(nums2[size-1]); 
unordered_map mp; 
mp[nums2[size-1]] = -1; 
for(int i=size-2; i>=0; i--){ 
    while(!s.empty() && s.top() < nums2[i]){ 
        s.pop();
        }
    if(s.empty()){ mp[nums2[i]] = -1; } else{ mp[nums2[i]] = s.top(); } s.push(nums2[i]); } vector result; for(auto i : nums1){ result.push_back(mp[i]); } return result;