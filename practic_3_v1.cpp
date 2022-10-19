#include "sortic.h"

int main()
{
    srand((unsigned int)time(NULL));
    setlocale(LC_ALL, "rus");
    int size, start_point = 0;
    cin >> size;
    vector <int> ar(size);
    int last_point = size - 1;

    ar_random(ar);
    //ar_show(ar);
    cout << endl;
    auto start = steady_clock::now();
    select_sort(ar);
    auto end = steady_clock::now();
    duration <double> elapsed =  (end - start);
    cout << elapsed.count() << endl;

    ar_random(ar);
    start = steady_clock::now();
    quick_sort(ar, start_point, last_point);
    end = steady_clock::now();
    elapsed =  (end - start);
    cout << elapsed.count() << endl;

    //ar_show(ar);
    ar.clear();

    return 0;
}

