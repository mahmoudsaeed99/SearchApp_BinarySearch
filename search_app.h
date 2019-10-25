#ifndef SEARCH_APP_H
#define SEARCH_APP_H
#include <vector>
#include <string>



using namespace std;
class search_app
{
    public:
        search_app();
        virtual ~search_app();
        void load_data();
        int binarysearch(int bot,int top,string rando);
        int testperformance();
        void put_excel();
        string getString();
    protected:
        vector<string>vec;
        double t_comparisons=0;
        int n_comparisons=0;
        double times[100];
        int nums[100];


    private:
};

#endif // SEARCH_APP_H
