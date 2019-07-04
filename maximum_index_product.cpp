#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
unsigned long int solve(vector<int> arr) {
    int size=arr.size();
    unsigned long int max=0,temp;
    size++;
    int a[4][size],i=2,k;
    auto itr = arr.begin();
    a[0][0] = a[1][0] = a[2][0] = a[3][0] = 0;
    a[0][1] = a[1][1] = a[2][1] = a[3][1] = 0;
    a[0][size] = a[1][size] = a[2][size] = a[3][size] = 0;
    itr++;
    while(itr!=arr.end())
    {
        if(*(itr-1) > *itr)
        {
            a[0][i] = *(itr-1);
            a[1][i] = i-1;
            itr++;
            i++;
            continue;
        }
        if(*(itr-1) < *itr)
        {
            k=i-1;
            while((a[0][k] <= *itr) && k)
                k=a[1][k];
            if(k)
            {
                a[0][i] = a[0][k];
                a[1][i] = a[1][k];
            }else{
                a[0][i] = 0;
                a[1][i] = 0;
            }
            itr++;
            i++;
            continue;
        }
        if(*(itr-1) == *itr)
        {
            a[0][i] = a[0][i-1];
            a[1][i] = a[1][i-1];
            itr++;
            i++;
            continue;
        }
    }
    auto it = arr.rbegin();
    i=size-1;
    while(it!=arr.rend())
    {
        if(*(it-1) > *it)
        {
            a[2][i] = *(it-1);
            a[3][i] = i+1;
            it++;
            i--;
            continue;
        }
        if(*(it-1) < *it)
        {
            k=i+1;
            while((a[2][k] <= *it) && k)
                k=a[3][k];
            if(k)
            {
                a[2][i] = a[2][k];
                a[3][i] = a[3][k];
            }
            else{
                a[2][i] = 0;
                a[3][i] = 0;
            }
            it++;
            i--;
            continue;
        }
        if(*(it-1) == *it)
        {
            a[2][i] = a[2][i+1];
            a[3][i] = a[3][i+1];
            it++;
            i--;
            continue;
        }
    }
    for(i=1;i<=size;i++)
    {
        temp = (unsigned long int)a[1][i] * (unsigned long int)a[3][i];
        if(temp>max)
            max = temp;
    }
    return max;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int arr_count;
    cin >> arr_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(arr_count);

    for (int arr_itr = 0; arr_itr < arr_count; arr_itr++) {
        int arr_item = stoi(arr_temp[arr_itr]);

        arr[arr_itr] = arr_item;
    }

    unsigned long int result = solve(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

