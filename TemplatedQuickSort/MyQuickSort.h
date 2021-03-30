#ifndef _MY_QUICK_SORT
#define _MY_QUICK_SORT

#include <vector>

class my_quick_sort
{
private:
	template <typename T>
	static size_t divide_arr(std::vector<T>& arr, size_t l, size_t r);

	template<typename T>
	static void move_elements(std::vector<T>& arr, size_t l, size_t r);

	inline static size_t select_pivot(size_t l, size_t r);

public:
	template <typename T>
	static void sort(std::vector<T>& arr, size_t l, size_t r);

	template <typename T>
	static void sort(std::vector<T>& arr);

};

template <typename T>
void my_quick_sort::sort(std::vector<T>& arr, size_t l, size_t r)
{
	if (l < r)
	{
		size_t i = divide_arr(arr, l, r);
		if(i!=0)
			my_quick_sort::sort(arr, l, i - 1);
		if(i!=r)
			my_quick_sort::sort(arr, i + 1, r);
	}
};

template <typename T>
void my_quick_sort::sort(std::vector<T>& arr)
{
	my_quick_sort::sort(arr, 0, arr.size() - 1);
}

template <typename T>
size_t my_quick_sort::divide_arr(std::vector<T>& arr, size_t l, size_t r)
{
	size_t mid_id = select_pivot(l, r);
	T mid_val = arr[mid_id];
	move_elements(arr, mid_id, r);

	size_t current_pos = l;
	for (size_t i = l; i < r; ++i) {
		if (arr[i] < mid_val) {
			move_elements(arr, i, current_pos);
			++current_pos;
		}
	}
	move_elements(arr, current_pos, r);
	return current_pos;
};


size_t my_quick_sort::select_pivot(size_t l, size_t r)
{
	return l + (r - l) / 2;
}

template <typename T>
void my_quick_sort::move_elements(std::vector<T>& arr, size_t l, size_t r)
{
	if (l != r)
	{
		std::swap(arr[l], arr[r]);
	}
}


#endif // !_MY_QUICK_SORT

