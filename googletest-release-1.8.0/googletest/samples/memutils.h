/**
 * @file   memutils.h
 * @brief  JC8 NOS Memory Manager API定義ファイル
 *
 * @par History:
 
 *  - Ver.0.9.00    2010.06.22    LIS K.Kudo
 *    - First Release
 */
 
typedef unsigned char		T_BYTE;
typedef unsigned short		T_USHORT;
typedef unsigned int		T_WORD;

#define D1_SYS_RET_SUCCESS					0xAAU	/* success */
#define D1_SYS_RET_FAILURE					0x50U	/* failure */

T_BYTE Nos_MemCopy(T_BYTE *pbyDestAddress_p, T_BYTE *pbySrcAddress_p, T_USHORT usLength_p);
T_BYTE Nos_MemCopyReverse(T_BYTE *pbyDestAddress_p, T_BYTE *pbySrcAddress_p, T_USHORT usLength_p);
T_BYTE Nos_Mm_MemComp(T_BYTE *pbyDestAddress_p, T_BYTE *pbySrcAddress_p, T_USHORT usLength_p);
// Returns n! (the factorial of n).  For negative n, n! is defined to be 1.
//int Factorial(int n);

// Returns true iff n is a prime number.
//bool IsPrime(int n);