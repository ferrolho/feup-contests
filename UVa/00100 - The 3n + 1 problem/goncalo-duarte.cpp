#include <unordered_map>

std::unordered_map<int, int> map;

int getCycleLength(int n){
        if(n == 1) {
                return 1;
        }
        if(map.find(n) == map.end()) {
                map[n] = getCycleLength(n % 2 == 0 ? n / 2 : 3 * n + 1) + 1;
        }
        return map[n];
}

int main(int argc, char const *argv[]) {
        int i, j;
        while(scanf("%d %d", &i, &j) != EOF) {
                int max = 0;
                for(int k = i; k <= j; k++) {
                        int length = getCycleLength(k);
                        max = length > max ? length : max;
                }
                printf("%d %d %d\n", i, j, max);
        }
        return 0;
}
