Prime XOR
// https://www.hackerrank.com/challenges/prime-xor/problem`
// Penny has an array of  integers, . She wants to find the number of unique multisets she can form using elements from the array such that the bitwise XOR of all the elements of the multiset is a prime number. Recall that a multiset is a set which can contain duplicate elements.

// Given  queries where each query consists of an array of integers, can you help Penny find and print the number of valid multisets for each array? As these values can be quite large, modulo each answer by  before printing it on a new line.

// Input Format

// The first line contains a single integer, , denoting the number of queries. The  subsequent lines describe each query in the following format:

// The first line contains a single integer, , denoting the number of integers in the array.
// The second line contains  space-separated integers describing the respective values of .
// Constraints

// Output Format

// On a new line for each query, print a single integer denoting the number of unique multisets Penny can construct using numbers from the array such that the bitwise XOR of all the multiset's elements is prime. As this value is quite large, your answer must be modulo .

// Sample Input

// 1   
// 3   
// 3511 3671 4153  
// Sample Output

// 4
// Explanation

// The valid multisets are:

//  is prime.
//  is prime.
//  is prime.
// , which is prime.
// Because there are four valid multisets, we print the value of  on a new line.


#define ll long long
#define mod 1000000007
bool prime[8193];
void sieve() {
  ll i,j;
  memset(prime,true,sizeof(prime));
  prime[0]=false;
  prime[1]=false;
  for(i=2;i*i<=8192;i++) {
    if(prime[i]) {
      for(j=2*i;j<=8192;j+=i) prime[j]=false; 
    } 
  } 
}

void solve() {
  ll n,i,j; cin>>n; vectorv(n); int m[5000]={0}; int dp[2][8192]={0};

  for(i=0;i<n;i++)
  {
    cin>>v[i];
    m[v[i]]++;
  }

  dp[0][0]=1;
  int flag=1;

  for(i=0;i<n;i++)
  {
      for(j=0;j<8192;j++)
      {
          //i.e the element occurs even times.., the result will the same as the including just the previous elements.
          ll excluded = (((m[v[i]]/2)+1)*(dp[flag^1][j]))%mod; 

          //i.e the element occurs odd times.., the result will number of ways to find the sum (j^a[i]) with the                  //help of i-1 elements... since a^b=j(wanted)..to find b a^b^a=j^a--> b=j^a            
          ll included = (((m[v[i]]+1)/2)*(dp[flag^1][j^v[i]]))%mod; 

          dp[flag][j]=(included+excluded)%mod;
          //cout<<dp[flag][j]<<" ";
      }
      flag=flag^1;
  }
  ll ans=0;
  for(i=0;i<8192;i++)
  {
      //cout<<dp[flag][i]<<" ";
     if(prime[i])
     {
         //cout<<dp[i]<<" ";
          ans=(ans+dp[flag^1][i])%mod;
     }
  }
}