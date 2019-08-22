//
// Created by iceli on 2019/8/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Kitty {
    char ch;
    int size;
} Kitty;


int cmp(const void *o1, const void *o2) {
    Kitty kitty1 = *((Kitty *) o1);
    Kitty kitty2 = *((Kitty *) o2);
    if (kitty1.size > kitty2.size) {
        return -1;
    }
    if (kitty1.size < kitty2.size) {
        return 1;
    }
    return 0;
}

/**
 *  为啥 heap 放在全局变量就会报错，不懂啊
 * @param s
 * @return
 */
char *frequencySort(char *s) {
    Kitty heap[1999];
    int _size = -1;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {

        bool find = false;
        for (int j = 0; j < _size; j++) {

            if (heap[j].ch == s[i]) {
                heap[j].size++;
                find = true;
            }

        }

        if (!find) {
            Kitty _new = {.size = 1, .ch = s[i]};
            heap[_size++] = _new;
        }

    }


    //排序
    qsort(heap, _size, sizeof(Kitty), cmp);

    char *ch = calloc(len + 5, sizeof(char));
    int start = 0;
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < heap[i].size; j++) {
            ch[start++] = heap[i].ch;
        }
    }

    return ch;
}


int main() {
    char *s = "cccaaa";
    char *ans = frequencySort(s);
    printf("%s\n", ans);
    return 0;
}