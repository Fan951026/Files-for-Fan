//
//  main.cpp
//  use tutor center with david and google for this assignment
//  Created by Xuecong Fan on 10/7/16.
//  Copyright © 2016 Xuecong Fan. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <unistd.h>
#include <chrono>
#include <numeric>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;



int main() {
    
    chrono::microseconds ptime;
    string word;
    vector<string> his;
    cout << "Put your command. (exit is quit!)" << endl;
    
    while (1) {
        cout << "[cmd]: ";
        getline(cin, word);
        
        if (word == "exit" ) {
            cout << "Program is done. You quit." << endl;
            return 0;
        }
        
        his.push_back(word);
        
        
        if (word == "history"){
            
            
            for( int i=0;i<his.size();i++){
                cout<<i+1<< " : "<<his[i]<<endl;
            }
        }
        if(word[0] == '^'){
            string temp;
            for(int i=1;i<word.length();i++){
                temp+=word[i];
            }
            int num1;
            num1=stoi(temp);
            cout<< his[num1-1]<<endl;
      
        
        
        }
      
        
        
        
        
        if (word == "ptime") {
            auto time = ptime.count();
            auto seconds = time / 1000000;
            auto milliseconds = (time % 1000000) / 1000;
            auto microseconds = time % 1000;
            cout << "Time spent executing child processes: " << seconds << " seconds " << milliseconds << " milliseconds and " << microseconds << " microseconds." << endl;
            continue;
        }
        
        char * argv[100];
        {
            stringstream ss(word);
            string command;
            
            for (int i = 0; ss >> command; ++i) {
                argv[i] = new char [command.size()];
                strcpy(argv[i], command.c_str());
            }
        }
        
        auto start = chrono::steady_clock::now();
        
        auto pid = fork();
        
        if (pid == 0) {
           
            
            if (execvp(argv[0], argv) < 0) {
                cerr << "Unknown command!" << endl;
                exit(0);
            }
        } else if (pid > 0) {
         
            
            waitpid(pid, NULL, 0);
            auto stop = chrono::steady_clock::now();
            ptime = chrono::duration_cast<chrono::microseconds>(stop - start);
            
        } else {
            cerr << "There was a problem. Program will now exit." << endl;
            exit(1);
        }
    }
    
    return 0;
}

    

