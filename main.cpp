#include <iostream>
#include <time.h>
#include "search_app.h"
using namespace std;

int main()
{
    //clock_t tStart = clock();
    /* write your operations */
    //cout<< (double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;

    search_app s;
    s.load_data();
    s.testperformance();
    return 0;
}
