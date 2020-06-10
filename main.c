#include <string.h>
#include <stdio.h>
#include "car.h"
#include "carlist.h"

void OptionPanel(void)
{
    printf("请输入所需功能对应编码：\n 1.请求停车\n 2.已停车辆请求离开\n \
3.查看当前剩余车位数\n 4.查看所有已停车辆信息\n 5.退出车位管理系统\n**********************\n");
}
void ToParkCar(struct ListNode *p)
{
    struct car *Car;
    printf("请输入车辆信息（按如下顺序）：车牌号 颜色 品牌\n");
    scanf("%s",Car->LicenseNum);
    scanf("%s",Car->color);
    scanf("%s",Car->brand);
    // char license[20], color[10], brand[30]; 
    // scanf("%s",license);
    // scanf("%s",color);
    // scanf("%s",brand);
    // strcpy(Car->LicenseNum,license);
    // strcpy(Car->color,color);
    // strcpy(Car->brand, brand);

    // if(ParkingIsFull(p)){
    //     printf("停车场已满！\n");
    //     return;
    // }
    p = insertElem(p, Car);
    printf("停车成功！\n");
    return;
}
int  main()
{
    struct ListNode *pHead = initList();
    int input_fun_code;
    freopen("sample.txt", "r", stdin);
    OptionPanel();
    while(scanf("%d",&input_fun_code)!= EOF){
        switch(input_fun_code){
            case 1:
                ToParkCar(pHead);
                break;
            case 2:
               // CarLeave();
                break;
            case 3:
                //CheckAvailable();
                break;
            case 4:
                display(pHead);
                break;
            case 5:
                    printf("感谢您使用停车管理系统！\n");
                    break;
            default:
                printf("您输入了无效的功能码,清重新输入：");
        }
    }
    return 0;
}