#include <iostream>

#define P 1000003

inline int hash(int key)
{
  return (key + 1'000'000'000) % P;
}

struct Node {
  Node(int _key = 0) : key(_key) {}
  int key, cnt = 1;
  Node *next = nullptr;
};

int T, N, M;
int partialA[1001], partialB[1001];

int poolCnt;
Node pool[2000000]; 
Node *hashA[P], *hashB[P];

Node *find(Node **hashTable, int key)
{
  Node *curr = hashTable[hash(key)];
  while(curr) {
    if(curr->key == key)
      break;
    curr = curr->next;
  }
  return curr;
}

void insert(Node **hashTable, int key)
{
  Node *curr;
  if((curr = find(hashTable, key))) {
    ++curr->cnt;
    return;
  }

  curr = hashTable[hash(key)];
  pool[poolCnt] = Node(key);

  if(curr == nullptr) {
    hashTable[hash(key)] = &pool[poolCnt++];
    return;
  }

  while(curr->next)
    curr = curr->next;
  curr->next = &pool[poolCnt++];
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> T >> N;
  for(int i = 1; i <= N; ++i) {
    int temp;
    std::cin >> temp;
    partialA[i] = partialA[i - 1] + temp;
  }
  std::cin >> M;
  for(int i = 1; i <= M; ++i) {
    int temp;
    std::cin >> temp;
    partialB[i] = partialB[i - 1] + temp;
  }

  for(int i = 1; i <= N; ++i)
    for(int j = i; j <= N; ++j)
      insert(hashA, partialA[j] - partialA[i - 1]);
  for(int i = 1; i <= M; ++i)
    for(int j = i; j <= M; ++j)
      insert(hashB, partialB[j] - partialB[i - 1]);

  long long ans = 0;
  for(int i = 0; i < P; ++i) {
    Node *curr = hashA[i];
    while(curr) {
      Node *f;
      if((f = find(hashB, T - curr->key)))
        ans += (long long) curr->cnt * f->cnt;
      curr = curr->next;
    }
  }
  std::cout << ans << std::endl;

  return 0;
}