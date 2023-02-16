#include "pythagorean_triplet.h"
#include<math.h>



int main(){
    int N = 1000;int result ;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if(i < j && j < k){
                    result = pow(i,2)+pow(j,2)+pow(k,2);
                    if(result == N){
                        printf("{%d %d %d}\n", i, j, k);
                    }
                }
            }
            
        }
        
    }
    





}