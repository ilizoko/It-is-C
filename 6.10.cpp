#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream f("1.txt");
    ofstream g("2.txt");
    string s;
    int k = 0;
    while (getline(f, s)) {
        k++;
    }
    f.clear();
    f.seekg(0, ios::beg);
    for (int i = 1; i <= k - 3; i++) {
        getline(f, s);
        g << s << endl;
    }
    f.close();
    g.close();
    remove("1.txt");
    rename("2.txt", "1.txt");
    return 0;
}