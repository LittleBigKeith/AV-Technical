// Question 1 Install g tests and add to cmakes lists
#include "gtest/gtest.h"
#include <iostream>
#include <map>
#include <type_traits>
#include <vector>
#include <thread>
#include <mutex>
#include "main.h"

bool GTEST_FLAG = false;

const int values[] = { 1,2,3,4,5 };
const int NVALS = sizeof values / sizeof (int);

void function(char[][6]);
void fn(const int**);

class Foo;

template <typename T>
struct ptr_holder {
  static_assert(!std::is_same_v<T, std::remove_pointer<T>>);
  T* ptr;
};

struct person{
   int age;
   float weight;
} person;

//NB: declaration moved to Main.h
//NB: definition moved to TesterFunction.cpp for Google Test
/*
class Wallet
{
    int mMoney;
public:
    Wallet() :mMoney(0){}
    int getMoney() { return mMoney; }
    void addMoney(int money)
    {
       std::lock_guard<std::mutex> guard(myMutex);
       for(int i = 0; i < money; ++i)
       {
          mMoney++;
       }
    }
};

int testerFunction()
{
   Wallet walletObject;
   std::vector<std::thread> threads;
   for(int i = 0; i < 5; ++i){
        threads.push_back(std::thread(&Wallet::addMoney, &walletObject, 1000));
   }
   for(int i = 0; i < threads.size() ; i++)
   {
       threads.at(i).join();
   }
   return walletObject.getMoney();
}
*/
//NB: declaration moved to Main.h
//NB: definition moved to TesterFunction.cpp for Google Test

int main(int argc, char *argv[])
{
    // Question 2
    int x = 10;
    int y = 15;
    std::cout << "Q2: ";
    std::cout << "(" << x << "," << y << ")" << std::endl;

    // Question 3 Get the function to run
    char arr[][6] = {"ant", "bat", "cat", "dog", "egg", "fly"};
    std::cout << "Q3: ";
	function(arr);


    // Question 4 Insert in map
    typedef std::map<int, double> valmap;

    valmap m;

    for (int i = 0; i < NVALS; i++)
        m.insert(std::make_pair(values[i], pow(values[i], .5)));
    std::cout << "Q4: ";
    valmap::iterator it = m.begin();
    for (it; it != m.end(); ++it) {
        std::cout << "{" << it->first << "," << it->second << "} ";
    }     
    std::cout << std::endl;
    m.insert(std::pair<int, double> (6,pow(6, .5)));
    m[1] = 2;
    valmap::iterator it2(m.begin());    
    for (it2; it2 != m.end(); ++it2) {
        std::cout << "{" << it2->first << "," << it2->second << "} ";
    }
    std::cout << std::endl;

    // Question 5
    int i = 1, j = 1;
    if ( (i != 3) && (j == 1))
    {
        std::cout << "Q5: ";
        std::cout << "inside if statement\n";
    }
    
    // Question 6 Store a char * pointer in template
    ptr_holder<char *> p;
    std::cout << "Q6: ";
    std::cout << sizeof(p) << "," << &p << std::endl;


    // Question 7 Fix the compiler errors and race conditions
    // Convert the testerFunction() into a google test
    int val = 0;
    std::cout << "Q7: ";
    if (!GTEST_FLAG) {
        for (int k = 0; k < 1000; k++)
        {
            if ((val = Main::testerFunction()) != 5000)
            {
                std::cout << "Error at count = " << k << " Money in Wallet = " << val << std::endl;
                return 1;
            }
        }
        std::cout << "passed" << std::endl;
    }
    else {
        std::cout << "not tested, use gtest instead." << std::endl;
    }

    // Question 8
    {
        int n = 1;
        const int* p = &n;
        std::cout << "Q8: ";
        fn(&p);
        std::cout << std::endl;
    }
    
    // Question 9
    struct person *ptr;
    ptr = (struct person *)malloc (sizeof(struct person));
    if (ptr) {
        ptr->age = 10;
        ptr->weight = 55.5;
        std::cout << "Q9: ";
        std::cout << ptr->age << "," << ptr->weight << std::endl;
        free(ptr);
    }
    
    
    // Question 10 Initialise foo
    Foo foo(int a, Wallet *b);
    std::cout << "Q10: ";
    std::cout << typeid(foo).name() << std::endl;

    // Question 11
    char c;
    std::cout << "Q11: ";
    while((c = getchar()) != EOF && c != '\n')
    {
        putchar(c);
    }
    return 0;                         

}

// Do not change anything besides the ptr variable
void function(char ptr[][6])
{
	char *ptr1;
	ptr1 = (ptr += sizeof(int))[-2];
	printf("%s\n", ptr1);
}

void fn(const int** pp)
{
    printf("%p : %p : %d", pp, *pp, **pp);
}

// Fix any compilation error
class Foo {
public:
    Foo(int a, Wallet* b);
};

Foo::Foo(int a, Wallet* b = NULL) {

}
