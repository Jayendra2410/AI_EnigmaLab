#include<stdio.h>
#include<stdlib.h>
#define MAX 6
using namespace std;
int st[MAX], top= -1;
int queue[MAX];
int front = -1, rear = -1;

// SEARCHING
void linearSearch(int arr[], int size, int key)
{
    int found=0;
    for (int i=0;i<size;i++)
	{
        	if (arr[i]==key)
		{
            printf("Element %d found at index %d\n",key,i);
            found=1;
        }
    }
    if(!found)
        printf("Element %d not found in the array\n", key);
}

void binarySearch(int arr[], int size, int key)
{
    int left=0,right=size-1,mid;
    while (left <= right) 
	{
        mid = (left + right) / 2;
        if (arr[mid] == key) 
		{
            printf("Element %d found at index %d\n",key,mid);
            return;
        }
        if (arr[mid]<key)
            left=mid+1;
        else
            right= mid - 1;
    }
    printf("Element %d not found in the array\n", key);
}

// SORTING
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++) 
	{
        for (int j = 0; j < size - i - 1; j++) 
		{
            if (arr[j] > arr[j + 1]) 
			{
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted using Bubble Sort.\n");
}

void insertionsort(int arr[],int size)
{
	for (int i = 1; i < size; i++)
	{
		int j,temp;
		temp=arr[i];
		j=i-1;
		while((temp<arr[j])&&(j>=0))
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
	printf("Array sorted using Insertion Sort.\n");
}

void selectionSort(int arr[], int size) 
{
    for (int i = 0; i < size - 1; i++) 
	{
        int minIndex = i;
        for (int j = i + 1; j < size; j++) 
		{
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    printf("Array sorted using Selection Sort.\n");
}

void merge(int arr[], int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
	{
    if (left < right)
	{
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

// STACK WITHOUT USING STRUCTURE
void push1_Stack(int st[], int val)
{
	if(top == MAX-1)
 	{
  		printf("\n STACK OVERFLOW");
 	}
 	else
 	{
  		top++;
  		st[top] = val;
 	}
}
int pop1_Stack(int st[])
{
	int val;
 	if(top == -1)
 	{
  		printf("\n STACK UNDERFLOW");
  		return -1;
 	}
 	else
 	{
  		val = st[top];
  		top--;
  		return val;
 	}
}
void display1_Stack(int st[])
{
	int i;
 	if(top == -1)
 	{
 		printf("\n STACK IS EMPTY");
	}
 	else
 	{
  		for(i=top;i>=0;i--)
  		printf("\n %d",st[i]);  
  		printf("\n"); 
 	}
}

// QUEUE WITHOUT USING STRUCTURE
void push1_Queue()
{
 	int num;
 	printf("\n Enter the number to be inserted in the queue : ");
 	scanf("%d", &num);
 	if(rear == MAX-1)
 	printf("\n OVERFLOW");
 	else if(front == -1 && rear == -1)
 	front = rear = 0;
 	else
 	rear++;
 	queue[rear] = num;
}
int pop1_Queue()
{
	int val;
	if(front == -1 || front>rear)
 	{
  		printf("\n UNDERFLOW");
  		return -1;
 	}
 	else
 	{
  		val = queue[front];
  		front++;
  		if(front > rear)
  		front = rear = -1;
  		return val;
 	}
}
void display1_Queue()
{
 	int i;
 	printf("\n");
 	if(front == -1 || front > rear)
 	printf("\n QUEUE IS EMPTY");
 	else
 	{
  	for(i = front;i <= rear;i++)
  	printf("\t %d", queue[i]);
 	}
}

// STACK USING STRUCTURE
struct Stack 
{
    int items[MAX];
    int top;
};

void initialize(struct Stack *s) 
{
    s->top = -1;
}

int isFull(struct Stack *s) 
{
    return s->top == MAX - 1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, int item) {
    if (isFull(s)) {
        printf("Stack is full. Cannot push %d.\n", item);
    } else {
        s->items[++s->top] = item;
        printf("%d pushed to the stack.\n", item);
    }
}

int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;  
    } else {
        int item = s->items[s->top--];
        printf("%d popped from the stack.\n", item);
        return item;
    }
}

void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}


// QUEUE USING STRUCTURE
struct Queue 
{
    int data[MAX];
    int front;
    int rear;
};

void initialize(struct Queue *q) 
{
    q->front = -1;
    q->rear = -1;
}

int isFull(struct Queue *q) 
{
    return (q->rear == MAX - 1);
}

int isEmpty(struct Queue *q) 
{
    return (q->front == -1);
}

void enqueue(struct Queue *q, int item) 
{
    if (isFull(q)) 
	{
        printf("Queue is full. Cannot enqueue %d\n", item);
    } else 
	{
        if (isEmpty(q)) 
		{
            q->front = 0;
        }
        q->rear++;
        q->data[q->rear] = item;
        printf("%d enqueued to the queue\n", item);
    }
}

int dequeue(struct Queue *q) 
{
    int item;
    if (isEmpty(q)) 
	{
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else 
	{
        item = q->data[q->front];
        if (q->front == q->rear) 
		{
            initialize(q);
        } else {
            q->front++;
        }
        return item;
    }
}

void display(struct Queue *q) 
{
    if (isEmpty(q)) 
	{
        printf("Queue is empty.\n");
    } else 
	{
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) 
		{
            printf("%d ", q->data[i]);
        }
        printf("\n");
    }
}

// SINGLY LINKED LIST
struct Node 
{
   	int data;
   	struct Node* next;
};
struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int insertAtBeginning(struct Node** head, int data) 
{
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
int insertAtEnd(struct Node** head, int data) 
{
    struct Node* newNode = createNode(data);
    if (*head == NULL) 
	{
        *head = newNode;
        return 0;
    }
    struct Node* current = *head;
    while (current->next != NULL) 
	{
        current = current->next;
    }
    current->next = newNode;
}
int insertAtPosition(struct Node** head, int data, int position) 
{
    if (position < 1) 
	{
        printf("Invalid position. Position should be greater than or equal to 1.\n");
        return 0;
    }
    if (position == 1) 
	{
        insertAtBeginning(head, data);
        return 0;
    }
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    int currentPosition = 1;
    while (currentPosition < position - 1 && current != NULL) 
	{
        current = current->next;
        currentPosition++;
    }
    if (current == NULL) 
	{
        printf("Position is out of range.\n");
        free(newNode);
        return 0;
    }
    newNode->next = current->next;
    current->next = newNode;
}
int deleteFromBeginning(struct Node** head) 
{
    if (*head == NULL) 
	{
        printf("The list is already empty.\n");
        return 0;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}
int deleteFromEnd(struct Node** head) 
{
    if (*head == NULL) 
	{
        printf("The list is already empty.\n");
        return 0;
    }
    if ((*head)->next == NULL) 
	{
        free(*head);
        *head = NULL;
        return 0;
    }
    struct Node* current = *head;
    while (current->next->next != NULL) 
	{
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}
int printList(struct Node* head) 
{
    struct Node* current = head;
    while (current != NULL) 
	{
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
	
// DOUBLY LINKED LIST
struct Node1 
{
    int data1;
    struct Node1* prev;
    struct Node1* next;
};
struct Node1* createNode1(int data1) 
{
    struct Node1* newNode = (struct Node1*)malloc(sizeof(struct Node1));
    newNode->data1 = data1;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
int insertAtBeginning1(struct Node1** head1, int data1) 
{
    struct Node1* newNode = createNode1(data1);
    newNode->next = *head1;
    if (*head1 != NULL) 
	{
        (*head1)->prev = newNode;
    }
    *head1 = newNode;
}
int insertAtEnd1(struct Node1** head1, int data1) 
{
    struct Node1* newNode = createNode1(data1);
    if (*head1 == NULL) 
	{
        *head1 = newNode;
        return 0;
    }
    struct Node1* temp = *head1;
    while (temp->next != NULL) 
	{
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
int insertAtPosition1(struct Node1** head1, int data1, int position1) {
    if (position1 < 1) 
	{
        printf("Invalid position. Position should be >= 1.\n");
        return 0;
    }
    if (position1 == 1) 
	{
        insertAtBeginning1(head1, data1);
        return 0;
    }

    struct Node1* newNode = createNode1(data1);
    struct Node1* temp = *head1;
    int currentPosition = 1;
    while (temp != NULL && currentPosition < position1 - 1) 
	{
        temp = temp->next;
        currentPosition++;
    }

    if (temp == NULL) 
	{
        printf("Position out of range. Insertion not possible.\n");
        free(newNode);
        return 0;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) 
	{
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}
int deleteAtBeginning1(struct Node1** head1)
{
    if (*head1 == NULL) 
	{
        printf("List is empty. Deletion not possible.\n");
        return 0;
    }

    struct Node1* temp = *head1;
    *head1 = temp->next;
    if (*head1 != NULL) 
	{
        (*head1)->prev = NULL;
    }
    free(temp);
}
int deleteAtEnd1(struct Node1** head1) 
{
    if (*head1 == NULL) 
	{
        printf("List is empty. Deletion not possible.\n");
        return 0;
    }

    if ((*head1)->next == NULL) 
	{
        free(*head1);
        *head1 = NULL;
        return 0;
    }

    struct Node1* temp = *head1;
    while (temp->next != NULL) 
	{
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}
int deleteAtPosition1(struct Node1** head1, int position1) 
{
    if (*head1 == NULL) 
	{
        printf("List is empty. Deletion not possible.\n");
        return 0;
    }

    if (position1 < 1) 
	{
        printf("Invalid position. Position should be >= 1.\n");
        return 0;
    }

    if (position1 == 1) 
	{
        deleteAtBeginning1(head1);
        return 0;
    }

    struct Node1* temp = *head1;
    int currentPosition = 1;
    while (temp != NULL && currentPosition < position1) 
	{
        temp = temp->next;
        currentPosition++;
    }

    if (temp == NULL) 
	{
        printf("Position out of range. Deletion not possible.\n");
        return 0;
    }

    if (temp->prev != NULL) 
	{
        temp->prev->next = temp->next;
    }

    if (temp->next != NULL) 
	{
        temp->next->prev = temp->prev;
    }

    free(temp);
}

int displayList1(struct Node1* head1) 
{
    struct Node1* current = head1;
    printf("Doubly Linked List: ");
    while (current != NULL) 
	{
        printf("%d <-> ", current->data1);
        current = current->next;
    }
    printf("NULL\n");
}

// CIRCULAR LINKED LIST
struct Node2 
{
    int data2;
    struct Node2* next;
};
struct Node2* createNode2(int data2) 
{
    struct Node2* newNode = (struct Node2*)malloc(sizeof(struct Node2));
    if (newNode == NULL) 
	{
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data2 = data2;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning2(struct Node2** head2, int data2) 
{
    struct Node2* newNode = createNode2(data2);
    if (*head2 == NULL) 
	{
        newNode->next = newNode; 
    } else 
	{
        struct Node2* last = *head2;
        while (last->next != *head2) 
		{
            last = last->next;
        }
        last->next = newNode;
        newNode->next = *head2;
    }
    *head2 = newNode;
}
void insertAtEnd2(struct Node2** head2, int data2) 
{
    struct Node2* newNode = createNode2(data2);
    if (*head2 == NULL) 
	{
        newNode->next = newNode; 
        *head2 = newNode;
    } else 
	{
        struct Node2* last = *head2;
        while (last->next != *head2) 
		{
            last = last->next;
        }
        last->next = newNode;
        newNode->next = *head2;
    }
}
void insertAtPosition2(struct Node2** head2, int data2, int position2)
{
    if (position2 <= 0) 
	{
        printf("Invalid position. Position should be a positive integer.\n");
        return;
    }

    struct Node2* newNode = createNode2(data2);
    if (position2 == 1) 
	{
        insertAtBeginning2(head2, data2);
    } 
	else 
	{
        struct Node2* current = *head2;
        int i = 1;
        while (i < position2 - 1 && current->next != *head2) 
		{
            current = current->next;
            i++;
        }
        if (i < position2 - 1) 
		{
            printf("Position out of range.\n");
        } 
		else 
		{
            newNode->next = current->next;
            current->next = newNode;
        }
    }
}
void deleteNode2(struct Node2** head2, int data2) 
{
    if (*head2 == NULL) 
	{
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node2* current = *head2;
    struct Node2* prev = NULL;

    while (current->next != *head2 && current->data2 != data2) 
	{
        prev = current;
        current = current->next;
    }

    if (current->data2 != data2) 
	{
        printf("Element not found in the list.\n");
        return;
    }

    if (current == *head2 && current->next == *head2) 
	{
        *head2 = NULL; 
    } else if (current == *head2) 
	{
        struct Node2* last = *head2;
        while (last->next != *head2) 
		{
            last = last->next;
        }
        *head2 = current->next;
        last->next = current->next;
    } else 
	{
        prev->next = current->next;
    }

    free(current);
}
void displayList2(struct Node2* head2) 
{
    if (head2 == NULL) 
	{
        printf("List is empty.\n");
        return;
    }

    struct Node2* current = head2;
    do 
	{
        printf("%d -> ", current->data2);
        current = current->next;
    } while (current != head2);
    printf("\n");
}


int main()
{
	int choice, arr[20], size, i, p, key, choice1, choice2, choice3, choice4, choice5, option1, option2, option3, option4, option5, option6, option7, val,item;
	struct Stack stack;
    initialize(&stack);
    struct Queue q;
    initialize(&q);
    struct Node* head = NULL;
    int data, position;
    struct Node1* head1 = NULL;
    int data1, position1;
    struct Node2* head2 = NULL;
    int data2, position2;
	{
		while(1)
		{
			printf("      MAIN MENU      \n");
			printf("1. Searching A number in a given Sequence \n");
			printf("2. Sorting The given sequence of Numbers\n");
			printf("3. Insertion and Deletion of Elements in Stack\n");
			printf("4. Insertion and Deletion of Elements in Queue\n");
			printf("5. Insertion and Deletion of Elements in Linked List\n");
			printf("6. Exit\n");
			printf("Enter your choice: ");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:
				printf("Enter the number of elements : ");
				scanf("%d",&size);
				printf("Enter %d elements : \n",size);
				for(i=0;i<size;i++)
				{
					scanf("%d",&arr[i]);
				}
				printf("Searching the element.\n");
				printf("1. Linear Search\n");
				printf("2. Binary Search\n"); 
				printf("Enter your choice : ");
				scanf("%d",&choice1);
				switch(choice1)
				{
				case 1:
					printf("Enter the element to search: ");
                	scanf("%d",&key);
                	linearSearch(arr,size,key);
                break;
            	case 2:
                	printf("Enter the element to search: ");
                	scanf("%d",&key);
                	binarySearch(arr,size,key);
                break;
				}
				break;
			case 2:
				printf("Enter the number of elements : ");
				scanf("%d",&size);
				printf("Enter %d elements : \n",size);
				for(i=0;i<size;i++)
				{
					scanf("%d",&arr[i]);
				}
				printf("Sorting the given sequence.\n");
				printf("1. Bubble Sort\n");
				printf("2. Insertion Sort\n");
				printf("3. Selection Sort\n");
				printf("4. Merge Sort\n");
				printf("Enter your choice: ");
				scanf("%d",&choice2);
				switch(choice2)
				{
				case 1:
                	bubbleSort(arr,size);
                	printf("The Sorted Array is : ");
					for (int i = 0; i < size; i++) 
            		printf("%d \t", arr[i]);
                break;
                case 2:
                	insertionsort(arr,size);
                	printf("The Sorted Array is : ");
					for(int i = 0; i < size; i++)
                    printf("%d\t", arr[i]);
                break;
                case 3:
                	selectionSort(arr,size);
                	printf("The Sorted Array is : ");
					for(int i = 0; i < size; i++)
                    printf("%d\t", arr[i]);
                break;
                case 4:
                	mergeSort(arr, 0, size-1);
                	printf("The Sorted Array is : ");
					for(int i = 0; i < size; i++)
                    printf("%d\t", arr[i]);
                break;
		 		}
				break;
			case 3:
				{
					while(1)
					{
						printf("\nInsertion and Deletion of Elements in Stack.\n");
						printf("1. Without Using Structure\n");
						printf("2. With Using Structure\n");
						printf("Enter your choice: ");
						scanf("%d",&choice3);
					switch(choice3)
		    		{
			 		case 1:
					{
						while(1)
						{
							printf("\nInsertion and Deletion of Elements in Stack Without Using Structure.");
							printf("\n 1. PUSH");
  							printf("\n 2. POP");
  							printf("\n 3. DISPLAY");
  							printf("\n 4. EXIT");
  							printf("\n Enter your option: ");
  							scanf("%d", &option1);
							switch(option1)
  							{
  							case 1:
   								printf("\n Enter the number to be pushed on stack: ");
   								scanf("%d", &val);
   								push1_Stack(st, val);
   							break;
  							case 2:
   								val = pop1_Stack(st);
   								if(val != -1)
   								printf("\n The value deleted from stack is: %d", val);
   							break;
  							case 3:
  								display1_Stack(st);
  							break;
  							case 4:
  								printf("Exiting the program.\n");
  								exit(0);
  							break;
  							default :
  								printf("\n Invalid choice");
   							break;
   							}
						}
					}
					break;
					case 2:
					{
						while(1)
						{
							printf("\nInsertion and Deletion of Elements in Stack With Using Structure.");
							printf("\n 1. PUSH");
  							printf("\n 2. POP");
  							printf("\n 3. DISPLAY");
  							printf("\n 4. Exit");
  							printf("\n Enter your option: ");
  							scanf("%d", &option2);
  							switch(option2)
  							{
  							case 1:
                				printf("Enter the element to push: ");
                				scanf("%d", &item);
                				push(&stack, item);
                			break;
            				case 2:
                				pop(&stack);
                			break;
            				case 3:
                				display(&stack);
                			break;
            				case 4:
                				printf("Exiting the program.\n");
                				exit(0);
                			break;
            				default:
                				printf("Invalid choice. Please try again.\n");	
							}
						}
						break;
					}   	
					}
					}
				break;
				}
			case 4:
				{
				while(1)
					{
						printf("\nInsertion and Deletion of Elements in Queue.\n");
						printf("1. Without Using Structure\n");
						printf("2. With Using Structure\n");
						printf("Enter your choice: ");
						scanf("%d",&choice4);
						switch(choice4)
		    			{
		     			case 1:
						{		
							while(1)
							{
								printf("\nInsertion and Deletion of Elements in Queue Without Using Structure.");
								printf("\n 1. PUSH");
  								printf("\n 2. POP");
  								printf("\n 3. DISPLAY");
  								printf("\n 4. Exit");
  								printf("\n Enter your option: ");
  								scanf("%d", &option3);
  								switch(option3)
  								{
  								case 1:
  									push1_Queue();
   								break;
  								case 2:
   									val = pop1_Queue();
   									if (val != -1)
   									printf("\n The number deleted is : %d", val);
   								break;
								case 3:
   									display1_Queue();
   								break;
   								case 4: 
   									printf("\nExiting the program.\n");
                					exit(0);
                				break;
            					default:
                					printf("Invalid choice. Please try again.\n");	
   								break;	
								}
							}
						}	
						break;
						case 2:
						{
							while(1)
							{
								printf("\nInsertion and Deletion of Elements in Queue With Using Structure.");
								printf("\n 1. PUSH");
  								printf("\n 2. POP");
  								printf("\n 3. DISPLAY");
  								printf("\n 4. Exit");
  								printf("\n Enter your option: ");
  								scanf("%d", &option4);
  								switch(option4)
  								{
  								case 1:
                					printf("Enter the element to enqueue: ");
                					scanf("%d", &item);
                					enqueue(&q, item);
                				break;
            					case 2:
                					item = dequeue(&q);
                					if (item != -1) 
									{
                    					printf("%d dequeued from the queue\n", item);
                					}
                				break;
            					case 3:
                					display(&q);
                				break;
            					case 4:
            						printf("\nExiting the program.\n");
                					exit(0);
            					default:
                					printf("Invalid choice. Please try again.\n");	
								}
							}
						}
						break;   	
						}
					}
				}
				break;
			case 5:
				{
					while(1)
					{
						printf("\nInsertion and Deletion of Elements in Linked List.\n");
						printf("1. Insertion and Deletion of Elements in a Singly Linked List\n");
						printf("2. Insertion and Deletion of Elements in a Doubly Linked List\n");
						printf("3. Insertion and Deletion of Elements in a Circular Linked List\n");
						printf("4. EXIT\n");
						printf("Enter your choice: ");
						scanf("%d",&choice5);
						switch(choice5)	
						{
							case 1:
							{
								while(1)
								{	
									printf("1. Insert at beginning\n");
        							printf("2. Insert at end\n");
        							printf("3. Insert at specific position\n");
        							printf("4. Delete from beginning\n");
        							printf("5. Delete from end\n");
        							printf("6. Print list\n");
        							printf("7. Exit\n");
        							printf("Enter your choice: ");
        							scanf("%d", &option5);
        							switch (option5) 
									{
            						case 1:
                						printf("Enter data to insert at the beginning: ");
                						scanf("%d", &data);
                						insertAtBeginning(&head, data);
                					break;
            						case 2:
                						printf("Enter data to insert at the end: ");
                						scanf("%d", &data);
                						insertAtEnd(&head, data);
                					break;
            						case 3:
                						printf("Enter data to insert: ");
                						scanf("%d", &data);
                						printf("Enter position to insert: ");
                						scanf("%d", &position);
                						insertAtPosition(&head, data, position);
                						break;
            						case 4:
                						deleteFromBeginning(&head);
                					break;
            						case 5:
               							deleteFromEnd(&head);
                					break;
            						case 6:
                						printf("Linked List: ");
                						printList(head);
                					break;
            						case 7:
            							printf("\nExiting the program.\n");
                						exit(0);
            						default:
                						printf("Invalid choice! Please enter a valid option.\n");
									}
								}
							}
							break;
							case 2:
							{
								while(1)
								{
									printf("\nDoubly Linked List Operations:\n");
        							printf("1. Insert at the beginning\n");
        							printf("2. Insert at the end\n");
        							printf("3. Insert at a specific position\n");
        							printf("4. Delete from the beginning\n");
        							printf("5. Delete from the end\n");
        							printf("6. Delete from a specific position\n");
        							printf("7. Display the list\n");
        							printf("8. Quit\n");
        							printf("Enter your choice: ");
        							scanf("%d", &option6);
        							switch (option6) 
									{
            						case 1:
                						printf("Enter data to insert at the beginning: ");
                						scanf("%d", &data1);
                						insertAtBeginning1(&head1, data1);
                					break;
            						case 2:
                						printf("Enter data to insert at the end: ");
               							scanf("%d", &data1);
                						insertAtEnd1(&head1, data1);
                					break;
            						case 3:
                						printf("Enter data to insert: ");
                						scanf("%d", &data1);
                						printf("Enter the position to insert at: ");
                						scanf("%d", &position1);
                						insertAtPosition1(&head1, data1, position1);
                					break;
            						case 4:
                						deleteAtBeginning1(&head1);
                					break;
            						case 5:
                						deleteAtEnd1(&head1);
                					break;
            						case 6:
                						printf("Enter the position to delete from: ");
                						scanf("%d", &position1);
                						deleteAtPosition1(&head1, position1);
                					break;
            						case 7:
                						displayList1(head1);
                					break;
            						case 8:
            							printf("\nExiting the program.\n");
                						exit(0);
            						default:
                						printf("Invalid choice. Please enter a valid option.\n");
									}
								}
							}
							break;
							case 3:
							{
								while(1)
								{
									printf("1. Insert at the beginning\n");
        							printf("2. Insert at the end\n");
        							printf("3. Insert at a specific position\n");
        							printf("4. Delete a node\n");
        							printf("5. Display the list\n");
        							printf("6. Exit\n");
        							printf("Enter your choice: ");
        							scanf("%d", &option7);
        							switch (option7) 
									{
            						case 1:
                						printf("Enter data to insert at the beginning: ");
                						scanf("%d", &data2);
               	 						insertAtBeginning2(&head2, data2);
                					break;
            						case 2:
                						printf("Enter data to insert at the end: ");
                						scanf("%d", &data2);
                						insertAtEnd2(&head2, data2);
                					break;
            						case 3:
                						printf("Enter data to insert: ");
                						scanf("%d", &data2);
                						printf("Enter position to insert at: ");
                						scanf("%d", &position2);
                						insertAtPosition2(&head2, data2, position2);
                					break;
            						case 4:
                						printf("Enter data to delete: ");
                						scanf("%d", &data2);
                						deleteNode2(&head2, data2);
                					break;
            						case 5:
                						displayList2(head2);
                					break;
            						case 6:
            							printf("\nExiting the program.\n");
                						exit(0);
            						default:
                						printf("Invalid choice. Please try again.\n");
        							}	
								}
							}
							break;
							case 4:
                				printf("Exiting the program.\n");
                				exit(0);
            				default:
                				printf("Invalid choice. Please try again.\n");
						}
					}
				}
				break;
				case 6:
					printf("Exiting the program.\n");
					exit(0);
				default:
					printf("Invalid Choice.");
			}
		}
	}
	return 0;
}


