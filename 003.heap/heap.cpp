//实现堆，优先级队列
//任务1：给定一个数组vector，将其变为堆，相当于实现STL的make_heap
//任务2：实现堆排序，交换堆顶和最后一个元素，缩减堆，循环直到堆大小为1
//任务3：优先级队列，插入push，删除pop、top
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//自上向下调整堆，i的左子树和右子树都是堆，只有i可能不满足。
//n代表堆中元素个数，可以小于arr.size()
void my_max_heap(vector<int> &arr, int i, int n) {
	//n <= arr.size()
	int left = i * 2 + 1, right = i * 2 + 2;
	int largest = i;
	if (left < n && arr[left] > arr[largest])
		largest = left;
	if (right < n && arr[right] > arr[largest])
		largest = right;
	if (largest != i) {
		swap(arr[largest], arr[i]);
		my_max_heap(arr, largest, n);
	}
}

//建堆，思路是，从最后一个非叶子节点（最后一个叶子节点的父节点）开始，
//一直到堆顶，调用自上向下调整堆
void my_make_heap(vector<int> &arr) {
	int n = arr.size()-1;//最后一个元素的索引
	for (int i = (n - 1) / 2; i >= 0; --i) {
		my_max_heap(arr, i, arr.size());
	}
}

//堆排序，思路是，先建堆，将堆顶元素与最后一个元素交换，缩减堆的大小，对堆顶进行自上向下调整
//一直到堆的大小变为1
void my_heap_sort(vector<int> &arr) {
	my_make_heap(arr);
	int n = arr.size();
	while (n > 1) {
		swap(arr[0], arr[n - 1]);
		--n;
		my_max_heap(arr, 0, n);
	}
}

//优先级队列，获取堆顶元素
int my_pq_top(vector<int> &arr) {
	//arr.size() > 0
	return arr[0];
}

//优先级队列，移除堆顶元素，思路是，与堆排序相似，用末尾元素覆盖堆顶，进行自上向下调整
void my_pq_pop(vector<int> &arr) {
	//arr.size() > 0
	arr[0] = arr[arr.size() - 1];
	arr.pop_back();
	my_max_heap(arr, 0, arr.size());
}

//优先级队列，插入新元素，思路是，插入在最后，然后自下向上调整，
//直到堆顶或当前节点i的父节点比i更大
//可以看到，通过逐个插入的方式建立的堆，与建堆操作建立的堆，可能是不相同的
void my_pq_push(vector<int> &arr, int num) {
	arr.push_back(num);
	int i = arr.size() - 1;
	while (i > 0 && arr[i] > arr[(i - 1) / 2]) {
		swap(arr[i], arr[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}

int main() {
	vector<int> arr({ 1,4,8,2,7,3,9 });
	//make_heap(arr.begin(), arr.end());
	//for (int x : arr)cout << x << " ";

	//建堆
	my_make_heap(arr);
	//堆排序
	//my_heap_sort(arr);
	for (int x : arr)cout << x << " ";
	cout << endl;

	my_make_heap(arr);
	while (arr.size()) {
		int num = my_pq_top(arr);
		my_pq_pop(arr);
		cout << num << " ";
	}
	cout << endl;

	vector<int> arr1({ 1,4,8,2,7,3,9 });
	vector<int> pq_from_insert;
	for (int x : arr1) {
		my_pq_push(pq_from_insert, x);
	}
	for (int x : pq_from_insert)cout << x << " ";
	cout << endl;

	cin.get();
	return 0;
}



