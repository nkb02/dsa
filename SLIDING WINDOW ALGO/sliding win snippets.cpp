1. max/ min subarray sum of size k

	int sum = 0;
    int maxi = 0 ;
    int mini = INT_MAX;
    // all positive nos

    int start = 0, end  = 0;
    while(end< n)
    {
        sum += a[end];
        if(end-start+1 < k)
            end++;
        else if(end-start+1 == k)
        {
            maxi = max(maxi , sum);
            mini = min(mini , sum);
            
            sum-= a[start];
            start++;
            end++;
        }
    }
    cout<<maxi<<" "<<mini;

2. first negative number in a subarray of size k
	

	int start = 0, end  = 0;
    queue<int> q;

    while(end< n)
    {
        if(a[end] < 0)
            q.push(a[end]);

        if(end -start +1 < k)
            end++;
        else if(end-start+1 == k)
        {
            if(q.empty()) cout<<0<<" ";
            else
            {
                cout<<q.front()<<" ";
                if(q.front() == a[start])
                {
                	// FIFO 
                    q.pop();
                }
            }
                start++;
                end++;    
            
        }
    }

3. count occurences of anagram
	
	ex =>	for = fro, rof, rfo (anagrams)

	string s,t;
    cin>>s>>t;
    cout<< search(s,t);

     int search(string pat, string txt) {
        unordered_map<char, int> mp;
        
        int n = pat.size();
        int k = txt.size();
        
        for(int x = 0; x<k; x++ )
            mp[txt[x]]++;

        int count = mp.size(); 
        int start , end;
        start = end = 0;
        int ans = 0;
         

        while(end< n)
        {
            if(mp.find(pat[end]) != mp.end()){
                mp[pat[end]]--;
                if(mp[pat[end]] == 0)
                    count--;
            }
            if(end-start+1 < k)
                end++;
            else if(end-start+1 == k)
            {
                if(count == 0)
                    ans++;
                 if(mp.find(pat[start]) != mp.end()){
                    mp[pat[start]]++;
                    if(mp[pat[start]] == 1)
                        count++;
                 }

                
                start++;
                end++;
            }
        }
        return ans;

    }


4. max of all subarray of size k

	i/p : 8 3
		  1 3 -1 -3 5 3 6 7 

    o/p : 3 3 5 5 6 7 

	void solveNkb(){
	    int n,k;
	    cin>>n>>k;

	    int a[n];
	    fl(i,n)cin>>a[i];

	    int start = 0, end  = 0;
	    deque<int> q;
	    vector<int>ans;

	    while(end< n)
	    {
	        while(q.size() > 0  && q.back() < a[end])
	            q.pop_back();

	            q.push_back(a[end]);

	        if(end -start +1 < k)
	            end++;
	        else if(end-start+1 == k)
	        {
	            // calc ans
	             ans.push_back(q.front());
	             // slide window
	             if(q.front() == a[start])
	                q.pop_front();

	            start++;
	            end++;        
	        }
	    }

	    for(auto it: ans) cout<< it<<" ";
	    return;
	}

	
// =============== variable win size  ques ==================//

5. largest subarray of sum k
	


	int sum = 0;
    int  maxi = 0 ;

    int start = 0, end  = 0;
    while(end< n)
    {
        sum += a[end];
        if(sum < k)
            end++;
        else if(sum >= k)
        {
            if(sum == k)
                maxi = max(maxi , end-start+1);
            while(sum> k){
                sum = sum - a[start] ;
                start++;
            }

            end++;
        }
    }
    cout<<maxi;


6. max substring with all unique character


	 int longestKSubstr(string s) {
	    int start, end;
	    start =end  =0;
	    unordered_map<char, int>mp;
	    int mx = 0;
	    while(end< s.size())
	    {
	        mp[s[end]]++;
	        // window size = end - start +1
	        if(mp.size() == end-start+1)
	          {
	            mx = max(mx, end-start+1);
	            end++;
	          }
	        else if(mp.size() < end-start+1)
	         {
	            while(mp.size() < end-start+1)
	            {
	                mp[s[start]]--;
	                if(mp[s[start]] == 0)
	                    mp.erase(s[start]);
	                start++;
	            }
	            end++;
	        
	         }
	    }
	    return mx;
	 }


7. Longest substring with k unique character

	int longestKSubstr(string s, int k) {
	    int start, end;
	    start =end  =0;
	    unordered_map<char, int>mp;
	    int mx = 0;
	    while(end< s.size())
	    {
	        mp[s[end]]++;
	        if(mp.size()< k)
	            end++;
	        else if(mp.size() == k)
	          {
	            mx = max(mx, end-start+1);
	            end++;
	          }
	        else if(mp.size() > k)
	         {
	            while(mp.size() > k)
	            {
	                mp[s[start]]--;
	                if(mp[s[start]] == 0)
	                    mp.erase(s[start]);
	                start++;
	            }
	            end++;
	        
	         }
	    }
	    return mx;
	 }