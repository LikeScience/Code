#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <utility>

using namespace std;

struct compRule {
    bool operator() (const pair<double, pair<double, int> >& lhs, const pair<double, pair<double, int> >& rhs) const {
        if (lhs.first > rhs.first) return 1;
        else if (lhs.first < rhs.first) return 0;
        else return (lhs.second.first < rhs.second.first);
    }
};

int main() {
    ifstream in ("ElectInfo.txt", ifstream::in);
    int seatN, regionN, partyN;
    in >> seatN >> regionN >> partyN;
   
    vector<string> PL(partyN), regions(regionN);
    vector<int> SPReg(regionN), NRes(partyN, 0);
    vector<vector<int> > RegRes(regionN, NRes);
    vector<double> LE(partyN), OP(partyN), ratio(partyN);
    vector<vector<double> > RegPerc (regionN, vector<double> (partyN));
    bool predict;
    for (int i = 0; i < regionN; i++){
        in >> regions[i] >> SPReg[i];
        
    }
    for (int i = 0; i < partyN; i++) {
        in >> PL[i];
    }
    for (int i = 0; i < partyN; i++) {
        in >> LE[i];
    }
    for (int i = 0; i < partyN; i++) {
        in >> OP[i];
        ratio[i] = OP[i] / LE[i];
        
    } 
   
    for (int i = 0; i < regionN; i++) {
        //cout << i << "i";
        set<pair<double, pair<double, int> >, compRule> s;
        in >> predict;
        double preV;
        for (int j = 0; j < partyN; j++) {
            in >> preV;
            if (preV != -1) {
            if (predict) {
                s.insert(make_pair(preV*ratio[j], make_pair(preV*ratio[j], j)));
                RegPerc[i][j] = preV*ratio[j];
            }
            else {
                s.insert(make_pair(preV, make_pair(preV, j)));
                RegPerc[i][j] = preV;
            }
            }
            else {
                s.insert(make_pair(OP[j], make_pair(OP[j], j)));
                RegPerc[i][j] = OP[j];
            }
        }
        
        int ASeats = SPReg[i];
        //cout << ASeats << endl;
        vector<float> divis(partyN,1.0);
        for (int j = 0; j < ASeats; j++) {
            int id = s.begin()->second.second;
            RegRes[i][id]++;
            NRes[id]++;
            divis[id] += 1.0;
            //cout << 1;
            pair<double, pair<double, int> > p = make_pair(s.begin()->second.first/divis[id], s.begin()->second);
            s.erase(s.begin());
            s.insert(p);
        }
    }
    cout << "Regional Results:" << endl;
    for (int i = 0; i < regionN; i++) {
        cout << regions[i];
        set<pair<pair<int, double> , int> > rs;
        for (int j = 0; j < partyN; j++) {
            rs.insert(make_pair(make_pair(RegRes[i][j], RegPerc[i][j]), j));
        }
        for (set<pair<pair<int, double>, int> >::reverse_iterator it = rs.rbegin(); it != rs.rend(); it++) {
            cout << " | " << PL[it->second] << " " << it->first.first << " (" << it->first.second << "%)";
        }
        cout << endl;
    }
    cout << "National Results:" << endl;
    set<pair<pair<int, double> , int> > rs;
    for (int j = 0; j < partyN; j++) {
        rs.insert(make_pair(make_pair(NRes[j], OP[j]), j));
    }
    for (set<pair<pair<int, double>, int> >::reverse_iterator it = rs.rbegin(); it != rs.rend(); it++) {
        cout << " | " << PL[it->second] << " " << it->first.first << " (" << it->first.second << "%)";
    }
    cout << endl;
    in.close();
}
