// GGACGGATTCTG", "AGGACGGATTCT"

#include "hamming.h"
#include<string.h>
/*Calculate the Hamming Distance between two DNA strands.

Your body is made up of cells that contain DNA. Those cells regularly wear out and need replacing, which they achieve by dividing into daughter cells. In fact, the average human body experiences about 10 quadrillion cell divisions in a lifetime!

When cells divide, their DNA replicates too. Sometimes during this process mistakes happen and single pieces of DNA get encoded with the incorrect information. If we compare two strands of DNA and count the differences between them we can see how many mistakes occurred. This is known as the "Hamming Distance".

We read DNA using the letters C,A,G and T. Two strands might look like this:

GAGCCTACTAACGGGAT
CATCGTAATGACGGCCT
^ ^ ^  ^ ^    ^^
They have 7 differences, and therefore the Hamming Distance is 7.

The Hamming Distance is useful for lots of things in science, not just biology, so it's a nice phrase to be familiar with :)

Implementation notes
The Hamming distance is only defined for sequences of equal length, so an attempt to calculate it between sequences of different lengths should not work.*/

int compute(const char *lhs, const char *rhs)
{
    int lenghtLhs = strlen(lhs);
    int lengthRhs = strlen(rhs);
    int HammingDistance = 0;
    if (lenghtLhs == lengthRhs)
    {
        for (int i = 0; i < lenghtLhs; i++)
        {
            if (lhs[i] != rhs[i])
            {

                HammingDistance++;
                //printf("HD: %d  |  %c : %c\n",HammingDistance,  lhs[i], rhs[i]);
            }
        }
    }else{
        return -1;
    }
    return HammingDistance;
}

int main()
{

    char lhs[] = "GGACGGATTCT";
    char rhs[] = "AGGACGGATTCT";

    printf("lhs: %s\n", lhs);
    printf("rhs: %s\n", rhs);
    printf("Hamming Distance: %d\n", compute(lhs, rhs));
}