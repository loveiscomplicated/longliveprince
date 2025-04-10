// Question 7: Linked List Implementation
struct Node {
    int val;
    Node* next;
};


class MyLinkedList {
    public:
        MyLinkedList() {
            head = nullptr;
            size = 0;
        }
        
        // find a node
        Node* findByPtr(int index) {
            if ((index < 0) || (index >= size)) {
                return nullptr;
            } else {
                Node* tempiter = head;
                for (int i = 0; i < index; i++) {
                    tempiter = tempiter -> next;
                }
                return tempiter;
            }
        }

        int get(int index) {
            // TODO: Implement
            if ((index < 0) || (index > size - 1)) {
                return -1;
            } else {
                return findByPtr(index)->val;
            }
        }
        
        void addAtHead(int val) {
            // TODO: Implement
            Node* NewNodeptr =  new Node; // create a new node
            NewNodeptr->val = val; // assign the value of new node
            NewNodeptr->next = head; // the next node has to be the previous head node
            head = NewNodeptr; // updating the head pointer pointing to new node
            size++; // updating the list size
        }
        
        void addAtTail(int val) {
            // TODO: Implement
            Node* NewNodeptr =  new Node; // create a new node
            NewNodeptr->val = val; // assign the value of new node
            NewNodeptr->next = nullptr;

            if (head == nullptr) {
                head = NewNodeptr;

            } else {
                Node* tempIter = head;
                for (int i = 0; i < (size - 1); i++) {
                    tempIter = tempIter->next;
                }
                tempIter->next = NewNodeptr;
            }
            size++;
        }
        
        void addAtIndex(int index, int val) {
            // TODO: Implement
            if (index == 0) { 
                addAtHead(val);
            } else if (index == size) {
                addAtTail(val);
            } else if ((index < 0) || (index > size)) {
                return;
            } else {
                Node* NewNodeptr =  new Node;
                NewNodeptr->next = findByPtr(index);
                NewNodeptr->val = val;
            
                findByPtr(index - 1)->next = NewNodeptr;
                size++;
            }
        }
        
        void deleteAtIndex(int index) {
            // TODO: Implement
            if ((index < 0) || (index >= size)) {
                return;
            } else if (index == 0) {
                Node* tempHead = head;
                head = head->next;
                delete tempHead;
                size--;
            } else {
                Node* tempPtr1 = findByPtr(index - 1);
                Node* tempPtr2 = findByPtr(index);
                Node* tempPtr3 = findByPtr(index + 1);
                
                tempPtr1->next = tempPtr3;
                delete tempPtr2;
                size--;
            }
        }
    
    private:
        Node* head;
        int size;
};