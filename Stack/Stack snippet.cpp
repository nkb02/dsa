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
	use a stack store min element before pushing next element

	void minStack(vector<int> &arr){
		stack<int> minS, helper;
		int mn = INT_MAX;
		for(auto it: arr){
			if(it < mn){
				mn = it;
			}
			helper.push(mn);
			st.push(it);
		}

	}


10. Implement min stack using O(1) space
	# Imp
	O(1) = > no data structure only variable

class SpecialStack {
    stack<int> s;
    int mini;
    public:
        
    void push(int data) {
        // Implement the push() function.
        if(s.empty()){
            s.push(data);
            mini = data;
        }
        else{
            if(data < mini){
                s.push(2*data - mini);
                mini = data;
            }
            else{
                s.push(data);
            }
        }
    }

    void pop() {
        if(s.empty()) return;

        int curr = s.top();
        s.pop();

        if(curr < mini){
            mini = 2*mini - curr;
        }
        return;
    }

    int top() {
        if(s.empty()) return -1;

        int cur = s.top();
        if(cur < mini){
            return mini;
        }

        return cur;
    }

    int getMin() {
        // Implement the getMin() function.
        return mini;
    }  
};

11. Longest Valid Parenthesis

12. iterative Tower of Hanoi

13. LRU Implementation

class LRUCache {
  public:
    class node {
      public:
      int key;
      int val;
      node * next;
      node * prev;
      node(int _key, int _val) {
        key = _key;
        val = _val;
      }
    };

  node * head = new node(-1, -1);
  node * tail = new node(-1, -1);

  int cap;
  unordered_map < int, node * > m;

  LRUCache(int capacity) {
    cap = capacity;
    head -> next = tail;
    tail -> prev = head;
  }

  void addnode(node * newnode) {
    node * temp = head -> next;
    newnode -> next = temp;
    newnode -> prev = head;
    head -> next = newnode;
    temp -> prev = newnode;
  }

  void deletenode(node * delnode) {
    node * delprev = delnode -> prev;
    node * delnext = delnode -> next;
    delprev -> next = delnext;
    delnext -> prev = delprev;
  }

  int get(int key_) {
    if (m.find(key_) != m.end()) {
      node * resnode = m[key_];
      int res = resnode -> val;
      m.erase(key_);
      deletenode(resnode);
      addnode(resnode);
      m[key_] = head -> next;
      return res;
    }

    return -1;
  }

  void put(int key_, int value) {
    if (m.find(key_) != m.end()) {
      node * existingnode = m[key_];
      m.erase(key_);
      deletenode(existingnode);
    }
    if (m.size() == cap) {
      m.erase(tail -> prev -> key);
      deletenode(tail -> prev);
    }

    addnode(new node(key_, value));
    m[key_] = head -> next;
  }
};

14. LFU leetcode [hard]

struct Node {
    int key, value, cnt;
    Node *next; 
    Node *prev;
    Node(int _key, int _value) {
        key = _key;
        value = _value; 
        cnt = 1; 
    }
}; 
struct List {
    int size; 
    Node *head; 
    Node *tail; 
    List() {
        head = new Node(0, 0); 
        tail = new Node(0,0); 
        head->next = tail;
        tail->prev = head; 
        size = 0;
    }
    
    void addFront(Node *node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++; 
    }
    
    void removeNode(Node* delnode) {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--; 
    }
    
    
    
};
class LFUCache {
    map<int, Node*> keyNode; 
    map<int, List*> freqListMap; 
    int maxSizeCache;
    int minFreq; 
    int curSize; 
public:
    LFUCache(int capacity) {
        maxSizeCache = capacity; 
        minFreq = 0;
        curSize = 0; 
    }
    void updateFreqListMap(Node *node) {
        keyNode.erase(node->key); 
        freqListMap[node->cnt]->removeNode(node); 
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {
            minFreq++; 
        }
        
        List* nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        } 
        node->cnt += 1; 
        nextHigherFreqList->addFront(node); 
        freqListMap[node->cnt] = nextHigherFreqList; 
        keyNode[node->key] = node;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key]; 
            int val = node->value; 
            updateFreqListMap(node); 
            return val; 
        }
        return -1; 
    }
    
    void put(int key, int value) {
        if (maxSizeCache == 0) {
            return;
        }
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key]; 
            node->value = value; 
            updateFreqListMap(node); 
        }
        else {
            if(curSize == maxSizeCache) {
                List* list = freqListMap[minFreq]; 
                keyNode.erase(list->tail->prev->key); 
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--; 
            }
            curSize++; 
            // new value has to be added who is not there previously 
            minFreq = 1; 
            List* listFreq = new List(); 
            if(freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq]; 
            }
            Node* node = new Node(key, value); 
            listFreq->addFront(node);
            keyNode[key] = node; 
            freqListMap[minFreq] = listFreq; 
        }
    }
};


===================================================================================

						BASIC QUESTIONS

===================================================================================

1. REVERSE A STACK USING RECURSION


void insert(stack<int>& st, int x){
    if(st.empty()){
        st.push(x);
        return;
    }

    int num = st.top();
    st.pop();
    insert(st, x);
    st.push(num);
}
void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.size() <= 1)
     return;

    int temp= stack.top();
    stack.pop();
    reverseStack(stack);

    insert(stack, temp);
    return;
}

2. sort a stack using RECURSION

void sortedInsert(stack<int> &st, int num){
	if(st.empty() || st.top() < num){
		st.push(num);
		return;
	}
	int n = st.top();
	st.pop();

	sortedInsert(st, num);
	st.push(n);
}
void sortStack(stack<int> &stack)
{
	if(stack.size() == 0)
		return;

	int num = stack.top();
	stack.pop();
	sortStack(stack);

	sortedInsert(stack, num);
}

3. Minimum Cost To Make String Valid

int findMinimumCost(string str) {
    if(str.size() & 1) return -1;
    stack<char> st;
    for(auto ch : str){
      if(ch == '{')
         st.push(ch);

      else{
        // is closed braces
        if(!st.empty() && st.top() == '{'){
          st.pop();
        }
        else{
          st.push(ch);
        }
      }
    }
    int open = 0, closed = 0;
    while(!st.empty()){
        if(st.top() == '{') open++;
        else closed++;

        st.pop();
    }

    int ans = (open+1)/2 + (closed+1)/2;
    return ans;
}

4. The Celebrity Problem 

class Solution 
{
    private:
    bool check(vector<vector<int> >& M, int n, int p1 , int p2){
        return M[p1][p2] == 1;
     }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        for(int i = 0 ; i< n; i++)
            st.push(i);
            
        while(st.size() > 1){
            int p1 =st.top();
            st.pop();
            int p2 =st.top();
            st.pop();
            
            if(check(M, n, p1, p2)){
                st.push(p2);
            }
            else
                st.push(p1);
        }
        
        int ans = st.top();
        int cntzero = 0, cntOne = 0;
        for(int i = 0 ; i< n; i++){
            if(M[i][ans] == 1) cntOne++;
        }
        if(cntOne != n-1) return -1;
        
        cntzero = 0;
        for(int i = 0 ; i< n; i++){
            if(M[ans][i] == 0) cntzero++;
        }
         if(cntzero != n) return -1;
         
         return ans;
    }
};

5. N stack

push Algo:
	check for overflow
    find index
    update freespot
    insert element in array
    update next
    update top

pop Algo: 
	just reverse of push

#include <bits/stdc++.h> 
class NStack
{
    int *arr;
    int *top;
    int *next;

    int n, s;
    int freeSpot;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr= new int[s];
        top = new int[n];
        next = new int[s];

        // intialize top 
        for(int i = 0; i< n; i++) top[i] = -1;
        // intialize next 
        for(int i = 0; i< s; i++) next[i] = i+1;

        // update value of last index to -1
        next[s-1] = -1;

        // initialise freeSpot
        freeSpot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // check for overflow
        if(freeSpot == -1) return false;

        // find index
        int index = freeSpot;

        // update freespot
        freeSpot = next[index];

        // insert element in array
        arr[index] = x;

        // update next
        next[index] = top[m-1];

        // update top
        top[m-1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // just reverse of push()

        // check for underflow
        if(top[m-1] == -1) return -1;

        int index = top[m-1];
        top[m-1] = next[index];
        next[index] = freeSpot;

        freeSpot = index;

        return arr[index];
    }
};
