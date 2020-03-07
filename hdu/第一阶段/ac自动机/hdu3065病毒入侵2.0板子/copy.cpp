#include <stdio.h>
#include <iostream>
using namespace std;
#include <string.h>
#include <math.h>
#include <queue>

#define KIND 26
#define N 1005
#define M 2000005

struct node
{
	node *fail;
	node *next[KIND];
	int id;
	node ()
	{
		fail = NULL;
		id = 0;
		memset(next, 0, sizeof(next));
	}
};

char ch[M], key[N][55];
int count[N];

void insert(node *&root, char *ch, int num)
{
	node *p = root;
	int i = 0, t;
	while(ch[i])
	{
		t = ch[i] - 'A';
		if(!p->next[t]) p->next[t] = new node();
		p = p->next[t];
		i++;
	}
	p->id = num;
}

void AC(node *&root)
{
	std::queue<node *> q;
	q.push(root);
	while(!q.empty())
	{
		node *p = NULL;
		node *t = q.front();
		q.pop();
		for(int i = 0; i < KIND; i++)
		{
			if(t->next[i])
			{
				p = t->fail;
				while(p)
				{
					if(p->next[i])
					{
						t->next[i]->fail = p->next[i];
						break;
					}
					p = p->fail;
				}
				if(!p) t->next[i]->fail = root;
				q.push(t->next[i]);
			}
		}
	}
}

void query(node *&root, char *ch)
{
	int i = 0, t;
	node *p = root, *tmp;
	while(ch[i])
	{
		if(ch[i] > 'Z' || ch[i] < 'A')
		{
			p = root;
			i++;
			continue;
		}
		t = ch[i] - 'A';
		while(!p->next[t] && p != root) p = p->fail;
		p = p->next[t];
		if(!p) p = root;
		tmp = p;
		while(tmp != root)
		{
			count[tmp->id]++;
			tmp = tmp->fail;
		}
		i++;
	}
}

int main()
{
	freopen("test", "r", stdin);
	freopen("out2", "w", stdout);
	int n;
	scanf("%d ", &n);
	{
		node *root = new node();
		memset(count, 0, sizeof(count));
		for(int i = 1; i <= n; i++)
		{
			scanf("%s ", key[i]);
			insert(root, key[i], i);
		}
		AC(root);
		cin.getline(ch, sizeof(ch));
		//        scanf("%s", ch);
		query(root, ch);
		for(int i = 1; i <= n; i++)
		{
			if(count[i])
			{
				printf("%s: %d\n", key[i], count[i]);
			}
		}
	}
	return 0;
}
