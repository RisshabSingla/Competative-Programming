#include<iostream>

using namespace std;

int findWorker(int* job, int workers,int* time){

}


int main()
{
    int workers;
    int jobs;
    cin>>workers>>jobs;
    int job[workers];
    int time[workers];
    int timeTaken = 0;
    for(int i = 0; i<workers; i++){
        cin>>job[i];
    }
    for(int i = 0; i<workers; i++){
        cin>>time[i];
    }

    for(int i = 0; i<jobs; i++){
        int index = findWorker(job, workers, time);
        
    }



    return 0;
}