#include "gtest/gtest.h"
#include "raylib.h" 

/***********************************************************************************/
/*                                                                                 */
/*     Function InitWindow()                                                       */
/*                                                                                 */
/***********************************************************************************/

// We expect creating and closing a window of different sizes
TEST(Window, test_init_window)
{
	//int w[]={INT_MIN,-50000,-300,0,50000,INT_MAX};
	//int h[]={INT_MIN,-50000,-300,0,50000,INT_MAX};
	int w[]={0,50000,INT_MAX};
	int h[]={0,50000,INT_MAX};
	
	bool isReady=false;
	
	SetTraceLogLevel(LOG_NONE);

	const char* title="Hello World!";
	for(int i=0; i<sizeof(w);i++)
	{
		InitWindow(w[i],h[i],title);
		isReady=IsWindowReady();
		CloseWindow();
    	EXPECT_EQ (isReady,true);
  
	}
}

// We expect creating and closing a window and some basic operation on it
TEST(Window, test_window_full_screen)
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

	SetTraceLogLevel(LOG_NONE);
	
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


// We expect creating and closing a window of different sizes
TEST(Window, test_title_window)
{
	
	bool isReady=false;
	
	SetTraceLogLevel(LOG_ALL);
	
	const char* title=NULL;
/*	InitWindow(400,300,title);
	isReady=IsWindowReady();
	CloseWindow();
    EXPECT_EQ (isReady,true);
*/
    title="";
	InitWindow(400,300,title);
	InitWindow(400,300,title);
	isReady=IsWindowReady();
	CloseWindow();
    EXPECT_EQ (isReady,true);

	title="\n";
	InitWindow(400,300,title);
	isReady=IsWindowReady();
	CloseWindow();
    EXPECT_EQ (isReady,true);

  
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