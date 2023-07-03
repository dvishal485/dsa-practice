#include <bits/stdc++.h>

#include <memory>

using namespace std;

#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define main_start int main(void)
// datatypes
#define i32 int
#define u32 unsigned i32
#define i64 long long
#define u64 unsigned i64
#define usize size_t
// vector print
template <typename T>
void print_vec(vector<T> const& v) {
    std::copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
}

template <typename T>
class Node {
   public:
    typedef Node<T> N;
    shared_ptr<N> next;
    T val;
    Node<T>(T val) : val(val) {
        // cout << "constructing node with val " << val << endl;
    }
    ~Node<T>() {
        // cout << "destructing node with val " << val << endl;
    }

    bool delete_next_node() {
        if (next.get() == nullptr) return false;
        next = next->next;
        return true;
    }

    shared_ptr<N> insert_node_after_me(T val) {
        auto inserted_node = make_shared<N>(val);
        (inserted_node.get())->next = next;
        next = inserted_node;
        return inserted_node;
    }
};
typedef Node<int> N;
class MyLinkedList {
    shared_ptr<N> head;
    shared_ptr<N> tail;
    usize len;

   public:
    MyLinkedList() : len(0) {
        // dummy node
        head = make_shared<N>(0);
        tail = head;
    }

    shared_ptr<N> nodeAtIndex(usize idx) {
        if (idx >= len) return shared_ptr<N>(nullptr);
        auto traversal = head->next;
        while (idx--) traversal = traversal->next;
        return traversal;
    }

    int get(int index) {
        auto node = nodeAtIndex(index);
        if (node.get() == nullptr) return -1;
        return node->val;
    }

    void addAtHead(int val) {
        auto added_node = head->insert_node_after_me(val);
        if (len == 0) tail = added_node;
        len++;
    }

    void addAtTail(int val) {
        auto new_tail = tail->insert_node_after_me(val);
        tail = new_tail;
        if (len == 0) head->next = tail;
        len++;
    }

    void addAtIndex(int index, int val) {
        if (index == len) return addAtTail(val);

        if (index == 0) return addAtHead(val);
        auto node = nodeAtIndex(index - 1);
        if (node.get() == nullptr) return;
        node->insert_node_after_me(val);
        len++;
    }

    void deleteAtIndex(int index) {
        if (index == 0) {
            if (head->delete_next_node()) len--;
            if (len == 0) tail = head;
            return;
        }
        auto node = nodeAtIndex(index - 1);
        if (node.get() == nullptr) return;
        if (node->delete_next_node()) len--;
        if (index == len) {
            tail = node;
        }
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