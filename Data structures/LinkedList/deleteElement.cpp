#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define lld long double
#define ff first
#define ss second
#define rep(i, m, n) for (int i = m; i < n; i++)
#define rev(i, n, m) for(int i=n-1; i>=m; i--)
#define pb push_back
#define mp make_pair
#define fl(i, n) for (int i = 0; i < n; i++)
#define rl(i, m, n) for (int i = n; i >= m; i--)
#define py cout << "YES\n";
#define pn cout << "NO\n";
#define pi 3.141592653589793238
#define vr(v) v.begin(), v.end()
#define rv(v) v.end(), v.begin()
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Nkb cout.tie(NULL);
using namespace std;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }
bool sorta(const pair<int, int> &a, const pair<int, int> &b) { return (a.second < b.second); }
bool sortd(const pair<int, int> &a, const pair<int, int> &b) { return (a.second > b.second); }
void printarr(ll arr[], ll n)
{
    fl(i, n) cout << arr[i] << " ";
    cout << "\n";
}

ll binaryToDecimal(string n)
{
    string num = n;
    ll dec_value = 0;
    int base = 1;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
//Code by Nitish Byahut
//Language C++
//Practice->Success
struct node
{
    int data;
    node *next; 
};
node* head;
void insert(int x, int n){
    node* temp1 = new node;
    temp1->data = x;
    temp1->next = NULL; 
    if(n==1){
    	temp1->next = head;
    	head = temp1;
    	return;
	}
    node* temp2 = head;
    fl(i,n-2){
    	temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
}
void print(){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<'\n';
}
void deleteAtn(int n){
	node* temp1 = head;
	if(n == 1){
		head = temp1->next;
		delete temp1;
		return;
	} 
	fl(i,n-2){
		temp1 = temp1->next;
	}
	node* temp2 = temp1->next;
	temp1->next = temp2->next;
	delete temp2;	
}
 
int main()
{
     Code By Nkb
     head = NULL;
    cout<<"List is : ";
    insert(1,1); //1
    insert(2,2); // 1 2
    insert(5,1); // 5 1 2 
    insert(16,3);// 5 1 16 2
    print();
    deleteAtn(2);
	    print();
   return 0;
}


