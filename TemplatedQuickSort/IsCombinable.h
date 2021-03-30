#ifndef _IS_COMBINABLE
#define _IS_COMBINABLE

#include <vector>

class is_combinable {
public:
	template<typename T>
	static bool check(T k, std::vector<T>& arr)
    {
        typename std::vector<T>::iterator it_front = arr.begin();
        typename std::vector<T>::iterator it_back = arr.end();
        it_back--;
        while (it_front != it_back) {
            if (*it_front + *it_back == k)
                return true;
            else
                if (*it_front + *it_back > k)
                    it_back--;
                else
                    it_front++;
        }
        return false;
    };
};

#endif // !_IS_COMBINABLE


