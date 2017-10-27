#include <iostream>
#include <ctime>
using namespace std;
int map[4][4];
int point = 0;
void crm(int u[4]) {
    for (int i = 0; i < 4; i++) {
        u[i] = 0;
    }
}
void crm(int u[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            u[i][j] = 0;
        }
    }
}
bool equal(int a, int a1[4][4], int a2[4],
          char op) {
    bool res = true;
    if (op == 'x') {
        for (int i = 0; i < 4; i++) {
            if (a1[a][i] != a2[i]) {
                res = false;
            }
        }
    }
    if (op == 'y') {
        for (int i = 0; i < 4; i++) {
            if (a1[i][a] != a2[i]) {
                res = false;
            }
        }
    }
    return res;
}
int rdm(int p) {
    int l = 0;
    int z = rand() % p;
    if (z != 0) {
        l = 1;
    }
    for (int i = 0; i < z; i++) {
        l += l;
    }
    return l;
}
void init() {
    crm(map);
    srand(time(NULL));
    map[1][0] = rdm(5);
    map[1][1] = rdm(5);
    map[1][2] = rdm(5);
    map[1][3] = rdm(5);
    map[2][3] = rdm(5);
    map[0][3] = rdm(5);
    map[2][2] = rdm(5);
}
bool up(int uper[4][4]) {
    bool any = false;
    for (int j = 0; j < 4; j++) {
        int y[4];
        crm(y);
        int n = 0;
        for (int i = 0; i < 4; i++) {
            if (uper[j][i] != 0) {
                y[n] = uper[j][i];
                n++;
            }
        }
        if (!equal(j, uper, y, 'x')) {
            any = true;
        }
        for (int z = 0; z < 4; z++) {
            if ((y[z] == y[z + 1]) && (y[z] !=0)) {
                y[z] += y[z + 1];
                y[z + 1] = 0;
                any = true;
                if (uper == map) {
                    point += y[z];
                }
            }
        }
        for (int w = 0; w < 3; w++) {
            if (y[w] == 0) {
                y[w] = y[w + 1];
                y[w + 1] = 0;
            }
        }
        for (int i = 0; i < 4; i++) {
            uper[j][i] = y[i];
        };
    }
    return any;
}
bool down(int uper[4][4]) {
    bool any = false;
    for (int j = 0; j < 4; j++) {
        int y[4];
        crm(y);
        int n = 3;
        for (int i = 3; i > -1; i--) {
            if (uper[j][i] != 0) {
                y[n] = uper[j][i];
                n--;
            }
        }
        if (!equal(j, uper, y, 'x')) {
            any = true;
        }
        for (int z = 3; z > 0; z--) {
            if ((y[z] == y[z - 1]) && (y[z] !=0)) {
                y[z] += y[z - 1];
                y[z - 1] = 0;
                any = true;
                if (uper == map) {
                    point += y[z];
                }
            }
        }
        for (int w = 3; w > 0; w--) {
            if (y[w] == 0) {
                y[w] = y[w - 1];
                y[w - 1] = 0;
            }
        }
        for (int i = 0; i < 4; i++) {
            uper[j][i] = y[i];
        };
    }
    return any;
}
bool left(int uper[4][4]) {
    bool any = false;
    for (int j = 0; j < 4; j++) {
        int y[4];
        crm(y);
        int n = 0;
        for (int i = 0; i < 4; i++) {
            if (uper[i][j] != 0) {
                y[n] = uper[i][j];
                n++;
            }
        }
        if (!equal(j, uper, y, 'y')) {
            any = true;
        }
        for (int z = 0; z < 4; z++) {
            if ((y[z] == y[z + 1]) && (y[z] !=0)) {
                y[z] += y[z + 1];
                y[z + 1] = 0;
                any = true;
                if (uper == map) {
                    point += y[z];
                }
            }
        }
        for (int w = 0; w < 3; w++) {
            if (y[w] == 0) {
                y[w] = y[w + 1];
                y[w + 1] = 0;
            }
        }
        for (int i = 0; i < 4; i++) {
            uper[i][j] = y[i];
        };
    }
    return any;
}
bool right(int uper[4][4]) {
    bool any = false;
    for (int j = 0; j < 4; j++) {
        int y[4];
        crm(y);
        int n = 3;
        for (int i = 3; i > -1; i--) {
            if (uper[i][j] != 0) {
                y[n] = uper[i][j];
                n--;
            }
        }
        if (!equal(j, uper, y, 'y')) {
            any = true;
        }
        for (int z = 3; z > 0; z--) {
            if ((y[z] == y[z - 1]) && (y[z] !=0)) {
                y[z] += y[z - 1];
                y[z - 1] = 0;
                any = true;
                if (uper == map) {
                    point += y[z];
                }
            }
        }
        for (int w = 3; w > 0; w--) {
            if (y[w] == 0) {
                y[w] = y[w - 1];
                y[w - 1] = 0;
            }
        }
        for (int i = 0; i < 4; i++) {
            uper[i][j] = y[i];
        };
    }
    return any;
}
void mapout() {
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 4; i++) {
            if (map[i][j] == 0) {
                cout << "*" << " ";
                continue;
            }
            cout << map[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}
void update(int fmap[4][4]) {
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 4; i++) {
            fmap[j][i] = map[j][i];
        }
    }
}
void GameOver(int fmap[4][4]) {
    if (!up(fmap)) {
        update(fmap);
        if (!down(fmap)) {
            update(fmap);
            if (!left(fmap)) {
                update(fmap);
                if (!right(fmap)) {
                    cout << "\nGame Over!";
                    exit(0);
                }
            }
        }
    }
}
void gem() {
    int n = 0;
    int y[16][2];
    bool need = false;
    srand(time(NULL));
    long int t = rand();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (map[i][j] == 0) {
                y[n][0] = i;
                y[n][1] = j;
                n++;
                need = true;
            }
        }
    }
    if (need) {
        int h = rand() % n;
        t = t % 10000000000;
        if ((0 < t) && (t <= 9090909090)) {
            map[y[h][0]][y[h][1]] = 2;
        } else if (t > 9090909090) {
            map[y[h][0]][y[h][1]] = 4;
        } else if (t == 0) {}
    }
}
int main() {
    char com = ' ';
    init();
    int vmap[4][4];
    crm(vmap);
    bool corr = true;
    while (com != 'q') {
        bool add = false;
        switch (com) {
            case 'j':
                add = down(map);
                corr = true;
                break;
            case 'k':
                add = up(map);
                corr = true;
                break;
            case 'h':
                add = left(map);
                corr = true;
                break;
            case 'l':
                add = right(map);
                corr = true;
                break;
        }
        if (corr) {
            update(vmap);
            if (add) {
                gem();
            }
            mapout();
            cout << "Point:" << point <<"\n";
            GameOver(vmap);
        }
        cin >> com;
        corr = false;
    }
    return 0;
}
