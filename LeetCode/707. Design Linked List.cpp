class MyLinkedList {
private:
    class MyLinkedListNode
    {
    public:
        MyLinkedListNode() = default;
        MyLinkedListNode(int val) : val(val), next(nullptr), prev(nullptr) {}
        ~MyLinkedListNode() = default;
        int val;
        MyLinkedListNode* next;
        MyLinkedListNode* prev;
    };

    MyLinkedListNode* head;
    MyLinkedListNode* tail;
    size_t size;
public:
    MyLinkedList() {
        head = new MyLinkedListNode();
        tail = head;
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    int get(int index) {
        if (index >= size)
            return -1;

        int i = 0;
        auto cur_node = head;
        //TODO: 
        while (i < index)
        {
            i++;
            cur_node = cur_node->next;
        }
        return cur_node->val;
    }

    void addAtHead(int val) {
        //额外处理 size 为 0的情况
        if (size == 0)
        {
            head->val = val;
        }
        else
        {
            auto node = new MyLinkedListNode(val);
            //link with head and
            head->prev = node;
            node->next = head;
            //link with tail
            tail->next = node;
            node->prev = tail;
            //make it become new head
            head = node;
        }
        size++;
    }

    void addAtTail(int val) {
        //额外处理 size 为 0的情况
        if (size == 0)
        {
            tail->val = val;
        }
        else
        {
            auto node = new MyLinkedListNode(val);
            //link with head and
            head->prev = node;
            node->next = head;
            //link with tail
            tail->next = node;
            node->prev = tail;
            //make it become new tail
            tail = node;
        }
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size)
            return;
        //额外处理 size 为 0（只有一个结点的情况）
        if (size == 0)
        {
            head->val = val;
            size++;
            return;
        }
        //额外处理在 index 0 和 index size （结尾）处插入的情况。注意是 index size
        //If index equals the length of the linked list, the node will be appended to the end of the linked list.
        if (index == 0)
        {
            addAtHead(val);
        }
        else if (index == size)
        {
            addAtTail(val);
        }
        else
        {
            int i = 0;
            auto cur_node = head;
            while (i < index)
            {
                i++;
                cur_node = cur_node->next;
            }
            auto node = new MyLinkedListNode(val);
            node->next = cur_node;
            node->prev = cur_node->prev;
            cur_node->prev->next = node;
            cur_node->prev = node;
            size++;
        }
    }

    void deleteAtIndex(int index) {
        if (index >= size || size == 0)
            return;
        //额外处理 size 为 1（只有一个结点的情况）
        if (size == 1)
        {
            head->val = INT32_MIN;
            tail = head;
        }
        else
        {
            int i = 0;
            auto cur_node = head;
            while (i < index)
            {
                i++;
                cur_node = cur_node->next;
            }
            cur_node->prev->next = cur_node->next;
            cur_node->next->prev = cur_node->prev;
            //额外处理在 index 0 和 index size - 1（结尾）处删除的情况
            //是 size - 1 不是 size，因为 index 从 0 开始，size - 1 才是合法的最后一个元素
            if (index == 0)
            {
                head = head->next;
            }
            else if (index == size - 1)
            {
                tail = tail->prev;
            }
            delete cur_node;
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
