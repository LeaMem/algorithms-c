//
// Created by iceli on 2019/8/21.
//

#include <stdio.h>
#include <stdlib.h>

int m_heap[50];
int m_capacity = 50;
int m_size = 0;


//向上调整
static void filter_up(int end) {

    int parent = (end - 1) / 2;
    int tmp = m_heap[end];

    while (end > 0) {

        if (m_heap[parent] >= tmp) {
            break;
        } else {
            m_heap[end] = m_heap[parent];
            end = parent;
            parent = (end - 1) / 2;
        }

    }

    m_heap[end] = tmp;

}

static void filter_down(int start, int end) {
    int l = 2 * start + 1;
    int tmp = m_heap[start];

    while (l <= end) {
        if (l < end && m_heap[l] < m_heap[l + 1]) {
            l++;
        }
        if (tmp >= m_heap[l]) {
            break;
        } else {
            m_heap[start] = m_heap[l];
            start = l;
            l = 2 * start + 1;
        }
    }
    m_heap[start] = tmp;
}

void insert(int data) {

    m_heap[m_size] = data;
    filter_up(m_size);
    m_size++;

}

int pop() {
    int data = m_heap[0];
    m_heap[0] = m_heap[--m_size];
    filter_down(0, m_size - 1);
    return data;
}

int lastStoneWeight(int *stones, int stonesSize) {
    for (int i = 0; i < stonesSize; i++) {
        insert(stones[i]);
    }

    while (m_size > 1) {
        int first = pop();
        int second = pop();
        if (first != second) {
            insert(first - second);
        }
    }


    return m_size == 0 ? 0 : pop();
}


int main() {

    int stones[2] = {2, 2};

    int weight = lastStoneWeight(stones, 2);

    printf("%d\n", weight);

    return 0;

}