#ifndef _HASH_HELPER_H_
#define _HASH_HELPER_H_

#include <vector>
#include <string>
#include "dataset.h"

using namespace std;

class myvalue
{
private:
  mypoint *point;

public:
  myvalue();
  ~myvalue();
  mypoint *get_point();
  void set_point(mypoint *mp);
};

#endif