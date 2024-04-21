#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


string key(string msj)
{
    int n = msj.size();
    int j;
    string prefix = "";
    string a, b;
    for (int i = 1; i < n; i++)
    {
        j = msj.substr(0, i).length();
        a = msj.substr(0, i);
        b = msj.substr(i, j);

        if (a == b)
        {
            int k = 2 * i, ok = 1;
            long unsigned int cnt = 0;


            while (msj[k] != '\0' && cnt < a.length())
            {
                if (msj[k] != a[cnt])
                {
                    ok = 0;
                    break;
                }
                k++;
                cnt++;
            }



            if (ok == 1 && msj[k] == '\0' && msj.substr(i + j) != a)
            {
                prefix = a;
                break;
            }
        }


    }

    if (!prefix.empty())
    {
        return prefix;
    }
    else
        return "-1";
}

int main()
{
    string mesaj;
    cin >> mesaj;
    string cheie = key(mesaj);
    cout << cheie << endl;
    return 0;
}