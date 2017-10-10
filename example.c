#include<stdio.h>
#include"list.h"

typedef struct _fsnode {
    int val;
    struct list_node list;
} fsnode;

int main(){
    struct list_head head;
    fsnode node1;
    fsnode node2;
    fsnode node3;
    fsnode *pos = NULL;
    INIT_LIST_HEAD(&head);
    INIT_LIST_NODE(&node1.list);
    node1.val = 1;
    INIT_LIST_NODE(&node2.list);
    node2.val = 2;
    INIT_LIST_NODE(&node3.list);
    node3.val = 3;
    list_add_tail(&node1.list, &head);
    list_add_tail(&node2.list, &head);
    list_add(&node3.list, &head);
    list_for_each_entry(pos, &head, list) {
        printf("list find %d, deleted\n", pos->val);    
	list_del(&pos->list);
    }
    if (list_empty(&head)) {
        printf("list is null\n");
    }
    return 0;
}

