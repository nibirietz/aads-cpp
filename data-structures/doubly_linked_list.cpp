#include <list>
#include <iostream>

struct ListNode {
    int value;
    ListNode *previous;
    ListNode *next;

    ListNode(int value) {
        this->value = value;
        this->previous = nullptr;
        this->next = nullptr;
    }
};

struct DoublyLinkedList {
    ListNode *head;
    ListNode *tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void add_to_end(int value) {
        auto *node = new ListNode(value);
        if (head == nullptr) {
            head = node;
            tail = node;
            return;
        }
        node->previous = tail;
        tail->next = node;
        tail = node;
    }

    void add_to_start(int value) {
        auto *node = new ListNode(value);
        head->previous = node;
        node->next = head;
        head = node;
    }

    void delete_start() {
        if (head == nullptr)
            return;
        auto temp = head;
        head->next->previous = nullptr;
        head = head->next;
        delete temp;
    }

    void delete_end() {
        if (tail == nullptr) {
            return;
        }
        auto temp = tail;
        tail->previous->next = nullptr;
        tail = tail->previous;
        delete temp;
    }

    void read() {
        auto current_node = head;
        while (current_node != nullptr) {
            std::cout << current_node->value << "\n";
            current_node = current_node->next;
        }
    }
};

int main() {
    auto x = DoublyLinkedList();
    x.add_to_end(10);
    x.add_to_end(20);
    x.add_to_end(4104);
    x.add_to_start(13);
    x.delete_start();
    x.delete_end();
    x.read();
    std::list
}