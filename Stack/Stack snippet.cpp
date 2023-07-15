1. Next smalller elme to right

	  //Function to find the next greater element for each element of the array.
    vector<long long> nextSmallerElementToRIGHT(vector<long long> arr, int n){
        vector<long long> nge(n);
        stack<long long> s;
        for(long long i = n-1; i >=0; i--)
        {
            if(s.size() == 0 )
            {
                nge[i]= -1;
            }
            else if(s.size() > 0 && s.top() < arr[i]){
                nge[i] = s.top();
            }
            else if(s.size() > 0 && s.top() >= arr[i]){
                while(s.size() > 0 && s.top() >= arr[i])
                    {
                        s.pop();
                    }
                if(s.size() == 0)
                {
                    nge[i]= -1;
                }
                else
                {
                    nge[i] = s.top();
                }
            }
            s.push(arr[i]);
        }
        return nge;
        
    }

2. Next smalller elme to right
    
    //Function to find the next greater element for each element of the array.
    vector<long long> nextSmallerElementToLEFT(vector<long long> arr, int n){
        vector<long long> nge(n);
        stack<long long> s;
        for(long long i = 0; i < n; i++)
        {
            if(s.size() == 0 )
            {
                nge[i]= -1;
            }
            else if(s.size() > 0 && s.top() < arr[i]){
                nge[i] = s.top();
            }
            else if(s.size() > 0 && s.top() >= arr[i]){
                while(s.size() > 0 && s.top() >= arr[i])
                    {
                        s.pop();
                    }
                if(s.size() == 0)
                {
                    nge[i]= -1;
                }
                else
                {
                    nge[i] = s.top();
                }
            }
            s.push(arr[i]);
        }
        return nge;
        
    }

3. 
//Function to find the next greater element for each element of the array.
	
	vector<long long> nextLargerElementToLEFT(vector<long long> arr, int n){
	    vector<long long> nge(n);
	    stack<long long> s;
	    for(long long i = 0; i < n; i++)
	    {
	        if(s.size() == 0 )
	        {
	            nge[i]= -1;
	        }
	        else if(s.size() > 0 && s.top() > arr[i]){
	            nge[i] = s.top();
	        }
	        else if(s.size() > 0 && s.top() <= arr[i]){
	            while(s.size() > 0 && s.top() <= arr[i])
	                {
	                    s.pop();
	                }
	            if(s.size() == 0)
	            {
	                nge[i]= -1;
	            }
	            else
	            {
	                nge[i] = s.top();
	            }
	        }
	        s.push(arr[i]);
	    }
	    return nge;
	    
	}

4. 
  //Function to find the next greater element for each element of the array.

	vector<long long> nextLargerElement(vector<long long> arr, int n){
	    vector<long long> nge(n);
	    stack<long long> s;
	    for(long long i = n-1 ; i >= 0; i--)
	    {
	        if(s.size() == 0 )
	        {
	            nge[i]= -1;
	        }
	        else if(s.size() > 0 && s.top() > arr[i]){
	            nge[i] = s.top();
	        }
	        else if(s.size() > 0 && s.top() <= arr[i]){
	            while(s.size() > 0 && s.top() <= arr[i])
	                {
	                    s.pop();
	                }
	            if(s.size() == 0)
	            {
	                nge[i]= -1;
	            }
	            else
	            {
	                nge[i] = s.top();
	            }
	        }
	        s.push(arr[i]);
	    }
	    return nge;
	    
	}

5. STOCK SPAN PROBLEM ##

//Function to find the next greater element for each element of the array.
    vector<long long> NGLStockSpan(vector<long long> arr, int n){
        vector<long long> nge(n);
        stack < pair < long long, long long >> s;
        for(long long i = 0; i < n; i++)
        {
            if(s.size() == 0 )
            {
                nge[i]= i+1;
            }
            else if(s.size() > 0 && s.top().first > arr[i]){
                nge[i] = i - s.top().second;
            }
            else if(s.size() > 0 && s.top().first <= arr[i]){
                while(s.size() > 0 && s.top().first <= arr[i])
                    {
                        s.pop();
                    }
                if(s.size() == 0)
                {
                    nge[i]= i+1;
                }
                else
                {
                    nge[i] = i - s.top().second;
                }
            }
            s.push( {arr[i], i} );
        }
        return nge;
        
    }

6. max area histogram ( MAH )

	* calculate NSR & NSL
	* WIDTH[I] = NSR[I] - NSL[I]
	* AREA[I] = WIDTH[I] * A[I]
	* FIND THE MAX AMOUNG ALL


	// Let's code it --> it's quite long but it is easy
	vector<long long> nextSmallerElementToLEFT(vector<long long> arr, int n){
        vector<long long> nge(n);
        stack<pair<long long, long long>> s;
        int pseudoIndex = -1;
        for(long long i = 0; i < n; i++)
        {
            if(s.size() == 0 )
            {
                nge[i]= pseudoIndex;
            }
            else if(s.size() > 0 && s.top().first < arr[i]){
                nge[i] = s.top().second;
            }
            else if(s.size() > 0 && s.top().first >= arr[i]){
                while(s.size() > 0 && s.top().first >= arr[i])
                    {
                        s.pop();
                    }
                if(s.size() == 0)
                {
                    nge[i]= pseudoIndex;
                }
                else
                {
                    nge[i] = s.top().second;
                }
            }
            s.push({arr[i],i});
        }
        return nge;
        
    }

	vector<long long> nextSmallerElementToRIGHT(vector<long long> arr, int n){
        vector<long long> nge(n);
        stack<pair<long long, long long>> s;
        int pseudoIndex = n;
        for(long long i = n-1; i >=0; i--)
        {
            if(s.size() == 0 )
            {
                nge[i]= pseudoIndex;
            }
            else if(s.size() > 0 && s.top().first < arr[i]){
                nge[i] = s.top().second;
            }
            else if(s.size() > 0 && s.top().first >= arr[i]){
                while(s.size() > 0 && s.top().first >= arr[i])
                    {
                        s.pop();
                    }
                if(s.size() == 0)
                {
                    nge[i]= pseudoIndex;
                }
                else
                {
                    nge[i] = s.top().second;
                }
            }
            s.push({arr[i], i});
        }
        return nge;
        
    }
 

	 
	void solveNkb()
	{ 
	    ll n;
	    cin>>n;
	    vector<long long> a(n), width(n), area(n);
	    fl(i,n)
	        cin>>a[i];

	    vector<long long> left,right;
	    left = nextSmallerElementToLEFT(a,n);
	    right = nextSmallerElementToRIGHT(a,n); 
	    // print(left,n);
	    // print(right,n);
	    fl(i,n)
	    {
	        width[i]= right[i] - left[i] -1;
	    }
	    fl(i,n)
	    {
	        area[i] = a[i] * width[i];
	    }    
	    cout<<*max_element(area.begin(), area.end());
	   return;
	    
	}

7. MAX AREA RECTANGLE IN BINARY MATRIX
	
	(Variation of MAH)

	* if a[i][j] == 1 then add 1
	* else if  == 0 then make it 0


// Let's code it --> it's quite long but it is easy
 	
 	vector<long long> nextSmallerElementToLEFT(vector<long long> &arr, int n){
        vector<long long> nge(n);
        stack<pair<long long, long long>> s;
        int pseudoIndex = -1;
        for(long long i = 0; i < n; i++)
        {
            if(s.size() == 0 )
            {
                nge[i]= pseudoIndex;
            }
            else if(s.size() > 0 && s.top().first < arr[i]){
                nge[i] = s.top().second;
            }
            else if(s.size() > 0 && s.top().first >= arr[i]){
                while(s.size() > 0 && s.top().first >= arr[i])
                    {
                        s.pop();
                    }
                if(s.size() == 0)
                {
                    nge[i]= pseudoIndex;
                }
                else
                {
                    nge[i] = s.top().second;
                }
            }
            s.push({arr[i],i});
        }
        return nge;
        
    }

 	vector<long long> nextSmallerElementToRIGHT(vector<long long> &arr, int n){
        vector<long long> nge(n);
        stack<pair<long long, long long>> s;
        int pseudoIndex = n;
        for(long long i = n-1; i >=0; i--)
        {
            if(s.size() == 0 )
            {
                nge[i]= pseudoIndex;
            }
            else if(s.size() > 0 && s.top().first < arr[i]){
                nge[i] = s.top().second;
            }
            else if(s.size() > 0 && s.top().first >= arr[i]){
                while(s.size() > 0 && s.top().first >= arr[i])
                    {
                        s.pop();
                    }
                if(s.size() == 0)
                {
                    nge[i]= pseudoIndex;
                }
                else
                {
                    nge[i] = s.top().second;
                }
            }
            s.push({arr[i], i});
        }
        return nge;
        
    }
 
	int MAH(vector<long long> &a, int n){
	    vector<long long> left,right;
	    left = nextSmallerElementToLEFT(a,n);
	    right = nextSmallerElementToRIGHT(a,n); 
	    // print(left,n);
	    // print(right,n);

	    vector<long long> width(n), area(n);
	    fl(i,n)
	    {
	        width[i]= right[i] - left[i] -1;
	    }
	    fl(i,n)
	    {
	        area[i] = a[i] * width[i];
	    }    
	    return *max_element(area.begin(), area.end());}
 
	void solveNkb(){ 
	    ll n,m;
	    cin>>n>>m;
	    vector<vector<long long>> a(n, vector<long long>(m,0));
	    fl(i,n){
	        fl(j,m)
	        cin>>a[i][j];
	    }

	    vector<long long> v;
	    fl(j,m){
	        v.push_back(a[0][j]);
	    }
	    int mx = MAH(v, m);

	    for (int i = 1; i < n; ++i)
	    {
	        fl(j,m){
	            if(a[i][j] == 1)
	                v[j] += 1;
	            else
	                v[j] = 0;
	        }
	        int temp = MAH(v, m);
	        mx = max(mx, temp);
	    }
	    cout<<mx;

	   
	   return;
	    
	}


8. RAIN WATER TRAPPING

	* NOT MAH QUES
	* NO USE OF NSL OR NSR
	* calculate MAX ELEMNENT FROM LEFT (MAXL) AND RIGHT (MAXR)
	* TAKE MINIMA OF BOTH
	* calculate WATER ABOVE EACH BUILDING (a[I] - MIN(MAXR[I], MAXL(I)))

	void solveNkb()
	{ 
	    int n;
	    cin>>n;
	    int a[n+5];
	    fl(i,n)
	        cin>>a[i];

	    int maxL[n], maxR[n];
	    maxL[0] = a[0];
	    rep(i,1,n)
	    {
	        if(a[i]> maxL[i-1])
	            maxL[i] = a[i];
	        else
	            maxL[i] = maxL[i-1];
	    }
	    maxR[n-1] = a[n-1];
	    for (int i = n-2; i >= 0; i--)
	    {
	        if(a[i]> maxR[i+1])
	            maxR[i] = a[i];
	        else
	            maxR[i] = maxR[i+1];
	    }
	    ll sum = 0;
	    fl(i,n)
	    {
	        sum += (min(maxR[i], maxL[i]) - a[i]);
	    }
	    cout<<sum;
	   return;
	    
	}


9. Implement min stack using extra space

	# easy


10. Implement min stack using O(1) space
	# Imp


11. Longest Valid Parenthesis

12. iterative Tower of Hanoi