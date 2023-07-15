/**
 * @file main.c
 * @author Rishabh Mukund (rishabh.m96@gmail.com)
 * @brief File with test code for implementation of multibyte buffer queue 
 * @version 0.1
 * @date 14/07/2023
*/

#include "queue.h"
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include<stdbool.h>
#include<string.h>

int main() {
    myqueue_t q;
    uint8_t data[10] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09};

    queueInit(&q);

    while(true) {
        if(!queuePush(&q, data, 10)) {
            printf("Queue is full, Queue size is %u\n", queueSize(&q));
            break;
        }
        data[0]++;
    }

    printf("/nContents of the Queue are: /n");

    node_t *temp;
    while(true) {
        temp = queuePop(&q);
        if(temp == NULL) {
            printf("Queue is empty");
            break;
        }

        for(uint8_t i = 0; i < temp->size; i++) {
            printf("%x, ", temp->data[i]);
        }
        printf("\r\n");
    }
}