/* 
	不能写成while (left < right && arr[left] < pivot), 如输入样例：
	10
	49 59 88 37 98 97 68 54 31 3 

	错误的第二轮划分：pivot = 3 -> left = 0, right = 4, arr[left] = 49, arr[right] = 3 
	-> 3 59 88 37 49 97 68 54 31 
	-> left = 1, right = 1 -> end; 
	-> 下一轮的划分为3 59和88 37 49 97 68 54 31

	正确的第二轮划分：pivot = 3 -> left = 0, right = 4, arr[left] = 49, arr[right] = 3 
	-> 3 59 88 37 49 97 68 54 31 
	-> left = 1, right = 0 -> end; 
	-> 下一轮的划分为3和59 88 37 49 97 68 54 31

	为什么会出现这种情况？3 59 88 37 49 97 68 54 31 -> left = 1，停在了59这儿，而59这儿是不小于pivot=3的情况
	此时[0, 1)是符合情况的，即：左侧为左闭右开的情况；且最多会right + 1 == left的时候停止。因为选择mid位置做pivot
	当移动到pivot元素所在位置时，此时pivot左侧全为不大于pivot的元素集合，而pivot的右侧全为不小于pivot的元素集合，不
	论是left还是right再往下移动一个位置，都会造成判断条件arr[left] < pivot或者arr[right] > pivot条件的不成立，因
	此，最多是right + 1 == left的情况，不会出现right + 2 == left的情况，即：不会出现一直向左的情况. 即：右侧部分为
	左开右闭的情况(0, 1]
*/		
void quick_sort(int *arr, int lo, int hi) {
    // quick partition
    if (lo >= hi) {
        return;
    }
    
    // 假设两个哨兵节点，最左侧为负无穷，最右侧为正无穷
    int left = lo - 1, right = hi + 1;
    int pivot = arr[(left + right) >> 1];
    
    while (left < right) {
        // do while 和 while的形式选择一种即可
        do {
        	++left; 
        } while (arr[left] < pivot);   // arr[left] >= pivot
        do {
        	--right; 
        } while (arr[right] > pivot); // arr[right] <= pivot
        
        // while (arr[++left] < pivot);
        // while (arr[--right] > pivot);
        
        if (left < right) {
            std::swap(arr[left], arr[right]);
        }
    }
    
    quick_sort(arr, lo, right);
    quick_sort(arr, right + 1, hi);
}

/* 
    快排模板记忆方法：
    1. 左右哨兵取极值
    2. 划分区间三部分 - 左小又大中间等，
    3. 游标划分不用比，交换时候比一比
 */