#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<string> v = {"Diana", "Gonçalo", "Leonardo", "Rúben", "Tiago"};
	random_device rd;
	cout << "Quem vai escrever é" << v[rd() %5] << "!\n";
	return 0;
}
