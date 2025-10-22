#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

map<string, vector<string>> gproductions = {
    {"A", {"Aa", "b", "Ac", "+"}},
    {"S'", {"SS'"}},
    };

// void process(unordered_map<string, vector<string>> &productions) {
//     for (auto production : productions) {
//         vector<string> alpha;
//         vector<string> beta;

//         for (auto )
//     }
// }

void process(const string &vn, vector<string> &productions, map<string, vector<string>> &newproductions) {
    vector<string> alpha;
    vector<string> beta;

    for (auto &production : productions) {
        if (production.substr(0, vn.size()) == vn) {
            //左递归
            alpha.push_back(production.substr(vn.size()));
        }
        else {
            //非左递归
            beta.push_back(production);
        }
    }

    if (!alpha.empty()) {
        string newVn = vn + "'";
        //A->bA'
        for(const auto &b : beta) {
            newproductions[vn].push_back(b + newVn);
        }
        for (const auto &a : alpha) {
            newproductions[newVn].push_back(a + newVn);
        }
        newproductions[newVn].push_back("ε");
    }
    else {
        newproductions[vn] = productions;
    }
}

int main()
 {
    // A->Aα|β转换成：
    // A->βA'
    // A'->αA'|ε

    string temp;
    map<string, vector<string>> newProductions;
    
    for (auto &production : gproductions) {
        process(production.first, production.second, newProductions);
    }

    for (const auto &production : newProductions) {
        cout << production.first << "->";
        for (int i = 0; i < production.second.size(); ++i) {
            cout << production.second[i];
            if (i != production.second.size() - 1) {
                cout << " | " ;
            }
        }
        cout << endl;
    }
    return 0;
 }