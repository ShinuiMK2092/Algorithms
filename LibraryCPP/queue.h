#ifndef QUEUE_H
#define QUEUE_H

#include "vector.h"
#include <utility>

struct Queue;

Queue *queue_create();
void queue_delete(Queue *queue);
void queue_enqueue(Queue *queue, const std::pair<int, int> &coordinates);
std::pair<int, int> queue_dequeue(Queue *queue);
bool queue_empty(const Queue *queue);
std::pair<int, int> queue_get(const Queue *queue);
void queue_remove(Queue *queue);
void queue_insert(Queue *queue, size_t index, const std::pair<int, int> &coordinates);

#endif