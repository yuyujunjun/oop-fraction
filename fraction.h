//
// Created by fcsx1 on 2016/11/17.
//

#ifndef FRACTION_FRACTION_H
#define FRACTION_FRACTION_H

#endif //FRACTION_FRACTION_H

#include<iostream>
#include<time.h>
#define random(x) (rand()%100)//get the srand
using namespace std;
class fraction{ //define the class
private:
    int numberator;//分子
    int denominator;//分母
    void reduction();//约分
public:
    fraction(int d,int n);//分别输入分子分母构造
    fraction(int n);//一个参数的情况，将整数变为构造函数
    fraction();//缺省构造函数
    //const void print()const;//print fraction
    const friend fraction operator+(fraction const&a,fraction const&b);//fraction c=a+b
    const friend fraction operator-(fraction const&a,fraction const&b);//c=a-b
    friend const fraction operator*(fraction const&a,fraction const&b);//c=a*b
    friend const fraction operator/(fraction const&a,fraction const&b);//c=a/b
    const fraction operator-()const;//b=-a
    const fraction reciprocal()const;//倒数操作,返回一个新的分数
    friend bool operator==(fraction const&a,fraction const&b);//if(a==b)
    friend bool operator!=(fraction const&a,fraction const&b);//if(a!=b)
    friend bool operator<(fraction const&a,fraction const&b);//if(a<b)
    friend bool operator>(fraction const&a,fraction const&b);//if(a>b)
    friend bool operator>=(fraction const&a,fraction const&b);//if(a>=b)
    friend bool operator<=(fraction const&a,fraction const&b);//if(a<=b)
    friend istream& operator>>(istream& in,fraction& com);
    friend ostream& operator<<(ostream& os,const fraction& com);

};
