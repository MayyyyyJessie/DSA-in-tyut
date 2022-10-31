#include <iostream>
#include "SqList.h"
using namespace std;

// 删除all值为x的元素                    ------------------------------------
// 有位置挑数字
void delnode1(SqList *&L,int x){
    int id = 0;
    for (int i = 0; i < L->length; ++i) {
        if(L->data[i] != x){
            L->data[id] = L->data[i];
            id++;
        }
    }
    L->length = id;
}
// 有数字找位置
void delnode2(SqList * &L,int x){
    int k = 0;
    for (int i = 0; i < L->length; ++i) {
        if (L->data[i] == x){
            k++;
        } else L->data[i - k] = L->data[i];
    }
    L->length = L->length - k;
}

// 以第一个元素为分界线 分离大于和小于它的数 ------------------------------------
// 交换
void partition1(SqList* &L){
    int s = L->data[0];
    int l = 0,r = L->length-1;
    while(l < r){
        while (l < r && L->data[r] > s) r--;
        //这个在前 因为是以第一个数为分界线 最后的边界l=r应该是小的 这样swap后才不会混
        while (l < r && L->data[l] <= s) l++;
//        if (l < r) 这个??
        swap(L->data[l],L->data[r]);
    }
    swap(L->data[0],L->data[l]);
}

// 覆盖
void partition2(SqList* &L){
    int s = L->data[0];
    int l = 0,r = L->length-1;
    while (l < r){
        while (l < r && L->data[r] > s) r--;
        L->data[l] = L->data[r];
        while (l < r && L->data[l] <= s) l++;
        L->data[r] = L->data[l];
    }
    L->data[l] = s;
}
// all奇数移到偶数的前面
void move1(SqList* &L){
    int l = 0,r = L->length-1;
    while(l < r){
        while (l < r && L->data[r] % 2 == 0) r--;
        while (l < r && L->data[l] % 2 != 0) l++;
        swap(L->data[l],L->data[r]);
    }
}

void move2(SqList* &L){
    int j = -1;
    for (int i = 0; i < L->length; ++i) {
        if (L->data[i] % 2 != 0){
            j++;
//            if(i != j) ??
            swap(L->data[i],L->data[j]);
        }
    }
}

int main(){
    SqList* L = NULL;
    int nums[5] = {7,8,9,6,3};
    CreateList(L,nums,5);
    cout << "L is:" <<endl;
    DispList(L);

//    int x = 9;
//    delnode2(L,x);
//    partition2(L);
    move2(L);
    cout << "L is:" <<endl;
    DispList(L);
    return 0;
}