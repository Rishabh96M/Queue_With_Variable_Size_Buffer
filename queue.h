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

#ifndef __SB_QUEUE_H
#define __SB_QUEUE_H

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


void queueInit (myqueue_t *q);
bool queuePush (myqueue_t *q, const void *data, uint8_t dataLen);
node_t* queuePop (myqueue_t *q);
uint16_t queueSize (myqueue_t *q);

#endif /* __SB_QUEUE_H */