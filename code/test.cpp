#include<limits>
#include<iostream>
int main(){


int t = std::numeric_limits<int>::digits;
t = 2>>1;
std::cout << t <<std::endl;

}