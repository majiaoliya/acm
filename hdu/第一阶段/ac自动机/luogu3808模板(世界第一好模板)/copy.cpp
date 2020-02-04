#include <iostream>
#include <string>
#include <queue>
/* GET(i):
 * 字符串x中的第i个字符减去'a'的值，
 * 也就是这个字符在它父亲的a数组中的位置
 * (a就是Trie上的这个节点的儿子们)。
 */
#define GET(i) (x[i] - 'a')
/* TO(x):
 * x是Trie上的一个节点。
 * 在跳转的时候，x可能为NULL(也就是0)，代表父亲没有这个儿子。
 * 这个时候就需要跳到root。
 */
#define TO(x) (x ? x : root)
using namespace std;

struct node {
    node *a[26], *fail; //a[]: 儿子们；fail: 就是fail指针
    int cnt; //有多少个字符以这个节点结尾（用来处理重复的字符串）

    /* 构造函数
     * 创造节点使用的是new。它不会将node里面的成员置为默认值0，
     * 所以需要专门赋一下值。
     */
    node(): cnt(0), fail(0) {
        for (int i = 0; i < 26; ++i)
            a[i] = 0;
    }
} *root = new node(); //Trie的根 

//建立Trie 
void build(const string& x) {
    node* curr = root; //从根开始往下建Trie 
    for (int i = 0; i < x.size(); ++i) {
        if (!curr->a[GET(i)]) //如果没有这个节点的话，就新建一个 
            curr->a[GET(i)] = new node();
        curr = curr->a[GET(i)]; //然后跳到儿子节点继续建 
    }
    ++curr->cnt; //建完了这个字符串，需要标记一下这里是结尾 
}

//找到fail指针 
void failure() {
    queue<node*> q; //开始bfs 
    for (int i = 0; i < 26; ++i)
        if (root->a[i])
            //把第一层(root的儿子)放进队列，并且标记它们的fail 
            q.push(root->a[i]), root->a[i]->fail = root;
    while (q.size()) {
        node* x = q.front(); q.pop();
        for (int i = 0; i < 26; ++i)
            if (x->a[i])
                /* 儿子的fail就是自己的fail的对应的儿子
                 * 当然，如果fail没有对应的儿子，就指向root
                 * 最后把儿子进队
                 */
                x->a[i]->fail = TO(x->fail->a[i]),
                q.push(x->a[i]);
            else
                //这里类似于并查集的路径压缩
                x->a[i] = x->fail->a[i];
    }
}

//查询 
int match(const string& x) {
    node* curr = root;
    int ans = 0;
    for (int i = 0; i < x.size(); ++i) {
        //跳到对应字符串中字符的那个儿子，如果没有，就跳到根
        curr = TO(curr->a[GET(i)]);
        /* 开始暴跳fail: 
         * 找到整条fail路径上的字符串结尾节点， 
         * 然后加到答案里，再标记成已经算过。
         * ~x就是x != -1的意思。
         */ 
        for (node* t = curr; t && ~t->cnt; t = t->fail)
            ans += t->cnt,
            t->cnt = -1;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string m;
        cin >> m;
        build(m);
    }
    failure(); //不要忘了算出fail指针 
    string k;
    cin >> k;
    cout << match(k);
    return 0;
}
