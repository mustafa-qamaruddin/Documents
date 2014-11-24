using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace FastFib
{
    class Program
    {
        //========================================================================================================
        //Your Code is Here:
        //===================
        /// <summary>
        /// Write efficient algorithm to the bounded-Fibonacci of index N using the matrix equation
        /// </summary>
        /// <param name="N">fibonacci index</param>
        /// <returns>fibonacci value</returns>
        static long FastBoundedFibonacci(long N)
        {
            /**
             A = [1     1]
                 [1     0]
             **/
            long[] A = { -1, 1, 1, 1, 0 };
            dnq(ref A, N);
            return A[3];
        }

        static void dnq(ref long[] A, long p)
        {
            if (p == 0)
                return;
            if (p == 1)
                return;
            if (p == 2)
            {
                mulMtrx(A, A, ref A);
                return;
            }

            dnq(ref A, p / 2 );

            if (p % 2 == 0)
                mulMtrx(A, A, ref A);
            else
            {
                long[] tmp = { -1, 1, 1, 1, 0 };
                mulMtrx(A, A, ref A);
                mulMtrx(A, tmp, ref A);
            }
        }
        
        // squares a matric by multiplying it to itself in O(1) time
        static void mulMtrx(long[] A,long[] B,ref long[] C)
        {
            /**
             A = [A11   A12]
                 [A21   A22]
             A = [0, A11, A12, A21, A22]
             **/
            int Z = 1000000;
            long[] K = new long[5];
            K[1] = (A[1] * B[1] + A[2] * B[3]) % Z;
            K[2] = (A[1] * B[2] + A[2] * B[4]) % Z;
            K[3] = (A[3] * B[1] + A[4] * B[3]) % Z;
            K[4] = (A[3] * B[2] + A[4] * B[4]) % Z;

            for (int i = 0; i < 5; i++)
                C[i] = K[i];
        }
    }
}
