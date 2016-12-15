
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
istream& operator>>(istream& in,fraction& com)
{
    cout<<"import the denominator"<<endl;
    in>>com.denominator;
    cout<<"import the numberator"<<endl;
    in>>com.numberator;
    com.reduction();
    return in;
}
ostream& operator<<(ostream& os,const fraction& com)
{
    if(com.numberator!=1&&com.denominator!=0)
        os<<com.denominator<<"/"<<com.numberator<<endl;
    else if(com.numberator==1)
        os<<com.denominator<<endl;
    else if(com.denominator==0)
        os<<0<<endl;
    return os;
}
fraction fraction:: operator-()const{
    fraction temp(-denominator,numberator);
     return temp;
}
fraction operator+(fraction const&a,fraction const&b)
{
    fraction temp;
    temp.numberator=a.numberator*b.numberator;
    temp.denominator=a.denominator*b.numberator+a.numberator*b.denominator;
    temp.reduction();
    return temp;
}
fraction operator-(fraction const&a,fraction const&b)
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
fraction fraction::reciprocal() const {
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
fraction operator*(fraction const &a, fraction const &b) {
    fraction temp(a.denominator*b.denominator,a.numberator*b.numberator);
    return temp;
}
fraction operator/(fraction const &a, fraction const &b) {
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
//const void fraction:: print()const
//{


//}
int main() {//get some exam
    cout<<"Test output looks like:2, -2/-4, 0/1, 2/0"<<endl;
    cout<<fraction(2);
    cout<<fraction(-2,-4);
    cout<<fraction(0,1);
    //cout<<fraction(2,0);
    fraction f1;//定义两个对象和一个整数
    fraction f2;
    int integer;
    cin>>f1>>f2;//输入两个对象，构造它们
    cin>>integer;//输入整数
    cout<<"the first fraction f1:"<<f1<<endl;//输出两个对象
    cout<<"the second fraction f2:"<<f2<<endl;
    //对两个对象和整数进行四则运算
    cout<<"integer+f1+f2="<<integer+f1+f2<<endl;
    cout<<"f1*integer*f2="<<f1*integer*f2<<endl;
    cout<<"f1/f2/integer="<<f1/f2/integer<<endl;
    cout<<"-f2="<<-f2<<endl;
    cout<<"the reciprocal f2="<<f2.reciprocal();
    cout<<"f1<f2:"<<(f1<f2)<<endl;
    cout<<"f1<=f2:"<<(f1<=f2)<<endl;
    cout<<"f1>f2:"<<(f1>f2)<<endl;
    cout<<"f1>=f2:"<<(f1>=f2)<<endl;
    cout<<"f1!=f2:"<<(f1!=f2)<<endl;
    cout<<"f1==f2:"<<(f1==f2)<<endl;

    return 0;
}
