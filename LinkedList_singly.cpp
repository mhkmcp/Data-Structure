#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};
struct Node *head = NULL;

void insertFront(int value){
    Node *temp = new Node();
    temp->data = value;
    temp->next = head;
    head = temp;
}
void insertBack(int value){
    Node *temp = new Node();
    temp->data = value;
    temp->next = NULL;
    if(head == NULL)
        head = temp;
    else {
        Node *temp1 = head;

        while(temp1->next != NULL)
            temp1 = temp1->next; /// temp1 points to last node
        temp1->next = temp; /// adding to tail
    }
}

void deleteData(int n){
    Node * prev = head;
    if(n == 1)
    {/// to delete the head
        head = prev->next;
        delete prev;
    }
    else { /// to delete any of the rest
        for(int i = 1; i < n - 1; i++)
            prev = prev->next;
        Node * next = prev->next;
        prev->next = next->next;
        delete next;
    }
}

void reverseList()
{
    Node *curr, *prev, *next;
    curr = head;
    prev = NULL;

    while(curr != NULL)
    {
        next = curr->next;  /// next holding address of curr's next
        curr->next = prev;  /// next of curr will be prev in reverese
        prev = curr;        /// new prev is actually curr
        curr = next;        /// new curr is actually next
    }
    head = prev;
}

void printItr()
{
    struct Node *node = head;
    cout<<"List is: ";
    while(node != NULL){
        cout << node->data << "  ";
        node = node->next;
    }
    cout << endl;
}

void printRecFor(struct Node *node)
{
    if(node == NULL)
        return;
    cout<<node->data<<" ";
    printRecFor(node->next);
}
void printRecRev(struct Node *node)
{
    if(node == NULL)
        return;
    printRecFor(node->next);
    cout<<node->data<<" ";
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
        cout<<"Forward: ";
        printRecFor(head);

        cout<<endl<<"Backward: ";
        printRecRev(head);
        cout<<endl<<endl;
    }

    int pos;
    cout<<"Enter a position to delete the value: "<<endl;
    cin >> pos;
    deleteData(pos);
    //print();  /// Head to Tail
    reverseList();
    //print();

    return 0;
}
