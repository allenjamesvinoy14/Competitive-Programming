#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define vvi vector<vector<ll>>
#define pi pair<ll,ll>
#define MOD 1000000007
#define M 1000000007

int main(){
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        regex re("[(L|R)(D|U)(L|R)(D|U)")
    }
    string sp("geeksforgeeks"); 
    regex re("(geeks)(.*)"); 
 
    smatch match; 
  
    if (regex_search(sp, match, re) == true) { 

        cout << "Match size = " << match.size() << endl; 
  
        cout << "Whole match : " << match.str(0) << endl; 
        cout << "First capturing group is '" << match.str(1) 
             << "' which is captured at index " << match.position(1) 
             << endl; 
        cout << "Second capturing group is '" << match.str(2) 
             << "' which is captured at index " << match.position(2) 
             << endl; 
    } 
    else { 
        cout << "No match is found" << endl; 
    } 
    return 0; 
}