#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

vector<string> words;
vector<vector<int> > lineNums;
vector<string>lines;

void makeIndex(string fileName,vector<string>&lines);
void handle_find(string keyword,vector<string>&lines);
void addWord(string word, int lineNum);
int findWord(string keyword);
vector<string> split_line(string line, char delimiter);


int main() {
    string command;
    while(true)		{
        cout << "$ ";
        cin >> command;
        if (command == "read")	{
            string fileName;
            cin >> fileName;
            makeIndex(fileName,lines);
        }
        else if (command == "exit")
            break;
        else if (command == "find")	{
            string keyword;
            cin >> keyword;
            handle_find(keyword,lines);
        }
    }
    return 0;
}

void handle_find(string keyword,vector<string>&lines) {
    int index = findWord(keyword);
    if (index !=-1)  {
        cout << "The word " << keyword << " appears " <<
             lineNums[index].size()  << " times in lines: "<<endl;
        for (auto v : lineNums[index]){
            int temp;
            if (temp==v){
                continue;
            }
            cout << v << ":"<<lines[v]<<endl;
            temp=v;
        }
        cout << endl;
    }
    else
        cout << "The word " << keyword << " doesn’t appear." << endl;
}

void makeIndex(string fileName,vector<string>&lines) {
    ifstream theFile(fileName);
    int lineNum = 0;
    string line;
    while(getline(theFile, line)) {
        string t_line=line;
        lines.push_back(t_line);
        vector<string> tokens = split_line(line, ' ');
        for (auto s : tokens)
            if (s.length()>2)
                addWord(s, lineNum);
        lineNum++;
    }
    theFile.close();
}

vector<string> split_line(string line, char delimiter)
{
    vector <string> tokens;
    stringstream sstream(line);
    string str;

    while(getline(sstream, str, delimiter)){
        string temp;
        for(int i=0;i<str.length();i++){
            int a=isalpha(str[i]);
            if (a==1){
                tolower(str[i]);
                temp=temp+str[i];
            }
        
        }
        str=temp;
        tokens.push_back(str);
    }
    return tokens;
}


void addWord(string word, int lineNum) {
    int index = findWord(word);
    if (index > -1)
        lineNums[index].push_back(lineNum);
    else {
        words.push_back(word);
        vector<int> tmp;
        tmp.push_back(lineNum);
        lineNums.push_back(tmp);
    }
}


int findWord(string keyword) {
    for (int i=0; i<words.size(); i++)
        if (words[i] == keyword)
            return i;
    return -1;
}
