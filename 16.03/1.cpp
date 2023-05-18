#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2){
    if(p1.second == p2.second){
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> participants(n);
    for(int i=0; i<n; i++){
        int id, points;
        cin >> id >> points;
        participants[i] = make_pair(id, points);
    }
    sort(participants.begin(), participants.end(), compare);
    for(auto participant: participants){
        cout << participant.first << " " << participant.second << endl;
    }
    return 0;
}

// Сначала считываем количество участников
// Затем создаем вектор пар для участников
// В цикле считываем идентификационный номер и количество баллов каждого участника и добавляем их в вектор пар
// Определяем функцию compare для сортировки вектора пар
// Сортируем вектор пар по количеству баллов в порядке убывания, а при равенстве баллов - по возрастанию идентификационного номера
// Наконец, выводим список участников в нужном порядке