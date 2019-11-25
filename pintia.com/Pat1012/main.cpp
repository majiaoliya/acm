#include <iostream>
#define MAXN 2005
#include <map>
#include <algorithm>
using namespace std;

char table[] = {'A', 'C', 'M', 'E'};

struct Stu {
    string name;
    double g[4]; // g[0]=avg, g[1]=C, g[2]=M, g[3]=E gread
    int r[4]; // g[0]=avg, g[1]=C, g[2]=M, g[3]=E pai_ming
    int temp;
} arr[MAXN];

int n, m;
int cmp(Stu& x, Stu& y) {
    if(x.temp == y.temp) return x.name < y.name;
    return x.temp > y.temp;
}

map<string, Stu*> mp;

int main()
{
    freopen("test.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) {
        double c, m, e;
        cin >> arr[i].name;
        scanf("%lf %lf %lf", &c, &m, &e);
        arr[i].g[1] = c, arr[i].g[2] = m, arr[i].g[3] = e;
        arr[i].g[0] = (c + m + e)/3;
    }

    for(int t=0; t<4; t++) {
        for(int i=1; i<=n; i++) {
            arr[i].temp = arr[i].g[t];
        }
        sort(arr+1, arr+1+n, cmp);
        arr[1].r[t] = 1;
        for(int i=2; i<=n; i++) {
            arr[i].r[t] = arr[i].temp == arr[i-1].temp ? arr[i-1].r[t] : i;
        }

    }
//    printf("%d\n", t);
//    for(int i=1; i<=n; i++) {
//        printf("%s: %d %d %d %d\n", arr[i].name.data(), arr[i].r[0], arr[i].r[1], arr[i].r[2], arr[i].r[3]);
//    }
    for(int i=1; i<=n; i++)
        mp[arr[i].name] = arr + i;
    for(int i=1; i<=m; i++) {
        string name;
        cin >> name;
        map<string, Stu*>::iterator it = mp.find(name);
        if(it == mp.end()) {
            printf("N/A\n"); continue ;
        }
        int min = MAXN, min_id = 0;
        Stu* s = it->second;
        for(int i=0; i<4; i++) {
            if(min > s->r[i]) {
                min = s->r[i];
                min_id = i;
            }
        }
        printf("%d %c\n", min, table[min_id]);
    }

    return 0;
}
