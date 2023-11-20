#include <iostream>

// Node structure for the linked list
struct Node
{
    int data;
    Node *next;

    Node(int value) : data(value), next(NULL) {}
};

// Linked list class
class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(NULL) {}

    // Function to insert a node at the end of the linked list
    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to insert a node at a specific position in the linked list
    void insertAtPosition(int value, int position)
    {
        Node *newNode = new Node(value);
        if (position == 1)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *temp = head;
            for (int i = 1; i < position - 1 && temp; ++i)
            {
                temp = temp->next;
            }
            if (!temp)
            {
                std::cout << "Invalid position\n";
                return;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Function to delete a node from the beginning of the linked list
    void deleteFromBeginning()
    {
        if (!head)
        {
            std::cout << "List is empty\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    // Function to delete a node from the end of the linked list
    void deleteFromEnd()
    {
        if (!head)
        {
            std::cout << "List is empty\n";
            return;
        }
        if (!head->next)
        {
            delete head;
            head = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next->next)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    // Function to delete a node from a specific position in the linked list
    void deleteFromPosition(int position)
    {
        if (!head)
        {
            std::cout << "List is empty\n";
            return;
        }
        if (position == 1)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            Node *temp = head;
            for (int i = 1; i < position - 1 && temp; ++i)
            {
                temp = temp->next;
            }
            if (!temp || !temp->next)
            {
                std::cout << "Invalid position\n";
                return;
            }
            Node *nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
    }

    // Function to search and update a node at a specific position
    void searchAndUpdate(int position, int newValue)
    {
        Node *temp = head;
        for (int i = 1; i < position && temp; ++i)
        {
            temp = temp->next;
        }
        if (!temp)
        {
            std::cout << "Invalid position\n";
            return;
        }
        temp->data = newValue;
    }

    // Function to display the linked list
    void display()
    {
        Node *temp = head;
        while (temp)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    LinkedList linkedList;

    // Insert at the end
    linkedList.insertAtEnd(1);
    linkedList.insertAtEnd(2);
    linkedList.insertAtEnd(3);
    linkedList.display(); // Output: 1 2 3

    // Insert at position
    linkedList.insertAtPosition(4, 2);
    linkedList.display(); // Output: 1 4 2 3

    // Delete from beginning
    linkedList.deleteFromBeginning();
    linkedList.display(); // Output: 4 2 3

    // Delete from end
    linkedList.deleteFromEnd();
    linkedList.display(); // Output: 4 2

    // Delete from position
    linkedList.deleteFromPosition(2);
    linkedList.display(); // Output: 4

    // Search and update
    linkedList.searchAndUpdate(1, 7);
    linkedList.display(); // Output: 7

    return 0;
}
