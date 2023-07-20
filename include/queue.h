/**
 * @copyright Copyright (c) 2023
 * 
 * @file queue.h
 * @author Rishabh Mukund (rishabh.m96@gmail.com)
 * @brief Header file for queue with a linked list of variable size multibyte 
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


#pragma once

#include<stdint.h>
#include<stdbool.h>

#define QUEUE_CAPACITY_BYTES 1000

// Node structure including data length
typedef struct node {
    uint8_t *data;
    uint8_t size;
    struct node *next;
} node_t;


// Queue structure
typedef struct myqueue {
    node_t *head;
    node_t *tail;
    uint16_t size;
    uint16_t footprint;
} myqueue_t;


/**
 * @brief Initializes a queue
 * @details Sets the read and write pointers to NULL, and initializes the size
 *          as 0
 * 
 * @param q - pointer to queue to initialize
*/
void queueInit (myqueue_t *q);


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
bool queuePush (myqueue_t *q, const void *data, uint8_t dataLen);


/**
 * @brief Remove an item from the queue. Changes the front of queue
 * @details Returns a pointer to the top node and removes it from the queue.
 * 
 * @param q - pointer to the queue to pop from
 * 
 * @return node_t* - pointer to the poped node
*/
node_t* queuePop (myqueue_t *q);


/**
 * @brief returns size of queue
 * 
 * @param  q - pointer to the queue to check
 *
 * @return uint16_t - size of queue (-1 if queue doesnt exist)
*/
uint16_t queueSize (myqueue_t *q);