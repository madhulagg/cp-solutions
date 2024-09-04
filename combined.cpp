#include<bits/stdc++.h>
using namespace std;

bool check_palindrome(int num)
{
    int temp = num;
    int ans = 0;
    for(int i=0; temp!=0;i++)
    {
        int last_digit = temp%10;
        ans = ans * 10 + last_digit;
        temp = temp/10;
    }
    if(ans == num)
    {
        return true;
    }
    return false;
}

long long factorial(int num)
{
    long long fact = 1;
    for(int i=1;i<=num;i++){
        fact = fact * i;
    }
    return fact;
}
int greatestcommondivisor(int a , int b)
{
    int ans = min(a,b);
    for(int i=ans; i>0 ; i--)
    {
        ans = i;
        if(a % ans == 0)
        {
            if(b % ans == 0)
            {
                break;
            }
        }
    }
    return ans;
}

int lcm(int a, int b){
    int ans = max(a,b);
    for(int i = ans;;i++ ){
        if((i % a == 0) && (i % b == 0)){
            ans = i;
            break;
        }
    }
    return ans;
}

void allfactors(int n)
{
    for(int i=1; i<=n; i++){
        if(n%i == 0){
            cout<<i<<" ";
        }
    }
}

void SieveOfEratosthenes(int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for(int p = 2; p*p <=n ; p++)
    {
        if(prime[p]==true)
        {
            for(int j=p*p; j<=n; j = j + p)
            {
                prime[j]=false;
            }
        }
    }
    for(int i=2; i<=n; i++)
    {
        if(prime[i])
        {
            cout<<i<<" ";
        }
    }
}
int countDigit(long long n)
{
	if (n == 0)
		return 1;
	int count = 0;
	while (n != 0) {
		n = n / 10;
		++count;
	}
	return count;
}

void bubblesort(int arr[], int n)
{
    for(int i=0; i<n-1;i++)
    {
        bool swapped = false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
}

void selectsort_notoptimised(int arr[],int n)
{
    int temp[n];
    for(int i=0;i<n;i++)
    {
        int min_index = 0;
        for(int j=0;j<n;j++)
        {
            if(arr[min_index]>arr[j])
            {
                min_index = j;
            }
            temp[i] = arr[min_index];
            arr[min_index] = INT_MAX;
        }
    }
    for(int i=0;i<n;i++){
        arr[i] = temp[i];
    }
}

void selectsort_optimised(int arr[],int n)
{
    for(int i=0;i<n;i++){
        int min_index = i;
        for(int j=i+1;j<n;j++){
            if(arr[min_index] > arr[j])
            {
                min_index = j;
                swap(arr[min_index],arr[j]);
            }
        }
    }
}

void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++)
    { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key)
        { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 

void mergesortedarr(int arr1[], int arr2[], int arr3[], int l1, int l2)
{
    int i,j,k;
    i=0;
    j=0;
    k=0;
    while(i<l1 && j<l2){
        if(arr1[i]<arr2[j]){
            arr3[k] = arr1[i];
            k++;
            i++;
        }
        else{
            arr3[k] = arr2[j];
            k++;
            j++;
        }
    }
    while(i<l1){
        arr3[k] = arr1[i];
        k++;
        i++;
    }
    while(j<l2){
        arr3[k] = arr2[j];
        k++;
        j++;
    }
}

int main()
{
    // SieveOfEratosthenes(20);
}