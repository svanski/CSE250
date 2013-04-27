#ifndef KW_ASSERT_H_
#define KW_ASSERT_H_

#include <iostream>

/*<snippet id="1" omit="false">*/
#define kw_assert(x)\
if (!(x)) {\
  std::cerr << "Assertion " << #x << " failed\n";\
  std::cerr << "Line " << __LINE__ << " in file " << __FILE__ << "\n";\
  exit(1);\
}
/*</snippet>*/
#endif
