/*
Get excited, folks, because it is time for the final match of Codechef Premier League (CPL)!

Mike and Tracy also want to watch the grand finale, but unfortunately, they could not get tickets to the match. However, Mike is not someone who gives up so easily — he has a plan to watch the match.

The field where the match is played is surrounded by a wall with height K. Outside, there are N boxes (numbered 1 through N). For each valid i, the i-th box has a height Hi.

Mike wants to take some boxes and stack them on top of each other to build two towers. The height of each tower is the sum of heights of all the boxes that form it. Of course, no box may be in both towers. The height of each tower should be at least K. Then Mike can climb on top of one tower and Tracy on top of the other, and they can watch the match uninterrupted!

While Mike is busy stacking the boxes, Tracy would like to know the smallest number of boxes required to build two towers such that each of them has height at least K, or at least that it is impossible to build such towers. Can you help Tracy?

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and K.
The second line contains N space-separated integers H1,H2,…,HN.
Output
For each test case, print a single line containing one integer — the smallest number of boxes required to build two towers, or −1 if it is impossible.

Constraints
1≤T≤5
1≤N,K≤4,000
1≤Hi≤105 for each valid i

Subtasks
Subtask #1 (30 points):

1≤N,K≤100
1≤Hi≤100 for each valid i
Subtask #2 (70 points): original constraints

Example Input
2
8 38
7 8 19 7 8 7 10 20
4 5
2 10 4 9
Example Output
7
2
Explanation
Example case 1: The first tower can be built with boxes 8+10+20=38 and the second tower with boxes 7+7+8+19=41. In this case, the box with height 7 is left unused.

Example case 2: We only need the box with height 10 for one tower and the box with height 9 for the other tower.
*/



#include<bits/stdc++.h>
using namespace std;
int findMin(int arr[], int n)
{
    // Calculate sum of all elements
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    // Create an array to store results of subproblems
    bool dp[n+1][sum+1];

    // Initialize first column as true. 0 sum is possible
    // with all elements.
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Initialize top row, except dp[0][0], as false. With
    // 0 elements, no other sum except 0 is possible
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

    // Fill the partition table in bottom up manner
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=sum; j++)
        {
            // If i'th element is excluded
            dp[i][j] = dp[i-1][j];

            // If i'th element is included
            if (arr[i-1] <= j)
                dp[i][j] |= dp[i-1][j-arr[i-1]];
        }
    }

    // Initialize difference of two sums.
    int diff = INT_MAX;

    // Find the largest j such that dp[n][j]
    // is true where j loops from sum/2 t0 0
    for (int j=sum/2; j>=0; j--)
    {
        // Find the
        if (dp[n][j] == true)
        {
            diff = sum-2*j;
            break;
        }
    }
    return diff;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,s=0;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        int b[n],l=0,i;
        for(i=n-1;i>=0;i--)
        {
            b[l]=a[i];
            s=s+a[i];
            l++;
            if(s>=2*k)
                break;
        }
        int m=findMin(b,l);
        if(s-m>=2*k)
            cout<<l<<endl;
        else
        {

                i--;
                int flag=0;
                while(i>=0)
                {
                    b[l]=a[i];
                    s=s+a[i];
                    l++;
                    int j=findMin(b,l);
                    if(s-j>=2*k)
                    {
                        flag=1;
                        break;
                    }
                    i--;
                }
                if(flag==1)
                    cout<<l<<endl;
                else
                    cout<<"-1"<<endl;
        }
    }
}
