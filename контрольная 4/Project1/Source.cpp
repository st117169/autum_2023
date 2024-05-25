#include <iostream>

struct Node
{
	int data;
	Node* next;
	Node(int data, Node* next = 0) : data(data), next(next) {}
	Node(const Node& node) : data(node.data), next(0) {}
	~Node() { data = 0; next = 0; }
	friend std::ostream& operator<<(std::ostream& stream, Node*& node)
	{
		stream << node->data << " ";
		return stream;
	}
};

class LinkedList
{
public:
    LinkedList() : head(0) {}

    ~LinkedList()
    {
        dispose();
    }

    int Length()
    {
        int l = 0;
        Node* t = head;
        while (t != 0 && t->next != head)
        {
            t = t->next;
            l++;
        }
        return l;
    }

    bool IsEmpty() 
    { 
        return head == nullptr; 
    }

    void PushHead(int data)
    {
        head = new Node(data, head);
    }

    void PushTail(int data) 
    {
        if (IsEmpty())
        {
            return PushHead(data);
        }
    }
    void Insert(int index, int data)
    {
        Node* n = new Node(data);
        InsertNode(Length(), n);
    }
    
    int PopHead()
    {
        return PopData(ExtractNode(0));
    }


    int Extract(int index) 
    {
        return PopData(ExtractNode(index));
    }

    int PopTail()
    {
        return PopData(ExtractNode(Length() - 1));
    }

    int Data(int index)
    {
        Node* n = head;
        for (int i = 0; i < index; i++)
        {
            n = n->next;
        }
        return n != nullptr ? n->data : 0;
    }

    void swap(int ia, int ib)
    {
        if (!IndexValid(ia) || !IndexValid(ib))
        {
            return;
        }
        if (ia == ib)
        {
            return;
        }
        Node* a = ExtractNode(ia); Node* b = ExtractNode(ib);
        if (a == nullptr || b == nullptr)
        {
            return;
        }
        InsertNode(ia, a); InsertNode(ib, b);

    }

    void sort()
    {
        for (int i =0; i < Length(); i ++)
        {
            for (int h = i; h < Length(); h++)
            {
                if (Data(h) > Data(h + 1))
                {
                    swap(h, h + 1);
                }
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& stream, const LinkedList& list)
    {
        Node* n = list.head;
        while (n != nullptr)
        {
            stream << n << " ";
            n = n ->next;
        }
        return stream;
    }


private:

    void dispose()
    {
        while (head != nullptr)
        {
            Node* n = head;
            head = head->next;
            delete n;
        }
    }

    int PopData(Node* node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int n = node->data;
        delete node;
        return n;
    }

    void InsertNode(int index, Node* node)
    {
        if (index == 0 || head == nullptr)
        {
            node->next = head;
            head = node;
        }
        else
        {
            Node* n = head;
            for (int i = 0; i < index - 1; i++)
            {
                n = n->next;
            }
            node->next = n->next;
            n->next = node;
        }
    }


    Node* ExtractNode(int index)
    {
        if (!IndexValid(index))
        {
            return nullptr;
        }
        if (index == 0)
        {
            Node* t = head;
            head = head->next;
            return t;
        }
        Node* n = head;
        for (int i = 0; i < index - 1; i++)
        {
            n = n->next;
        }
        Node* t = n->next;
        n->next = t->next;
        return t;
    }


    bool IndexValid(int index) 
    {
        if (index < 0)
        {
            return false;
        }

        Node* n = head;
        for (int i = 0; i < index - 1; i++)
        {
            n = n->next;
        }
        return n != nullptr;
    }

    Node* head;
};

int main(int argc, char* argv[])
{
    LinkedList list;
    std::cout << list << std::endl;
    list.PushHead(1);
    std::cout << list << std::endl;
    list.PushTail(3);
    std::cout << list << std::endl;
    list.Insert(1, 2);
    std::cout << list << std::endl;
    list.Insert(3, 4);
    std::cout << list << std::endl << std::endl;
    std::cout << list << std::endl;
    std::cout << list.PopHead() << " ";
    std::cout << list.Extract(1) << " ";
    std::cout << list.PopTail() << " ";
    std::cout << list.Extract(0) << std::endl;
    std::cout << list << std::endl << std::endl;

    list.PushHead(3); list.PushHead(4); list.PushHead(1); list.PushHead(2);
    list.PushHead(7); list.PushHead(5); list.PushHead(8); list.PushHead(6);
    std::cout << list << std::endl;
    list.sort();
    std::cout << list << std::endl;
    return EXIT_SUCCESS;