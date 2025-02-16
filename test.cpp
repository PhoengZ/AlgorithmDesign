#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> A; // store prefix sum

int get_sum(int start, int stop) // [start, stop]
{
    // Trivial case
    // if (start == stop) return A[start] - (start > 2 ? A[start - 2] : 0);

    int sum1; int sum2;

    /* คี่คี่ */
    if (start%2 != 0 && stop%2 != 0)
    {
        if (start == 1)
        {
            sum1 = A[stop];
        }else
        {
            sum1 = A[stop] - A[start - 2];
        }
        sum2 = A[stop-1] - A[start-1];
    }
    /* คี่คู่ */
    else if (start%2 != 0 && stop%2 == 0)
    {
        if (start == 1)
        {
            sum1 = A[stop-1];
        }
        else
        {
            sum1 = A[stop-1] - A[start-2];
        }
        sum2 = A[stop] - A[start-1];
    }
    /* คู่คี่ */
    else if (start%2 == 0 && stop%2 != 0)
    {
        if (start == 2)
        {
            sum1 = A[stop-1];
        } else
        {
            sum1 = A[stop-1] - A[start-2];
        }
        sum2 = A[stop] - A[start-1];
    }
    /* คู่คู่ */
    else
    {
        if(start == 2)
        {
            sum1 = A[stop];
        }
        else
        {  
            sum1 = A[stop] - A[start-2];
        }
        sum2 = A[stop-1] - A[start-1];
    }

    // cout << "start = " << start << " stop = " << stop << endl;
    // cout << sum1 << " & " << sum2 << endl;

    return sum1 - sum2;
}

int mss(int start, int stop)
{
    // Terminate case
    if (stop == start)
    {
        return get_sum(start, stop);
    }
    
    // Recursive case
    int mid = (start + stop)/2;
    int r1 = mss(start,mid); // recur left side
    int r2 = mss(mid+1, stop); // recur right side

    // left
    int max_1 = get_sum(mid, mid);
    int num_mid_1 = 1;
    for (int i = start; i < mid+1; i++)
    {
        int tmp = get_sum(i,mid);
        if (tmp > max_1)
        {
            num_mid_1 = mid - i + 1;
            max_1 = tmp;
        }
        // max_1 = max(max_1, tmp);
    }

    // right
    int max_2 = get_sum(mid+1, mid+1);
    int least_2 = get_sum(mid+1, mid+1);
    for (int i = mid+1; i < stop+1; i++)
    {
        max_2 = max(max_2, get_sum(mid+1, i));
        least_2 = min(least_2, get_sum(mid+1, i));
    }

    // middle >> r3
    int r3;
    if (num_mid_1%2 == 0) r3 = max_1 + max_2;
    else r3 = max_1 - least_2;

    return max({r1, r2, r3});
}

int main()
{
    cin >> n;
    A.resize(n+1);
    for (int i = 1; i < n+1; i++)
    {
        int a;
            cin >> a;
        if (i == 1 || i == 2)
        {
            A[i] = a;
        } else{
            A[i] = A[i-2] + a;
        }
    }

    cout << mss(1, n);
    
    return 0;
}