#include "car.h"
#include <stdio.h>
#include <stdlib.h>
struct ListNode{
    struct car *ParkingCar;
    struct ListNode *next;
};


struct ListNode *initList(){
    struct ListNode *p=(struct ListNode*)malloc(sizeof(struct ListNode));//创建头结点
    p->ParkingCar=NULL;
    p->next=NULL;
    return p;
}


struct ListNode * insertElem(struct ListNode * p,struct car *ParkingCar){
    /*申请新节点并赋值*/
    struct ListNode *c=(struct ListNode*)malloc(sizeof(struct ListNode));
    c->ParkingCar=ParkingCar;
    c->next=NULL;
    /*寻找尾结点*/
    struct ListNode *temp=p;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    /*新结点插入链表尾部*/
    temp->next=c;
    return p;
}


struct ListNode * delElem(struct ListNode * p,int add){
    struct ListNode * temp=p;
    for(int i=1;i<add;i++){
        temp=temp->next;
    }
    struct ListNode * del=temp->next;
    temp->next=temp->next->next;
    free(del);
    return p;
}


struct ListNode *amendElem(struct ListNode * p,int add,int newElem){
    struct ListNode * temp=p;
    temp=temp->next;
    for(int i=1;i<add;i++){
        temp=temp->next;
    }
    temp->ParkingCar=newElem;
    return p;
}


int selectElem(struct ListNode * p,int ParkingCar){
    struct ListNode * j=p;
    int i=1;
    while(j->next){
        j=j->next;
        if(j->ParkingCar==ParkingCar){
            return i;
        }
        i++;
    }
    return -1;
}


void display(struct ListNode *p){
    struct ListNode *temp=p;
    while(temp->next){
        temp=temp->next;
        printf("%s,%s,%s",temp->ParkingCar->LicenseNum,temp->ParkingCar->color,temp->ParkingCar->brand);
    }
    printf("\n");
}