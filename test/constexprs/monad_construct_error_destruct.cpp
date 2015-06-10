#include "../../include/boost/spinlock/future.hpp"

extern BOOST_SPINLOCK_NOINLINE std::error_code test1(std::error_code ec)
{
  using namespace boost::spinlock::lightweight_futures;
  monad<int> m(std::move(ec));
  return m.get_error();
}
extern BOOST_SPINLOCK_NOINLINE void test2()
{
}

int main(void)
{
  int ret=0;
  if(std::error_code()!=test1(std::error_code())) ret=1;
  test2();
  return ret;
}