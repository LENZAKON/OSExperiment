#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define LOOP true
#define FIRST 1
#define BEST 2
#define EXIT 3
#define TOTALAREA 640
#define FREE "free"
#define BUSY "busy"

typedef struct Node {
    int ID;             // 分区号
    int size;           // 分区大小
    int address;        // 分区所在地址
    char status[10];    // 分区状态
    struct Node *prior; // 前指针
    struct Node *next;  // 后指针
} node, *list;

list first;
list last;

void init() {

    first = (list) malloc(sizeof(node));
    last = (list) malloc(sizeof(node));

    first->prior = NULL;
    first->next = last;

    last->prior = first;
    last->next = NULL;
    last->ID = 0;
    last->size = TOTALAREA;
    last->address = 0;
    strcpy(last->status, FREE);

    return;
}

int firstAlgorithm(int id, int space) {

    list temp = (list) malloc(sizeof(node));
    strcpy(temp->status, BUSY);
    temp->ID = id;
    temp->size = space;

    node *t = first->next;

    while (t) {
        if (t->size == space && strcmp(t->status, FREE) == 0) {

            t->ID = id;
            strcpy(t->status, BUSY);

            return 0;
        } else if (t->size > space && strcmp(t->status, FREE) == 0) {

            temp->prior = t->prior;
            temp->next = t;
            temp->address = t->address;
            t->prior->next = temp;
            t->prior = temp;
            t->address = t->address + temp->size;
            t->size = t->size - temp->size;
            return 0;
        }
        t = t->next;
    }
    return 0;
}

int bestAlgorithm(int id, int space) {

    list temp = (list) malloc(sizeof(node));

    strcpy(temp->status, BUSY);
    temp->ID = id;
    temp->size = space;

    node *t = first->next;

    int minSize;           // 记录适合分配且最小的内存空间
    node *p = NULL;        // 指向适合分配且最小的内存空间的节点

    while (t) {

        if (strcmp(t->status, FREE) == 0 && t->size >= space) {

            minSize = t->size;
            p = t;
            break;
        }
        t = t->next;
    }

    while (t) {

        if (strcmp(t->status, FREE) == 0 && t->size == space) {

            t->ID = id;
            strcpy(t->status, BUSY);
            break;
        }
        if (strcmp(t->status, FREE) == 0 && t->size > space) {

            if (t->size < minSize) {
                minSize = t->size;
                p = t;
            }

        }
        t = t->next;
    }

    if (!p) {
        return 1;
    } else {

        temp->prior = p->prior;
        temp->next = p;
        temp->address = p->address;
        p->prior->next = temp;
        p->prior = temp;
        p->address = temp->address + temp->size;
        p->size = minSize - temp->size;

        return 0;
    }

}

void printfRAM() {

    printf("-------------\n");
    printf("作业号　开始地址　分区大小　状态\n");
    node *p = first->next;
    while (p) {

        printf("%d\t\t%d\t\t%d\t\t%s\n", p->ID, p->address, p->size, p->status);

        p = p->next;
    }

}

void freeSpace() {

    int id;
    printf("请输入要释放的内存的id号\n");
    scanf("%d", &id);

    node *p = first;
    while (p) {
        if (p->ID == id) {

            p->ID = 0;
            strcpy(p->status, FREE);
            if (strcmp(p->prior->status, FREE) == 0) {

                p->prior->size = p->prior->size + p->size;
                p->prior->next = p->next;
                p->next->prior = p->prior;
            }
            if (strcmp(p->next->status, FREE) == 0) {
                p->size = p->size + p->next->size;
                p->next->next->prior = p;
                p->next = p->next->next;
            }
            break;
        }
        p = p->next;
    }
}

void alloc(int selection) {

    int id, space;
    printf("请输入作业号：\n");
    scanf("%d", &id);
    printf("请输入要申请的内存：\n");
    scanf("%d", &space);

    if (space <= 0) {
        printf("请重新输入正确的内存大小：\n");
    } else if (selection == FIRST) {

        if (firstAlgorithm(id, space) == 0) {
            printfRAM();
            printf("\n分配成功\n");
        } else {
            printf("\n分配失败\n");
        }


    } else if (selection == BEST) {


        if (bestAlgorithm(id, space) == 0) {
            printfRAM();
            printf("\n分配成功\n");
        } else {
            printf("\n分配失败\n");
        }

    }
}


void menu() {

    int selection;
    int opeartion;

    printf("请选择算法：\n");
    printf("1. 首次适应算法\n");
    printf("2. 最佳适应算法\n");
    printf("请输入序号\n");

    scanf("%d", &selection);

    while (LOOP) {
        printf("请选择操作：\n");
        printf("1. 申请内存\n");
        printf("2. 释放内存\n");
        printf("3. 退出\n");
        printf("请输入序号：\n");
        scanf("%d", &opeartion);
        if (opeartion == 1) {
            alloc(selection);
        } else if (opeartion == 2) {
            freeSpace();
            printfRAM();
        } else if (opeartion == EXIT) {
            break;
        } else {
            printf("请输入正确的序号\n");
        }
    }

}


int main() {
    init();
    menu();
    return 0;
}