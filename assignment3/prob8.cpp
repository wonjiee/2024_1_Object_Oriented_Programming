#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> findword(vector<string>dictionary,string arrayPuzzle[100][100],int N){
    vector<string>words;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            string word=arrayPuzzle[i][j];
            auto it=find(dictionary.begin(),dictionary.end(),word);
            if(it!=dictionary.end())
                words.push_back(*it);
            //right
            int j_1=j;
            j_1++;
            while(j_1<N){
                word=word+arrayPuzzle[i][j_1];
                it=find(dictionary.begin(),dictionary.end(),word);
                if(it!=dictionary.end())
                    words.push_back(*it);
                j_1++;
            }
            //left
            word=arrayPuzzle[i][j];
            j_1=j;
            j_1=j_1-1;
            while(j_1>=0){
                word=word+arrayPuzzle[i][j_1];
                it=find(dictionary.begin(),dictionary.end(),word);
                if(it!=dictionary.end())
                    words.push_back(*it);
                j_1=j_1-1;
            }
            //up
            word=arrayPuzzle[i][j];
            int i_1=i;
            i_1=i_1-1;
            while(i_1>=0){
                word=word+arrayPuzzle[i_1][j];
                it=find(dictionary.begin(),dictionary.end(),word);
                if(it!=dictionary.end())
                    words.push_back(*it);
                i_1=i_1-1;
            }
            //down
            word=arrayPuzzle[i][j];
            i_1=i;
            i_1=i_1+1;
            while(i_1<N){
                word=word+arrayPuzzle[i_1][j];
                it=find(dictionary.begin(),dictionary.end(),word);
                if(it!=dictionary.end())
                    words.push_back(*it);
                i_1=i_1+1;
            }
            //right up
            word=arrayPuzzle[i][j];
            i_1=i;
            j_1=j;
            j_1++;
            i_1=i_1-1;
            while(i_1>=0 && j_1<N){
                word=word+arrayPuzzle[i_1][j_1];
                it=find(dictionary.begin(),dictionary.end(),word);
                if(it!=dictionary.end())
                    words.push_back(*it);
                j_1++;
                i_1=i_1-1;
            }
            //left up
            word=arrayPuzzle[i][j];
            i_1=i;
            j_1=j;
            i_1=i_1-1;
            j_1=j_1-1;
            while(i_1>=0 && j_1>=0){
                word=word+arrayPuzzle[i_1][j_1];
                it=find(dictionary.begin(),dictionary.end(),word);
                if(it!=dictionary.end())
                    words.push_back(*it);
                i_1=i_1-1;
                j_1=j_1-1;
            }
            //right down
            word=arrayPuzzle[i][j];
            i_1=i;
            j_1=j;
            i_1++;
            j_1++;
            while(i_1<N && j_1<N){
                word=word+arrayPuzzle[i_1][j_1];
                it=find(dictionary.begin(),dictionary.end(),word);
                if(it!=dictionary.end())
                    words.push_back(*it);
                i_1++;
                j_1++;
            }
            //left down
            word=arrayPuzzle[i][j];
            i_1=i;
            j_1=j;
            j_1=j_1-1;
            i_1++;
            while(i_1<N && j_1>=0){
                word=word+arrayPuzzle[i_1][j_1];
                it=find(dictionary.begin(),dictionary.end(),word);
                if(it!=dictionary.end())
                    words.push_back(*it);
                j_1=j_1-1;
                i_1++;
            }
        }
    return words;
}
vector<string> duplicate(vector<string>&a){
    vector<string>value;
    for(auto word:a){
        auto it=find(value.begin(),value.end(),word);
        if (it==value.end())
            value.push_back(word);
    }
    return value;
}


int main(){
    vector<string>dictionary;
    string word;
    ifstream infile("dictionary.txt");
    while(infile>>word){
        dictionary.push_back(word);
    }
    infile.close();
    ifstream puzzle("puzzle.txt");
    int N=0;
    string arrayPuzzle[100][100];
    int x=0;
    int y=0;
    while(puzzle>>word){
        if (N==0){
            N=stoi(word);
            continue;
        }
        arrayPuzzle[y][x]=word;
        x++;
        if(x>=N){
            x=0;
            y++;
        }
    }

    vector<string>value=findword(dictionary,arrayPuzzle,N);
    vector<string>result=duplicate(value);
    for(auto a:result)
        cout<<a<<endl;


    return 0;
}
