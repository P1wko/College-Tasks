#include <iostream>
#include <string>
#include <vector>
using namespace std;

int whereBanana(int row, bool** tree, int j)
{
    for (int x = 0; x < row; x++)
    {
        if (tree[j][x] && j != x) return x;
    }
    return 0;
}


int main()
{
    int cases = 0;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        int row = 0;
        cin >> row;
        bool** tree = new bool* [row];
        vector<int> connections(row);

        for (int j = 0; j < row; j++)
        {
            tree[j] = new bool[row];
        }
        string word;
        cin >> word;
        int which = 0;

        for (int j = 0; j < row; j++)
        {
            for (int x = 0; x < row; x++)
            {
                if (word[which] == '1')
                {
                    tree[j][x] = true;
                    if (j > x)
                    {
                        connections[j]++;
                        connections[x]++;
                    }
                }
                else tree[j][x] = false;
                which++;
            }
        }

        int howMuchBananas = 0;
        int ifBanana = 0;
        for (int j = 0; j < row; j++)
        {
            if (connections[j] == 1)
            {
                if (ifBanana == 0)
                {
                    ifBanana = connections[whereBanana(row, tree, j)];
                    howMuchBananas++;
                }
                else
                {
                    if (connections[whereBanana(row, tree, j)] == ifBanana)
                    {
                        howMuchBananas++;
                    }
                    else
                    {
                        howMuchBananas = 0;
                        break;
                    }
                }
                if (ifBanana == howMuchBananas && row % ifBanana == 0 && row > 2)
                {
                    howMuchBananas = 0;
                    break;
                }
            }
        }

        if (howMuchBananas > 0) cout << howMuchBananas << " bananas :)" << endl;
        else cout << "0 bananas :(" << endl;

    }
}
