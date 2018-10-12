// your code here
#include "Bar.h"

using namespace potd;

Bar::Bar(string) {
  Foo * f_(string);
}
Bar::Bar(const Bar & other) : f_(other.f_){}
Bar::~Bar() {
  delete f_;
}
string Bar::get_name() {
  return f_->get_name();
}
