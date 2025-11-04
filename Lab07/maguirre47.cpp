#include <iostream>
#include <list>
#include <vector>
using namespace std;


static int M; // table size
vector<list<int>> T;


int HASH_FUNCTION(int key){
    return key % M;
}

void HASH_INSERT(int key){
    T[HASH_FUNCTION(key)].push_front(key);
}

bool HASH_SEARCH(int key, int &i , int &j){
    i = HASH_FUNCTION(key);
    j = 0;
    
    for (list<int>::iterator it = T[i].begin(); it != T[i].end(); ++it) {
        if (*it == key) return true;
        ++j;
    }
    return false;
}



void HASH_DELETE(int key){
    int i = HASH_FUNCTION(key);
    list<int> &bucket = T[i];
    for (list<int>::iterator it = bucket.begin(); it != bucket.end(); ++it){
        if (*it == key){
            bucket.erase(it);
            cout << key << ":DELETED;\n";
            return;
        }
    }
    cout << key << ":DELETE_FAILED;\n";
}




void HASH_OUTPUT(){
    for (int i = 0; i < M; i++){
        cout << i << ":";
        for (list<int>::iterator it = T[i].begin(); it != T[i].end(); ++it)
            cout << *it << "->";
        cout << ";\n";
    }
}

void TOKEN_READER(string token, char &op, int &key){
    op = token[0];
    if (token.size() > 1)
        key = stoi(token.substr(1));
}

int main(){
    if (!(cin >> M)) return 0;
    if (M <= 0) return 0;
    T.assign(M, list<int>());



    string token;
    while (cin >> token){
        char op; 
        int key = 0;
        TOKEN_READER(token, op, key);
        if (op == 'e') break;
        if (op == 'i') HASH_INSERT(key);
        else if (op == 'd') HASH_DELETE(key);
        else if (op == 's') {
            int i, j;
            if (HASH_SEARCH(key, i, j))
                cout << key << ":FOUND_AT" << i << "," << j << ";\n";
            else
                cout << key << ":NOT_FOUND;\n";
        }
        else if (op == 'o') HASH_OUTPUT();
    }
    return 0;
}
