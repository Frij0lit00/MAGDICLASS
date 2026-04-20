#include <iostream>
using namespace std;

int main(void) {

    int a, b;
    int *ptr1 = NULL;
    int *ptr2 = NULL;
    int **pptr = NULL;

    int A[5] = {1,2,3,4,5};

    ptr1 = &a;
    ptr2 = &b;

    *ptr1 = 5;   // antes estaba mal: ptr1 = 5;
    cout << ptr1 << endl;

    *ptr2 = 5;
    *ptr1 = *ptr2;

    cout << a << endl;
    cout << b << endl;

    pptr = &ptr1;   // antes estaba mal
    pptr = &ptr2;

    **pptr += 5;

    cout << pptr << endl;
    cout << *pptr << endl;
    cout << **pptr << endl;

    *pptr = ptr1;
    **pptr += 10;

    cout << a << endl;
    cout << b << endl;

    *pptr = ptr2;
    ptr2 = &a;

    cout << *ptr1 << endl;
    cout << *ptr2 + 4 << endl;

    a = 2;
    b = *ptr2 + 3;

    cout << *pptr << endl;
    cout << **pptr << endl;
    cout << ptr1 << endl;
    cout << ptr2 << endl;

    **pptr += 1;

    cout << *ptr1 << endl;
    cout << *ptr2 << endl;

    a = 8;
    b = 6;

    pptr = &ptr1;
    **pptr -= 3;

    cout << pptr << endl;
    cout << *ptr1 << endl;
    cout << *ptr2 << endl;
    cout << b << endl;
    cout << a << endl;
    cout << **pptr << endl;

    ptr1 = A;
    pptr = &ptr1;

    cout << (pptr + 3) << endl;
    cout << *ptr1 << endl;
    cout << (ptr1 + 3) << endl;

    for (int i = 0; i < 5; i++) {
        // esta línea estaba completamente mal
        // (pptr + i) =( pptr +i ) +1;
        // no se puede hacer eso con doble puntero
    }

    cout << *(ptr1 + 1) << endl;
    cout << (pptr + 2) << endl;
    cout << (*pptr + 2) << endl;
    cout << (ptr1 + 4) << endl;

    return 0;
}
