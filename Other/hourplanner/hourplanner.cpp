#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <random>
using namespace std;

#define F(i,s,e) for(int i = s; i < e; i++)

int main() {
    int a1, a2, N, I, h1, m1, h2, m2, t1, t2, g;
    
    random_device rd;

    cout << "Hy, I'm Preddy, the assistant which will try to help you predicting the hour of the day you can publish a new photo to the my_wildlife page so that it is determined randomly. Please choose whether you prefer to introduce your schedule here (type \"1\") or in a file (type \"0\")." << '\n';

    cin >> a1;
    if (a1){

        cout << "Please tell me if you prefer to say the intervals of time in which you are available to post the photos (including the extremes) (type \"1\") or the intervals of time in which you are not available to post the photos (including the extremes) (type \"0\")." << '\n';
        cin >> a2;
        cout << "Now, please say the number of days you want to find the posting time." << '\n';
        cin >> N;

        if (a2) {

            cout << "Finally, please introduce the intervals of time in the day in which you think you will be avaliable to post a new photo in yout page. To that, for each day, type in the first line the number N of intervals you want to introduce and then, in each of the following N lines, write the beginning time of that interval and than the ending time (in the format \"HH MM HH MM\"). Please ensure the first time does not go after the second one." << '\n';
            vector<int> ot;

            F(i,1,N+1) {
                cout << "Day " << i << ":" << '\n';
                cin >> I;
                vector<int> add(1440,0), vtimes;

                F(j,0,I) {
                    cin >> h1 >> m1 >> h2 >> m2;
                    t1 = 60*h1 + m1; t2 = 60*h2+m2;
                    if (t1 <= t2) {
                        add[t1]++;
                        if (t2 < 1440) add[t2+1]--;
                    }
                }

                int cnt = 0;
                F(j,0,1440) {
                    cnt += add[j];
                    if (cnt > 0) {
                        vtimes.push_back(j);
                    }
                }

                if (I != 0) {g = vtimes[rd() % (int)vtimes.size()];}
                else g = -1;
                ot.push_back(g);

            }

            F(i,0,N) {
                cout << "Day " << i+1 << ": " << (ot[i] / 60) << ":" << (ot[i] % 60) << '\n';
            }

        } else {

            cout << "Finally, please introduce the intervals of time in the day in which you think you will not be avaliable to post a new photo in yout page. To that, for each day, type in the first line the number X of intervals you want to introduce and then, in each of the following X lines, write the beginning time of that interval and than the ending time (in the format \"HH MM HH MM\"). Please ensure the first time does not go after the second one." << '\n';
            vector<int> ot;

            F(i,1,N+1) {
                cout << "Day " << i << ":" << '\n';
                cin >> I;
                vector<int> add(1440,0), vtimes(0);
                F(j,0,I) {
                    cin >> h1 >> m1 >> h2 >> m2;
                    t1 = 60*h1 + m1; t2 = 60*h2+m2;
                    if (t1 <= t2) {
                        add[t1]++;
                        if (t2 < 1440) add[t2+1]--;
                    }
                }

                int cnt = 0;
                F(j,0,1440) {
                    cnt += add[j];
                    if (cnt == 0) {
                        vtimes.push_back(j);
                    }
                }

                g = vtimes[rd() % (int)vtimes.size()];
                ot.push_back(g);

            }
            F(i,0,N) {
                cout << "Day " << i+1 << ": " << (ot[i] / 60) << ":" << (ot[i] % 60) << '\n';
            }

        }
    } else {
        cout << "Please create a file named \"dates.txt\" in the same folder as this program. Write:\n1) In the first line, write \"1\" if you prefer to say the intervals of time in which you are available to post the photos (including the extremes) or \"0\" if you prefer to tell me the intervals of time in which you are not available to post the photos (including the extremes);\n2) In the second line, write the number N of days you want to to find the posting time;\n3) Then, in a new line, introduce for the first day the number X of intervals in one line and, in each of the following X lines, write the beginning time of the interval following the end time (in format \"HH MM HH MM\");\n4) Repeat step 3) for each of the remaining days, starting each day in a new line." << '\n';
        fstream fin("dates.txt", fstream::in);
        fin >> a2 >> N;
        if (a2) {
            vector<int> ot;

            F(i,1,N+1) {
                fin >> I;
                vector<int> add(1440,0), vtimes;

                F(j,0,I) {
                    fin >> h1 >> m1 >> h2 >> m2;

                    t1 = 60*h1 + m1; t2 = 60*h2+m2;
                    if (t1 <= t2) {
                        add[t1]++;
                        if (t2 < 1440) add[t2+1]--;
                    }
                }

                int cnt = 0;
                F(j,0,1440) {
                    cnt += add[j];
                    if (cnt > 0) {
                        vtimes.push_back(j);
                    }
                }

                if (I != 0) {g = vtimes[rd() % (int)vtimes.size()];}
                else g = -1;
                ot.push_back(g);

            }

            F(i,0,N) {
                cout << "Day " << i+1 << ": " << (ot[i] / 60) << ":" << (ot[i] % 60) << '\n';
            }

        } else {
            vector<int> ot;

            F(i,1,N+1) {
                fin >> I;
                vector<int> add(1440,0), vtimes(0);
                F(j,0,I) {
                    fin >> h1 >> m1 >> h2 >> m2;
                    t1 = 60*h1 + m1; t2 = 60*h2+m2;
                    if (t1 <= t2) {
                        add[t1]++;
                        if (t2 < 1440) add[t2+1]--;
                    }
                }

                int cnt = 0;
                F(j,0,1440) {
                    cnt += add[j];
                    if (cnt == 0) {
                        vtimes.push_back(j);
                    }
                }

                g = vtimes[rd() % (int)vtimes.size()];
                ot.push_back(g);

            }
            F(i,0,N) {
                cout << "Day " << i+1 << ": " << (ot[i] / 60) << ":" << (ot[i] % 60) << '\n';
            }

        
        fin.close();
        }
    }
    cout << "I loved to help you creating a schedule! Use me whenever you want ;)" << '\n';

}