#include <iostream>

struct ListNode {
    int value;
    struct ListNode *next;

    explicit ListNode(int value) {
        this->value = value;
        this->next = nullptr;
    }
};

struct LinkedList {
    struct ListNode *head;

    LinkedList() { head = nullptr; }

    void read() const {
        ListNode *current_node = head;
        while (current_node != nullptr) {
            std::cout << current_node->value << '\n';
            current_node = current_node->next;
        }
    }

    void add_to_end(int value) {
        auto *node = new ListNode(value);
        if (head == nullptr) {
            head = node;
            return;
        }
        ListNode *current_node = head;
        while (current_node->next != nullptr) {
            current_node = current_node->next;
        }
        current_node->next = node;
    }

    void add_to_start(int value) {
        auto *node = new ListNode(value);
        node->next = head;
        head = node;
    }

    void delete_end() {
        if (head == nullptr)
            return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        ListNode *current_node = head;
        while (current_node->next->next != nullptr) {
            current_node = current_node->next;
        }
        delete (current_node->next)->next;
        current_node->next = nullptr;
    }

    void delete_start() {
        if (head == nullptr) {
            return;
        }
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
};

int main() {
    LinkedList list = LinkedList();
    for (int i = 0; i < 2; ++i) {
        list.add_to_end(i);
    }
    list.delete_end();
    list.delete_end();
    list.add_to_end(10);
    list.add_to_start(20);
    list.delete_start();
    list.read();
}