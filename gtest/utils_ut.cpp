#include "gtest/gtest.h"
#include "raylib.h" 
#include "../..//fff/fff.h"



/***********************************************************************************/
/*                                                                                 */
/*     Mocks with FFF                                                              */
/*                                                                                 */
/***********************************************************************************/

DEFINE_FFF_GLOBALS;
FAKE_VOID_FUNC(vprintf);

void setup()
{
    RESET_FAKE(vprintf);
    FFF_RESET_HISTORY();
}



/***********************************************************************************/
/*                                                                                 */
/*     Function SetTraceLogLevel()                                                 */
/*                                                                                 */
/***********************************************************************************/

// We expect storing trace log level
TEST(SetTraceLogLevel, test_basic_set)
{
 	
 	for(int i=-300;i<300;i++)
	{
  		SetTraceLogLevel(i);
	}
}
/***********************************************************************************/
/*                                                                                 */
/*     Function SetTraceLogExit()                                                  */
/*                                                                                 */
/***********************************************************************************/

// We expect storing trace log level
TEST(SetTraceLogExit, test_basic_set)
{
 	
 	for(int i=-300;i<300;i++)
	{
  		SetTraceLogExit(i);
	}
}

/***********************************************************************************/
/*                                                                                 */
/*     Function SetTraceLogCallback()                                              */
/*                                                                                 */
/***********************************************************************************/

// We expect storing trace log callback pointer
TEST(SetTraceLogCallback, test_basic_set)
{
 	TraceLogCallback data_in=NULL;
  	
  	SetTraceLogCallback(data_in);

}
/***********************************************************************************/
/*                                                                                 */
/*     Function TraceLog()                                                         */
/*                                                                                 */
/***********************************************************************************/

// We expect basic function, rpinting a message
TEST(TraceLog, test_basic_set)
{
 	int logType=LOG_WARNING;
 	const char *text= "Hello World!";

 	SetTraceLogExit(LOG_NONE);
	SetTraceLogLevel(LOG_ALL);

  	TraceLog(logType,text);

}
/***********************************************************************************/
/*                                                                                 */
/*     Function TraceLog()                                                         */
/*                                                                                 */
/***********************************************************************************/

// We expect Message has level below current threshold, don't call vprintf
TEST(TraceLog, test_no_print)
{
 	int logType=LOG_TRACE;
 	const char *text= "Hello World!";

 	SetTraceLogExit(LOG_NONE);
	SetTraceLogLevel(LOG_NONE);

  	TraceLog(logType,text);

	SetTraceLogLevel(LOG_ALL);

}

/***********************************************************************************/
/*                                                                                 */
/*     Function TraceLog()                                                         */
/*                                                                                 */
/***********************************************************************************/

// We expect print the message and exit. It works. It is commented so the UT execution doesn't stop
//TEST(TraceLog, test_exit)
//{
//	int logType=LOG_TRACE;
//	const char *text= "Hello World!";

//	SetTraceLogExit(LOG_ALL);
//	TraceLog(logType,text);

//}


/***********************************************************************************/
/*                                                                                 */
/*     Functions SaveFileText() LoadFileText()                                     */
/*                                                                                 */
/***********************************************************************************/

// We expect storing and loading basic string into a new file and read it again
TEST(LoadFileText, test_basic_save_load)
{
	const char* fileName="test.text";
	const char* data_in="Hello World!";
	char* data_out=NULL;
	
	SaveFileText(fileName,(char*)data_in);
    data_out=LoadFileText(fileName);
	
	for(int i=0;i<13;i++)
	{
  		EXPECT_EQ (data_in[i],data_out[i]);
	}
}


/***********************************************************************************/
/*                                                                                 */
/*     Function SaveFileData() and LoadFileData()                                  */
/*                                                                                 */
/***********************************************************************************/

// We expect storing and loading 10 int number into a new file and read them again
TEST(LoadFileData, test_basic_save_load)
{
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

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}