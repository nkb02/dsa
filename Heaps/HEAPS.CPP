//------------- HEAPS ------------------------//

1.  k-th smallest number in the array 

// max heap

int maxh(int a[], int n, int k){
    priority_queue<int> maxHeap;
    for (int i = 0; i < n; ++i)
    {
        maxHeap.push(a[i]);
        if(maxHeap.size() >k)
            maxHeap.pop();
    }
    return maxHeap.top();
}

2.  k-th largest number in the array 

// min heap

int minh(int a[], int n ,int k){
    priority_queue<int,vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; ++i)
    {
        minHeap.push(a[i]);
        if(minHeap.size() >k)
            minHeap.pop();
    }
    return minHeap.top();
}


3. sort a k-sorted array

	arr[] : {6, 5, 3, 2, 8, 10, 9}
	k = 3

// min heap

void minh(){
    priority_queue<int,vector<int>, greater<int>> minHeap;
        vector<int> sortedArray;
        for (int i = 0; i < n; ++i)
        {
            minHeap.push(a[i]);
            if(minHeap.size() >k)
                {
                    sortedArray.push_back(minHeap.top());
                    minHeap.pop();
                }
        }
        while(minHeap.size()!= 0){
            sortedArray.push_back(minHeap.top());
            minHeap.pop();
        }
              
        for(auto x: sortedArray)
        {
            cout<<x<<" ";
        }
}


4. k- closest numbers

	k = 3
	x = 7
	TO FIND K (=3) NUM CLOSEST TO X (=7)

    int maxh(){
        priority_queue<pair<int, int>> maxHeap;
        for (int i = 0; i < n; ++i)
        {
            maxHeap.push({abs(a[i]-x), a[i]});
            if(maxHeap.size() >k)
                maxHeap.pop();
        }
        while(maxHeap.size()!= 0){
                cout<<maxHeap.top().second<<" ";
                maxHeap.pop();
            }
               
    }	


5. top k -frequent #

    // min heap
    void minh(){
            priority_queue<pair<int,int>,vector<pair<int,int>>, 
            greater<pair<int,int>>> minHeap;
            
            unordered_map<int, int> mp;
            fl(i,n)
             mp[a[i]]++;

            

            for (auto i :mp)
            {
                 minHeap.push({i.second, i.first});
            if(minHeap.size() >k)
                {
                    minHeap.pop();
                }
            }
                    
            while(minHeap.size()!= 0){
                cout<<minHeap.top().second<<" ";
                minHeap.pop();
            }
                  
            
    }



6. frequency sort
    
    a[]: 1, 1 ,2, 2, 2, 3, 4

    o/p: 2, 2, 2, 1, 1, 3, 4
            [3]     [2] [1] [1]

    // max heap
    int maxh(){
          unordered_map<int, int> mp;
            fl(i,n)
             {
                mp[a[i]]++;
             }

        priority_queue<pair<int, int>> maxHeap;
         for (auto i :mp)
        {
            maxHeap.push({i.second, i.first});
             
        }
        while(maxHeap.size()!= 0){
            for (int i = 0; i < maxHeap.top().first; ++i)
            {
                cout<<maxHeap.top().second<<" ";
            }
                maxHeap.pop();
        }
               
    }


7. k-closest points to origin
    
    void solveNkb(){
        cin >> n >>k; // no of points
     
        priority_queue<pair<int,pair<int, int>>> maxHeap;
        fl(i,n)
        {
            ll x,y;
            cin>>x>>y;
          
            maxHeap.push( { (x*x +y*y) , {x,y} } );
            if(maxHeap.size() >k)
                maxHeap.pop(); 
        }

            while(maxHeap.size()> 0){
                    auto it = maxHeap.top().second;
                    cout<<it.first<<" "<<it.second <<"\n";
                    maxHeap.pop();
                } 

        return;
    }



8. connect ropes to get min cost

    a[] : 1 2 3 4 5

    // implementation
    minh: 5 4 3 2 1
          5 4 3 3    cost = 2+1 = 3
          5 4 6      cost = 3 + 3 + 3 = 9
          6 9        cost = 9 + 9 = 18
          15         cost = 18 + 15 = 33 = ans
    // min heap

    void minh(){
        priority_queue<int,vector<int>, greater<int>> minHeap;
            int cost = 0;
            for (int i = 0; i < n; ++i)
            {
                 minHeap.push(a[i]);
            }
           
            while(minHeap.size() >= 2)
            {
                int first = minHeap.top();
                minHeap.pop();
                int second = minHeap.top();
                minHeap.pop();
                
                cost = cost + first + second;
                minHeap.push(first + second);

            }

                cout<<cost;
    }


9. sum of elems b/w k1 smallest and k2 smallest

    a[] : 1 3 15  5 12 11
    k1= 3
    k2 = 6

    // algo
    1- use maxHeap to get k1 , k2 smallest numbers
    for (int i = 0; i < n; ++i)
    {
        if(a[i] > k1 && a[i] < k2)
            sum += a[i];
    }

    TC: O(nlogk1) + O(nlog(k2)) + O(N)
    sc: O(max(k1, k2))





