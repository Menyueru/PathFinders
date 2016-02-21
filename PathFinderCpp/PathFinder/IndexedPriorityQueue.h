#ifndef INDEXEDPRIORITY_QUEUE
#define INDEXEDPRIORITY_QUEUE
#include<vector>
#include <cassert>

template<class Type>
class MinIndexedPriorityQueue{
private:
	std::vector<Type>& Keys;
	std::vector<int> Heap;
	std::vector<int> InvHeap;
	int Size, MaxSize;

	void Swap(int i,int j){
		int temp = Heap[i];
		Heap[i] = Heap[j];
		Heap[j] = temp; 

		InvHeap[Heap[i]] = i;
		InvHeap[Heap[j]] = j;
	}

	void ReorderUp(int k){
		while (k > 1 && Keys[Heap[k / 2]] > Keys[Heap[k]]){
			Swap(k / 2, k);
			k /= 2;
		}
	}

	void ReorderDown(int k, int HeapSize){
		while (2 * k <= HeapSize){
			int child = 2 * k;
			if (child<HeapSize && Keys[Heap[child / 2]]>Keys[Heap[child + 1]]){
				++child;
			}
			if (Keys[Heap[k]] <= Keys[Heap[child]]){
				break;
			}
			Swap(child, k);
			k = child;
		}
	}
public:
	MinIndexedPriorityQueue(std::vector<Type>& keys, int maxSize) :Keys(keys), MaxSize(maxSize), Size(0){
		Heap.assign(MaxSize + 1, 0);
		InvHeap.assign(MaxSize + 1, 0);
	}

	bool IsEmpty()const{ return Size == 0; }

	void Insert(const int id){
		assert(Size+1 <=MaxSize && "Trying to Insert more than MaxSize into PriorityQueue");

		++Size;
		Heap[Size] = id;
		InvHeap[id] = Size;
		ReorderUp(Size);
	}

	int Pop(){
		Swap(1, Size);
		ReorderDown(1, Size - 1);
		return Heap[Size--];
	}

	void ChangePriority(int id){
		ReorderUp(InvHeap[id]);
	}

};

#endif