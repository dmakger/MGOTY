#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        for(int k=0; k<n; k++){
            cout << arr[k] << " ";
        }
        cout << endl;
    }
    return 0;
}

// Сначала считываем количество элементов в массиве
// Затем создаем вектор и считываем элементы массива
// В цикле от 1 до n-1 проходим по массиву
// Для каждого элемента сохраняем его значение в переменной key и запоминаем его индекс j=i-1
// Пока j>=0 и arr[j]>key, сдвигаем элементы массива на одну позицию вправо и уменьшаем j на 1
// Вставляем key на позицию j+1
// Наконец, выводим состояние массива после каждой вставки