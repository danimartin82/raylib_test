#include "gtest/gtest.h"
#include "raylib.h" 

/***********************************************************************************/
/*                                                                                 */
/*     Function SaveFileData() and LoadFileData()                                  */
/*                                                                                 */
/***********************************************************************************/

// We expect storing and loading 10 int number into a new file
TEST(LoadFileData, test_basic_save_load) {
	const char* fileName="test.data";
	int data_in[10]={0,1,2,3,4,5,6,7,8,9};
	unsigned char* data_out=NULL;
	unsigned int bytesToWrite=sizeof(data_in);
	unsigned int numberBytesRead=0;

	SaveFileData(fileName,&data_in,bytesToWrite);
    data_out=LoadFileData(fileName,&numberBytesRead);
	int* data_out2=(int*)data_out;
	
	EXPECT_EQ (bytesToWrite,numberBytesRead);

	for(int i=0;i<10;i++)
	{
  		EXPECT_EQ (data_in[i],data_out2[i]);
	}
    
}


/***********************************************************************************/
/*                                                                                 */
/*     MAIN                                                                        */
/*                                                                                 */
/***********************************************************************************/

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}