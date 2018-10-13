#include <iostream>

using namespace std;
struct Node{
    int data;
    Node *next, *prev;
};

struct Node *head = NULL;

Node *getNewNode(int x)
{
    struct Node * temp = new Node();
    temp->data = x;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}
void insertFront(int x)
{
    struct Node * temp = getNewNode(x);
    if(head == NULL){
        head = temp;
        return;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
}

void InsertAtTail(int x) {
	struct Node* temp = head;
	struct Node* newNode = getNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	while(temp->next != NULL) temp = temp->next; // Go To last Node
	temp->next = newNode;
	newNode->prev = temp;
}

void printItr()
{
    struct Node *node = head;
    cout<<"List is: ";
    while(node != NULL){
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

void ReversePrint() {
	struct Node* temp = head;
	if(temp == NULL) return; // empty list, exit
	// Going to last Node
	while(temp->next != NULL) {
		temp = temp->next;
	}
	// Traversing backward using prev pointer
	printf("Reverse: ");
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

int main()
{
    int i, n, value;

    cout << "Enter number of data: "<<endl;
    cin >> n;
    cout<<"Enter "<<n<<" data: "<<endl;

    for(i = 0; i < n; i++)
    {
        cin >> value;
        insertFront(value);
        printItr();
        ReversePrint();
    }

    return 0;
}
