
#include<stdio.h>
#include <stdlib.h>

typedef struct tree {
    int item;           /* data item */
    struct tree *left;  /* pointer to left child */
    struct tree *right; /* pointer to right child */
} tree;


 typedef struct list
{
    int i;
    struct list *next;
} list; 

struct tree* create_tree(int value) {
    struct tree *l  = (struct tree*) malloc(sizeof(struct tree));
    l->item = value;
    l->left = NULL;
    l->right= NULL;
    return l;     
}

void add_tree(tree *tree, int value) {
    int current_value = tree->item;

    if(value < current_value){
        if(tree->left == NULL){
          struct tree *sub_tree = create_tree(value);
          tree->left = sub_tree;
        }
        else  
          add_tree(tree->left, value);  
    } else {
         if(tree->right == NULL){
          struct tree *sub_tree = create_tree(value);
          tree->right = sub_tree;
        }
        else  
          add_tree(tree->right, value); 
    }
}

void printTree(tree *l)
{
if (l != NULL) {
    printTree(l->left);
    printf("%d,", l->item);
    printTree(l->right);
  }
}

struct list* create(int value)
{
    struct list *l = (struct list*) malloc(sizeof(struct list)); 

    l->i = value;
    l->next = NULL; 

    return l;
};

void printList(struct list *l) {
       printf("%d,", l->i);
       if(l->next != NULL){
            printList(l->next);
       }
      
       
}

void insert_list(struct list **tail, int x){
    struct list* head = create(x);
    head->next = *tail;
    *tail = head;
}

int contains(list *l, int e) {
    if(l == NULL)return 0; 
    if(l->i == e) return 1;
    return contains(l->next, e);
}

list* search(struct list * l, int elem) {
    if(l == NULL) return NULL;

    if(l->i == elem) {
        return l;
    }else{
       return search(l->next, elem);
    }
}

int main(void)
{    

  struct list *l = create(6);

  insert_list(&l, 5);
  insert_list(&l, 6);
  insert_list(&l, 7);
  insert_list(&l, 8);
  insert_list(&l, 9);

  //printList(l);

  //printf("list contains %d", contains(l,12));


   struct tree *tree = create_tree(5);

   add_tree(tree,1);
   add_tree(tree,6);
   add_tree(tree,4);


   printTree(tree);


   int r = 0;
   for (int i = 1; i <= 10; i++){
       for (int j = i; j < 2 * i; j++){
           r += 1;
       }
   }

   int arr[] = {1,2,3,4,5,6,7,8,9};
   //printf("%lu\n",sizeof(arr) / sizeof(arr[0]));
      
}



void insestion_sort(int arr[]) {
   int n = sizeof(arr) / sizeof(arr[0]);

   for (int i = 1; i < n; i++) {
          int tmp = arr[i];
          int j = i - 1;
          while (j >= 0 && tmp < arr[j]){
              arr[j + 1] = arr[j];
              j--;
          }
          arr[j + 1] = tmp;
   }

}
