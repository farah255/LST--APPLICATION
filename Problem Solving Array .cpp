#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> array(n) , sequence;
    for(int i=0; i<n; i++){
        cin >> array[i] ;
    }
    int cur = 0;
    for(int i=0; i<n ; i++){
        if(array[i]) cur++;
        else {
            sequence.push_back(cur);
            cur = 0;
        }
    }
    sequence.push_back(cur);
    int index , best = 0;
    for(int i=0; i<(int)sequence.size()-1 ; i++){
        if(sequence[i]+sequence[i+1] >= best) index = i, best = sequence[i]+sequence[i+1];
    }
    for(int i=0; i<n; i++){
        if(!index && !array[i]){
            cout << i ;
            break;
        }
        else if(!array[i]) index--;
    }
}