// C++ program to illustrate the use of unique_ptr 
#include <iostream> 
#include <memory> 
#include <algorithm>
#include <iostream>
#include <vector>

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
    cout << "Time taken by test_vector_insert: "
         << duration.count() << " microseconds" << endl;
}

std::vector<Employee> empData;
std::vector<Employee> empData1;

void test_vector_insert()
{
    for(uint32_t itr = 0; itr < gSampleSize; itr++)
    {
        empData.push_back(Employee(itr, "abcd", itr+5000));
    }
}

void test_vector_find()
{
    for(auto itr = empData.begin(); itr != empData.end(); itr++) {
        empData.pop_back();
    }
}

void test_reserved_vector_insert()
{    
    for(uint32_t itr = 0; itr < gSampleSize; itr++)
    {
        empData1.push_back(Employee(itr, "abcd", itr+5000));
    }
}

void test_reserved_vector_find()
{
    for(auto itr = empData.begin(); itr != empData.end(); itr++) {
        empData1.pop_back();
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
    
    PROFILE(test_vector_insert(), time_aken);
    cout << "test_vector_insert copies: " << TotalCopyOperations() << endl;
    cout << "test_vector_insert execution time: " << time_aken << endl;
    PROFILE(test_vector_find(), time_aken);
    cout << "test_vector_find execution time: " << time_aken << endl;

    empData1.reserve(gSampleSize);

    PROFILE(test_reserved_vector_insert(), time_aken);
    cout << "test_reserved_vector_insert copies: " << TotalCopyOperations() << endl;
    cout << "test_reserved_vector_insert execution time: " << time_aken << endl;
    PROFILE(test_reserved_vector_find(), time_aken);
    cout << "test_reserved_vector_find execution time: " << time_aken << endl;

    return 0;
}
