/*
duyệt toàn bộ
với N đồ vật, sẽ có 2 khả năng
0: ko lấy
1: có lấy
Ci: giá trị sử dụng
Ai: khối lượng
B: trọng lượng tối đa túi
vậy ta sẽ xét 1 xâu nhị phân
với mỗi bit thuộc tập {0,1}
sao cho tổng a[i]*arr[i]<=B
và có F=c[i]*arr[i] max
và ta xét từng trg hợp , trg hợp nào có
F Optimized thì ta lưu kết quả =fopt
và xâu nhị phân đó là xopt
*/
#include<bits/stdc++.h>
int c[100],a[100],arr[100],B,N;
int xopt[100],fopt;
void init() {
    fopt=-1;
    std::cin>>N>>B;
    for(int i=1;i<=N;++i) {
        std::cin>>a[i]>>c[i];
    }
}
void display() {
    for(int i=1;i<=N;++i) {
        std::cout<<xopt[i];
    }
    std::cout<<std::endl<<fopt;
}
void update(int useValue) {
    for(int i=1;i<=N;++i) {
        xopt[i]=arr[i];
    }
    fopt=useValue;
}
void xuLy() {
    int useValue=0,weight=0;
    for(int i=1;i<=N;++i) {
        int k=c[i]*arr[i];
        useValue+=k;
        k=a[i]*arr[i];
        weight+=k;
    }
    if(weight<=B&&useValue>fopt) {
        update(useValue);
    }
}
void backTrack(int j) {
    for(int i=0;i<=1;++i) {
        arr[j]=i;
        if(j<N) {
        backTrack(j+1);
        }
        else{
        xuLy();  
        }
    }
}
int main() {
    init();
    backTrack(1);
    display();
}