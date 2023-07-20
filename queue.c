/**
 * @copyright Copyright (c) 2023
 * 
 * @file queue.c
 * @author Rishabh Mukund (rishabh.m96@gmail.com)
 * @brief Implementation of Queue with a linked list of variable size multibyte
 *        buffer
 * @version 1.1
 * @date 14/07/2023
 * 
 * 
 * MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * 
*/


#include "queue.h"

#include<stdlib.h>
#include<string.h>


/**
 * @brief Initializes a queue
 * @details Sets the read and write pointers to NULL, and initializes the size
 *          as 0
 * 
 * @param q - pointer to queue to initialize
*/
void queueInit (myqueue_t *q) {
    q->size = 0;
    q->footprint = 0;
    q->head = NULL;
    q->tail = NULL;
}


/**
 * @brief Pushes a multibyte data buffer to queue
 * @details Allocates space for a new node, and a variable length data buffer
 *          and pushes it to the specified queue
 * 
 * @param q - pointer to queue to push to
 * @param data - pointer to data to be pushed
 * @param dataLen - number of bytes in data buffer
 * 
 * @return bool - true if successfully pushed, false otherwise
*/
bool queuePush (myqueue_t *q, const void *data, uint8_t dataLen) {
    // Check if queue exists
    if(q == NULL) {
        return false;
    }

    // Check if the data will fit
    if(q->footprint + ((dataLen + 1) * sizeof(uint8_t)) + sizeof(node_t *)
        > QUEUE_CAPACITY_BYTES) {
        return false;
    }

    // Allocate memory for node
    node_t *newNode = (node_t *)malloc(sizeof(node_t));

    if(newNode == NULL) {
        return false;
    }

    // Allocate memory for data
    newNode->data = (uint8_t *)malloc(dataLen * sizeof(uint8_t));

    if(newNode->data == NULL) {
        free(newNode);
        return false;
    }

    newNode->size = dataLen;
    newNode->next = NULL;

    memcpy(newNode->data, data, dataLen);

    if(q->size == 0) {
        q->head = q->tail = newNode;
    }
    else {
        q->tail->next = newNode;
        q->tail = newNode;
    }

    q->size++;
    q->footprint += ((dataLen + 1) * sizeof(uint8_t)) + sizeof(node_t *);

    return true;
}


/**
 * @brief Remove an item from the queue. Changes the front of queue
 * @details Returns a pointer to the top node and removes it from the queue.
 * 
 * @param q - pointer to the queue to pop from
 * 
 * @return node_t* - pointer to the poped node
*/
node_t* queuePop (myqueue_t *q) {
    // Check if queue exists
    if(q == NULL) {
        return NULL;
    }

    // Check if queue is empty
    if(q->size == 0) {
        return NULL;
    }

    node_t *tempNode = q->head;

    if(q->size > 1) {
        q->head = q->head->next;
    }
    else {
        q->head = NULL;
        q->tail = NULL;
    }

    q->size--;
    q->footprint -= ((tempNode->size + 1) * sizeof(uint8_t)) + sizeof(node_t *);
    tempNode->next = NULL;

    return tempNode;
}


/**
 * @brief returns size of queue
 * 
 * @param  q - pointer to the queue to check
 *
 * @return uint16_t - size of queue (-1 if queue doesnt exist)
*/
uint16_t queueSize (myqueue_t *q) {
    // Check if queue exists
    if(q == NULL)
        return -1;

    return q->size;
}