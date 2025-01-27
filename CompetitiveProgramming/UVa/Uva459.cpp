    #include <bits/stdc++.h>
    using namespace std;
    #define F(i,s,e) for (int i = s; i<e; i++)

    int main() {
        int t; cin >> t;
        vector<vector<int> > al(26);
        string s; char k;
        cin >> k;
        F(z,0,t) {
            al.assign(26, vector<int>(0));
            while (cin >> s) {
                if (s.size()==1) break;
                al[s[0]-'A'].push_back(s[1]-'A');
                al[s[1]-'A'].push_back(s[0]-'A');
                //cout << s[1]-'A' << " " << s[0]-'A' << '\n';
            }
            vector<int> vis(26,0);
            int cnt = 0;
            F(i,0,(k - 'A')+1) if (!vis[i]) {
                cnt++;
                //cout << i << '\n';
                queue<int> q; q.push(i);  
                while(!q.empty()) {
                    int u = q.front();
                    //cout << u << '\n';
                    q.pop();
                    if (!vis[u]) {
                        vis[u]=1;
                        for (int it : al[u]) if (!vis[it]) {
                            q.push(it);   
                        }
                    }
                }
            }
            k=s[0];
            cout << cnt << "\n" << (z==t-1 ? "" : "\n");
        }
    }