#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int a[1009];
int n;
void dfs(int index) {
    if (index * 2 > n && index * 2 + 1 > n) {
        if (index <= n) {
            for (int i = 0; i < v.size(); i++) {
                printf("%d", v[i]);
                if (i != v.size() - 1) printf(" ");
                else printf("\n");
            }
        }
    } else {
        v.push_back(a[index * 2 + 1]);
        dfs(index * 2 + 1);
        v.pop_back();
        v.push_back(a[index * 2]);
        dfs(index * 2);
        v.pop_back();
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    v.push_back(a[1]);
    dfs(1);
    int isMin = 1, isMax = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i / 2] > a[i]) isMin = 0;
        if (a[i / 2] < a[i]) isMax = 0;
    }
    if (isMin == 1) {
        cout << "Min Heap";
    } else if (isMax == 1) {
        cout << "Max Heap";
    } else {
        cout << "Not Heap";
    }
    return 0;
}

