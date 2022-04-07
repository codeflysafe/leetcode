//
// Created by sjhuang on 2022/3/19.
//
#include "leetcode.h"
using namespace  std;
class FrontMiddleBackQueue {
public:

    typedef struct queue_node{
        int val;
        struct queue_node* prev;
        struct queue_node* next;
        queue_node(int v): val(v), prev(nullptr), next(nullptr){};
    } Node;
    // 奇偶数
    bool odd;
    Node *head, *tail, *mid;
    FrontMiddleBackQueue() {
        odd = false;
        head = tail = mid = nullptr;
    }

    void pushFront(int val) {
        Node *node = new Node(val);
        // 如果头节点存在
        if(head){
            head->prev = node;
            node->next = head;
            // 头节点更新
            head = node;
        }else{
            head = tail = mid = node;
        }
        odd = !odd;
        if(!odd){
            // 中间节点更新
            mid = mid->prev;
        }
    }

    void pushMiddle(int val) {
        Node *node = new Node(val);
        // 如果中间节点存在
        if(mid){
            // 如果是奇数
            if(odd){
                // 插在前面
                insert_front(mid->prev, mid, val);
                mid = mid->prev;
            }else{
                // 插在后面
                insert_back(mid->next, mid, val);
                mid = mid->next;
            }
        }else{
            head = tail = mid = node;
        }
        odd = !odd;
    }

    void insert_front(Node *prev, Node *cur, int val){
        Node *node = new Node(val);
        // 如果 prev == nullptr
        node->next = cur;
        cur->prev = node;
        if(prev == nullptr){
            head = node;
        }else{
            prev->next = node;
            node->prev = prev;
        }
    }

    void  insert_back(Node *next, Node *cur, int val){
        Node *node = new Node(val);
        // 如果 prev == nullptr
        cur->next = node;
        node->prev = cur;
        if(next == nullptr){
            tail = node;
        }else{
            next->prev = node;
            node->next = next;
        }
    }

    void pushBack(int val) {
        Node *node = new Node(val);
        // 如果头节点存在
        if(tail){
            node->prev = tail;
            tail->next = node;
            // 头节点更新
            tail = node;
        }else{
            head = tail = mid = node;
        }
        odd = !odd;
        if(odd && head != tail){
            // 中间节点更新
            mid = mid->next;
        }
    }

    int popFront() {
        // 从前面弹出
        if(!head) return -1;
        else {
            int val = head->val;
            if(head == tail){
                head = tail = mid = nullptr;
            }else{
                head = head->next;
                head->prev = nullptr;
            }

            odd = !odd;
            if(odd && mid){
                mid = mid->next;
            }
            return val;
        }

    }

    int popMiddle() {
        if(!mid){
            return -1;
        }
        int val = mid->val;
        if(head == tail){
            head = tail= mid = nullptr;
        }else{
            Node *p = mid->prev, *ne = mid->next;
            if(p && ne){
                p->next = ne;
                ne->prev = p;
                if(!odd){
                    mid = ne;
                }else mid = p;
            }else if(ne){
                ne->next = nullptr;
                ne->prev = nullptr;
                head = tail = mid = ne;
            }

        }
        odd = !odd;
        return val;
    }

    int popBack() {
// 从前面弹出
        if(!head) return -1;
        else {
            int val = tail->val;
            if(head == tail){
                head = tail = mid = nullptr;
            }else{
                tail = tail->prev;
                tail->next = nullptr;
            }

            odd = !odd;
            if(!odd && mid){
                mid = mid->prev;
            }
            return val;
        }
    }


};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */

int main(){
    FrontMiddleBackQueue q ;
   //  q.pushFront(1);   // [1]
    q.pushBack(2);    // [1, 2]
//    q.pushMiddle(3);  // [1, 3, 2]
//    q.pushMiddle(4);  // [1, 4, 3, 2]
//    cout << q.popFront() << " " ;     // 返回 1 -> [4, 3, 2]
    cout << q.popMiddle() << " ";    // 返回 3 -> [4, 2]
//    cout << q.popMiddle() << " ";    // 返回 4 -> [2]
//    cout << q.popBack() << " ";      // 返回 2 -> []
//    cout << q.popFront() << " ";     // 返回 -1 -> [] （队列为空）

    return 0;
}