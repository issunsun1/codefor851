#include <iostream>
#include <string>

using namespace std;

int main()
{
    string raw, half;
    cin >> raw;

    // Check if the length of the string is odd
    if (raw.length() % 2 != 0)
    {
        cout << "NO" << endl;
        return 0;
    }

    // Get the first half of the string
    half = raw.substr(0, raw.length() / 2);

    cout << half << endl;

    // Compare the first half with the second half
    for (int i = 0; i < raw.length() / 2; i++)
    {
        if (raw[i] != raw[i + raw.length() / 2])
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    cout << half << endl;
    return 0;
}
