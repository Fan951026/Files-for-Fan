//xuecong Fan
//use tutor center and google for this
//I spend 20 hour for this, I try many different way to do this assig but at final I confused myself. I still can not pipe this code very well.

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
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
using namespace std;
#define MAX_COM 200
#define MAX_NUM 20

int psd(char * cmd, char** pr){
    int l = -1;

    for (int i = 0 ; i<MAX_NUM; i++){
        pr[i]=strsep(&cmd, " ");
        l++;
        if(pr[i] == NULL) break;
    }
    return (l);
}

int pipe (char ** argv1, char ** argv2){
    int d[2];
    pipe(d);
    pid_t pid = fork();
    if (pid == -1)
    {
       
        cout<<"wrong cmd"<<endl;
        return -1;
    }
    if (pid == 0)
    {
        close(d[1]);
        dup2(d[0], 0);
        execvp(argv2[0], argv2);
        cout<<"wrong cmd"<<endl;
        return 0;
    } else { // parent process
        close(d[0]);
        dup2(d[1], 1);
        execvp(argv1[0], argv1);
       cout<<"wrong cmd"<<endl;
        return 0;
    }
};
//


int main() {
    
    chrono::microseconds ptime;
    
    vector<string> his;
    string word;
    vector<string> sword;
    vector<string> things;
    char ** D_things = NULL;
    bool swapthings = false;
    int d1[2];
    int d2[2];
    pipe(d1);
    pipe(d2);
    
    unsigned str;
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
            word = his[num1-1];
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
     
        //        while (true){
        //            str=word.find(' ');
        //            if(str == -1){
        //                sword.push_back(word);
        //                word.clear();
        //                break;
        //            }
        //            sword.push_back(word.substr(0,str));
        //            word.erase(0,str+1);
        //
        //        }
        //        things.push_back(sword.front());
        if(pid==0){
//            auto both_lr =false;
//                        auto left = false;
//                        auto right = false;
//                        if(things.front()==">"){
//                            both_lr = true;
//                        }
//                        if(things.front()=="|"||things.front()==">"){
//                            auto left = true;
//                            things.erase(things.begin());
//            
//                        }
//                        if(things.back()=="|"||things.back()==">"){
//                            auto right=true;
//                            things.pop_back();
//                        }
//            
//            
//                        int num_1=things.size();
//            
//                        D_things = new char*[num_1+1];
//                        D_things[num_1]=NULL;
//                        for (int i=0 ;i<num_1;i++){
//            
//                            int size = things[i].size()+1;
//                            D_things[i]=new char[size];
//                            strcpy(D_things[i], things[i].c_str());
//                        }
//            
//                        if(both_lr == true){
//                            auto f = fopen(D_things[0],"w");
//                            auto fd = fileno(f);
//                            if (swapthings==true){
//                                close(d1[0]);
//                                dup2(d2[0],0);
//                                dup2(fd,1);
//                            }
//                            else {
//                                close(d2[0]);
//                                dup2(d1[0], 0);
//                                dup2(fd,1);
//                            }
//                            fclose(f);
//                            return 0;
//            
//                        }
//            
//                        if(left==true){
//                            if(swapthings==true){
//                                close(d1[0]);
//                                dup2(d2[0], 0);
//                            }
//                            else{
//                                close(d2[0]);
//                                dup2(d1[0],0);
//                            }
//                            
//                            
//                        }
//                        else{
//                            close(d1[0]);
//                            close(d2[0]);
//                        }
//                        
//                        if(right==true){
//                            if(swapthings==true){
//                                close(d2[1]);
//                                dup2(d1[1], 1);
//                            }
//                            else{
//                                close(d1[1]);
//                                dup2(d2[1],1);
//                            }
//                        }
//                        else{
//                            close(d1[1]);
//                            close(d2[1]);
//                        }
//                        
//                        
//                        swapthings = !swapthings;
            if (execvp(argv[0], argv) < 0) {
                cerr << "Unknown command!" << endl;
                exit(0);
            }
            
    
            
        }
        else if (pid > 0) {
            
            
            waitpid(pid, NULL, 0);
            auto stop = chrono::steady_clock::now();
            ptime = chrono::duration_cast<chrono::microseconds>(stop - start);
            
            
            for (int i=0; i<100;i++){
                argv[i]=NULL;
            }
            
            
        } else {
            cerr << "There was a problem. Program will now exit." << endl;
            exit(1);
        }
    }
    
    return 0;
}
