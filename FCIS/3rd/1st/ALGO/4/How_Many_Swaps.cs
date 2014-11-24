using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace HowManyAdjacentSwaps
{
    class Program
    {
        //========================================================================================================
        //Your Code is Here:
        //===================
        /// <summary>
        /// Write efficient algorithm to count the number of adjacent swaps needed to sort array of N distinct integers in ascending order
        /// </summary>
        /// <param name="A">array of N distinct integers</param>
        /// <param name="N">num of elements in the array</param>
        /// <returns>num of adjacent swaps needed to sort the array A in ascending order</returns>
        static int NumOfAdjacentSwaps(int[] A, int N)
        {
            return mergesort(A, 0, N-1);
        }

        static int mergesort(int[] A, int p, int r)
        {
            int ret = 0;
            if( p < r){
                int q = (p+r) / 2;
                ret += mergesort(A, p, q);
                ret += mergesort(A, q+1, r);
                ret += merge(A, p, q, r);
            }
            return ret;
        }

        static int merge(int[] A, int p, int q, int r)
        {
            int ret = 0;
            int OO = 2147483647;
            int n1 = q - p + 1;
            int n2 = r - q;
            int[] left = new int[n1+1];
            int[] right = new int[n2+1];
            for(int i = 0; i < n1; i++)
            {
                left[i] = A[p+i];
            }
            left[n1] = OO;

            for (int i = 0; i < n2; i++)
            {
                right[i] = A[q + 1 + i];
            }
            right[n2] = OO;

            int x = p;
            int j = 0;
            int k = 0;
            while (x <= r)
            {
                if (left[j] > right[k])
                {
                    A[x] = right[k];
                    k++;
                    if (left[j] < OO)
                    {
                        ret+= (n1 - j);
                    }
                }
                else if (left[j] <= right[k])
                {
                    A[x] = left[j];
                    j++;
                }
                x++;
            }
            return ret;
        }
    }
}
