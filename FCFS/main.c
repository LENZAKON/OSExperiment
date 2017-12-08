#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define JOBNUM 5                // 进程个数
#define WAIT "wait"             // 进程到达后等待运行状态
#define RUN "run"               // 进程运行状态
#define FINISH "finish"         // 进程运行完成状态
#define NOWAITING -1            // 没有作业等待时的返回值
#define LOOP true               // 循环条件
#define MAX_LINE 1024
#define DATA_LENGTH 15

typedef struct JCB {
    char jobName[12];       // 作业名称
    int arriveTime;         // 到达时间
    int serviceTime;        // 服务时间
    int startTime;          // 开始时间
    int finishedTime;       // 完成时间
    int turnoverTime;       // 周转时间
    float perTurnoverTime;  // 带权周转时间
    char jobStaus[10];      // 作业状态
};

int currentTime = -1;           // 当前时间
int finishJob = 0;              // 已经运行完成的作业数
int hasPreviousJob = false;     // 某个进程运行时是否已经有进程运行完成

// 创建jcb表
void createJCB(struct JCB *jcb) {

    printf("作业名　  到达时间  　服务时间\n");

    // 从文件中读取数据
    FILE *pFile = fopen("/home/linzikang/code/code/os/FCFS/data", "r");

    char data[DATA_LENGTH][MAX_LINE];

    for (int i = 0; i < DATA_LENGTH; i++) {
        fscanf(pFile, "%s", data[i]);
    }
    // 把文件指针移动到文件开头
    rewind(pFile);
    // 关闭文件指针
    fclose(pFile);

    int k = 0;

    for (int i = 0; i < JOBNUM; ++i) {
        strcpy(jcb[i].jobName, &data[k++]);
        jcb[i].arriveTime = atoi(data[k++]);
        jcb[i].serviceTime = atoi(data[k++]);
    }

    for (int j = 0; j < JOBNUM; j++) {
        jcb[j].startTime = 0;
        jcb[j].finishedTime = 0;
        jcb[j].turnoverTime = 0;
        jcb[j].perTurnoverTime = 0.0;
        strcpy(jcb[j].jobStaus, WAIT);
    }

    for (int i = 0; i < JOBNUM; i++) {
        printf("%s\t\t%d\t\t%d\n", jcb[i].jobName, jcb[i].arriveTime, jcb[i].serviceTime);
    }

    return;
}

// 打印jcb表
void printfJCB(struct JCB *jcb) {

    printf("当前时间：%d\n", currentTime);

    printf("进程名称  到达时间  服务时间  开始时间  完成时间  周转时间  带权周转时间  进程状态\n");

    for (int i = 0; i < JOBNUM; i++) {
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%.3f\t\t%s\n", jcb[i].jobName, jcb[i].arriveTime,
               jcb[i].serviceTime, jcb[i].startTime, jcb[i].finishedTime, jcb[i].turnoverTime, jcb[i].perTurnoverTime,
               jcb[i].jobStaus);
    }

    return;
}

// 获得最先到的且处于等待状态的作业的下标
int getFirstArriveIndex(struct JCB *jcb) {

    int firstArriveIndex = 0, testNoWait = 0, minArrive = 10000;
    for (int i = 0; i < JOBNUM; i++) {
        if (strcmp(jcb[i].jobStaus, WAIT) == 0) {
            if (jcb[i].arriveTime < minArrive) {
                minArrive = jcb[i].arriveTime;
                firstArriveIndex = i;
            }
        } else {
            testNoWait++;
        }
    }
    if (testNoWait == JOBNUM) {
        return NOWAITING;
    } else {
        return firstArriveIndex;
    }
}

// 计算响应比
int calcuHRRF(struct JCB jcb) {
    if (currentTime >= jcb.arriveTime) {
        return (jcb.serviceTime + (currentTime - jcb.arriveTime)) / jcb.serviceTime;
    } else {
        return -1;
    }
}

// 获得相应比最高的作业的索引值
int getHRRFIndex(struct JCB *jcb) {

    int maxHRRFIndex = 0, testNoWait = 0, maxHRRF = -1;
    for (int i = 0; i < JOBNUM; i++) {
        if (strcmp(jcb[i].jobStaus, WAIT) == 0) {

            if (calcuHRRF(jcb[i]) != -1) {

                if (calcuHRRF(jcb[i]) > maxHRRF) {
                    maxHRRF = calcuHRRF(jcb[i]);
                    maxHRRFIndex = i;
                }
            }

        } else {
            testNoWait++;
        }
    }
    if (testNoWait == JOBNUM) {
        return NOWAITING;
    } else {
        return maxHRRFIndex;
    }
}

// 高响应比优先调度算法
void HRRF(struct JCB *jcb) {

    int minHRRFIndex = getHRRFIndex(jcb);

    if (minHRRFIndex == NOWAITING) {
        printfJCB(jcb);
    } else {
        jcb[minHRRFIndex].startTime = currentTime;
        jcb[minHRRFIndex].finishedTime = jcb[minHRRFIndex].startTime + jcb[minHRRFIndex].serviceTime;
        jcb[minHRRFIndex].turnoverTime = jcb[minHRRFIndex].finishedTime - jcb[minHRRFIndex].arriveTime;

        jcb[minHRRFIndex].perTurnoverTime =
                jcb[minHRRFIndex].turnoverTime * 1.0 / jcb[minHRRFIndex].serviceTime;

        strcpy(jcb[minHRRFIndex].jobStaus, RUN);

        while (LOOP) {
            if (currentTime == jcb[minHRRFIndex].finishedTime) {

                strcpy(jcb[minHRRFIndex].jobStaus, FINISH);
                finishJob++;
                if (JOBNUM == finishJob) {
                    printfJCB(jcb);
                }

                break;
            } else {
                printfJCB(jcb);
                currentTime++;
            }
        }
    }

    return;

}

// 先来先服务算法
void FCFS(struct JCB *jcb) {

    int firstArriveIndex = getFirstArriveIndex(jcb);

    if (firstArriveIndex == NOWAITING) {
        printfJCB(jcb);
    } else {
        jcb[firstArriveIndex].startTime = currentTime;
        jcb[firstArriveIndex].finishedTime = jcb[firstArriveIndex].startTime + jcb[firstArriveIndex].serviceTime;
        jcb[firstArriveIndex].turnoverTime = jcb[firstArriveIndex].finishedTime - jcb[firstArriveIndex].arriveTime;

        jcb[firstArriveIndex].perTurnoverTime =
                jcb[firstArriveIndex].turnoverTime * 1.0 / jcb[firstArriveIndex].serviceTime;

        strcpy(jcb[firstArriveIndex].jobStaus, RUN);

        while (LOOP) {
            if (currentTime == jcb[firstArriveIndex].finishedTime) {

                strcpy(jcb[firstArriveIndex].jobStaus, FINISH);
                finishJob++;
                if (JOBNUM == finishJob) {
                    printfJCB(jcb);
                }

                break;
            } else {
                printfJCB(jcb);
                currentTime++;
            }
        }
    }

    return;
}


void runHRRF(struct JCB *jcb) {

    // 获得第一个到达时间
    int firstArriveTime = 10000;
    for (int i = 0; i < JOBNUM; i++) {
        if (firstArriveTime > jcb[i].arriveTime) {
            firstArriveTime = jcb[i].arriveTime;
        }
    }

    while (finishJob < 5) {

        if (currentTime < firstArriveTime) {
            printfJCB(jcb);
        } else if (currentTime >= firstArriveTime) {
            if (hasPreviousJob) {
                currentTime--;  // 前一个进程结束时立即开始下一个进程
            }
            HRRF(jcb);
            hasPreviousJob = true;
        }
        currentTime++;
    }
    reset();
}

// 每次执行完算法重置公共变量
void reset() {
    hasPreviousJob = false;
    currentTime = -1;
    finishJob = 0;
}


void runFCFS(struct JCB *jcb) {

    // 获得第一个到达时间
    int firstArriveTime = 10000;
    for (int i = 0; i < JOBNUM; i++) {
        if (firstArriveTime > jcb[i].arriveTime) {
            firstArriveTime = jcb[i].arriveTime;
        }
    }

    while (finishJob < 5) {

        if (currentTime < firstArriveTime) {
            printfJCB(jcb);
        } else if (currentTime >= firstArriveTime) {
            if (hasPreviousJob) {
                currentTime--;  // 前一个进程结束时立即开始下一个进程
            }
            FCFS(jcb);
            hasPreviousJob = true;
        }
        currentTime++;
    }
    reset();
}

// 平均周转时间
void calAverTurTime(struct JCB *jcb) {

    float total = 0.0;
    for (int i = 0; i < JOBNUM; i++) {
        total += jcb[i].turnoverTime;
    }
    float averTurtime = total / JOBNUM;

    printf("\n平均周转时间为: %.3f\n", averTurtime);
}


// 平均带权周转时间
void calAverPreTurTime(struct JCB *jcb) {

    float total = 0.0;
    for (int i = 0; i < JOBNUM; i++) {
        total += jcb[i].perTurnoverTime;
    }
    float averPreTurtime = total / JOBNUM;

    printf("\n平均带权周转时间为: %.3f\n", averPreTurtime);
}


void selectAlgorithm(struct JCB *jcb) {

    int selection;

    while (LOOP) {

        printf("\n请选择算法\n");
        printf("1. 先来先服务算法\n");
        printf("2.　高响应比算法\n");
        printf("3. 退出系统\n");
        printf("请输入序号: ");
        scanf("%d", &selection);

        switch (selection){
            case 1:
                createJCB(jcb);
                runFCFS(jcb);
                calAverTurTime(jcb);
                calAverPreTurTime(jcb);
                break;
            case 2:
                createJCB(jcb);
                runHRRF(jcb);
                calAverTurTime(jcb);
                calAverPreTurTime(jcb);
                break;
            case 3:
                exit(0);
            default:
                printf("请重新输入序号\n");
                break;
        }
    }
}

int main() {

    struct JCB jcb[JOBNUM];

    selectAlgorithm(jcb);

    return 0;
}