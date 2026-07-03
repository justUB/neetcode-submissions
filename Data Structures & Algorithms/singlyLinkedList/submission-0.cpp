typedef struct listnode{
    int val;
    struct listnode* prev;
    struct listnode* next;
} Node;
class LinkedList {
private:
   Node* listHead;
   Node* listTail;
   int size; 

public:
    LinkedList() {
        listHead = NULL;
        listTail = NULL;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size || !listHead)
            return -1;

        Node *curr = listHead;
        while(curr != NULL)
        {
            if (index == 0)
                return curr->val;

            curr = curr->next;
            index--;
        }

        return -1;
    }

    void insertHead(int val) {
        Node * curr = new Node();
        curr->val =  val;
        curr->next = NULL;
        curr->prev = NULL;

        if (listHead)
        {
            Node *nxt = listHead;
            listHead = curr;
            curr->next = nxt;
            nxt->prev = listHead;
        }
        else
        {
            listHead = curr;
            listTail = curr;
        }
        size++;
    }
    
    void insertTail(int val) {
        Node* curr = new Node();
        curr->val =  val;
        curr->next = NULL;
        curr->prev = NULL;

        if (listTail)
        {
            Node *nxt = listTail;
            listTail = curr;
            nxt->next = curr;
            curr->prev = nxt;
        }
        else
        {
            listHead = curr;
            listTail = curr;
        }
        size++;
    }

    bool remove(int index) {
        if(index < 0 || index >= size) return false;

        if (index == 0)
        {
            Node * curr = listHead;
            listHead = curr->next;
            if (listHead) listHead->prev = NULL;
            else listTail = NULL;
            delete curr;
            size--;
            return true;
        }

        if (index == size - 1)
        {
            Node * curr = listTail;
            listTail = curr->prev;
            if (listTail) listTail->next = NULL;
            else listHead = NULL;
            delete curr;
            size--;
            return true;
        }

        Node * curr = listHead;
        int count = 0;
        while(curr)
        {
            if(count == index)
            {
                Node *prevNode = curr->prev;
                Node *nextNode = curr->next;
                prevNode->next = nextNode;
                if (nextNode) nextNode->prev = prevNode;
                delete curr;
                size--;
                return true;
            }
            curr = curr->next;
            count++;
        } 
        return false;       
    }

    vector<int> getValues() {
        Node *curr = listHead;
        vector<int>out;
        while(curr)
        {
            out.push_back(curr->val);
            curr = curr->next;
        }
        return out;
    }
};