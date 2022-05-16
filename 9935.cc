#include <cstdio>
#include <cstring>

char stack[1000001];
char sequence[1000001], pattern[37];
int seq_len, pat_len, stack_len;

int main()
{
  scanf("%s", sequence);
  scanf("%s", pattern);
  seq_len = strlen(sequence);
  pat_len = strlen(pattern);
  
  for(int i = 0; i < seq_len; ++i) {
    stack[stack_len++] = sequence[i];
    if(sequence[i] != pattern[pat_len - 1] || stack_len < pat_len) continue;

    bool match = true;
    for(int j = stack_len - 1, k = pat_len - 1; j >= stack_len - pat_len; --j, --k) {
      if(stack[j] == pattern[k]) continue;
      match = false;
      break;
    }

    if(match == false) continue;
    stack_len -= pat_len;
  }

  if(stack_len == 0) {
    printf("FRULA\n");
    return 0;
  }

  for(int i = 0; i < stack_len; ++i)
    printf("%c", stack[i]);
  printf("\n");

  return 0;
}