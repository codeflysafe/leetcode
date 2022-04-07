//
// Created by sjhuang on 2022/4/3.
//
#include "leetcode.h"
class Encrypter {
public:

    //
    unordered_map<char,int> keysMap;
    unordered_map<string,vector<int>> valuesMap;
    unordered_map<string,int> dictionaryMap;
    vector<string> svalues;
    vector<char> skeys;

    // tree
    struct tree{
        unordered_map<char, struct tree*> childs;
        bool leaf;
        tree(){};
    };

    struct tree *trie;

    void build(){
        trie = new tree();
    }

    void insert(string word){
        tree *head = trie;
        for(char ch: word){
            if(head->childs.count(ch) == 0) {
                head->childs[ch] = new tree();
            }
            head = head->childs[ch];
        }
        head->leaf = true;
    }

    bool isPrefix(string prefix){
        tree *head = trie;
        for(char ch: prefix){
            if(head->childs.count(ch) == 0) return false;
            head = head->childs[ch];
        }
        return true;
    }


    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        build();
        for(int i = 0; i < keys.size(); i++){
            keysMap[keys[i]] = i;
        }
        for(int i = 0; i < values.size(); i++){
            if(valuesMap.count(values[i]) == 0){
                valuesMap[values[i]] = {i};
            }else{
                valuesMap[values[i]].push_back(i);
            }
        }
        for(int i = 0; i < dictionary.size(); i++){
            dictionaryMap[dictionary[i]] = i;
            insert(dictionary[i]);
        }
        svalues = values;
        skeys = keys;

    }

    string encrypt(string word1) {

        string ans = "";
        for(char c: word1){
            ans += svalues[keysMap[c]];
        }
        return ans;

    }

    int decrypt(string word2) {
        int ans = 0;
        // 将字符串每相邻 2 个字符划分为一个子字符串
        vector<string> prefixes = {""};
        // 从中选择 任意 一个。这意味着一个字符串解密可能得到多个解密字符串
        for(int i = 0; i < word2.size(); i+= 2){
            string s = word2.substr(i,2);
            vector<string> tmps;
            // 果存在多个有效的 i ，从中选择 任意 一个。这意味着一个字符串解密可能得到多个解密字符串。
            for(int idx: valuesMap[s]){
                for(string prefix: prefixes){
                    if(isPrefix(prefix + skeys[idx])){
                        tmps.push_back(prefix + skeys[idx]);
                    }
                }
            }
            prefixes = tmps;
        }

        for(string prefix: prefixes){
            if(dictionaryMap.count(prefix) > 0){
                ans ++;
            }
        }
        return ans;

    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */

int main(){
    vector<char> keys = {'a','b','c','d'};
    vector<string> values  = {"ei","zf","ei","am"};
    vector<string> dictionary = {"abcd","acbd","adbc","badc","dacb","cadb","cbda","abad"};
    Encrypter* obj = new Encrypter(keys, values, dictionary);
    string param_1 = obj->encrypt("abcd");
    int param_2 = obj->decrypt("eizfeiam");
    cout << param_1 << param_2 << endl;
    return 0;
}