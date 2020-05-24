    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long int

    int main(){
        int n,k;

        cin>>n>>k;

        set<string> cards;

        for(int i=0;i<n;i++){
            string temp;
            cin>>temp;

            cards.insert(temp);
        }

        auto i = cards.begin();

        unordered_map<char,int> checker;

        checker['E'] = 0;
        checker['S'] = 0;
        checker['T'] = 0;

        string check = "EST";

        //set<string> v = {"T","E","S"};

        string c1,c2,r;

        ll count = 0;
        for(;i!=cards.end();i++){
            auto t = i;
            t++;
            for(auto j=t;j!=cards.end();j++){
                c1 = *i;
                c2 = *j;

                r="";
                for(int x=0;x<k;x++){
                    if(c1[x]==c2[x])
                        r+=c1[x];
                    else
                    {
                        // v.erase(string{c1[x]});
                        // v.erase(string{c2[x]});
                        // r+=*v.begin();
                        // v.insert(string{c1[x]});
                        // v.insert(string{c2[x]});

                        checker[c1[x]]=1;
                        checker[c2[x]]=1;

                        for(auto y:check)
                        {
                            if(checker[y]==0){
                                r+=y;
                                // cout<<r<<endl;
                                break;
                            }
                        }
                        checker[c1[x]]=0;
                        checker[c2[x]]=0;
                    }
                }
                
                if(cards.find(r)!=cards.end())
                {
                    count++;
                    // cout<<c1<<" "<<c2<<endl;
                }
            }
        }

        cout<<count/3<<endl;
    }