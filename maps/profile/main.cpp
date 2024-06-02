// C++ program to illustrate the use of unique_ptr 
#include <iostream> 
#include <memory> 
#include <stdint.h>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <chrono>
#include <iostream>
#include<vector>
#include <unordered_map>

using namespace std::chrono;
using namespace std;

#define MAX_SIZE (1000000)

class Employee
{
    uint32_t mId = 0;
    string mName;
    uint32_t mSalary = 0;
    public:
    Employee(uint32_t aId, string aName, uint32_t aSalary):
    mId(aId), mName(aName),mSalary(aSalary){}
};

typedef void (*FuncToExecute)(void);

#define PROFILE(fn) \
do{ \
    auto start = high_resolution_clock::now(); \
    fn(); \
    auto stop = high_resolution_clock::now(); \
 \
   auto duration = duration_cast<microseconds>(stop - start); \
    cout << "Time taken by " << #fn << ": " \
         << duration.count() << " microseconds" << endl; \
}while(0)

void execute_function(FuncToExecute aFn)
{
    auto start = high_resolution_clock::now();
    aFn();
    auto stop = high_resolution_clock::now();

   auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by test_map_insert: "
         << duration.count() << " microseconds" << endl;
}

std::map<uint32_t, Employee> empData;
unordered_map<uint32_t, Employee> empData1;

void test_map_insert()
{
    for(size_t itr = 0; itr < MAX_SIZE; itr++)
    {
        empData.insert(make_pair(itr, Employee(itr, "abcd", itr+5000)));
    }
}

void test_unordered_map_insert()
{    
    for(size_t itr = 0; itr < MAX_SIZE; itr++)
    {
        empData1.insert(make_pair(itr, Employee(itr, "abcd", itr+5000)));
    }
}

void test_map_find()
{        
    auto val = empData.find(MAX_SIZE);
    for(size_t itr = 1; itr < MAX_SIZE; itr++) {
        val = empData.find(MAX_SIZE);
    }
}

void test_unordered_map_find()
{
    auto val = empData1.find(MAX_SIZE);
    for(size_t itr = 1; itr < MAX_SIZE; itr++) {
        val = empData1.find(MAX_SIZE);
    }
}

int main()
{
    PROFILE(test_map_insert);
    PROFILE(test_unordered_map_insert);

    PROFILE(test_map_find);
    PROFILE(test_unordered_map_find);

    return 0;
}