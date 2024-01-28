================ EASY =======================

1. Remove duplicates from Sorted array

int removeDuplicates(vector<int>& nums) {
        int j = 0, i = 1;;
        int n = nums.size();
       for(; i < n; i++){
           if(nums[j] != nums[i])
            {
                nums[j+1] = nums[i];
                j++;
            }
        }
        return j+1;
    }

2. Rotate array by K elements

	For Rotating Elements to left
	Step 1: Reverse the first k elements of the array

	Step 2: Reverse the last n-k elements of the array.

	Step 3: Reverse the whole array.


void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k%n;
    if(n==1) return;
    reverse(nums.begin(), nums.begin()+n-k);
    reverse(nums.begin() +n- k, nums.begin() + n);
    reverse(nums.begin(), nums.begin() + n);
  }  


// can also write our own reverse function
void Reverse(int arr[], int start, int end)
{
  while (start <= end)
  {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}


3. Move all Zeros to the end of the array

	Algorithm:
	* First, using a loop, we will place the pointer j. If we don’t find any 0, we will not perform the following steps.
	* After that, we will point i to index j+1 and start moving the pointer using a loop.
	* While moving the pointer i, we will do the following:
	* If a[i] != 0 i.e. a[i] is a non-zero element: We will swap a[i] and a[j]. Now, the current j is pointing to the non-zero element a[i]. So, we will shift the pointer j by 1 so that it can again point to the first zero.
	* Finally, our array will be set in the right manner.

vector<int> moveZeros(int n, vector<int> a) {
    int j = -1;
    //place the pointer j:
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            j = i;
            break;
        }
    }

    //no non-zero elements:
    if (j == -1) return a;

    //Move the pointers i and j
    //and swap accordingly:
    for (int i = j + 1; i < n; i++) {
        if (a[i] != 0) {
            swap(a[i], a[j]);
            j++;
        }
    }
    return a;
}

4. union of two sorted arrays

vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
  int i = 0, j = 0; // pointers
  vector < int > Union; // Uninon vector
  while (i < n && j < m) {
    if (arr1[i] <= arr2[j]) // Case 1 and 2
    {
      if (Union.size() == 0 || Union.back() != arr1[i])
        Union.push_back(arr1[i]);
      i++;
    } else // case 3
    {
      if (Union.size() == 0 || Union.back() != arr2[j])
        Union.push_back(arr2[j]);
      j++;
    }
  }
  while (i < n) // IF any element left in arr1
  {
    if (Union.back() != arr1[i])
      Union.push_back(arr1[i]);
    i++;
  }
  while (j < m) // If any elements left in arr2
  {
    if (Union.back() != arr2[j])
      Union.push_back(arr2[j]);
    j++;
  }
  return Union;
}

5. Longest Subarray with given Sum K(Positives)

most optmial 

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int i = 0, j = 0;
    long long sum = 0;
    int n = a.size();
    int mx = 0;
    while(j< n){
        sum += a[j];
        
        while(i <= j && sum > k){
                sum-= a[i];
                i++;
            }
        if(sum == k){
            mx = max(mx, j-i+1);
        }
        j++;        
    }
    return mx;
}

other- use hash, use double loop


6. Longest Subarray with given Sum K(Positives & negatives)

brute = O(N ^3)
BETTER = O(N ^2)
OPTIMAL = USE MAPS O(N)
STORE PREFUX SUM

Optimal Approach (Using Hashing): 
Approach:
The steps are as follows:

* First, we will declare a map to store the prefix sums and the indices.
* Then we will run a loop(say i) from index 0 to n-1(n = size of the arr* ay).
* For each index i, we will do the following:
* We will add the current element i.e. a[i] to the prefix sum.
* If the sum is equal to k, we should consider the length of t* he current subarray i.e. i+1. We will compare this length with the existing length and consider the maximum one.
* We will calculate the prefix sum i.e. x-k, of the remaining subarray.* 
* If that sum of the remaining part i.e. x-k exists in the map, we will calculate the length i.e. i-preSumMap[x-k], and consider the maximum one comparing it with the existing length we have achieved until now.
* If the sum, we got after step 3.1, does not exist in the map we will add that with the current index into the map. We are checking the map before insertion because we want the index to be as minimum as possible and so we will consider the earliest index where the sum x-k has occurred. 

Edge Case: Why do we need to check the map if the prefix sum already exists?

In the algorithm, we have seen that at step 3.4, we are checking the map if the prefix sum already exists, and if it does we are not updating it.

int getLongestSubarray(vector<int>& a, int k) {
    int n = a.size(); // size of the array.

    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        //calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        int rem = sum - k;

        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}


================== MEDIUM =============================================================

 