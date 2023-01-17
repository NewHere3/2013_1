#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>


using namespace std;

int read(vector<int>& s, vector<string>& name);
void write(int limitas, vector<int>& s, vector<string>& name);

int atstumas(int x, int y)
{
    return (abs(x) + abs(y))*2;
}

int main()
{
    vector<int> atstumas;
    vector<string> name;
    int m = read(atstumas, name);
    for (size_t i = 0; i < name.size(); i++)
    {
        cout << atstumas[i] << '\n';
        cout << name[i] << '\n';
    }
    write(m, atstumas, name);
    return 0;
}

int read(vector<int>& s, vector<string>& name)
{
    ifstream duom("Duomenys.txt");
    int n, m;
    duom >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        char temp[11];
        duom.ignore();
        duom.get(temp, 11);
        name.push_back(temp);
        duom >> x >> y;
        s.push_back(atstumas(x, y));
    }
    duom.close();
    return m;
}

void write(int limitas, vector<int>& s, vector<string>& name)
{
    ofstream rez("Rezultatai.txt");
    int i=0, k=0;
    cout << '\n' << '\n';
    while (limitas > k + s[i])
    {
        k += s[i];
        i++;
        cout << k << '\n';
    }
    rez << i << ' ' << k << ' ' << name[i-1];
    rez.close();
}
