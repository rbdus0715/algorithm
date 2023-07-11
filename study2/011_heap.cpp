#include <iostream>
#include <vector>
using namespace std;

vector<int> heap;

void push_heap(vector<int>& heap, int newValue) {
    
    heap.push_back(newValue);
    int idx = heap.size() - 1;
    
    while(idx > 0 && heap[(idx-1)/2] < heap[idx]) {
        swap(heap[(idx-1)/2], heap[idx]);
        idx = (idx-1)/2;
    }
}

void pop_heap(vector<int>& heap) {
    
    cout << heap[0];
    
    heap[0] = heap.back();
    heap.pop_back();
    int here = 0;
    
    while(true) {
        int left = here * 2 + 1, right = here * 2 + 2;
        
        // 리프 노드 도착
        if(left >= heap.size()) break;
    
        int next = here;
        if(heap[next] < heap[left])
            next = left;
        if(right < heap.size() && heap[next] < heap[right])
            next = right;
        
        if(next == here) break;
        
        swap(heap[here], heap[next]);
        here = next;
    }
}

int main() {
    
    push_heap(heap, 3);
    push_heap(heap, 2);
    push_heap(heap, 4);
    push_heap(heap, 9);
    push_heap(heap, 1);
    push_heap(heap, 7);
    
    pop_heap(heap);
    pop_heap(heap);
    pop_heap(heap);
    pop_heap(heap);
    pop_heap(heap);
    pop_heap(heap);
}
