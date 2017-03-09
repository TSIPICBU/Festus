#include "memutils.h"
/**
 * @ingroup MM_UTIL
 * @public
 * @callgraph
 * @callergraph
 *
 * @brief ãƒ¡ãƒ¢ãƒªã‚³ãƒ³ãƒšã‚¢
 *
 * @par Detail:
 *  æŒ‡å®šã•ã‚ŒãŸæ¯”è¼ƒå…ƒã‚¢ãƒ‰ãƒ¬ã‚¹ã¨æ¯”è¼ƒå…ˆã‚¢ãƒ‰ãƒ¬ã‚¹ã‚’ãƒ‡ãƒ¼ã‚¿é•·åˆ†æ¯”è¼ƒã™ã‚‹ã€‚@n
 *  ã‚»ã‚­ãƒ¥ãƒªãƒ†ã‚£å¯¾ç­–ãªã—ã®é«˜é€ŸAPIã¨ã™ã‚‹ã€‚@n
 *  æ¯”è¼ƒå¯¾è±¡ã¯ã€RAMã€ROMã€NVMã‚’æŒ‡å®šå¯èƒ½ã¨ã™ã‚‹ã€‚
 *
 * @param[in]   pbySrc1Address_p    æ¯”è¼ƒå…ˆã‚¢ãƒ‰ãƒ¬ã‚¹
 * @param[in]   pbySrc2Address_p    æ¯”è¼ƒå…ƒã‚¢ãƒ‰ãƒ¬ã‚¹
 * @param[in]   usLength_p          ãƒ‡ãƒ¼ã‚¿é•·
 *
 * @retval D1_SYS_RET_SUCCESS       Source1 == Source2
 * @retval D1_SYS_RET_FAILURE       Source1 != Source2
 * @retval D1_SYS_RET_NVM_PARITY    NVM Parityã‚¨ãƒ©ãƒ¼ç™ºç”Ÿ
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
 *  ãªã—
 * 
 * @par History:
 *  - Ver.1.1.02    2013.02.12    TSBJ
 *    - FALSE is deleted
 *  - Ver.1.1.01    2012.11.02    TSIP
 *    - NVM parity check not supported by UIM
 *  - Ver.1.1.00    2012.08.30    TSIP
 *    - Modified as per 9QM/91K LSI
 *  - Ver.1.0.02    2012.04.06    JPD Y.Urushio
 *    - å‘¼å‡ºå›žæ•°ãŒå¤šã„ãƒ¢ã‚¸ãƒ¥ãƒ¼ãƒ«ã®å‡¦ç†é€Ÿåº¦æ”¹å–„å®Ÿæ–½
 *  - Ver.1.0.01    2012.04.06    JPD Y.Urushio
 *    - Nos_Mm_IsNvmParity()ã®ä¿®æ­£ã«ã‚ˆã‚‹é€Ÿåº¦æ”¹å–„å®Ÿæ–½
 *  - Ver.1.0.00    2011.03.15    LIS K.Kudo
 *    - å˜ä½“è©¦é¨“å®Œäº†
 *  - Ver.0.9.09    2011.03.04    LIS K.Kudo
 *    - D1_SYS_RET_FAILUREãŒè¿”ã‚‹ãƒ‘ã‚¿ãƒ¼ãƒ³ãŒæœ€é©åŒ–ã«ã‚ˆã‚Š
 *      å‰Šé™¤ã•ã‚Œãªã„ã‚ˆã†ã«volatileå®£è¨€ã‚’ä»˜ä¸Ž
 *  - Ver.0.9.08    2010.11.26    LIS K.Kudo
 *    - ãƒ‘ãƒ©ãƒ¡ãƒ¼ã‚¿:ãƒ‡ãƒ¼ã‚¿é•·ã‚’16bitã«å¤‰æ›´
 *  - Ver.0.9.07    2010.11.15    LIS K.Kudo
 *    - for --> whileã«å¤‰æ›´
 *  - Ver.0.9.06    2010.11.08    LIS K.Kudo
 *    - ãƒ—ãƒ­ã‚°ãƒ©ãƒ å®Ÿè£…(not optimizing)
 *  - Ver.0.9.05    2010.10.27    LIS K.Kudo
 *    - æ¯”è¼ƒå¯¾è±¡ã‚¢ãƒ‰ãƒ¬ã‚¹'NVM'ã‚’ã‚µãƒãƒ¼ãƒˆ
 *  - Ver.0.9.04    2010.10.15    LIS J.Pragash
 *    - ãƒ‘ãƒ©ãƒ¡ãƒ¼ã‚¿ä¿®æ­£
 *  - Ver.0.9.03    2010.10.06    LIS K.Kudo
 *    - æ—¥æœ¬èªžåŒ–
 *  - Ver.0.9.02    2010.09.30    LIS K.Kudo
 *    - APIåã®å¤‰æ›´
 *  - Ver.0.9.01    2010.07.29    LIS K.Kudo
 *    - æ—¥æœ¬èªžåŒ– & ãƒ•ã‚©ãƒ¼ãƒžãƒƒãƒˆä¿®æ­£
 *  - Ver.0.9.00    2010.07.26    LIS J.Pragash
 *    - ãƒªãƒªãƒ¼ã‚¹
 *
 * @par Processing flow:
 */
T_BYTE
Nos_Mm_MemComp( T_BYTE *pbySrc1Address_p,
            T_BYTE *pbySrc2Address_p,
            T_USHORT     usLength_p)
{
	//START(R1-0CC-0D0-014-000)
	T_USHORT* pusSrc1Address;//[[R1-0CC-0D0-014-000]]
	T_USHORT* pusSrc2Address;

	/// - 2. NVM Parityã‚¨ãƒ©ãƒ¼ç™ºç”Ÿãƒ•ãƒ©ã‚°ã‚’åˆæœŸåŒ–
	/** Not supported by UIM platform */

	/// - 3. æ¯”è¼ƒå…ƒãƒ‡ãƒ¼ã‚¿ã¨æ¯”è¼ƒå…ˆãƒ‡ãƒ¼ã‚¿ã‚’ã‚³ãƒ³ãƒšã‚¢ã™ã‚‹
	///    - SRC_DATA != DEST_DATA : @e D1_SYS_RET_FAILURE
/*#5*/
	///TSIP Warning Removal : Warning #767-D
	if( ((T_WORD)pbySrc1Address_p&0x01) || ((T_WORD)pbySrc2Address_p&0x01) || (usLength_p&0x01) )/* pgr0246 *//* pgr0246 *///[[Y2-0CC-0D0-167-000]]//[[Y2-0CC-0D0-168-000]]
	{
/*#1*/
		while(usLength_p--)
		{
/*#2*/
			if(*pbySrc1Address_p++ != *pbySrc2Address_p++)
			{
/*#3*/
				/** Proto-A2: To be removed. Not supported by UIM platform */
				//return (g_byNmmNvmFiq == D1_NMM_NVM_PARITY_ERROR)//[[J3-0CC-0D0-013-000]]
				//	? D1_SYS_RET_NVM_PARITY : D1_SYS_RET_FAILURE;
				return D1_SYS_RET_FAILURE;
			}
		}
	}
	else
	{
		usLength_p = usLength_p >> 1;
		pusSrc1Address = (T_USHORT*) pbySrc1Address_p;
		pusSrc2Address = (T_USHORT*) pbySrc2Address_p;
/*#6*/
		while(usLength_p--)
		{
/*#7*/
			if(*pusSrc1Address++ != *pusSrc2Address++)
			{
/*#8*/
				/** Proto-A2: To be removed. Not supported by UIM platform */
				//return (g_byNmmNvmFiq == D1_NMM_NVM_PARITY_ERROR)
				//	? D1_SYS_RET_NVM_PARITY : D1_SYS_RET_FAILURE;
				return D1_SYS_RET_FAILURE;
			}
		}
	}
	//END(R1-0CC-0D0-014-000)
	/// - 4. NVM Parityã‚¨ãƒ©ãƒ¼ãƒã‚§ãƒƒã‚¯ã—ã€å®Ÿè¡Œçµæžœã‚’ãƒªã‚¿ãƒ¼ãƒ³ã€‚
	///      - @e D1_SYS_RET_NVM_PARITY
/*#4*/
	/** Not supported by UIM platform */
	return D1_SYS_RET_SUCCESS;
	/// - 5. æ¬ ç•ª
	//[[R1-0CC-0D0-01A-000]]
}