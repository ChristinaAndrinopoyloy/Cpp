#ifndef _HASH_HELPER_H_
#define _HASH_HELPER_H_

#include <vector>
#include <string>

using namespace std;

class myvalue
{
  private:
    int itemID;
    vector<int> *point;

  public:
    myvalue();
    ~myvalue();
    vector<int> *get_point();
    void set_point(vector<int> *setmp);
    int get_itemID();
    void set_itemID(int id);
};

#endif