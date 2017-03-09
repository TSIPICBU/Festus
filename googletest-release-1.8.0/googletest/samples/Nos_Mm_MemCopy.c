#include "memutils.h"
/**
 * @ingroup MM_UTIL
 * @public
 * @callgraph
 * @callergraph
 *
 * @brief メモリコピー
 *
 * @par Detail:
 *  指定されたコピー元アドレスからコピー先アドレスへデータをコピーする。@n
 *  セキュリティ対策なし、パラメータチェックなしの高速APIとする。@n
 *  コピー元アドレスは、RAM、ROM、NVMを指定可能とする。@n
 *  コピー先アドレスについては、RAMのみをサポートする。
 *
 * @param[out]  pbyDestAddress_p  コピー先アドレス
 * @param[in]   pbySrcAddress_p   コピー元アドレス
 * @param[in]   usLength_p        データ長
 *
 * @retval D1_SYS_RET_SUCCESS     成功
 * @retval D1_SYS_RET_FAILURE     失敗(本LSIでは発生しない)
 * @retval D1_SYS_RET_NVM_PARITY  失敗(NVM Parityエラー発生)
 *
 * @pre
 *  なし
 *
 * @post
 *  なし
 *
 * @par NVM:
 *  なし
 *
 * @par Global Variable Used:
 *  なし
 *
 * @par Sensitive operations:
 *  なし
 *
 * @remarks
 *  -# pbyDestAddress_p にROM、NVMが指定された場合の動作は未定義とする
 *  -# pbyDestAddress_p と pbySrcAddress_p が重なっている場合、@n
 *     以下の関係の場合の動作は未定義とする
 *     - pbyDestAddress_p > pbySrcAddress_p
 *
 * @par History:
 *  - Ver.1.1.01    2012.11.02    TSIP
 *    - NVM parity check not supported by UIM
 *  - Ver.1.1.00    2012.08.30    TSIP
 *    - Modified as per 9QM/91K LSI
 *  - Ver.1.0.02    2012.04.06    JPD Y.Urushio
 *    - 呼出回数が多いモジュールの処理速度改善実施
 *  - Ver.1.0.01    2012.04.06    JPD Y.Urushio
 *    - Nos_Mm_IsNvmParity()の修正による速度改善実施
 *  - Ver.1.0.00    2011.03.15    LIS K.Kudo
 *    - 単体試験完了
 *  - Ver.0.9.11    2011.03.04    LIS K.Kudo
 *    - D1_SYS_RET_FAILUREが返るパターンが最適化により
 *      削除されないようにvolatile宣言を付与
 *  - Ver.0.9.10    2010.12.16    LIS K.Kudo
 *    - SrcとDestが重なっている場合も許容するようにRemarksの文章を変更
 *  - Ver.0.9.09    2010.12.01    LIS K.Kudo
 *    - Remarksの記述を追記
 *  - Ver.0.9.08    2010.11.26    LIS K.Kudo
 *    - パラメータ:データ長を16bitに変更
 *  - Ver.0.9.07    2010.11.15    LIS K.Kudo
 *    - パラメータチェック廃止
 *  - Ver.0.9.06    2010.11.08    LIS K.Kudo
 *    - プログラム実装(not optimizing)
 *  - Ver.0.9.05    2010.10.27    LIS K.Kudo
 *    - コピー元アドレス'NVM'をサポート
 *  - Ver.0.9.04    2010.10.15    LIS J.Pragash
 *    - パラメータ修正
 *  - Ver.0.9.03    2010.10.06    LIS K.Kudo
 *    - 日本語化
 *  - Ver.0.9.02    2010.09.30    LIS K.Kudo
 *    - API名の変更
 *  - Ver.0.9.01    2010.07.29    LIS K.Kudo
 *    - 日本語化 & フォーマット修正
 *  - Ver.0.9.00    2010.07.26    LIS J.Pragash
 *    - リリース
 *
 * @par Processing flow:
 */
#if 0 
int Factorial(int n) {
  int result = 1;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }

  return result;
}

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
#if 1
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
#endif