#include "Array1.h"

Array1::Array1():arr_(){
    rowArray=true;
}
Array1::Array1(const vector<double>& arr):arr_(arr){
    rowArray=true;
}
Array1::Array1(const Array1& arr):arr_(arr.arr_){
    rowArray=true;
}
Array1::Array1(const initializer_list<double>& init_list):arr_(init_list){
    rowArray=true;
}
Array1& Array1::operator = (const Array1& arr){
    arr_ = arr.arr_;
    return *this;
}
Array1& Array1::operator= (const vector<double>& arr){
    arr_ = arr;
    return *this;
}
Array1& Array1::operator= (const initializer_list<double>& init_list){
    arr_ = init_list;
    return *this;
}
bool Array1::operator == (const Array1& arr){
    if(arr_.size()!=arr.size()) return false;
    else{
        int size_ = arr_.size();
        bool res = true;
        for(int i=0;i<size_;i++) if(arr[i]!=arr_[i]){
            res = false;
            break;
        }
        return res;
    }
}
bool Array1::operator != (const Array1& arr){
    return !((*this)==arr);
}
Array1 Array1::operator + (double num) const{
    Array1 res = *this;
    for(auto& element:res.arr_){
        element+=num;
    }
    return res;
}
Array1 Array1::operator - (double num) const{
    Array1 res = *this;
    for(auto& element:res.arr_){
        element-=num;
    }
    return res;
}
Array1 Array1::operator * (double num) const{
    Array1 res = *this;
    for(auto& element:res.arr_){
        element*=num;
    }
    return res;
}
Array1 Array1::operator / (double num) const{
    Array1 res = *this;
    for(auto& element:res.arr_){
        element/=num;
    }
    return res;
}
double& Array1::operator[] (unsigned index){
    return arr_[index];
}
double Array1::operator[] (unsigned index) const{
    return arr_[index];
}
unsigned Array1::size() const{
    return arr_.size();
}
Array1 Array1::operator + (const Array1& arr) const{
    Array1 res = *this;
    if(res.size()!=arr.size()) throw exception();
    int length = res.size();
    for(int i=0;i<length;i++) res[i]+=arr[i];
    return res;
}
Array1 Array1::operator - (const Array1& arr) const{
    Array1 res = *this;
    if(res.size()!=arr.size()) throw exception();
    int length = res.size();
    for(int i=0;i<length;i++) res[i]-=arr[i];
    return res;
}
Array1 Array1::operator * (const Array1& arr) const{
    Array1 res = *this;
    if(res.size()!=arr.size()) throw exception();
    int length = res.size();
    for(int i=0;i<length;i++) res[i]*=arr[i];
    return res;
}
Array1 Array1::operator / (const Array1& arr) const{
    Array1 res = *this;
    if(res.size()!=arr.size()) throw exception();
    int length = res.size();
    for(int i=0;i<length;i++) res[i]/=arr[i];
    return res;
}
Array1& Array1::operator += (const Array1& arr){
    if(size()!=arr.size()) throw exception();
    int length = size();
    for(int i=0;i<length;i++) arr_[i]+=arr[i];
    return *this;
}
Array1& Array1::operator -= (const Array1& arr){
    if(size()!=arr.size()) throw exception();
    int length = size();
    for(int i=0;i<length;i++) arr_[i]-=arr[i];
    return *this;
}
Array1& Array1::operator *= (const Array1& arr){
    if(size()!=arr.size()) throw exception();
    int length = size();
    for(int i=0;i<length;i++) arr_[i]*=arr[i];
    return *this;
}
Array1& Array1::operator /= (const Array1& arr){
    if(size()!=arr.size()) throw exception();
    int length = size();
    for(int i=0;i<length;i++) arr_[i]/=arr[i];
    return *this;
}
Array1 operator + (double num,const Array1& arr){
    Array1 res = arr;
    int length = arr.size();
    for(int i=0;i<length;i++){
        res[i] = num + res[i];
    }
    return res;
}
Array1 operator - (double num,const Array1& arr){
    Array1 res = arr;
    int length = arr.size();
    for(int i=0;i<length;i++){
        res[i] = num - res[i];
    }
    return res;
}
Array1 operator * (double num,const Array1& arr){
    Array1 res = arr;
    int length = arr.size();
    for(int i=0;i<length;i++){
        res[i] = num * res[i];
    }
    return res;
}
Array1 operator / (double num,const Array1& arr){
    Array1 res = arr;
    int length = arr.size();
    for(int i=0;i<length;i++){
        res[i] = num / res[i];
    }
    return res;
}
double Array1::sum() const{
    if(arr_.size()==0) throw exception();
    double res = 0;
    for(auto e:arr_) res += e;
    return res;
}
double Array1::max() const{
    if(arr_.size()==0) throw exception();
    double res = arr_[0];
    for(auto e:arr_) res = (e>res)?e:res;
    return res;
}
double Array1::min() const{
    if(arr_.size()==0) throw exception();
    double res = arr_[0];
    for(auto e:arr_) res = (e>res)?res:e;
    return res;
}
Array1 Array1::apply(const function<long double(long double)>& func) const{
    Array1 res = arr_;
    for(auto& e:res.arr_) e=func(e);
    return res;
}
Array1 Array1::apply(const function<double(double)>& func) const{
    Array1 res = arr_;
    for(auto& e:res.arr_) e=func(e);
    return res;
}
Array1& Array1::operator += (double num){
    for(auto&e :arr_) e+=num;
    return *this;
}
Array1& Array1::operator -= (double num){
    for(auto&e :arr_) e-=num;
    return *this;
}
Array1& Array1::operator *= (double num){
    for(auto&e :arr_) e*=num;
    return *this;
}
Array1& Array1::operator /= (double num){
    for(auto&e :arr_) e/=num;
    return *this;
}
