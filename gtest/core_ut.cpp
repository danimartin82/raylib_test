#include "gtest/gtest.h"
#include "raylib.h" 

/***********************************************************************************/
/*                                                                                 */
/*     Function InitWindow()                                                       */
/*                                                                                 */
/***********************************************************************************/

// We expect creating and closing a window
TEST(InitWindow, test_basic_initWindow)
{
	int w=1000;
	int h=1000;
	bool isReady;
	bool isResized1;
	bool isResized2;
	bool isFullScreen1;
	bool isFullScreen2;
	bool windowShouldClose;
	const char* title="Hello World!";

	InitWindow(w,h,title);
	isReady=IsWindowReady();

    isResized1=IsWindowResized();   
    isFullScreen1=IsWindowFullscreen();
	ToggleFullscreen();
    isResized2=IsWindowResized();
    isFullScreen2=IsWindowFullscreen();
	
	windowShouldClose=WindowShouldClose();
	CloseWindow();

    
    EXPECT_EQ (isReady,true);
    EXPECT_EQ (isFullScreen1,false);
    EXPECT_EQ (isFullScreen2,true);
    EXPECT_EQ (isResized1,false);
    EXPECT_EQ (isResized2,true);
    EXPECT_EQ (windowShouldClose,false);

}


/***********************************************************************************/
/*                                                                                 */
/*     Functions SaveStorageValue() and LoadStorageValue()                         */
/*                                                                                 */
/***********************************************************************************/

// We expect storing and loading OK in position 0
TEST(SaveStorageValue, test_basic_save_load)
{
	int in=19;
	int out=0;
	unsigned int position=0;

	SaveStorageValue(position,in);
	out=LoadStorageValue(position);
    
    EXPECT_EQ (in,out);
    
}


// We expect to create file storage.data and save/load OK
TEST(SaveStorageValue, create_storage_data_file)
{
	int in=19;
	int out=0;
	unsigned int position=0;

	system("del storage.data");
	SaveStorageValue(position,in);
	out=LoadStorageValue(position);
    EXPECT_EQ (in,out);
}


// We expect to create and increase the size of the file storage.data save/load OK
TEST(SaveStorageValue, increase_storage_data_file)
{
	int in=19;
	int out=0;
	unsigned int position=0;

	system("del storage.data");
	SaveStorageValue(position,in);
	out=LoadStorageValue(position);
    EXPECT_EQ (in,out);
	
	position=23;
	SaveStorageValue(position,in);
	out=LoadStorageValue(position);
    EXPECT_EQ (in,out);
  
}


  // We expect a failure in SaveStorageValue, and so save is not performed. Load gives different data than save
TEST(SaveStorageValue, fail_realloc_in_SaveStorageValue)
{
	int in=19;
	int out=0;
	unsigned int position=INT_MAX;
	
	SaveStorageValue(position,in);
	out=LoadStorageValue(position);
    
    EXPECT_NE (in,out);
    
}



/***********************************************************************************/
/*                                                                                 */
/*     MAIN                                                                        */
/*                                                                                 */
/***********************************************************************************/

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}