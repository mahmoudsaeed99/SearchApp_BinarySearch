#include "search_app.h"
#include <fstream>
#include <iostream>
#include<string>
#include <time.h>
#include <ctime>
#include<bits/stdc++.h>

using namespace std;

search_app::search_app()
{
    //ctor
}

search_app::~search_app()
{
    //dtor
}
void search_app::load_data()
{
    ifstream f("words.txt");
    vector<string>::iterator it;
    string s;
    while(f>>s)
    {
        vec.push_back(s);
    }
}
int search_app::binarysearch(int bot,int top,string rando)
{
    int pivot;
    n_comparisons=0;

    while (bot <= top)
    {
        pivot=(top+bot)/2;
        if (vec[pivot] ==rando )
            return pivot;

        if (vec[pivot] > rando)
        {
            cout<<"BIGGER"<<endl;
            top = pivot-1;
            n_comparisons++;
        }
        else
        {
            cout<<"SMALLER"<<endl;
            bot = pivot+1;
            n_comparisons++;
        }
    }
    return -1;
}
int search_app::testperformance()
{
    string rando;
    int y;
    char alpha[]="abcdefghijklmnopqrstuvwxyz";
    cout<<"1- do you want to make case one that get random words existing"<<endl;
    cout<<"2- do you want to make case one that get random words non_existing"<<endl;
    cin>>y;
    if(y==1)
    {
        srand(time(0));
        for(int i=0; i<100; i++)
        {
            rando=vec[rand()%4];
            clock_t tStart = clock();
            binarysearch(0,vec.size(),rando);
            t_comparisons=(double)(clock() - tStart)/CLOCKS_PER_SEC;
            times[i]=t_comparisons;
            nums[i]=n_comparisons;
        }
        put_excel();
    }
    if(y==2)
    {
        for(int i=0; i<100; i++)
        {
        string g;
        srand (time(0));
        g=getString();
            rando =g;
            //cout<<rando<<endl;
            clock_t tStart = clock();
            int x=binarysearch(0,vec.size(),rando);
            t_comparisons=(double)(clock() - tStart)/CLOCKS_PER_SEC;
            if(x==-1)
            {
                cout<<n_comparisons<<endl;
                times[i]=t_comparisons;
                nums[i]=n_comparisons;
            }
        }
        put_excel();
    }

}
void search_app::put_excel()
{
    fstream f;
    f.open("case1.csv",ios::app|ios::out);
    f<<"n "<<","<<"t(comparison)";
    int count1=0;
    double count2=0;
    f<<endl;
    for(int i=0; i<100; i++)
    {
        count1+=nums[i];
        count2+=times[i];
        f<<nums[i]<<","<<times[i]<<endl;
    }
    f<<endl;
    f<<"av_num"<<","<<"av_time"<<endl;
    f<<count1/100<<","<<count2/100<<endl;
    f.close();	 	

}
string search_app:: getString()
{
    char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z' };
     srand ( time(0) );
    string res = "";
    for (int i = 0; i <5 ; i++){
        int x=i+rand()%((25+1)-i);
        res = res + alphabet[rand() % x];
    }
    cout<<res<<endl;
    return res;
}
