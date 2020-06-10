#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "car.h"

#define MAXSIZE 100
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

int ParkingIsFull(struct ListNode *p){
    struct ListNode *temp=p;
    int i=0;
    while(temp->next!=NULL){
        temp=temp->next;
        ++i;
    }
    if(i<MAXSIZE){
        return 0;
    }
    else
        return 1;
}


struct ListNode * insertElem(struct ListNode * p,struct car *ParkingCar){
    /*申请新结点并赋值*/
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


struct ListNode *delElem(struct ListNode *p,int add){
    struct ListNode *temp=p;
    for(int i=1;i<add;i++){
        temp=temp->next;
    }
    struct ListNode * del=temp->next;
    temp->next=temp->next->next;
    free(del);
    return p;
}


// struct ListNode *amendElem(struct ListNode * p,int add,struct ListNode newElem){
//     struct ListNode * temp=p;
//     temp=temp->next;
//     for(int i=1;i<add;i++){
//         temp=temp->next;
//     }
//     temp->ParkingCar=newElem;
//     return p;
// }


struct ListNode *selectElem(struct ListNode * p,struct car ParkingCar){
    //struct ListNode *j=p;
    struct ListNode *temp=p;
    while(temp->next!=NULL){
        if(strcmp(temp->ParkingCar->LicenseNum,ParkingCar.LicenseNum)==0){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}


void display(struct ListNode *p){
    struct ListNode *temp=p;
    if(temp->next == NULL){
        printf("停车场是空的！\n");
        return; 
    }
    while(temp->next){
        temp=temp->next;
        printf("%s,%s,%s\n",temp->ParkingCar->LicenseNum,temp->ParkingCar->color,temp->ParkingCar->brand);
    }
}