// C++ program to illustrate the use of unique_ptr 
#include <iostream> 
#include <memory> 
#include <stdint.h>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

#include "../../include/profile.hpp"

using namespace std::chrono;
using namespace std;

#define MAX_SIZE (900000)
size_t gSampleSize = MAX_SIZE;

size_t aCopyCount = 0;

size_t TotalCopyOperations()
    {
        size_t val = aCopyCount;
        aCopyCount = 0;
        return val;
    }


class Employee
{
    uint32_t mId = 0;
    string mName;
    uint32_t mSalary = 0;    
    public:
    Employee(uint32_t aId, string aName, uint32_t aSalary):
    mId(aId), mName(aName),mSalary(aSalary){}

    Employee(const Employee &aEmp):
    mId(aEmp.mId), mName(aEmp.mName), mSalary(aEmp.mSalary)
    {
        aCopyCount++;
    }
    
};

typedef void (*FuncToExecute)(void);

void execute_function(FuncToExecute aFn)
{
    auto start = high_resolution_clock::now();
    aFn;
    auto stop = high_resolution_clock::now();

   auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by test_map_insert: "
         << duration.count() << " microseconds" << endl;
}

std::map<uint32_t, Employee> empData;
unordered_map<uint32_t, Employee> empData1;

void test_map_insert()
{
    for(uint32_t itr = 0; itr < gSampleSize; itr++)
    {
        empData.insert(make_pair(itr, Employee(itr, "abcd", itr+5000)));
    }
}

void test_unordered_map_insert()
{    
    for(uint32_t itr = 0; itr < gSampleSize; itr++)
    {
        empData1.emplace(make_pair(itr, Employee{itr, "abcd", itr+5000}));
    }
}

void test_map_find()
{        
    auto val = empData.find(gSampleSize);
    for(uint32_t itr = 1; itr < gSampleSize; itr++) {
        val = empData.find(gSampleSize);
    }
}

void test_unordered_map_find()
{
    auto val = empData1.find(gSampleSize);
    for(uint32_t itr = 1; itr < gSampleSize; itr++) {
        val = empData1.find(gSampleSize);
    }
}

int main(int argc, char* argv[])
{
    uint32_t time_aken;
    if(argc > 2) {
        cout<<"Usage: ./program <sample-count>"<<endl;
        return 1;
    }
    if(argc == 2) {
        gSampleSize = strtoul(argv[1], nullptr, 0);
    }

    cout<<"Testing for "<< gSampleSize << " samples"<<endl;
    empData1.reserve(gSampleSize);

    PROFILE(test_map_insert(), time_aken);
    cout << "test_map_insert copies: " << TotalCopyOperations() << endl;
    cout << "test_map_insert execution time: " << time_aken << endl;
    PROFILE(test_map_find(), time_aken);
    cout << "test_map_find execution time: " << time_aken << endl;

    PROFILE(test_unordered_map_insert(), time_aken);
    cout << "test_unordered_map_insert copies: " << TotalCopyOperations() << endl;
    cout << "test_unordered_map_insert execution time: " << time_aken << endl;
    PROFILE(test_unordered_map_find(), time_aken);
    cout << "test_unordered_map_find execution time: " << time_aken << endl;

    return 0;
}
