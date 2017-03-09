/*
 * TestCopy.cpp
 *
 *  Created on: 17-Feb-2017
 *      Author: ssanjana
 */
#include "gtest/gtest.h"
//#include "gmock/gmock.h"
#include "stdio.h"
#include "memutils.h"

TEST(MemCopyTest, HandlesAlignedAddress)
{
	unsigned char *pbyDstAddr = (unsigned char *)0x2000A000;
	unsigned char *pbySrcAddr = (unsigned char *)0x2000A100;
	unsigned short uslen = 10;
	EXPECT_EQ(D1_SYS_RET_SUCCESS, Nos_MemCopy(pbyDstAddr, pbySrcAddr, uslen));

}

TEST(MemCopyTest, HandlesUnAlignedAddress)
{
	unsigned char *pbyDstAddr = (unsigned char *)0x2000A001;
	unsigned char *pbySrcAddr = (unsigned char *)0x2000A101;
	unsigned short uslen = 10;
	EXPECT_EQ(D1_SYS_RET_SUCCESS, Nos_MemCopy(pbyDstAddr, pbySrcAddr, uslen));

}

TEST(MemCopyTest, HandlesUnAlignedLength)
{
	unsigned char ucDestination[7];
	unsigned char ucSrc[7] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07};
	unsigned short uslen = 7;
	EXPECT_EQ(D1_SYS_RET_SUCCESS, Nos_MemCopy(ucDestination, ucSrc, uslen));
	for (unsigned short i = 0; i < uslen; i++)
	{
		EXPECT_EQ(ucDestination[i], ucSrc[i]);
	}
	//ASSERT_THAT(ucDestination, ElementsAreArray(ucSrc));
}

TEST(MemCopyTest, HandlesAlignedLength)
{
	unsigned char ucDestination[8];
	unsigned char ucSrc[8] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
	unsigned short uslen = 8;
	EXPECT_EQ(D1_SYS_RET_SUCCESS, Nos_MemCopy(ucDestination, ucSrc, uslen));
	for (unsigned short i = 0; i < uslen; i++)
	{
		EXPECT_EQ(ucDestination[i], ucSrc[i]);
	}
	//ASSERT_THAT(ucDestination, ElementsAreArray(ucSrc));
}

TEST(MemCompTest, HandlesAlignedAddress)
{
	unsigned char *pbyDstAddr = (unsigned char *)0x2000A000;
	unsigned char *pbySrcAddr = (unsigned char *)0x2000A100;
	unsigned short uslen = 10;
	EXPECT_EQ(D1_SYS_RET_SUCCESS, Nos_Mm_MemComp(pbyDstAddr, pbySrcAddr, uslen));

}

TEST(MemCompTest, HandlesUnAlignedAddress)
{
	unsigned char *pbyDstAddr = (unsigned char *)0x2000A001;
	unsigned char *pbySrcAddr = (unsigned char *)0x2000A101;
	unsigned short uslen = 10;
	EXPECT_EQ(D1_SYS_RET_SUCCESS, Nos_Mm_MemComp(pbyDstAddr, pbySrcAddr, uslen));

}

TEST(MemCompTest, HandlesUnAlignedLength)
{
	unsigned char ucDestination[7] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07};
	unsigned char ucSrc[7] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07};
	unsigned short uslen = 7;
	EXPECT_EQ(D1_SYS_RET_SUCCESS, Nos_Mm_MemComp(ucDestination, ucSrc, uslen));
	for (unsigned short i = 0; i < uslen; i++)
	{
		EXPECT_EQ(ucDestination[i], ucSrc[i]);
	}
	//ASSERT_THAT(ucDestination, ElementsAreArray(ucSrc));
}

TEST(MemCompTest, HandlesAlignedLength)
{
	unsigned char ucDestination[8] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
	unsigned char ucSrc[8] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
	unsigned short uslen = 8;
	EXPECT_EQ(D1_SYS_RET_SUCCESS, Nos_Mm_MemComp(ucDestination, ucSrc, uslen));
	for (unsigned short i = 0; i < uslen; i++)
	{
		EXPECT_EQ(ucDestination[i], ucSrc[i]);
	}
	//ASSERT_THAT(ucDestination, ElementsAreArray(ucSrc));
}

TEST(MemCopyReverseTest, HandlesAlignedAddress)
{
	unsigned char *pbyDstAddr = (unsigned char *)0x2000A000;
	unsigned char *pbySrcAddr = (unsigned char *)0x2000A100;
	unsigned short uslen = 10;
	EXPECT_EQ(D1_SYS_RET_SUCCESS, Nos_MemCopyReverse(pbyDstAddr, pbySrcAddr, uslen));

}

TEST(MemCopyReverseTest, HandlesUnAlignedAddress)
{
	unsigned char *pbyDstAddr = (unsigned char *)0x2000A001;
	unsigned char *pbySrcAddr = (unsigned char *)0x2000A101;
	unsigned short uslen = 10;
	EXPECT_EQ(D1_SYS_RET_SUCCESS, Nos_MemCopyReverse(pbyDstAddr, pbySrcAddr, uslen));

}

TEST(MemCopyReverseTest, HandlesUnAlignedLength)
{
	unsigned char ucDestination[7];
	unsigned char ucSrc[7] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07};
	unsigned short uslen = 7;
	EXPECT_EQ(D1_SYS_RET_SUCCESS, Nos_MemCopyReverse(ucDestination, ucSrc, uslen));
	for (unsigned short i = 0; i < uslen; i++)
	{
		EXPECT_EQ(ucDestination[i], ucSrc[i]);
	}
	//ASSERT_THAT(ucDestination, ElementsAreArray(ucSrc));
}

TEST(MemCopyReverseTest, HandlesAlignedLength)
{
	unsigned char ucDestination[8];
	unsigned char ucSrc[8] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
	unsigned short uslen = 8;
	EXPECT_EQ(D1_SYS_RET_SUCCESS, Nos_MemCopyReverse(ucDestination, ucSrc, uslen));
	for (unsigned short i = 0; i < uslen; i++)
	{
		EXPECT_EQ(ucDestination[i], ucSrc[i]);
	}
	//ASSERT_THAT(ucDestination, ElementsAreArray(ucSrc));
}