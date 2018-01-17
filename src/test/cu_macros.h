#ifndef CU_MACROS_H
#define CU_MACROS_H

// TESTS MACROS
// -------------------------------------------------------------
// The class using these macros need to provide:
//   void   incRun()         - Increment number of tests run
//   void   incFail()        - Increment number of tests fail
//   int    getRun()         - Number of tests run
//   string getId()          - Test name
//   void   setSubTestName() - Set function name in which an assert is checked
//   string getAssertMessage(s_exp, s_det, s_cndName)
// -------------------------------------------------------------

// NOTE: Only 1 assert fails per test because it calls return
// -------------------------------------------------------------
#define CU_ASSERT_EQ( anExpected, aDetected, aCndName ) do     \
{                                                              \
    setSubTestName( __FUNCTION__ );                            \
                                                               \
    std::string s1       = std::to_string( anExpected );       \
    std::string s2       = std::to_string(  aDetected );       \
    std::string asrt_msg = getAssertMessage(s1, s2, aCndName); \
                                                               \
    bool condition = (s1 == s2);                               \
                                                               \
    if( condition == false ) { return asrt_msg; }              \
                                                               \
}   while(0)


// Called by execute()
// TODO: Init()/Deinit() before/after each function()?
// -------------------------------------------------------------
#define CU_RUN( function ) do                                  \
{                                                              \
    std::string message = function();                          \
    incRun();                                                   \
    if( message != "" )                                        \
    {                                                          \
        incFail();                                              \
        std::cout << "[Error]: Test " << getRun()              \
                  <<           " of " << getId() << std::endl  \
                  << "         "      << message << std::endl; \
    }                                                          \
}   while (0)
// -------------------------------------------------------------

#endif // CU_MACROS_H
