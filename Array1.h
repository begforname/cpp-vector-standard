#ifndef ARRAY1_H
#define ARRAY1_H
#include <functional>
#include <initializer_list>
#include <exception>
#include <vector>
using std::function;
using std::initializer_list;
using std::exception;
using std::vector;
typedef function<double(double)> ApplyFunction1;
class Array1
{
    public:
        Array1();
        Array1(const vector<double>& arr);
        Array1(const Array1& arr);
        Array1(const initializer_list<double>& init_list);
        Array1& operator = (const Array1& arr);
        Array1& operator = (const vector<double>& arr);
        Array1& operator = (const initializer_list<double>& init_list);
        bool operator == (const Array1& arr);
        bool operator != (const Array1& arr);
        Array1 operator + (double num) const;
        Array1 operator - (double num) const;
        Array1 operator * (double num) const;
        Array1 operator / (double num) const;
        Array1 operator + (const Array1& arr) const;
        Array1 operator - (const Array1& arr) const;
        Array1 operator * (const Array1& arr) const;
        Array1 operator / (const Array1& arr) const;
        Array1& operator += (const Array1& arr);
        Array1& operator -= (const Array1& arr);
        Array1& operator *= (const Array1& arr);
        Array1& operator /= (const Array1& arr);
        Array1& operator += (double num);
        Array1& operator -= (double num);
        Array1& operator *= (double num);
        Array1& operator /= (double num);
        Array1 apply(const function<long double(long double)>& func) const;
        Array1 apply(const function<double(double)>& func) const;
        double& operator[] (unsigned index);
        double operator [](unsigned index) const;
        unsigned size() const;
        double sum() const;
        double max() const;
        double min() const;
        vector<double> arr_;
        decltype(arr_.cbegin()) begin() const {return arr_.cbegin();}
        decltype(arr_.begin()) begin() {return arr_.begin();}
        decltype(arr_.cend()) end() const {return arr_.cend();}
        decltype(arr_.end()) end() {return arr_.end();}
        bool rowArray;

    protected:

    private:
};
Array1 operator + (double num,const Array1& arr);
Array1 operator - (double num,const Array1& arr);
Array1 operator * (double num,const Array1& arr);
Array1 operator / (double num,const Array1& arr);


#endif // ARRAY1_H
