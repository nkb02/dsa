1.  Insert, Search, Starts-with
/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

struct Node{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return (links[ch-'a']!= NULL);
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie {

public:
    Node* root ;
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;

        for(int i = 0; i< word.size(); i++){
            if(!(node->containsKey(word[i])))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd(); // marks true
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = root;
        for(int i = 0; i< word.size(); i++){
            if(!(node->containsKey(word[i])))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();

    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        Node* node = root;
        for(int i = 0; i< word.size(); i++){
            if(!(node->containsKey(word[i])))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return true;
    }
};

2. Insert, Search, Count end with, cntPrefix , erase

struct Node{
    Node* links[26];
    int cntPrefix = 0;
    int cntEndWith = 0;

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }
    void increaseEnd(){
         cntEndWith++ ; 
    }
    void increasePrefix(){
         cntPrefix++ ; 
    }

    void reduceEnd(){
         cntEndWith-- ; 
    }
    void reducePrefix()
    { 
        cntPrefix-- ; 
    }
    int getEnd() {
        return cntEndWith;
    }
    int getPrefix() { return cntPrefix; }
};
class Trie{
    private:
        Node* root;    
    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(int i = 0; i< word.size(); i++){
            if(!(node->containsKey(word[i])))
                {
                    node->put(word[i], new Node()); 
                }
            node = node->get(word[i]);                   
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i = 0; i< word.size(); i++){
            if(node->containsKey(word[i]) )
                {
                    node = node->get(word[i]);   
                }
            else return 0;
            
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i = 0; i< word.size(); i++){
            if((node->containsKey(word[i])))
                {
                    node = node->get(word[i]);   
                }
            else return 0;
            
        }
        return node->getPrefix();
    }

    void erase(string &word){
        Node* node = root;
        for(int i = 0; i< word.size(); i++){
            if((node->containsKey(word[i])))
                {
                    node = node->get(word[i]);
                    node->reducePrefix();   
                }
            else 
                return;
            
        }
        node->reduceEnd();
    }
};


3. Longest word with All Prefixes || Complete string

#include <bits/stdc++.h> 

struct Node{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return (links[ch-'a']!= NULL);
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie {

public:
    Node* root ;
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;

        for(int i = 0; i< word.size(); i++){
            if(!(node->containsKey(word[i])))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd(); // marks true
    }

  
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool checkIfAllPrefixExists(string word) {
        Node* node = root;
        bool flag = true;

        for(int i = 0; i< word.size(); i++){
            if(!(node->containsKey(word[i])))
            {
                return false;
            }
            node = node->get(word[i]);
            flag = flag & node->isEnd();
        }
        return flag;
    }
};
string completeString(int n, vector<string> &a){
    Trie* obj = new Trie();
    for(auto word: a) obj->insert(word);

    string longest ="";

    for(auto word: a){
        if (obj->checkIfAllPrefixExists(word)) {
            if (word.size() > longest.size())
                longest = word;
            else if(word.size() == longest.size() 
            && word < longest) // lexicographically smaller
                longest = word;
        }
    }

    if(longest == "") return "None";
    return longest;
}

4. Number of Distinct substring in a string 

struct Node{
    Node* links[26];

    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
};

int countDistinctSubstrings(string &s)
{
    Node* root = new Node();
    int cnt  = 0;
    int n = s.size();

    for(int i =0; i< n; i++){

        Node* node = root;
        for(int j = i; j< n; j++){
            if(!node->containsKey(s[j])){
                node->put(s[j], new Node());
                cnt++;
            }

            node = node->get(s[j]);
        }
    }
    return cnt +1;
}


5. Maximum XOR of Two Numbers in an Array

struct Node{
    Node* links[2];
    
    bool containsKey(int bit){
        return links[bit] !=NULL;
    }
    
    Node* get(int bit){
        return links[bit];
    }
    
    void put(int bit, Node* node){
        links[bit] = node;
    }
    
};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    
    void insert(int num){
        Node* node = root;
        for(int i = 31; i>= 0; i--){
            int bit = (num>>i) & 1;
            
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    
    int findMax(int num){
        Node* node = root;
        int maxNum = 0;
        for(int i = 31; i>= 0; i--){
            int bit = (num>>i) & 1;
            
            if(node->containsKey(1 - bit)){
                maxNum = maxNum | (1 << i);
                node = node->get(1-bit);
            }
            else
                node = node->get(bit);
        }
        return maxNum;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto &it: nums) trie.insert(it);
        
        int maxXor = 0;
        for(auto &it: nums) maxXor = max(maxXor, trie.findMax(it));
        
            return maxXor;
    }
};


6. Maximum XOR With an Element From Array || Hard

=> the answer is max(nums[j] XOR xi) for all j 
such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.

struct Node{
    Node* links[2];
    
    bool containsKey(int bit){
        return links[bit] !=NULL;
    }
    
    Node* get(int bit){
        return links[bit];
    }
    
    void put(int bit, Node* node){
        links[bit] = node;
    }
    
};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    
    void insert(int num){
        Node* node = root;
        for(int i = 31; i>= 0; i--){
            int bit = (num>>i) & 1;
            
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    
    int findMax(int num){
        Node* node = root;
        int maxNum = 0;
        for(int i = 31; i>= 0; i--){
            int bit = (num>>i) & 1;
            
            if(node->containsKey(1 - bit)){
                maxNum = maxNum | (1 << i);
                node = node->get(1-bit);
            }
            else
                node = node->get(bit);
        }
        return maxNum;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int q = queries.size();
        int n = nums.size();
        
        vector<int> ans(q, 0);
        vector<pair< int, pair<int, int> >> oQ;
        sort(nums.begin(), nums.end());
        int index = 0;
        
        // converting online Qs to offline Qs
        for(auto &it: queries){
            oQ.push_back({it[1], {it[0], index++}});
        }
        sort(oQ.begin(), oQ.end());
        index = 0;
        Trie trie;
        
        for(auto &it: oQ){
            while(index < n && nums[index] <= it.first){
                trie.insert(nums[index]);
                index++;
            }
            
            if(index != 0 ) ans[it.second.second] = trie.findMax(it.second.first);
            else ans[it.second.second] = -1;
        }
        
        
        return ans;
    }
};