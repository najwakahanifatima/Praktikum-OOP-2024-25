#include <string>
#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, string> mymap;
    mymap["first"] = "hi";
    mymap["third"] = "how r you";
    mymap["second"] = "hello";

    map<string, string>::iterator itr;
    for(itr = mymap.begin(); itr != mymap.end(); itr++)
    {
    string newline = itr->second;
    cout << newline << endl;
    }


    return 0;
}