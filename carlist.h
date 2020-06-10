#include "car.h"
#include <stdio.h>
#include <stdlib.h>
struct ListNode{
    struct car *ParkingCar;
    struct ListNode *next;
};

ListNode * initList();
ListNode * insertElem(ListNode * p,int ParkingCar);
//向列表中加入元素
ListNode * delElem(ListNode * p,int add);
//将列表中第add个元素删除
ListNode *amendElem(ListNode * p,int add,int newElem);
//将列表中第add个元素内容更改为newElem数据域中的内容
int selectElem(ListNode * p,int ParkingCar);
//查找列表中的某个结点的内容
void display(ListNode *p);



ListNode *initList(){
    ListNode *p=(ListNode*)malloc(sizeof(ListNode));//创建头结点
    ListNode *temp=p;//只想头结点的指针，用于遍历链表
    for(int i=1;i<5;i++){
        ListNode *a=(ListNode*)malloc(sizeof(ListNode));
        a->ParkingCar=i;
        a->next=NULL;
        temp->next=a;
        temp=temp->next;
    }
    return p;
}


ListNode * insertElem(ListNode * p,int ParkingCar){
    ListNode * c=(ListNode*)malloc(sizeof(ListNode));
    c->ParkingCar=ParkingCar;
    c->next=temp->next;
    temp->next=c;
    return p;
}


ListNode * delElem(ListNode * p,int add){
    ListNode * temp=p;
    for(int i=1;i<add;i++){
        temp=temp->next;
    }
    ListNode * del=temp->next;
    temp->next=temp->next->next;
    free(del);
    return p;
}


ListNode *amendElem(ListNode * p,int add,int newElem){
    ListNode * temp=p;
    temp=temp->next;
    for(int i=1;i<add;i++){
        temp=temp->next;
    }
    temp->ParkingCar=newElem;
    return p;
}


int selectElem(ListNode * p,int ParkingCar){
    ListNode * j=p;
    int i=1;
    while(j->next){
        j=j->next;
        if(t->ParkingCar==ParkingCar){
            return i;
        }
        i++;
    }
    return -1;
}


void display(ListNode *p){
    ListNode* temp=p;
    while(temp->next){
        temp=temp->next;
        printf("%d",temp->ParkingCar);
    }
    printf("\n");
}