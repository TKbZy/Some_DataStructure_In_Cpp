template<class Iter, class T>
Iter binarySearch(Iter s, Iter e, T target) {
    Iter t = e--;
    Iter mid;
    while (s <= e) {
        mid = s + (e - s) / 2;
        if (*mid == target) return mid;
        if (*mid > target) e = mid - 1;
        else s = mid + 1;
    }
    return t;
}

template<class Iter, class T>
Iter lower_bound(Iter s, Iter e, T target) {
    e--;
    Iter mid;
    while (s <= e) {
        mid = s + (e - s) / 2;
        if (*mid < target) s = mid + 1;
        else e = mid - 1;
    }
    return s;
}
template<class Iter, class T>
Iter upper_bound(Iter s, Iter e, T target) {
    e--;
    Iter mid;
    while (s <= e) {
        mid = s + (e - s) / 2;
        if (*mid <= target) s = mid + 1;
        else e = mid - 1;
    }
    return s;
}
