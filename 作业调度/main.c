#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define PROCESSNUM 5            // 进程个数
#define WAIT "wait"             // 进程到达后等待运行状态
#define RUN "run"               // 进程运行状态
#define FINISH "finish"         // 进程运行完成状态
#define NOTARRIVE "notArrive"   // 进程尚未到达状态
#define NOWAITING -1            // 没有进程等待时的返回值
#define LOOP true               // 循环条件
#define MAX_LINE 1024
#define DATA_LENGTH 15

int currentTime = -1;           // 当前时间
int finishProcess = 0;          // 已经运行完成的进程数
bool hasPreviousPro = false;    // 某个进程运行时是否已经有进程运行完成

typedef struct PCB {
    char processName[12];   // 进程名称
    int arriveTime;         // 到达时间
    int serviceTime;        // 服务时间
    int startTime;          // 开始时间
    int finishedTime;       // 完成时间
    int turnoverTime;       // 周转时间
    float perTurnoverTime;  // 带权周转时间
    char processStaus[10];  // 进程状态
};

// 创建pcb表

void createPCB(struct PCB *pcb) {

    printf("进程名　  到达时间  　服务时间\n");

//    strcpy(pcb[0].processName, "processA");
//    pcb[0].arriveTime = 0;
//    pcb[0].serviceTime = 4;
//
//    strcpy(pcb[1].processName, "processB");
//    pcb[1].arriveTime = 1;
//    pcb[1].serviceTime = 3;
//
//    strcpy(pcb[2].processName, "processC");
//    pcb[2].arriveTime = 2;
//    pcb[2].serviceTime = 5;
//
//    strcpy(pcb[3].processName, "processD");
//    pcb[3].arriveTime = 3;
//    pcb[3].serviceTime = 2;
//
//    strcpy(pcb[4].processName, "processE");
//    pcb[4].arriveTime = 4;
//    pcb[4].serviceTime = 4;

    // 从文件中读取数据
    FILE *pFile = fopen("/home/linzikang/code/code/os/SJF/data", "r");

    char data[DATA_LENGTH][MAX_LINE];

    for (int i = 0; i < DATA_LENGTH; i++) {
        fscanf(pFile, "%s", data[i]);
    }
    // 把文件指针移动到文件开头
    rewind(pFile);
    // 关闭文件指针
    fclose(pFile);

    int k = 0;

    for (int i = 0; i < PROCESSNUM; ++i) {
        strcpy(pcb[i].processName, &data[k++]);
        pcb[i].arriveTime = atoi(data[k++]);
        pcb[i].serviceTime = atoi(data[k++]);
    }


    for (int j = 0; j < PROCESSNUM; j++) {
        pcb[j].startTime = 0;
        pcb[j].finishedTime = 0;
        pcb[j].turnoverTime = 0;
        pcb[j].perTurnoverTime = 0.0;
        strcpy(pcb[j].processStaus, NOTARRIVE);
    }

    for (int i = 0; i < PROCESSNUM; i++) {
        printf("%s\t%d\t\t%d\n", pcb[i].processName, pcb[i].arriveTime, pcb[i].serviceTime);
    }

    return;
}

// 将进程从未到达变成等待状态
void transStatus(struct PCB *pcb) {
    for (int i = 0; i < PROCESSNUM; i++) {
        if (currentTime >= pcb[i].arriveTime && strcmp(pcb[i].processStaus, NOTARRIVE) == 0) {
            strcpy(pcb[i].processStaus, WAIT);
        }
    }
}


void printfPCB(struct PCB *pcb) {

    printf("当前时间：%d\n", currentTime);

    printf("进程名称 到达时间 服务时间 开始时间 完成时间 周转时间 带权周转时间 进程状态\n");

    for (int i = 0; i < PROCESSNUM; i++) {
        printf("%s\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%.3f\t\t%s\n", pcb[i].processName, pcb[i].arriveTime,
               pcb[i].serviceTime, pcb[i].startTime, pcb[i].finishedTime, pcb[i].turnoverTime, pcb[i].perTurnoverTime,
               pcb[i].processStaus);
    }

    return;
}


// 获得最短进程的下标
int getShortestPro(struct PCB *pcb) {
    transStatus(pcb);
    int minTimeIndex = 0, testNoWait = 0, minTime = 10000;
    for (int i = 0; i < PROCESSNUM; i++) {
        if (strcmp(pcb[i].processStaus, WAIT) == 0) {
            if (pcb[i].serviceTime <= minTime) {
                minTime = pcb[i].serviceTime;
                minTimeIndex = i;
            }
        } else {
            testNoWait++;
        }
    }
    // 没有进程等待时则返回 -1
    if (testNoWait == PROCESSNUM) {
        return NOWAITING;
    } else {
        return minTimeIndex;
    }

}

void runProcess(struct PCB *pcb) {
    transStatus(pcb);
    int minTimeProIndex = getShortestPro(pcb);
    if (minTimeProIndex == NOWAITING) {
        printfPCB(pcb);
    } else {

        pcb[minTimeProIndex].startTime = currentTime;
        pcb[minTimeProIndex].finishedTime = pcb[minTimeProIndex].startTime + pcb[minTimeProIndex].serviceTime;
        pcb[minTimeProIndex].turnoverTime = pcb[minTimeProIndex].finishedTime - pcb[minTimeProIndex].arriveTime;
        pcb[minTimeProIndex].perTurnoverTime =
                pcb[minTimeProIndex].turnoverTime * 1.0 / pcb[minTimeProIndex].serviceTime;
        strcpy(pcb[minTimeProIndex].processStaus, RUN);

        while (LOOP) {
            if (currentTime == pcb[minTimeProIndex].finishedTime) {

                strcpy(pcb[minTimeProIndex].processStaus, FINISH);
                finishProcess++;
                transStatus(pcb);
                if (PROCESSNUM == finishProcess) {
                    printfPCB(pcb);
                }
                break;
            } else {
                transStatus(pcb);
                printfPCB(pcb);
                currentTime++;
            }
        }
    }
    return;
}

void startRun(struct PCB *pcb) {

    // 获得第一个到达时间
    int firstArriveTime = 10000;
    for (int i = 0; i < PROCESSNUM; i++) {
        if (firstArriveTime > pcb[i].arriveTime) {
            firstArriveTime = pcb[i].arriveTime;
        }
    }

    while (finishProcess < 5) {

        if (currentTime < firstArriveTime) {
            printfPCB(pcb);
        } else if (currentTime >= firstArriveTime) {
            if (hasPreviousPro) {
                currentTime--;  // 前一个进程结束时立即开始下一个进程
            }
            runProcess(pcb);
            hasPreviousPro = true;
        }
        currentTime++;
    }
}

// 平均周转时间
void calAverTurTime(struct PCB *pcb) {

    float total = 0.0;
    for (int i = 0; i < PROCESSNUM; i++) {
        total += pcb[i].turnoverTime;
    }
    float averTurtime = total / PROCESSNUM;

    printf("\n平均周转时间为: %.3f\n", averTurtime);
}

// 平均带权周转时间
void calAverPreTurTime(struct PCB *pcb) {

    float total = 0.0;
    for (int i = 0; i < PROCESSNUM; i++) {
        total += pcb[i].perTurnoverTime;
    }
    float averPreTurtime = total / PROCESSNUM;

    printf("\n平均带权周转时间为: %.3f\n", averPreTurtime);
}


int main() {

    struct PCB pcb[PROCESSNUM];

    createPCB(pcb);

    startRun(pcb);

    calAverTurTime(pcb);

    calAverPreTurTime(pcb);

    return 0;
}



