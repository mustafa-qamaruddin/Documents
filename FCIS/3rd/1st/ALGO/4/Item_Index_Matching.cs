using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace ItemIndexMatching
{
    class Program
    {
        //========================================================================================================
        //Your Code is Here:
        //===================
        /// <summary>
        /// Write efficient algorithm to check whether or not there is an index i that matches the corresponding item A[i]
        /// </summary>
        /// <param name="A">array of N distinct integers</param>
        /// <param name="N">num of elements in the array</param>
        /// <returns>If Exists: return item, else, return -1</returns>
        static int FindMatching(int[] A, int N)
        {
            // NOTE: you should return the item itself if exists, otherwise, return -1
            return bs(A, 0, N-1);
        }

        static int bs(int[] A, int p, int r)
        {
            if (p >= r)
            {
                if (A[p] == p)
                    return r;
                else
                    return -1;
            }
            int q = (p + r) / 2;
            if (A[q] == q)
            {
                return q;
            }
            else if (A[q] < q)
            {
                return bs(A, q + 1, r);
            }
            else
            {
                return bs(A, p, q - 1);
            }
        }
    }
}
