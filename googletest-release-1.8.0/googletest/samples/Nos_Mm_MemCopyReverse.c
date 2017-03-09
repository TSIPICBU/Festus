#include "memutils.h"
/**
 * @ingroup MM_UTIL
 * @public
 * @callgraph
 * @callergraph
 *
 * @brief ãƒ¡ãƒ¢ãƒªã‚³ãƒ”ãƒ¼
 *
 * @par Detail:
 *  æŒ‡å®šã•ã‚ŒãŸã‚³ãƒ”ãƒ¼å…ƒã‚¢ãƒ‰ãƒ¬ã‚¹ã‹ã‚‰ã‚³ãƒ”ãƒ¼å…ˆã‚¢ãƒ‰ãƒ¬ã‚¹ã¸ãƒ‡ãƒ¼ã‚¿ã‚’ã‚³ãƒ”ãƒ¼ã™ã‚‹ã€‚@n
 *  æŒ‡å®šã•ã‚ŒãŸã‚³ãƒ”ãƒ¼å…ƒãƒãƒƒãƒ•ã‚¡ã¨ã‚³ãƒ”ãƒ¼å…ˆãƒãƒƒãƒ•ã‚¡ã«é‡ãªã‚ŠãŒç”Ÿã˜@n
 *  (æŒ‡å®šã•ã‚ŒãŸã‚³ãƒ”ãƒ¼å…ƒã‚¢ãƒ‰ãƒ¬ã‚¹) < (ã‚³ãƒ”ãƒ¼å…ˆã‚¢ãƒ‰ãƒ¬ã‚¹)ã®å ´åˆã«ä½¿ç”¨ã™ã‚‹ã€‚@n
 *  ã‚»ã‚­ãƒ¥ãƒªãƒ†ã‚£å¯¾ç­–ãªã—ã€ãƒ‘ãƒ©ãƒ¡ãƒ¼ã‚¿ãƒã‚§ãƒƒã‚¯ãªã—ã®é«˜é€ŸAPIã¨ã™ã‚‹ã€‚@n
 *
 * @param[out]  pbyDestAddress_p  ã‚³ãƒ”ãƒ¼å…ˆã‚¢ãƒ‰ãƒ¬ã‚¹
 * @param[in]   pbySrcAddress_p   ã‚³ãƒ”ãƒ¼å…ƒã‚¢ãƒ‰ãƒ¬ã‚¹
 * @param[in]   usLength_p        ãƒ‡ãƒ¼ã‚¿é•·
 *
 * @retval D1_SYS_RET_SUCCESS     æˆåŠŸ
 * @retval D1_SYS_RET_FAILURE     å¤±æ•—(æœ¬LSIã§ã¯ç™ºç”Ÿã—ãªã„)
 * @retval D1_SYS_RET_NVM_PARITY  å¤±æ•—(NVM Parityã‚¨ãƒ©ãƒ¼ç™ºç”Ÿ)
 *
 * @pre
 *  ãªã—
 *
 * @post
 *  ãªã—
 *
 * @par NVM:
 *  ãªã—
 *
 * @par Global Variable Used:
 *  ãªã—
 *
 * @par Sensitive operations:
 *  ãªã—
 *
 * @remarks
 *  -# pbyDestAddress_p ã«ROMã€NVMãŒæŒ‡å®šã•ã‚ŒãŸå ´åˆã®å‹•ä½œã¯æœªå®šç¾©ã¨ã™ã‚‹
 *
 * @par History:
 *  - Ver.1.1.00    2012.11.02    TSIP
 *    - NVM parity check not supported by UIM
 *  - Ver.1.0.01    2012.04.06    JPD Y.Urushio
 *    - Nos_Mm_IsNvmParity()ã®ä¿®æ­£ã«ã‚ˆã‚‹é€Ÿåº¦æ”¹å–„å®Ÿæ–½
 *  - Ver.1.0.00    2011.03.15    LIS K.Kudo
 *    - å˜ä½“è©¦é¨“å®Œäº†
 *  - Ver.0.9.01    2011.03.04    LIS K.Kudo
 *    - D1_SYS_RET_FAILUREãŒè¿”ã‚‹ãƒ‘ã‚¿ãƒ¼ãƒ³ãŒæœ€é©åŒ–ã«ã‚ˆã‚Š
 *      å‰Šé™¤ã•ã‚Œãªã„ã‚ˆã†ã«volatileå®£è¨€ã‚’ä»˜ä¸Ž
 *  - Ver.0.9.00    2011.01.07    LIS K.Kudo
 *    - ãƒªãƒªãƒ¼ã‚¹
 *
 * @par Processing flow:
 */
T_BYTE
Nos_MemCopyReverse(T_BYTE   *pbyDestAddress_p,
                   T_BYTE   *pbySrcAddress_p,
                   T_USHORT usLength_p)
{
	/// - 1. ãƒ­ãƒ¼ã‚«ãƒ«å¤‰æ•°ã®åˆæœŸåŒ–
	volatile T_BYTE byRetVal = D1_SYS_RET_FAILURE;
	T_BYTE *pbyDestAddress = pbyDestAddress_p + usLength_p - 1;
	T_BYTE *pbySrcAddress  = pbySrcAddress_p  + usLength_p - 1;

	/// - 2. NVM Parityã‚¨ãƒ©ãƒ¼ç™ºç”Ÿãƒ•ãƒ©ã‚°ã‚’åˆæœŸåŒ–
	/** Not supported by UIM platform */

	/// - 3. Source Data --> Destination Data
/*#1*/
	while(usLength_p--)
	{
		*pbyDestAddress-- = *pbySrcAddress--;
	}

	/// - 4. NVM Parityã‚¨ãƒ©ãƒ¼ãƒã‚§ãƒƒã‚¯
	///      - @e D1_SYS_RET_NVM_PARITY
/*#2*/
	/** Not supported by UIM platform */
	byRetVal = D1_SYS_RET_SUCCESS;

	/// - 5. å®Ÿè¡Œçµæžœã‚’ãƒªã‚¿ãƒ¼ãƒ³
	return byRetVal;
}
