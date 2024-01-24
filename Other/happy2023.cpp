#include <iostream>
#include <ctime>

using namespace std;

int main() {
    time_t t = time(NULL);
    cout << t << " | " << t - ((52*365 + 13)*24*3600) << '\n';
    time_t curr_time;
	curr_time = time(NULL);

	tm *tm_gmt = gmtime(&curr_time);
	cout << "Current time : " << tm_gmt->tm_hour << ":" << tm_gmt->tm_min << ":" << tm_gmt->tm_sec << " GMT";
	return 0;
}
