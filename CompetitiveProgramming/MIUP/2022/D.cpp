#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int d, y; string m;
    map<string, int> month;
    month["Jan"] = 0; month["Feb"] = 31; month["Mar"] = 59; month["Apr"] = 90; month["May"] = 120; month["Jun"] = 151,
    month["Jul"] = 181, month["Aug"] = 212, month["Sep"] = 243, month["Oct"] = 273, month["Nov"] = 304; month["Dec"] = 334;
    vector<string> wd = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    while (cin >> d) {
        cin >> m >> y;
        y--;
        int x = 0, yr = y%400;
        x += (y/400)*(365*400+97);
        x += yr*365;
        x += (yr/4 - yr/100);
        //cout << (yr/4 - yr/100) << '\n';
        x += month[m] + (((m != "Jan" && m != "Feb") && (!((yr+1) % 400) || ((yr+1) %100 && !((yr+1)%4)))) ? 1 : 0);

        x += d-1;
        //cout << x << '\n';
        cout << wd[(x-693595)%7] << '\n';
    }
}