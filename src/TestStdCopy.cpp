#include "TestStdCopy.h"

TestStdCopy::TestStdCopy()
{

}

TestStdCopy::~TestStdCopy()
{

}

void TestStdCopy::RunTests() const
{
    vector<string> v1;
    v1.push_back("123");
    v1.push_back("234");
    vector<string> v2 = v1;

    v1[0][2] = '5';
    for(int i = 0; (int)i < v1.size(); i++)
    {
        cout << v1[i] << endl;
    }

    for(int i = 0; (int)i < v1.size(); i++)
    {
        cout << v2[i] << endl;
    }

    string a = "abc";
    string b;
    b = a;
    a[2] = 'd';
    cout << a << endl << b << endl;

    vector<string> v3;
    v3.resize(1);
    v3[0] = b;
    b[2] = 'e';
    for(int i = 0; (int)i < v3.size(); i++)
    {
        cout << v3[i] << endl;
    }
    cout << b << endl;

    vector<vector<int> > test1 = {{1,2,3}, {4,5}};
    cout << "This is test1" << endl;
    for(int i = 0; (int)i < test1.size(); i++)
    {
        for(int j = 0; j < (int)test1[i].size(); j++)
        {
            cout << test1[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<int> > test2;
    test2 = test1;

    test1[0][0] = 0;
    cout << "This is test2" << endl;
    for(int i = 0; (int)i < test2.size(); i++)
    {
        for(int j = 0; j < (int)test2[i].size(); j++)
        {
            cout << test2[i][j] << " ";
        }
        cout << endl;
    }
}
