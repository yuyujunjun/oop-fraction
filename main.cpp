
#include"fraction.h"
using namespace std;
fraction::fraction(int d, int n):denominator(d),numberator(n){//the first argument as denominator, and the second argument is numberator
    if(0==numberator)//if numberator is zero, the programming will exit
    {
        cout<<"the numberator can't be zero"<<endl;
        exit(0);
    }
    reduction();//reduction
}
fraction::fraction(int d):denominator(d),numberator(1){
    reduction();
}
fraction::fraction():denominator(0),numberator(1){
    reduction();
}
 const fraction fraction:: operator-()const{
    fraction temp(-denominator,numberator);
     return temp;
}
const fraction operator+(fraction const&a,fraction const&b)
{
    fraction temp;
    temp.numberator=a.numberator*b.numberator;
    temp.denominator=a.denominator*b.numberator+a.numberator*b.denominator;
    temp.reduction();
    return temp;
}
const fraction operator-(fraction const&a,fraction const&b)
{
    return a+(-b);

}
void fraction::reduction()//使用辗转相除法
{
    if(numberator==0){
        cout<<"the numberator can't be zero"<<endl;
        exit(0);
    }
    if(denominator!=0) {
        int a, b, temp;
        a=numberator>0?numberator:-numberator;
        b=denominator>0?denominator:-denominator;
        if(a<b)
        {
            temp=a;
            a=b;
            b=temp;
        }
        while (b) {
            temp = a % b;
            a = b;
            b = temp;
        }
        denominator /= a;
        numberator /= a;
        if(numberator<0){
            numberator=-numberator;
            denominator=-denominator;
        }
    }
}
const fraction fraction::reciprocal() const {
    fraction temp(numberator,denominator);
    return temp;
}
bool operator==(fraction const &a,fraction const &b)
{
    fraction c=a-b;
    return c.denominator==0;
}
bool operator!=(fraction const &a,fraction const &b)
{
    return !(a==b);
}
const fraction operator*(fraction const &a, fraction const &b) {
    fraction temp(a.denominator*b.denominator,a.numberator*b.numberator);
    return temp;
}
const fraction operator/(fraction const &a, fraction const &b) {
        fraction c=b.reciprocal();
        return a*c;
}

bool operator>(fraction const &a,fraction const &b)
{
    fraction c=a-b;
    return c.denominator>0;
}
bool operator<(fraction const &a,fraction const &b)
{
    return !(a>=b);
}
bool operator>=(fraction const &a,fraction const &b)
{
    fraction c=a-b;
    return c.denominator>=0;
}
bool operator<=(fraction const &a,fraction const &b)
{
    return !(a>b);
}
const void fraction:: print()const
{
    if(numberator!=1&&denominator!=0)
        cout<<denominator<<"/"<<numberator<<endl;
    else if(numberator==1)
        cout<<denominator<<endl;
    else if(denominator==0)
        cout<<0<<endl;

}
int main() {//get some exam
    srand((int)time(0));
    int numerator=random();
    int denomintor=random();
    cout<<"Test output looks like:2, 2/4, 0/1, 2/0"<<endl;
    fraction(2).print();
    fraction(2,4).print();
    fraction(0,1).print();
    //fraction(2,0).print();
    fraction f1;
    f1=denomintor;
    cout<<"the first random fraction by "<<denomintor<<" and "<< "1 : ";
    f1.print();
    numerator=random()*(-3);//for display the fraction<0 and reduction
    denomintor=random()*6;
    fraction f2(denomintor,numerator);
    cout<<"the second random fraction by "<<denomintor<<" and "<<numerator<<" :  ";
    f2.print();
    cout<<"f1+f2=";
    (f1+f2).print();
    cout<<"f1*f2=";
    (f1*f2).print();
    cout<<"f1/f2=";
    (f1/f2).print();
    cout<<"-f2=";
    (-f2).print();
    cout<<"the reciprocal f2=";
    f2.reciprocal().print();
    cout<<"f1<f2:"<<(f1<f2)<<endl;
    cout<<"f1<=f2:"<<(f1<=f2)<<endl;
    cout<<"f1>f2:"<<(f1>f2)<<endl;
    cout<<"f1>=f2:"<<(f1>=f2)<<endl;
    cout<<"f1!=f2:"<<(f1!=f2)<<endl;
    cout<<"f1==f2:"<<(f1==f2)<<endl;

    return 0;
}