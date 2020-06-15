#include <stdio.h>
#include <stdlib.h>
#define INF -65535 // infinity
#define SIZE 6

int w[SIZE][SIZE] = {{  0,   1,   2, INF, INF, INF},  
		     {INF,   0,   2,   2, INF, INF},
		     {INF, INF,   0,   3,   5, INF},
		     {INF, INF, INF,   0,   1,   4},
		     {INF, INF, INF, INF,   0,   5},
		     {INF, INF, INF, INF, INF,   0}};
         //1番目のノードから各ノードへの重み、つながってないとこはINF
         //D[u]からみてD[v]に辺伸ばす、uからvまでの変のおもみw[u,v] 小さくなれば更新
         //INFのときは処理しない、そもそも調べない

void bellmanford(int s) {
  int D[SIZE] = {INF, INF, INF, INF, INF, INF};
  D[s] = 0;

  // Please fill the algorithm
  for (int v=0; v<SIZE; v++) {
    for (int e=0; e<SIZE; e++) {
      if (w[v][e] != INF) {
        if (w[v][e+1] > w[v][e] + w[e][e+1]){
          w[v][e+1] = w[v][e] + w[e][e+1];
        }
      }
    }
  }
  
  

  
  for (int i=0; i<SIZE; i++) {
    printf("D[%d]=%d\n", i+1, D[i]);
  }
}

int main(void) {
  for (int i=0; i<SIZE; i++) {
    printf("-- %2d ----\n", i+1);
    bellmanford(i);
    printf("----------\n");
  }
  return 0;
}
