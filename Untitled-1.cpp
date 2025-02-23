#include<bits/stdc++.h>
using namespace std;
struct item{
    int profit,weight;
    item(int profit,int weight){
        this->profit=profit;
        this->weight=weight;
    }
};
static bool cmp(struct item a,struct item b){
     double r1=(double)a.profit/(double)a.weight;
    double r2=(double)b.profit/(double)b.weight;
    return r1>r2;
}
 double knapsack(int W,struct item arr[],int N){
    sort(arr,arr+N,cmp);
    (double)final_value=0.0;
    for(int i;i<N;i++){
        if(arr[i].weight<W){
            w-=arr[i].weight;
            final_value +=arr[i].profit;
        }
        else {
        final_value += arr[i].profit*((double)W/(double)arr[i].weight);
        break;}
    }
    return final_value;
}
int main(){
    int w =50;
    item arr[]={{60,10},{100,20},{120,30}}
    int N=sizeof(arr)/sizeof(arr[0]);
    cout<<knapsack(int W,arr[],int N);
    return 0;
}