// Copyright 2005, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// A sample program demonstrating using Google C++ testing framework.
//
// Author: wan@google.com (Zhanyong Wan)

#include "sample1.h"

// Returns n! (the factorial of n).  For negative n, n! is defined to be 1.
int Factorial(int n) {
  int result = 1;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }

  return result;
}
#if 0
// Returns true iff n is a prime number.
bool IsPrime(int n) {
  // Trivial case 1: small numbers
  if (n <= 1) return false;

  // Trivial case 2: even numbers
  if (n % 2 == 0) return n == 2;

  // Now, we have that n is odd and n >= 3.

  // Try to divide n by every odd number i, starting from 3
  for (int i = 3; ; i += 2) {
    // We only have to try i up to the squre root of n
    if (i > n/i) break;

    // Now, we have i <= n/i < n.
    // If n is divisible by i, n is not prime.
    if (n % i == 0) return false;
  }

  // n has no integer factor in the range (1, n), and thus is prime.
  return true;
}
#endif
T_BYTE
Nos_MemCopy(T_BYTE   *pbyDestAddress_p,
            T_BYTE   *pbySrcAddress_p,
            T_USHORT usLength_p)
{
	//START(R1-0CE-0D2-015-000)
	T_USHORT* pusDestAddress;//[[R1-0CE-0D2-015-000]]
	T_USHORT* pusSrcAddress;
	/// - 1. ローカル変数の初期化
	volatile  T_BYTE byRetVal = D1_SYS_RET_FAILURE;

	/// - 2. NVM Parityエラー発生フラグを初期化
	/** Not supported by UIM platform */

	/// - 3. Source Data --> Destination Data
/*#3*/
	///TSIP Warning Removal : Warning #767-D
	if( ((T_WORD)pbySrcAddress_p&0x01) || ((T_WORD)pbyDestAddress_p&0x01) || (usLength_p&0x01) )/* pgr0246 *//* pgr0246 *///[[Y2-0CE-0D2-1D7-000]]//[[Y2-0CE-0D2-1D8-000]]
	{
/*#1*/
		while(usLength_p--)
		{
			*pbyDestAddress_p++ = *pbySrcAddress_p++;
		}
	}
	else
	{
		usLength_p = usLength_p >> 1;
		pusDestAddress = (T_USHORT*)pbyDestAddress_p;
		pusSrcAddress = (T_USHORT*)pbySrcAddress_p;
/*#4*/
		while(usLength_p--)
		{
			*pusDestAddress++ = *pusSrcAddress++;
		}
	}
	//END(R1-0CE-0D2-015-000)

	/// - 4. NVM Parityエラーチェック
	///      - @e D1_SYS_RET_NVM_PARITY
/*#2*/
	/** Not supported by UIM platform */
	byRetVal = D1_SYS_RET_SUCCESS;

	/// - 5. 実行結果をリターン
	return byRetVal;
}
